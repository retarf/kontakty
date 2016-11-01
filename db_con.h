#ifndef DB_CON_H
#define DB_CON_H
#include <QSqlDatabase>
#include <iostream>
#include "/home/retarf/kontakty/tajne/tajne.h"


class Db_con
{
private:
    QSqlDatabase db;

    Secret x; // This class contains my privet data to database connect and it should be remove or data in tajne.h shut be replaced

    QString conn_name = x.conn_name;      // Conection name
    QString db_type = x.db_type;            // DataBase Type
    QString h_name = x.h_name;       // hostname
    QString user = x.user;        // username
    QString db_name = db_name;     // DB name


public:
    Db_con();
    ~Db_con();
    void db_list();
};

#endif // DB_CON_H
