#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include <QList>

inline bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("os_db");
    db.setUserName("postgres");
    db.setPassword("eugene555");

    if(!db.open())
    {
        QMessageBox::information(NULL, "Ошибка БД", db.lastError().text());
        return false;
    }

    else
    {
        QMessageBox::information(NULL, "Успешно", "Соединение с базой данных успешно установлено.");
        return true;
    }
}



#endif // CONNECTION_H
