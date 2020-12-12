/********************************************************************************
** Form generated from reading UI file 'waiter_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITER_WINDOW_H
#define UI_WAITER_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_waiter_window
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QTableView *rdOrders;
    QLabel *label;
    QTableView *chat;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *chatSend;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *position;
    QLabel *waiterName;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *takeOrder;
    QPushButton *closeOrder;
    QLabel *label_2;

    void setupUi(QDialog *waiter_window)
    {
        if (waiter_window->objectName().isEmpty())
            waiter_window->setObjectName(QString::fromUtf8("waiter_window"));
        waiter_window->resize(582, 361);
        gridLayout_2 = new QGridLayout(waiter_window);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        rdOrders = new QTableView(waiter_window);
        rdOrders->setObjectName(QString::fromUtf8("rdOrders"));

        gridLayout->addWidget(rdOrders, 4, 0, 1, 2);

        label = new QLabel(waiter_window);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        chat = new QTableView(waiter_window);
        chat->setObjectName(QString::fromUtf8("chat"));
        chat->setLineWidth(0);
        chat->setShowGrid(false);
        chat->setWordWrap(false);
        chat->setCornerButtonEnabled(false);
        chat->horizontalHeader()->setVisible(false);
        chat->horizontalHeader()->setHighlightSections(false);
        chat->verticalHeader()->setVisible(false);
        chat->verticalHeader()->setHighlightSections(false);

        gridLayout->addWidget(chat, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit = new QLineEdit(waiter_window);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        chatSend = new QPushButton(waiter_window);
        chatSend->setObjectName(QString::fromUtf8("chatSend"));

        horizontalLayout_2->addWidget(chatSend);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        position = new QLabel(waiter_window);
        position->setObjectName(QString::fromUtf8("position"));

        horizontalLayout->addWidget(position);

        waiterName = new QLabel(waiter_window);
        waiterName->setObjectName(QString::fromUtf8("waiterName"));

        horizontalLayout->addWidget(waiterName);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        takeOrder = new QPushButton(waiter_window);
        takeOrder->setObjectName(QString::fromUtf8("takeOrder"));

        verticalLayout->addWidget(takeOrder);

        closeOrder = new QPushButton(waiter_window);
        closeOrder->setObjectName(QString::fromUtf8("closeOrder"));

        verticalLayout->addWidget(closeOrder);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        label_2 = new QLabel(waiter_window);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(waiter_window);

        QMetaObject::connectSlotsByName(waiter_window);
    } // setupUi

    void retranslateUi(QDialog *waiter_window)
    {
        waiter_window->setWindowTitle(QApplication::translate("waiter_window", "Dialog", nullptr));
        label->setText(QApplication::translate("waiter_window", "\320\223\320\276\321\202\320\276\320\262\321\213\320\265 \320\267\320\260\320\272\320\260\320\267\321\213", nullptr));
        chatSend->setText(QApplication::translate("waiter_window", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        position->setText(QApplication::translate("waiter_window", "\320\236\321\204\320\270\321\206\320\270\320\260\320\275\321\202", nullptr));
        waiterName->setText(QApplication::translate("waiter_window", "\320\230\320\274\321\217 \320\276\321\204\320\270\321\206\320\270\320\260\320\275\321\202\320\260", nullptr));
        takeOrder->setText(QApplication::translate("waiter_window", "\320\236\321\204\320\276\321\200\320\274\320\270\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        closeOrder->setText(QApplication::translate("waiter_window", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        label_2->setText(QApplication::translate("waiter_window", "\320\247\320\260\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class waiter_window: public Ui_waiter_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITER_WINDOW_H
