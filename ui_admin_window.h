/********************************************************************************
** Form generated from reading UI file 'admin_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_WINDOW_H
#define UI_ADMIN_WINDOW_H

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

class Ui_admin_window
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *adminName;
    QVBoxLayout *verticalLayout;
    QPushButton *OrdersList;
    QPushButton *emplList;
    QLabel *label;
    QLineEdit *emplName;
    QLineEdit *empLogin;
    QPushButton *addEmpl;
    QPushButton *deleteBtn;
    QLineEdit *emplPos;
    QLineEdit *chatInput;
    QLineEdit *deleteEmp;
    QLabel *label_5;
    QPushButton *chatSend;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *emplPass;
    QSpacerItem *horizontalSpacer;
    QTableView *chatTable;
    QTableView *tableView;
    QLabel *label_6;

    void setupUi(QDialog *admin_window)
    {
        if (admin_window->objectName().isEmpty())
            admin_window->setObjectName(QString::fromUtf8("admin_window"));
        admin_window->resize(1056, 476);
        gridLayout_3 = new QGridLayout(admin_window);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(admin_window);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        adminName = new QLabel(admin_window);
        adminName->setObjectName(QString::fromUtf8("adminName"));

        horizontalLayout->addWidget(adminName);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        OrdersList = new QPushButton(admin_window);
        OrdersList->setObjectName(QString::fromUtf8("OrdersList"));

        verticalLayout->addWidget(OrdersList);

        emplList = new QPushButton(admin_window);
        emplList->setObjectName(QString::fromUtf8("emplList"));

        verticalLayout->addWidget(emplList);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(verticalLayout_2, 0, 4, 2, 1);

        label = new QLabel(admin_window);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 3, 1, 1);

        emplName = new QLineEdit(admin_window);
        emplName->setObjectName(QString::fromUtf8("emplName"));

        gridLayout->addWidget(emplName, 2, 4, 1, 1);

        empLogin = new QLineEdit(admin_window);
        empLogin->setObjectName(QString::fromUtf8("empLogin"));

        gridLayout->addWidget(empLogin, 4, 4, 1, 1);

        addEmpl = new QPushButton(admin_window);
        addEmpl->setObjectName(QString::fromUtf8("addEmpl"));

        gridLayout->addWidget(addEmpl, 6, 4, 1, 1);

        deleteBtn = new QPushButton(admin_window);
        deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));

        gridLayout->addWidget(deleteBtn, 1, 3, 1, 1);

        emplPos = new QLineEdit(admin_window);
        emplPos->setObjectName(QString::fromUtf8("emplPos"));

        gridLayout->addWidget(emplPos, 3, 4, 1, 1);

        chatInput = new QLineEdit(admin_window);
        chatInput->setObjectName(QString::fromUtf8("chatInput"));

        gridLayout->addWidget(chatInput, 6, 0, 1, 1);

        deleteEmp = new QLineEdit(admin_window);
        deleteEmp->setObjectName(QString::fromUtf8("deleteEmp"));

        gridLayout->addWidget(deleteEmp, 0, 3, 1, 1);

        label_5 = new QLabel(admin_window);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 3, 1, 1);

        chatSend = new QPushButton(admin_window);
        chatSend->setObjectName(QString::fromUtf8("chatSend"));

        gridLayout->addWidget(chatSend, 6, 1, 1, 1);

        label_3 = new QLabel(admin_window);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 3, 1, 1);

        label_4 = new QLabel(admin_window);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 3, 1, 1);

        emplPass = new QLineEdit(admin_window);
        emplPass->setObjectName(QString::fromUtf8("emplPass"));

        gridLayout->addWidget(emplPass, 5, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        chatTable = new QTableView(admin_window);
        chatTable->setObjectName(QString::fromUtf8("chatTable"));

        gridLayout->addWidget(chatTable, 0, 0, 6, 3);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        tableView = new QTableView(admin_window);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout_2->addWidget(tableView, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);

        label_6 = new QLabel(admin_window);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);


        retranslateUi(admin_window);

        QMetaObject::connectSlotsByName(admin_window);
    } // setupUi

    void retranslateUi(QDialog *admin_window)
    {
        admin_window->setWindowTitle(QApplication::translate("admin_window", "Dialog", nullptr));
        label_2->setText(QApplication::translate("admin_window", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));
        adminName->setText(QApplication::translate("admin_window", "admin_name", nullptr));
        OrdersList->setText(QApplication::translate("admin_window", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \320\267\320\260\320\272\320\260\320\267\320\276\320\262", nullptr));
        emplList->setText(QApplication::translate("admin_window", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\200\320\260\320\261\320\276\321\202\320\275\320\270\320\272\320\276\320\262", nullptr));
        label->setText(QApplication::translate("admin_window", "                            \320\230\320\274\321\217", nullptr));
        addEmpl->setText(QApplication::translate("admin_window", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\200\320\260\320\261\320\276\321\202\320\275\320\270\320\272\320\260", nullptr));
        deleteBtn->setText(QApplication::translate("admin_window", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\200\320\260\320\261\320\276\321\202\320\275\320\270\320\272\320\260", nullptr));
        label_5->setText(QApplication::translate("admin_window", "                      \320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        chatSend->setText(QApplication::translate("admin_window", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("admin_window", "                \320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_4->setText(QApplication::translate("admin_window", "                        \320\233\320\276\320\263\320\270\320\275", nullptr));
        label_6->setText(QApplication::translate("admin_window", "\320\247\320\260\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin_window: public Ui_admin_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_WINDOW_H
