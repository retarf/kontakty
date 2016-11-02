#include <QVBoxLayout>
#include <QTabWidget>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QButtonGroup>
#include <QPushButton>
#include <QGroupBox>
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
    setWindowTitle("Kontakty");

}

void Dodaj::createButtons()
{
    hGroupBox = new QGroupBox;

    QHBoxLayout *buttons = new QHBoxLayout;

    QPushButton *dodaj = new QPushButton("Dodaj");
    QPushButton *wyczysc = new QPushButton("Wyczyść");

    buttons->addWidget(dodaj);
    buttons->addWidget(wyczysc);

    hGroupBox->setLayout(buttons);

}

Dodaj::Dodaj(QWidget *parent)
    :QWidget(parent)
{

    QLabel *imieLab = new QLabel("Imię:");
    QLineEdit *imie = new QLineEdit();
    QLabel *nazwiskoLab = new QLabel("Nazwisko:");
    QLineEdit *nazwisko = new QLineEdit();
    QLabel *numerLab = new QLabel("Nr telefonu:");
    QLineEdit *numer = new QLineEdit();

    // QButtonGroup *buttons = new QButtonGroup;

    Dodaj::createButtons();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(imieLab);
    layout->addWidget(imie);
    layout->addWidget(nazwiskoLab);
    layout->addWidget(nazwisko);
    layout->addWidget(numerLab);
    layout->addWidget(numer);

    layout->addWidget(hGroupBox);

    setLayout(layout);


}

Lista::Lista(QWidget *parent)
    :QWidget(parent)
{

}
