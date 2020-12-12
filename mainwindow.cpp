#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::setFixedSize(300,300);
    QWidget::setWindowTitle("Авторизация");

    w = new waiter_window();
    c = new cook_window();
    a = new admin_window();


    connect(this, SIGNAL(sendData(QVector<QString>)), w, SLOT(getData(QVector<QString>)));
    connect(this, SIGNAL(sendData(QVector<QString>)), c, SLOT(getData(QVector<QString>)));
    connect(this, SIGNAL(sendData(QVector<QString>)), a, SLOT(getData(QVector<QString>)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// авторизация по кнопке "Войти"
void MainWindow::on_autoriz_enter_btn_clicked()
{
    // Если поля пустые выводит сообщение об ошибке
    if((ui->autoriz_line_login->text().isEmpty()) || (ui->autoriz_line_pass->text().isEmpty()))
    {
        QMessageBox::information(NULL, "Ошибка авторизации", "Необходимо заполнить все поля.");
    }

    else
    {
        QSqlQuery query;
        QSqlRecord record;


        QString    id;
        QString    strLogin;
        QString    strPassword;
        QString    strPermissions;
        QString    strName;

        query.exec("SELECT * FROM users");

        record = query.record();

        while (query.next())
        {
                id             = query.value(record.indexOf("id")).toString();
                strLogin       = query.value(record.indexOf("login")).toString();
                strPassword    = query.value(record.indexOf("password")).toString();
                strPermissions = query.value(record.indexOf("permissions")).toString();
                strName        = query.value(record.indexOf("name")).toString();

                QVector<QString> s;
                s.push_back(id);
                s.push_back(strPermissions);
                s.push_back(strName);

                if((ui->autoriz_line_login->text() == strLogin) && (ui->autoriz_line_pass->text() == strPassword))
                {
                    if(strPermissions == "waiter")
                    {
                        emit sendData(s);
                        w->exec();
                    }
                    if(strPermissions == "cook")
                    {
                        emit sendData(s);
                        c->exec();
                    }
                    if(strPermissions == "admin")
                    {
                        emit sendData(s);
                        a->exec();
                    }
                }
        }
    }
}
