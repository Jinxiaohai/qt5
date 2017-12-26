#include <QtCore/QString>

#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

#include "finddialog.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  FindDialog *dialog = new FindDialog;
  dialog->show();

  return a.exec();
}
