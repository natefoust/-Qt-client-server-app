#include "cook_window.h"
#include "ui_cook_window.h"

cook_window::cook_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cook_window)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getUnconfirmedOrders()));
    connect(timer, SIGNAL(timeout()), this, SLOT(getConfirmedOrders()));
    connect(timer, SIGNAL(timeout()), this, SLOT(getMessages()));
        timer->start(6000);

    ui->unconfirmed->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->unconfirmed->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->unconfirmed->setWordWrap(true);
    ui->unconfirmed->horizontalHeader()->setStretchLastSection(true);

    ui->confirmed->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->confirmed->setSelectionBehavior(QAbstractItemView::SelectRows);  
    ui->confirmed->setWordWrap(true);
    ui->confirmed->horizontalHeader()->setStretchLastSection(true);

    ui->tableChat->setShowGrid(false);
    ui->tableChat->setWordWrap(true);
    ui->tableChat->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableChat->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableChat->horizontalHeader()->setStretchLastSection(true);
}


void cook_window::getData(QVector<QString> empl)
{
    cooker->setName(empl[2]);
    cooker->setPosition(empl[1]);
    cooker->setId(empl[0]);
    ui->cookName->setText(cooker->getName());
}

void cook_window::getUnconfirmedOrders()
{
    QSqlQuery getRows; QSqlRecord rec;
    getRows.exec("SELECT count(*) FROM unconfirmed_orders");
    rec = getRows.record();
    getRows.first();
    int rows = getRows.value(rec.indexOf("count")).toInt();

    unconfirmedOrders = new QStandardItemModel(rows, 4, this);
    ui->unconfirmed->setModel(unconfirmedOrders);

    QModelIndex index;
    QList<QList<QString>> listOfOrders;
    listOfOrders = cooker->checkUnconfirmedOrders();

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            index = unconfirmedOrders->index(i,j);
            unconfirmedOrders->setData(index, listOfOrders[i][j]);
        }
    }
}

cook_window::~cook_window()
{
    delete ui;
}

// Отменить заказ
void cook_window::on_pushButton_clicked()
{
    QModelIndex index = ui->unconfirmed->selectionModel()->currentIndex();
    int row = index.row();
    index = unconfirmedOrders->index(row,0);
    QString id = unconfirmedOrders->data(index).toString();
    cooker->cancelOrder(id);
}

// Подтвердить заказ
void cook_window::on_takeOrder_clicked()
{
     QModelIndex index = ui->unconfirmed->selectionModel()->currentIndex();
     int row = index.row();
     index = unconfirmedOrders->index(row,0);
     QString id = unconfirmedOrders->data(index).toString();
     cooker->confirmOrger(id);
}

void cook_window::getConfirmedOrders()
{
    QSqlQuery getRows; QSqlRecord rec;
    getRows.exec("SELECT count(*) FROM confirmed_orders");
    rec = getRows.record();
    getRows.first();
    int rows = getRows.value(rec.indexOf("count")).toInt();

    confirmedOrders = new QStandardItemModel(rows, 4, this);
    ui->confirmed->setModel(confirmedOrders);

    QModelIndex index;
    QList<QList<QString>> listOfOrders;
    listOfOrders = cooker->checkConfirmedOrders();

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            index = confirmedOrders->index(i,j);
            confirmedOrders->setData(index, listOfOrders[i][j]);
        }
    }
}

void cook_window::on_readyOrder_clicked()
{
    QModelIndex index = ui->confirmed->selectionModel()->currentIndex();
    int row = index.row();
    index = confirmedOrders->index(row,0);
    QString id = confirmedOrders->data(index).toString();
    cooker->readyOrder(id);
}

void cook_window::getMessages()
{
    QSqlQuery getRows; QSqlRecord rec;
    getRows.exec("SELECT count(*) FROM chat");
    rec = getRows.record();
    getRows.first();
    int rows = getRows.value(rec.indexOf("count")).toInt();

    ctTable = new QStandardItemModel(rows, 3, this);
    ui->tableChat->setModel(ctTable);


    QModelIndex index;
    QList<QList<QString>> listOfMessages;
    listOfMessages = cooker->checkMessages();

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            index = ctTable->index(i,j);
            ctTable->setData(index, listOfMessages[i][j]);
        }
    }
}

void cook_window::on_chatSend_clicked()
{
    QString str = ui->chatInput->text();
    QString name = cooker->getName();
    QString pos = cooker->getPosition();

    QSqlQuery query;
    query.prepare("INSERT INTO chat(name_,position_,msg_) VALUES(:name, :pos, :str)");
    query.bindValue(":name", name);
    query.bindValue(":pos", pos);
    query.bindValue(":str", str);
    query.exec();
}
