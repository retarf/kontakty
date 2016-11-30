#ifndef DBOPERATIONS_H
#define DBOPERATIONS_H

#include <vector>

#include "connection.h"

class DbOperations
{

public:
    DbOperations();
    ~DbOperations();

    Connection* connect;

    std::vector<std::vector<QString> > get_list();
    void set_record(QString *record);       //add to database from WindowDodaj object

    int listSize;
    // QString** list;


};

#endif // DBOPERATIONS_H
