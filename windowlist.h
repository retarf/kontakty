#ifndef WINDOWLIST_H
#define WINDOWLIST_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>

#include "dboperations.h"

class WindowList : public QWidget
{

    Q_OBJECT

public:
    explicit WindowList(DbOperations *dboper);
    ~WindowList();

private:

    QVBoxLayout *layout;
    QString *text;
    QLineEdit *row;

    DbOperations* dboperator;

};

#endif // WINDOWLIST_H
