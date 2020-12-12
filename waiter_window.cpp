#include "waiter_window.h"
#include "ui_waiter_window.h"
#include <QDebug>
waiter_window::waiter_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::waiter_window)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getReadyOrders()));
    connect(timer, SIGNAL(timeout()), this, SLOT(getMessages()));
        timer->start(6000);

        ui->chat->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->chat->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->chat->setShowGrid(false);
        ui->chat->setWordWrap(true);

        ui->chat->horizontalHeader()->setStretchLastSection(true);

        ui->rdOrders->setWordWrap(true);
        ui->rdOrders->horizontalHeader()->setStretchLastSection(true);
        ui->rdOrders->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->rdOrders->setSelectionBehavior(QAbstractItemView::SelectRows);


}

waiter_window::~waiter_window()
{
    delete ui;
}

void waiter_window::getData(QVector<QString> empl)
{
    wait->setName(empl[2]);
    wait->setPosition(empl[1]);
    wait->setId(empl[0]);

    ui->waiterName->setText(wait->getName());

}

void waiter_window::getReadyOrders()
{
    QSqlQuery getRows; QSqlRecord rec;
    getRows.exec("SELECT count(*) FROM ready_orders");
    rec = getRows.record();
    getRows.first();
    int rows = getRows.value(rec.indexOf("count")).toInt();

    readyOrders = new QStandardItemModel(rows, 4, this);
    ui->rdOrders->setModel(readyOrders);


    QModelIndex index;
    QList<QList<QString>> listOfOrders;
    listOfOrders = wait->checkReadyOrders();

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            index = readyOrders->index(i,j);
            readyOrders->setData(index, listOfOrders[i][j]);
        }
    }
}

void waiter_window::on_takeOrder_clicked()
{
    wait->takeOrder();
}

void waiter_window::on_closeOrder_clicked()
{
    // TODO: сделать базу данных для истории заказов
    // удалить данные из таблицы readyOrders и добавить заказ в новую таблицу с указанием инфы о официанте(+возможно поваре)

    QModelIndex index = ui->rdOrders->selectionModel()->currentIndex();
    int row = index.row();
    index = readyOrders->index(row,0);
    QString id = readyOrders->data(index).toString();
    QString name = wait->getName();
    wait->closeOrder(id, name);
}



void waiter_window::on_chatSend_clicked()
{
    QString str = ui->lineEdit->text();
    QString name = wait->getName();
    QString pos = wait->getPosition();

    QSqlQuery query;
    query.prepare("INSERT INTO chat(name_,position_,msg_) VALUES(:name, :pos, :str)");
    query.bindValue(":name", name);
    query.bindValue(":pos", pos);
    query.bindValue(":str", str);
    query.exec();
}

void waiter_window::getMessages()
{
    QSqlQuery getRows; QSqlRecord rec;
    getRows.exec("SELECT count(*) FROM chat");
    rec = getRows.record();
    getRows.first();
    int rows = getRows.value(rec.indexOf("count")).toInt();

    chatTable = new QStandardItemModel(rows, 3, this);
    ui->chat->setModel(chatTable);


    QModelIndex index;
    QList<QList<QString>> listOfMessages;
    listOfMessages = wait->checkMessages();

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            index = chatTable->index(i,j);
            chatTable->setData(index, listOfMessages[i][j]);
        }
    }
}
