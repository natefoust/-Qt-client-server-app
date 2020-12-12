#ifndef COOK_WINDOW_H
#define COOK_WINDOW_H
#include "employers.h"
#include <QDialog>
#include <QDebug>
#include <QStandardItemModel>

namespace Ui {
class cook_window;
}

class cook_window : public QDialog
{
    Q_OBJECT

public:
    explicit cook_window(QWidget *parent = nullptr);
    ~cook_window();


    void show()
    {
        qDebug() << cooker->getName();
    }




private slots:
    void on_pushButton_clicked();
    void getUnconfirmedOrders();
    void getConfirmedOrders();
    void getData(QVector<QString> empl);
    void getMessages();


    void on_takeOrder_clicked();
    void on_readyOrder_clicked();



    void on_chatSend_clicked();

private:
    Ui::cook_window *ui;
    QStandardItemModel *unconfirmedOrders;
    QStandardItemModel *confirmedOrders;
    QStandardItemModel *ctTable;

    QString id;
    QString name;
    QString permissions;
    cook *cooker = new cook;



};

#endif // COOK_WINDOW_H
