#include <QVBoxLayout>
#include <QTabWidget>
#include <QString>
#include "tabdialog.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
QT_END_NAMESPACE

TabDialog::TabDialog(QWidget *parent)
    :QDialog(parent)
{
    tabWidget = new QTabWidget;
    tabWidget->addTab(new Lista, "Lista:");
    tabWidget->addTab(new Dodaj, "Dodaj:");

    QVBoxLayout *leyout = new QVBoxLayout;

    leyout->addWidget(tabWidget);

    setLayout(leyout);

}

Dodaj::Dodaj(QWidget *parent)
    :QWidget(parent)
{
    /*
    QLabel *imie_label = new QLabel("Imię:");
    QLineEdit *imie = new QLineEdit();
    QLabel *nazwisko_label = new QLabel("Nazwisko:");
    QLineEdit *nazwisko = new QLineEdit();
    QLabel *numer_label = new QLabel("Nr telefonu:");
    QLineEdit *numer = new QLineEdit();
    */

}

Lista::Lista(QWidget *parent)
    :QWidget(parent)
{

}
