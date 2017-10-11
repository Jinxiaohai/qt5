#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>


int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QPushButton *button = new QPushButton(QObject::tr("退出"));
  QObject::connect(button, SIGNAL(clicked()), &a, SLOT(quit()));
  button->show();

  return a.exec();
}
