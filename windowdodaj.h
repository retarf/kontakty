#ifndef WINDOWDODAJ_H
#define WINDOWDODAJ_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMenu>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>

#include "dboperations.h"
#include "window.h"


class WindowDodaj :public QWidget
{
    Q_OBJECT

public:
    explicit WindowDodaj(DbOperations* dboper);
    ~WindowDodaj();

public slots:
    void get_values();
    void clear_form();

public:

    QVBoxLayout *layout;

    QLabel* imieLab;
    QLabel* nazwiskoLab;
    QLabel* numerLab;

    QLineEdit* imie;
    QLineEdit* nazwisko;
    QLineEdit* numer;

    QPushButton* dodaj;         // zmienic na dodaj_button
    QPushButton* wyczysc;       // zmienic na wyczysc_button

    DbOperations* dboperator;

};

#endif // WINDOWDODAJ_H
