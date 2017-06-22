#include "mainwindow.h"
#include <QApplication>
#include <QTextEdit>
#include <QSplashScreen>
#include <QtTest/QtTest>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("./figure/test.png"));
    splash->show();
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash->showMessage(QObject::tr("qidong...."), topRight, Qt::red);
    QTest::qSleep(3000);
    QTextEdit *textEdit = new QTextEdit;
    splash->showMessage(QObject::tr("test...."), topRight, Qt::blue);
    QTest::qSleep(3000);
    textEdit->show();
    splash->finish(textEdit);
    delete splash;

    return a.exec();
}
