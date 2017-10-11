#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QLabel *label = new QLabel(QObject::tr("<font color=red>金小海的第一个Qt程序.</font>"));
  label->show();

  return a.exec();
}
