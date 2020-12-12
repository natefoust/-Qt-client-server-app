#ifndef EMPLOYERS_H
#define EMPLOYERS_H
#include <QString>
#include <QInputDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QDialog>
#include <QtGui>
#include <QDate>
#include <QTime>
#include <QMessageBox>
#include <QTimer>
#include <QModelIndex>

class waaiter
{
public:
    QString id;
    QString position;
    QString name;

    waaiter(QString id, QString position, QString name);
    waaiter(const waaiter & other);
    waaiter() {}

    QList<QList<QString>> checkReadyOrders();
    QString getName();
    QString getPosition();
    void setName(QString ename);
    void setPosition(QString pos);
    void setId(QString id);
    void takeOrder();
    void editOrder();
    void closeOrder(QString id, QString name);
    void sendMessage();
    QList<QList<QString>> checkMessages();
};

class cook
{
public:
    QString id;
    QString position;
    QString name;

    cook(QString id, QString position, QString name);
    cook(const cook & other);
    cook() {}

    void confirmOrger(QString id);
    void createMessage();
    void cancelOrder(QString id);
    void readyOrder(QString id);

    void setName(QString ename);
    void setPosition(QString pos);
    void setId(QString id);
    QString getName();
    QString getPosition();

    QList<QList<QString>> checkUnconfirmedOrders();
    QList<QList<QString>> checkConfirmedOrders();
    QList<QList<QString>> checkMessages();

};

class administrator
{
public:
    QString id;
    QString position;
    QString name;
    administrator(QString id, QString position, QString name);
    administrator(const cook &other);
    administrator() {}

    QList<QList<QString>> checkMessages();
    void setName(QString ename);
    void setPosition(QString pos);
    void setId(QString id);
    QString getName();
    QString getPosition();
    void addnewuser(QString name, QString position, QString login, QString password);
    void deleteEmployer(QString login);
    QList<QList<QString>> showOrdersStory();
    QList<QList<QString>> showEmployers();

};


#endif // EMPLOYERS_H
