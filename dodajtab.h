#ifndef DODAJTAB_H
#define DODAJTAB_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>

class DodajTab
{
private:
    QLabel *imie_label = new QLabel("Imię:");
    QLineEdit *imie = new QLineEdit();
    QLabel *nazwisko_label = new QLabel("Nazwisko:");
    QLineEdit *nazwisko = new QLineEdit();
    QLabel *numer_label = new QLabel("Nr telefonu:");
    QLineEdit *numer = new QLineEdit();
public:
    DodajTab();
};

#endif // DODAJTAB_H
