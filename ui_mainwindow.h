/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *autoriz_box;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *autoriz_login;
    QLineEdit *autoriz_line_login;
    QLabel *autoriz_pass;
    QLineEdit *autoriz_line_pass;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *autoriz_enter_btn;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(286, 319);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        autoriz_box = new QGroupBox(centralwidget);
        autoriz_box->setObjectName(QString::fromUtf8("autoriz_box"));
        QFont font;
        font.setPointSize(10);
        autoriz_box->setFont(font);
        widget = new QWidget(autoriz_box);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 50, 178, 52));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        autoriz_login = new QLabel(widget);
        autoriz_login->setObjectName(QString::fromUtf8("autoriz_login"));

        formLayout->setWidget(0, QFormLayout::LabelRole, autoriz_login);

        autoriz_line_login = new QLineEdit(widget);
        autoriz_line_login->setObjectName(QString::fromUtf8("autoriz_line_login"));

        formLayout->setWidget(0, QFormLayout::FieldRole, autoriz_line_login);

        autoriz_pass = new QLabel(widget);
        autoriz_pass->setObjectName(QString::fromUtf8("autoriz_pass"));

        formLayout->setWidget(1, QFormLayout::LabelRole, autoriz_pass);

        autoriz_line_pass = new QLineEdit(widget);
        autoriz_line_pass->setObjectName(QString::fromUtf8("autoriz_line_pass"));

        formLayout->setWidget(1, QFormLayout::FieldRole, autoriz_line_pass);

        widget1 = new QWidget(autoriz_box);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(160, 180, 101, 71));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        autoriz_enter_btn = new QPushButton(widget1);
        autoriz_enter_btn->setObjectName(QString::fromUtf8("autoriz_enter_btn"));

        verticalLayout_2->addWidget(autoriz_enter_btn);

        pushButton_2 = new QPushButton(widget1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);


        verticalLayout->addWidget(autoriz_box);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 286, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        autoriz_box->setTitle(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\320\265", nullptr));
        autoriz_login->setText(QApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        autoriz_pass->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        autoriz_enter_btn->setText(QApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
