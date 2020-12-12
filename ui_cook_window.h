/********************************************************************************
** Form generated from reading UI file 'cook_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COOK_WINDOW_H
#define UI_COOK_WINDOW_H

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

class Ui_cook_window
{
public:
    QGridLayout *gridLayout;
    QTableView *unconfirmed;
    QTableView *confirmed;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *cookName;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *takeOrder;
    QPushButton *pushButton;
    QPushButton *readyOrder;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QTableView *tableChat;
    QLabel *label_4;
    QPushButton *chatSend;
    QLineEdit *chatInput;

    void setupUi(QDialog *cook_window)
    {
        if (cook_window->objectName().isEmpty())
            cook_window->setObjectName(QString::fromUtf8("cook_window"));
        cook_window->resize(777, 463);
        gridLayout = new QGridLayout(cook_window);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        unconfirmed = new QTableView(cook_window);
        unconfirmed->setObjectName(QString::fromUtf8("unconfirmed"));

        gridLayout->addWidget(unconfirmed, 1, 0, 1, 1);

        confirmed = new QTableView(cook_window);
        confirmed->setObjectName(QString::fromUtf8("confirmed"));

        gridLayout->addWidget(confirmed, 3, 0, 1, 3);

        label = new QLabel(cook_window);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(cook_window);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        cookName = new QLabel(cook_window);
        cookName->setObjectName(QString::fromUtf8("cookName"));

        horizontalLayout->addWidget(cookName);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        takeOrder = new QPushButton(cook_window);
        takeOrder->setObjectName(QString::fromUtf8("takeOrder"));

        verticalLayout->addWidget(takeOrder);

        pushButton = new QPushButton(cook_window);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        readyOrder = new QPushButton(cook_window);
        readyOrder->setObjectName(QString::fromUtf8("readyOrder"));

        verticalLayout->addWidget(readyOrder);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(verticalLayout_2, 1, 2, 1, 1);

        label_3 = new QLabel(cook_window);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        tableChat = new QTableView(cook_window);
        tableChat->setObjectName(QString::fromUtf8("tableChat"));

        gridLayout->addWidget(tableChat, 1, 1, 1, 1);

        label_4 = new QLabel(cook_window);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 1, 1, 1);

        chatSend = new QPushButton(cook_window);
        chatSend->setObjectName(QString::fromUtf8("chatSend"));

        gridLayout->addWidget(chatSend, 2, 2, 1, 1);

        chatInput = new QLineEdit(cook_window);
        chatInput->setObjectName(QString::fromUtf8("chatInput"));

        gridLayout->addWidget(chatInput, 2, 1, 1, 1);


        retranslateUi(cook_window);

        QMetaObject::connectSlotsByName(cook_window);
    } // setupUi

    void retranslateUi(QDialog *cook_window)
    {
        cook_window->setWindowTitle(QApplication::translate("cook_window", "Dialog", nullptr));
        label->setText(QApplication::translate("cook_window", "\320\237\320\276\321\201\321\202\321\203\320\277\320\270\320\262\321\210\320\270\320\265 \320\267\320\260\320\272\320\260\320\267\321\213", nullptr));
        label_2->setText(QApplication::translate("cook_window", "\320\237\320\276\320\262\320\260\321\200", nullptr));
        cookName->setText(QApplication::translate("cook_window", "cook_name", nullptr));
        takeOrder->setText(QApplication::translate("cook_window", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        pushButton->setText(QApplication::translate("cook_window", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        readyOrder->setText(QApplication::translate("cook_window", "\320\241\320\276\320\276\320\261\321\211\320\270\321\202\321\214 \320\276 \320\263\320\276\321\202\320\276\320\262\320\275\320\276\321\201\321\202\320\270", nullptr));
        label_3->setText(QApplication::translate("cook_window", "\320\242\320\265\320\272\321\203\321\211\320\270\320\265 \320\267\320\260\320\272\320\260\320\267\321\213:", nullptr));
        label_4->setText(QApplication::translate("cook_window", "\320\247\320\260\321\202", nullptr));
        chatSend->setText(QApplication::translate("cook_window", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cook_window: public Ui_cook_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COOK_WINDOW_H
