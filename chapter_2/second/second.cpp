#include <QtGui/QApplication>
#include <QtGui/QPushButton>
#include <QtGui/QLabel>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  QLabel *label = new QLabel("<h2><font color='red'>Hello</font>, world.<h2>");
  label->show();

  return app.exec();
}
