#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
   // w.show();
    QPushButton *button = new QPushButton("QUIT");
    QObject::connect(button, SIGNAL(clicked()), &a, SLOT(quit()));
    button->show();
    return a.exec();
}
