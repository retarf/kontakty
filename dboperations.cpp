#include <QSql>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QString>
#include <QVariant>
#include <list>
#include <vector>

#include <QDebug>

#include "dboperations.h"

#include <iostream>

DbOperations::DbOperations()
{
    connect = new Connection;
    // connect->db.open();

    get_list();
}

DbOperations::~DbOperations()
{
    // connect->db.close();
    delete connect;
}


std::vector<std::vector<QString> > DbOperations::get_list()
{
    std::vector <std::vector <QString>> rowlist;

    if(connect->db.open())
    {
        QSqlQuery query("SELECT imie, nazwisko, numer FROM dane order by nazwisko", connect->db);

        int size = query.size();
        rowlist.resize(size);

        if (true)
        {
            int j = 0;

            while (query.next()) {
                rowlist[j].resize(3);
                for (int i = 0; i <= 2; i++) {
                    rowlist[j][i] = query.value(i).toString();
                }
                j++;
            }
        }
        else {

        }

        qDebug() << "Połączenie nawiązane: " << connect->db.open();



        return rowlist;

        qDebug() << "DbOperations::get_list() db opened";

        connect->db.close();

    }
    else
    {
        qDebug() << "DbOperations::get_list() db not opened";

        rowlist.resize(1);

        rowlist[0].resize(1);

        rowlist[0][0] = "0";

        return rowlist;

    }

    std::cout << "Wykonane get_list" << std::endl;
}

void DbOperations::set_record(QString *record)
{

    if(connect->db.open())
    {
        QSqlQuery query(connect->db);

        query.prepare("INSERT INTO dane (imie, nazwisko, numer)"
                      "VALUES (:imie, :nazwisko, :numer)");

        query.bindValue(":imie", record[0]);
        query.bindValue(":nazwisko", record[1]);
        query.bindValue(":numer", record[2]);

        query.exec();

        std::cout << "1: " << record[0].toStdString() << std::endl;
        std::cout << "2: " << record[1].toStdString() << std::endl;
        std::cout << "3: " << record[2].toStdString() << std::endl;

        qDebug() << "set_rechord: Połączenie nawiązane: " << connect->db.open();

        connect->db.close();
    }
    else
    {
        qDebug() << "DbOperations::set_record() db is not opened";
    }

}
