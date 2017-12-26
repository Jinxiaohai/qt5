#include <QtCore/QString>

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
  tableWidget->setColumnCount(4);
  tableWidget->setHorizontalHeaderLabels(labels);

  messageLabel = new QLabel(tr("0 files found"), this);
  messageLabel->setFrameShape(QLabel::Panel);
  messageLabel->setFrameShadow(QLabel::Sunken);

  findButton = new QPushButton(tr("&Find"), this);
  stopButton = new QPushButton(tr("Stop"), this);
  closeButton = new QPushButton(tr("Close"), this);
  helpButton = new QPushButton(tr("Hlelp"), this);

  connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

  setWindowTitle(tr("Find Files or Folders"));
  setMinimumSize(265, 190);
  resize(365, 240);
}

void FindFileDialog::resizeEvent(QResizeEvent *)
{
  int extraWidth = width() - minimumWidth();
  int extraHeight = height() - minimumHeight();

  nameLabel->setGeometry(9, 9, 50, 25);
  nameLineEdit->setGeometry(65, 9, 100+extraWidth, 25);
  lookInLabel->setGeometry(9, 40, 50, 25);
  lookInLineEdit->setGeometry(65, 40, 100+extraWidth, 25);
  subfolderCheckBox->setGeometry(9, 100, 156+extraWidth, 50+extraHeight);
  tableWidget->setGeometry(9, 100, 156+extraWidth, 50+extraHeight);
  messageLabel->setGeometry(9, 156+extraHeight, 156+extraWidth, 25);
  findButton->setGeometry(171+extraWidth, 9, 85, 32);
  stopButton->setGeometry(171+extraWidth, 47, 85, 32);
  closeButton->setGeometry(171+extraWidth, 84, 85, 32);
  helpButton->setGeometry(171+extraWidth, 149+extraHeight, 85, 32);
}
