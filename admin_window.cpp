#include "admin_window.h"
#include "ui_admin_window.h"

admin_window::admin_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_window)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getMessages()));
        timer->start(6000);
}

void admin_window::getData(QVector<QString> empl)
{
    admin->setName(empl[2]);
    admin->setPosition(empl[1]);
    admin->setId(empl[0]);

    ui->adminName->setText(admin->getName());
}

admin_window::~admin_window()
{
    delete ui;
}

void admin_window::on_addEmpl_clicked()
{
    QString name = ui->emplName->text();
    QString position = ui->emplPos->text();
    QString login = ui->empLogin->text();
    QString password = ui->emplPass->text();
    admin->addnewuser(name, position, login, password);
}

void admin_window::getMessages()
{
    QSqlQuery getRows; QSqlRecord rec;
    getRows.exec("SELECT count(*) FROM chat");
    rec = getRows.record();
    getRows.first();
    int rows = getRows.value(rec.indexOf("count")).toInt();

    ctTable = new QStandardItemModel(rows, 3, this);
    ui->chatTable->setModel(ctTable);


    QModelIndex index;
    QList<QList<QString>> listOfMessages;
    listOfMessages = admin->checkMessages();

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            index = ctTable->index(i,j);
            ctTable->setData(index, listOfMessages[i][j]);
        }
    }
}


void admin_window::on_chatSend_clicked()
{
    QString str = ui->chatInput->text();
    QString name = admin->getName();
    QString pos = admin->getPosition();

    QSqlQuery query;
    query.prepare("INSERT INTO chat(name_,position_,msg_) VALUES(:name, :pos, :str)");
    query.bindValue(":name", name);
    query.bindValue(":pos", pos);
    query.bindValue(":str", str);
    query.exec();
}

void admin_window::on_deleteBtn_clicked()
{
     QString login = ui->deleteEmp->text();
     admin->deleteEmployer(login);
}

void admin_window::on_OrdersList_clicked()
{
    QSqlQuery getRows; QSqlRecord rec;
    getRows.exec("SELECT count(*) FROM orders_story");
    rec = getRows.record();
    getRows.first();
    int rows = getRows.value(rec.indexOf("count")).toInt();

    view = new QStandardItemModel(rows, 6, this);
    ui->tableView->setModel(view);


    QModelIndex index;
    QList<QList<QString>> listOfMessages;
    listOfMessages = admin->showOrdersStory();

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            index = view->index(i,j);
            view->setData(index, listOfMessages[i][j]);
        }
    }
}

void admin_window::on_emplList_clicked()
{
    QSqlQuery getRows; QSqlRecord rec;
    getRows.exec("SELECT count(*) FROM users");
    rec = getRows.record();
    getRows.first();
    int rows = getRows.value(rec.indexOf("count")).toInt();

    view = new QStandardItemModel(rows, 4, this);
    ui->tableView->setModel(view);


    QModelIndex index;
    QList<QList<QString>> listOfMessages;
    listOfMessages = admin->showEmployers();

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            index = view->index(i,j);
            view->setData(index, listOfMessages[i][j]);
        }
    }
}
