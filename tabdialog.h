#ifndef TABDIALOG_H
#define TABDIALOG_H

#include <QObject>
#include <QDialog>

QT_BEGIN_NAMESPACE
class QTabWidget;
class QWidget;
class QGroupBox;

QT_END_NAMESPACE

class Lista : public QWidget
{
    Q_OBJECT

public:
    explicit Lista(QWidget *parent = 0);
};

class Dodaj : public QWidget
{
    Q_OBJECT

public:
    explicit Dodaj(QWidget *parent = 0);

private:
    QGroupBox *hGroupBox;

    void createButtons();
};



class TabDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TabDialog(QWidget *parent = 0);

private:
    QTabWidget *tabWidget;

};

#endif // TABDIALOG_H
