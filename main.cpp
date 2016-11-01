#include <QtCore>
#include <QtGui>
#include <QApplication>
#include "tabdialog.h"

int main(int argc, char *argv)
{
    QApplication app(argc, &argv);

    TabDialog dialog;
    dialog.show();

    return app.exec();
}
