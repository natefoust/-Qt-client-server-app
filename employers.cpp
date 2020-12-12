#include "employers.h"

// waiter section

waaiter::waaiter(QString id, QString position, QString name)
{
    this->id = id;
    this->position = position;
    this->name = name;
}

waaiter::waaiter(const waaiter & other)
{
    this->id = other.id;
    this->name = other.name;
    this->position = other.position;
}

QString waaiter::getName()
{
    return name;
}

QString waaiter::getPosition()
{
    return position;

}

void waaiter::setName(QString ename)
{
    this->name = ename;
}

void waaiter::setPosition(QString pos)
{
    this->position = pos;
}

void waaiter::setId(QString id)
{
    this->id = id;
}


void waaiter::takeOrder()
{
    QInputDialog *orderInput = new QInputDialog();
    QString w_table = orderInput->getText(0, "Оформление заказа", "Столик");
    QString w_order = orderInput->getText(0, "Оформление заказа", "Заказ");

    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    QString time_s = time.toString();
    QString date_s = date.toString();

    QSqlQuery query;
    query.prepare("INSERT INTO unconfirmed_orders (time, order_val, date, table_no) VALUES (:time, :w_order, :date, :w_table)");
    query.bindValue(":time", time_s);
    query.bindValue(":w_table", w_table);
    query.bindValue(":w_order", w_order);
    query.bindValue(":date", date_s);
    if( !query.exec() )
    {
        qDebug() << w_table << w_order << time_s << date_s;
    }

}

QList<QList<QString>> waaiter::checkReadyOrders()
{
    QSqlQuery query;
    QSqlRecord rec;

    QList <QString> lst;
    QList <QList<QString>> listOfOrders;

    QString id = 0;
    QString time;
    QString table_;
    QString order_;

    query.exec("SELECT * FROM ready_orders;");
    rec = query.record();
    while (query.next()) {
            id  = query.value(rec.indexOf("id")).toString();
            time  = query.value(rec.indexOf("time_")).toString();
            table_ = query.value(rec.indexOf("table_")).toString();
            order_ = query.value(rec.indexOf("order_")).toString();

            lst.push_back(id);
            lst.push_back(time);
            lst.push_back(table_);
            lst.push_back(order_);

            listOfOrders.push_back(lst);

            lst.clear();

        }
    return listOfOrders;
}

QList<QList<QString>> waaiter::checkMessages()
{
    QSqlQuery query;
    QSqlRecord rec;

    QList <QString> lst;
    QList <QList<QString>> listOfMessages;

    QString id = 0;
    QString name_;
    QString position_;
    QString msg_;

    query.exec("SELECT * FROM chat;");
    rec = query.record();
    while (query.next()) {

            name_  = query.value(rec.indexOf("name_")).toString();
            position_ = query.value(rec.indexOf("position_")).toString();
            msg_ = query.value(rec.indexOf("msg_")).toString();

            lst.push_back(name_);
            lst.push_back(position_);
            lst.push_back(msg_);

            listOfMessages.push_back(lst);

            lst.clear();

        }
    return listOfMessages;
}

void waaiter::closeOrder(QString id, QString name)
{
    qDebug() << "150: " << id;
    QSqlQuery getChosen;
    QSqlRecord rec;

    QString time;
    QString data_;
    QString table_;
    QString order_;



    getChosen.prepare("SELECT * FROM ready_orders WHERE id = :row");
    getChosen.bindValue(":row", id);
    getChosen.exec();

    rec = getChosen.record();
    getChosen.first();

    time  = getChosen.value(rec.indexOf("time_")).toString();
    data_ = getChosen.value(rec.indexOf("data_")).toString();
    table_ = getChosen.value(rec.indexOf("table_")).toString();
    order_ = getChosen.value(rec.indexOf("order_")).toString();

    qDebug() << "time: " << time;
    qDebug() << "data: " << data_;
    qDebug() << "table: " << table_;
    qDebug() << "order: " << order_;

    qDebug()<< "178: " << id;

    QSqlQuery insertInStory;
    insertInStory.prepare("INSERT INTO orders_story(name_, time_, data_, table_, order_) VALUES (:name_, :time_, :data_, :table_, :order_)");
    insertInStory.bindValue(":name_", name);
    insertInStory.bindValue(":time_", time);
    insertInStory.bindValue(":data_", data_);
    insertInStory.bindValue(":table_", table_);
    insertInStory.bindValue(":order_", order_);
    if(!insertInStory.exec()) {qDebug() << "ERROR NAHUI";}

    int id_ = id.toInt();

    QSqlQuery deleteFromReady;
    deleteFromReady.prepare("DELETE FROM ready_orders WHERE id = :id");
    deleteFromReady.bindValue(":id", id_);
    qDebug() << id_;
    deleteFromReady.exec();
}

// waiter section


// cook section

cook::cook(QString id, QString position, QString name)
{
    this->id = id;
    this->position = position;
    this->name = name;
}

cook::cook(const cook & other)
{
    this->id = other.id;
    this->name = other.name;
    this->position = other.position;
}

void cook::setName(QString ename)
{
    this->name = ename;
}

void cook::setPosition(QString pos)
{
    this->position = pos;
}
void cook::setId(QString id)
{
    this->id = id;
}

QString cook::getName()
{
    return this->name;
}

QString cook::getPosition()
{
    return this->position;
}

QList<QList<QString>> cook::checkUnconfirmedOrders()
{
    QSqlQuery query;
    QSqlRecord rec;

    QList <QString> lst;
    QList <QList<QString>> listOfOrders;

    QString id = 0;
    QString time;
    QString table_;
    QString order_;

    query.exec("SELECT * FROM unconfirmed_orders;");
    rec = query.record();
    while (query.next()) {
            id  = query.value(rec.indexOf("id")).toString();
            time  = query.value(rec.indexOf("time")).toString();
            table_ = query.value(rec.indexOf("table_no")).toString();
            order_ = query.value(rec.indexOf("order_val")).toString();

            lst.push_back(id);
            lst.push_back(time);
            lst.push_back(table_);
            lst.push_back(order_);

            listOfOrders.push_back(lst);

            lst.clear();

        }
    return listOfOrders;
}

QList<QList<QString>> cook::checkConfirmedOrders()
{
    QSqlQuery query;
    QSqlRecord rec;

    QList <QString> lst;
    QList <QList<QString>> listOfOrders;

    QString id = 0;
    QString time;
    QString table_;
    QString order_;

    query.exec("SELECT * FROM confirmed_orders;");
    rec = query.record();
    while (query.next()) {
            id  = query.value(rec.indexOf("id")).toString();
            time  = query.value(rec.indexOf("time_")).toString();
            table_ = query.value(rec.indexOf("table_")).toString();
            order_ = query.value(rec.indexOf("order_")).toString();

            lst.push_back(id);
            lst.push_back(time);
            lst.push_back(table_);
            lst.push_back(order_);

            listOfOrders.push_back(lst);

            lst.clear();

        }
    return listOfOrders;
}

void cook::confirmOrger(QString id)
{

    qDebug() << "150: " << id;
    QSqlQuery getChosen;
    QSqlRecord rec;

    QString time;
    QString data_;
    QString table_;
    QString order_;



    getChosen.prepare("SELECT * FROM unconfirmed_orders WHERE id = :row");
    getChosen.bindValue(":row", id);
    getChosen.exec();

    rec = getChosen.record();
    getChosen.first();

    time  = getChosen.value(rec.indexOf("time")).toString();
    data_ = getChosen.value(rec.indexOf("date")).toString();
    table_ = getChosen.value(rec.indexOf("table_no")).toString();
    order_ = getChosen.value(rec.indexOf("order_val")).toString();

    qDebug() << "time: " << time;
    qDebug() << "data: " << data_;
    qDebug() << "table: " << table_;
    qDebug() << "order: " << order_;

    qDebug()<< "178: " << id;

    QSqlQuery insertInConfirmed;
    insertInConfirmed.prepare("INSERT INTO confirmed_orders(time_, data_, table_, order_) VALUES (:time_, :data_, :table_, :order_)");
    insertInConfirmed.bindValue(":time_", time);
    insertInConfirmed.bindValue(":data_", data_);
    insertInConfirmed.bindValue(":table_", table_);
    insertInConfirmed.bindValue(":order_", order_);
    if(!insertInConfirmed.exec()) {qDebug() << "ERROR NAHUI";}

    int id_ = id.toInt();

    QSqlQuery deleteFromUnconfirmed;
    deleteFromUnconfirmed.prepare("DELETE FROM unconfirmed_orders WHERE id = :id");
    deleteFromUnconfirmed.bindValue(":id", id_);
    qDebug() << id_;
    deleteFromUnconfirmed.exec();
}

void cook::cancelOrder(QString id)
{
    QInputDialog *orderInput = new QInputDialog();
    QString cancel_msg = orderInput->getText(0, "Отмена заказа", "Введите причину отмены:");

    int id_ = id.toInt();

    QSqlQuery deleteFromUnconfirmed;
    deleteFromUnconfirmed.prepare("DELETE FROM unconfirmed_orders WHERE id = :id");
    deleteFromUnconfirmed.bindValue(":id", id_);
    qDebug() << id_;
    deleteFromUnconfirmed.exec();

}

void cook::readyOrder(QString id)
{
    QSqlQuery getReady;
    QSqlRecord rec;

    QString time;
    QString data_;
    QString table_;
    QString order_;

    getReady.prepare("SELECT * FROM confirmed_orders WHERE id = :row");
    getReady.bindValue(":row", id);
    getReady.exec();

    rec = getReady.record();
    getReady.first();

    time  = getReady.value(rec.indexOf("time_")).toString();
    data_ = getReady.value(rec.indexOf("data_")).toString();
    table_ = getReady.value(rec.indexOf("table_")).toString();
    order_ = getReady.value(rec.indexOf("order_")).toString();

    qDebug() << "time: " << time;
    qDebug() << "data: " << data_;
    qDebug() << "table: " << table_;
    qDebug() << "order: " << order_;

    QSqlQuery insertInReady;
    insertInReady.prepare("INSERT INTO ready_orders(time_, data_, table_, order_) VALUES (:time_, :data_, :table_, :order_)");
    insertInReady.bindValue(":time_", time);
    insertInReady.bindValue(":data_", data_);
    insertInReady.bindValue(":table_", table_);
    insertInReady.bindValue(":order_", order_);
    if(!insertInReady.exec()) {qDebug() << "ERROR NAHUI";}

    QSqlQuery deleteFromConfirmed;
    deleteFromConfirmed.prepare("DELETE FROM confirmed_orders WHERE id = :id");
    deleteFromConfirmed.bindValue(":id", id);
    qDebug() << id;
    deleteFromConfirmed.exec();

}

QList<QList<QString>> cook::checkMessages()
{
    QSqlQuery query;
    QSqlRecord rec;

    QList <QString> lst;
    QList <QList<QString>> listOfMessages;

    QString id = 0;
    QString name_;
    QString position_;
    QString msg_;

    query.exec("SELECT * FROM chat;");
    rec = query.record();
    while (query.next()) {

            name_  = query.value(rec.indexOf("name_")).toString();
            position_ = query.value(rec.indexOf("position_")).toString();
            msg_ = query.value(rec.indexOf("msg_")).toString();

            lst.push_back(name_);
            lst.push_back(position_);
            lst.push_back(msg_);

            listOfMessages.push_back(lst);

            lst.clear();

        }
    return listOfMessages;
}

// cook section

// admin section

administrator::administrator(QString id, QString position, QString name)
{
    this->id = id;
    this->position = position;
    this->name = name;
}

administrator::administrator(const cook &other)
{
    this->id = other.id;
    this->name = other.name;
    this->position = other.position;
}

void administrator::setName(QString ename)
{
    this->name = ename;
}

void administrator::setPosition(QString pos)
{
    this->position = pos;
}

void administrator::setId(QString id)
{
    this->id = id;
}

QString administrator::getName()
{
    return this->name;
}

QString administrator::getPosition()
{
    return this->position;
}


void administrator::addnewuser(QString name, QString position, QString login, QString password)
{

    QSqlQuery query;
    query.prepare("INSERT INTO users (login, password, permissions, name) VALUES (:name, :position, :login, :password)");
    query.bindValue(":name", name);
    query.bindValue(":position", position);
    query.bindValue(":login", login);
    query.bindValue(":password", password);


}

QList<QList<QString>> administrator::checkMessages()
{
    QSqlQuery query;
    QSqlRecord rec;

    QList <QString> lst;
    QList <QList<QString>> listOfMessages;

    QString id = 0;
    QString name_;
    QString position_;
    QString msg_;

    query.exec("SELECT * FROM chat;");
    rec = query.record();
    while (query.next()) {

            name_  = query.value(rec.indexOf("name_")).toString();
            position_ = query.value(rec.indexOf("position_")).toString();
            msg_ = query.value(rec.indexOf("msg_")).toString();

            lst.push_back(name_);
            lst.push_back(position_);
            lst.push_back(msg_);

            listOfMessages.push_back(lst);

            lst.clear();

        }
    return listOfMessages;
}

void administrator::deleteEmployer(QString login)
{
    QSqlQuery delEmpl;
    delEmpl.prepare("DELETE FROM users WHERE login = :login");
    delEmpl.bindValue(":login", login);
    delEmpl.exec();

}

QList<QList<QString>> administrator::showOrdersStory()
{
    QSqlQuery query;
    QSqlRecord rec;

    QList <QString> lst;
    QList <QList<QString>> listOfMessages;

    QString id;
    QString name_;
    QString time_;
    QString data_;
    QString table_;
    QString order_;

    query.exec("SELECT * FROM orders_story;");
    rec = query.record();
    while (query.next()) {

            id  = query.value(rec.indexOf("id")).toString();
            name_  = query.value(rec.indexOf("name_")).toString();
            time_ = query.value(rec.indexOf("time_")).toString();
            data_ = query.value(rec.indexOf("data_")).toString();
            table_  = query.value(rec.indexOf("table_")).toString();
            order_  = query.value(rec.indexOf("order_")).toString();

            lst.push_back(id);
            lst.push_back(name_);
            lst.push_back(time_);
            lst.push_back(data_);
            lst.push_back(table_);
            lst.push_back(order_);

            listOfMessages.push_back(lst);

            lst.clear();

        }
    return listOfMessages;
}

QList<QList<QString>> administrator::showEmployers()
{
    QSqlQuery query;
    QSqlRecord rec;

    QList <QString> lst;
    QList <QList<QString>> listOfMessages;

    QString id;
    QString name_;
    QString pos_;
    QString login_;

    query.exec("SELECT * FROM users;");
    rec = query.record();
    while (query.next()) {

            id  = query.value(rec.indexOf("id")).toString();
            name_  = query.value(rec.indexOf("name")).toString();
            pos_ = query.value(rec.indexOf("permissions")).toString();
            login_ = query.value(rec.indexOf("login")).toString();


            lst.push_back(id);
            lst.push_back(name_);
            lst.push_back(pos_);
            lst.push_back(login_);

            listOfMessages.push_back(lst);

            lst.clear();

        }
    return listOfMessages;
}


// admin section

