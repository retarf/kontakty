#include <QWidget>
#include <QObject>
#include <QDialog>
#include <QVBoxLayout>

#include <QDebug>
#include <QSqlError>

#include <iostream>

#include "dboperations.h"
#include "window.h"


Window::Window(QWidget *parent)
    :QWidget(parent)
{
    dboperator = new DbOperations;

    layout = new QVBoxLayout;

    new_window();
}

void Window::dodaj_function()
{
    WindowDodaj* w_dodaj = new WindowDodaj(dboperator);

    QObject::connect(w_dodaj, SIGNAL( destroyed() ), this, SLOT( list_refresh()));
}



Window::~Window()
{

    delete list;
    delete dodaj;
    delete wyjdz;
    delete layout;
}

void Window::new_window()
{
    list = new WindowList(dboperator);

    // list = new WindowList();
    dodaj = new QPushButton("Dodaj", this);
    wyjdz = new QPushButton("Wyjdź", this);

    layout->addWidget(list);
    layout->addWidget(dodaj);
    layout->addWidget(wyjdz);

    QObject::connect(dodaj, SIGNAL( clicked() ), this, SLOT( dodaj_function() ) );
    QObject::connect(wyjdz, SIGNAL( clicked() ), this, SLOT( close() ) );

    setLayout(layout);
    this->setWindowTitle("Kontakty");

    this->show();
}

void Window::list_refresh()
{

    layout->removeWidget(list);
    layout->removeWidget(dodaj);
    layout->removeWidget(wyjdz);

    list->hide();

    list->setAttribute(Qt::WA_QuitOnClose);

    list->close();

    list = new WindowList(dboperator);

    layout->addWidget(list);
    layout->addWidget(dodaj);
    layout->addWidget(wyjdz);

    this->show();

}
