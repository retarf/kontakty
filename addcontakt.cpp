#include "addcontakt.h"
#include <QLabel>
#include <QLineEdit>

AddContakt::AddContakt()
{
    QLabel *imie_label = new QLabel("Imię:");
    QLineEdit *imie = new QLineEdit();
    QLabel *nazwisko_label = new QLabel("Nazwisko:");
    QLineEdit *nazwisko = new QLineEdit();
    QLabel *numer_label = new QLabel("Nr telefonu:");
    QLineEdit *numer = new QLineEdit();

}
