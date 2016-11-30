#ifndef WINDOW_H
#define WINDOW_H

#include <QObject>
#include <QDialog>
#include <QTabWidget>
#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

#include "dboperations.h"
#include "windowdodaj.h"
#include "windowlist.h"

class Window :public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget* parent = 0);
    ~Window();

    WindowList *list;
    QPushButton *dodaj;
    QPushButton* wyjdz;

    QVBoxLayout *layout;

    DbOperations* dboperator;

    //void new_window();

public slots:
    void dodaj_function();
    void new_window();
    void list_refresh();

};

#endif // WINDOW_H
