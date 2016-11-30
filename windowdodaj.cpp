#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

#include <QDebug>
#include <QSqlError>

#include <vector>

#include "window.h"
#include "windowdodaj.h"


WindowDodaj::WindowDodaj(DbOperations* dboper)
    :QWidget()
{
    dboperator = dboper;

    // dboperator->connect->db.open();

    QVBoxLayout *layout = new QVBoxLayout;

    QLabel* imieLab = new QLabel("Imię:");
    QLabel* nazwiskoLab = new QLabel("Nazwisko:");
    QLabel* numerLab = new QLabel("Nr telefonu:");

    dodaj = new QPushButton("Dodaj", this);
    wyczysc = new QPushButton("Wyczyść", this);

    imie = new QLineEdit();
    nazwisko = new QLineEdit();
    numer = new QLineEdit();

    layout->addWidget(imieLab);
    layout->addWidget(imie);
    layout->addWidget(nazwiskoLab);
    layout->addWidget(nazwisko);
    layout->addWidget(numerLab);
    layout->addWidget(numer);
    layout->addWidget(dodaj);
    layout->addWidget(wyczysc);

    this->setLayout(layout);

    QObject::connect(dodaj, SIGNAL(clicked()), this, SLOT( get_values() ) );
    QObject::connect(wyczysc, SIGNAL(clicked()), this, SLOT( clear_form() ) );

    this->show();

    // dboperator->connect->db.close();
}

WindowDodaj::~WindowDodaj()
{
    emit destroyed();

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->close();
}

void WindowDodaj::get_values()
{
    QString *record = new QString [3];

    record[0] = this->imie->text();
    record[1] = this->nazwisko->text();
    record[2] = this->numer->text();

    dboperator->set_record(record);

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->close();
}

void WindowDodaj::clear_form()
{
    this->imie->setText("");
    this->nazwisko->setText("");
    this->numer->setText("");
}
