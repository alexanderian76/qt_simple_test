#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QToolButton>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>
#include "mainwindow.h"



int main(int argc, char *argv[ ])
{
    QApplication app(argc, argv);
   // QLabel hello;
    MainWindow w;
    w.resize(600,480);
   // w.showMaximized();
    w.show();

    return app.exec();
}
