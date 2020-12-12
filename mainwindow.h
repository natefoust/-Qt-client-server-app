#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVector>
#include <QMainWindow>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include <QDebug>
#include "employers.h"
#include "waiter_window.h"
#include "cook_window.h"
#include "admin_window.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sendData(QVector<QString>);
private slots:
    void on_autoriz_enter_btn_clicked();

private:
    Ui::MainWindow *ui;
    waiter_window *w;
    cook_window *c;
    admin_window *a;


};
#endif // MAINWINDOW_H
