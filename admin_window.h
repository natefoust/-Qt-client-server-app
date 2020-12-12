#ifndef ADMIN_WINDOW_H
#define ADMIN_WINDOW_H
#include "employers.h"
#include <QDialog>

namespace Ui {
class admin_window;
}

class admin_window : public QDialog
{
    Q_OBJECT

public:
    explicit admin_window(QWidget *parent = nullptr);
    ~admin_window();
    QString id;
    QString name;
    QString permissions;
    administrator *admin = new administrator;


private slots:
    void getData(QVector<QString> empl);
    void getMessages();

    void on_addEmpl_clicked();

    void on_chatSend_clicked();

    void on_deleteBtn_clicked();

    void on_OrdersList_clicked();

    void on_emplList_clicked();

private:
    Ui::admin_window *ui;
    QStandardItemModel *ctTable;
    QStandardItemModel *view;
};

#endif // ADMIN_WINDOW_H
