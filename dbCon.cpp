#include "db_con.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <iostream>
#include <QByteArray>
#include <QDebug>


using namespace std;

Db_con::Db_con()
{
    db = QSqlDatabase::addDatabase(db_type, conn_name);
    db.database(conn_name);
    db.setHostName(h_name);
    db.setDatabaseName(db_name);
    db.setUserName(user);
}

Db_con::~Db_con()
{
    db.close();
    db.removeDatabase(conn_name);
}

void Db_con::db_list()
{
    db.open();

    QSqlQuery query("SELECT Nazwa, ulica, nr_domu, kod_pocztowy, miasto, nip FROM kontrahenci", db);
    while (query.next())
    {
        for (int i = 0; i <= 5; i++)
        {
            QString nazwa = query.value(i).toString();
            string std_nazwa = nazwa.toStdString();
            cout << std_nazwa;
            if (i != 5) cout << ", ";
            if (i == 5) cout << endl;
         }
    }

    db.close();
}

