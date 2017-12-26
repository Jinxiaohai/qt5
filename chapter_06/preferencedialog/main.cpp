#include "preferencedialog.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  PreferenceDialog dialog;
  dialog.show();

  return a.exec();
}
