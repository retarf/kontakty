#include <QVBoxLayout>
#include <QWidget>
#include <QLineEdit>

#include <iostream>
#include <vector>

#include "dboperations.h"
#include "connection.h"
#include "windowlist.h"

#include <QDebug>

WindowList::WindowList(DbOperations* dboper)
    :QWidget()
{

    dboperator = dboper;

    std::vector <std::vector <QString>> list;


    // DbOperations* dboperator = new DbOperations;

    // dboperator->connect->db.open();

    qDebug() << "Wykonane db.open()";

    list = dboperator->get_list();

    qDebug() << "Wykonane get_list()";

    // list = dboperator->list;

    qDebug() << list.size();


    layout = new QVBoxLayout;
    text = new QString;


    if ((list.size()) > 0) {

        row = new QLineEdit [list.size()];

        for(int i = 0; i < list.size(); i++)
        {
            *text = "";

            for (int j = 0; j <= 2; j++) {
                (*text) += list[i][j];

                if (j < 2) {
                    (*text) += " ";
                }
            }

            row->setText((*text));
            row->setReadOnly(true);
            layout->addWidget(row);

            row++;
        }
    }
    else {
        QLineEdit *row = new QLineEdit [1];
        row->setText("Baza danych jest pusta!");
        row->setReadOnly(true);
        layout->addWidget(row);
    }

    this->setLayout(layout);

    // dboperator->connect->db.close();


    // delete dboperator;

    std::cout << "Wykonane WindowList" << std::endl;
}

WindowList::~WindowList()
{
    delete row;

    delete layout;
    delete text;

}
