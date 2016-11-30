#include <QSqlDatabase>
#include <QSqlDatabase>
#include "connection.h"

#include <iostream>

Connection::Connection()
{
    db = QSqlDatabase::addDatabase(db_type, conn_name);
    db.database(conn_name);
    db.setHostName(h_name);
    db.setDatabaseName(db_name);
    db.setUserName(user);

    std::cout << "Wykonane Connection" << std::endl;
}



