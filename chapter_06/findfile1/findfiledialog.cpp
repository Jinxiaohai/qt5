#include <QtCore/QString>
#include <QtCore/QStringList>

#include <QtPrintSupport/QPageSetupDialog>
#include <QtPrintSupport/QPrintDialog>

#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QColorDialog>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QErrorMessage>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QFontDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QListView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QProgressDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

#include "findfiledialog.h"

FindFileDialog::FindFileDialog(QWidget *parent)
: QDialog(parent)
{
  nameLabel = new QLabel(tr("&Name:"), this);
  nameLineEdit = new QLineEdit(this);
  nameLabel->setBuddy(nameLineEdit);

  lookInLabel = new QLabel(tr("&Look in:"), this);
  lookInLineEdit = new QLineEdit(this);
  lookInLabel->setBuddy(lookInLineEdit);

  subfolderCheckBox = new QCheckBox(tr("Include subfolders"), this);

  QStringList labels;
  labels << tr("Name") << tr("In Folder") << tr("Size") << tr("Modified");

  tableWidget = new QTableWidget(this);
  /// 设置列的个数
  tableWidget->setColumnCount(4);
  tableWidget->setHorizontalHeaderLabels(labels);

  messageLabel = new QLabel(tr("0 files found"), this);
  messageLabel->setFrameShape(QLabel::Panel);
  messageLabel->setFrameShadow(QLabel::Sunken);

  findButton = new QPushButton(tr("&Find"), this);
  stopButton = new QPushButton(tr("Stop"), this);
  closeButton = new QPushButton(tr("Close"), this);
  helpButton = new QPushButton(tr("Help"), this);

  connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

  nameLabel->setGeometry(9, 9, 50, 25);
  nameLineEdit->setGeometry(65, 9, 200, 25);
  lookInLabel->setGeometry(9, 40, 50, 25);
  lookInLineEdit->setGeometry(65, 40, 200, 25);
  subfolderCheckBox->setGeometry(9, 71, 256, 23);
  tableWidget->setGeometry(9, 100, 256, 100);
  messageLabel->setGeometry(9, 206, 256, 25);
  findButton->setGeometry(271, 9, 85, 32);
  stopButton->setGeometry(271, 47, 85, 32);
  closeButton->setGeometry(271, 84, 85, 32);
  helpButton->setGeometry(271, 199, 85, 32);

  setWindowTitle(tr("Find Files or Folders"));
  setFixedSize(365, 240);
}
