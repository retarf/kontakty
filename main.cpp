#include <QtCore>
#include <QtGui>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QApplication>
#include <QTabWidget>
#include "db_con.h"




int main (int argc, char **argv)
{
    QApplication app(argc, argv);





    QTabWidget *tab = new QTabWidget;
    tab->addTab(QLabel("Lista"));
    tab->addTab( QLabel("Dodaj"));

    QFormLayout *layout = new QFormLayout;

    layout->addWidget(tab);
    layout->addRow(imie_label, imie);
    layout->addRow(nazwisko_label, nazwisko);
    layout->addRow(numer_label, numer);

    window->setLayout(layout);
    window->show();

    Db_con x;
    x.db_list();

    return app.exec();
}
