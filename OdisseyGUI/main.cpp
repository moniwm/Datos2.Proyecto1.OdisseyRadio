/**
  *
  * @author Monica Waterhouse Montoya
  * @since October 9th, 2020
  *
  */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return QApplication::exec();
}
