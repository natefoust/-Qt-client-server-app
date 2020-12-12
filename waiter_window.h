#ifndef WAITER_WINDOW_H
#define WAITER_WINDOW_H

#include <QDialog>
#include <QVector>
#include <QInputDialog>
#include <QString>

#include "employers.h"


namespace Ui {
class waiter_window;
}

class waiter_window : public QDialog
{
    Q_OBJECT

public:
    explicit waiter_window(QWidget *parent = nullptr);
    ~waiter_window();
    QString id;
    QString name;
    QString permissions;
    waaiter *wait = new waaiter;


signals:


public slots:
    void getData(QVector<QString> empl);
    void getReadyOrders();
    void getMessages();


private slots:
    void on_takeOrder_clicked();


    void on_closeOrder_clicked();



    void on_chatSend_clicked();


private:
    Ui::waiter_window *ui;
    QStandardItemModel *readyOrders;
    QStandardItemModel *chatTable;

};

#endif // WAITER_WINDOW_H
