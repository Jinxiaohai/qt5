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
  nameLabel = new QLabel(tr("Name:"));
  nameLineEdit = new QLineEdit(tr("Jin Xiaohai"));
  nameLabel->setBuddy(nameLineEdit);

  lookInLabel = new QLabel(tr("Look in:"));
  lookInLineEdit = new QLineEdit;
  lookInLabel->setBuddy(lookInLineEdit);

  subfolderCheckBox = new QCheckBox(tr("Include subfolers"));

  QStringList labels;
  labels << tr("Name") << tr("In Folder") << tr("Size") << tr("Modified");

  tableWidget = new QTableWidget;
  tableWidget->setColumnCount(4);
  tableWidget->setHorizontalHeaderLabels(labels);

  messageLabel = new QLabel(tr("0 files found"));
  messageLabel->setFrameShape(QLabel::Panel);
  messageLabel->setFrameShadow(QLabel::Sunken);

  findButton = new QPushButton(tr("Find"));
  stopButton = new QPushButton(tr("Stop"));
  closeButton = new QPushButton(tr("Close"));
  helpButton = new QPushButton(tr("Help"));

  connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

  QGridLayout *leftLayout = new QGridLayout;
  leftLayout->addWidget(nameLabel, 0, 0, Qt::AlignLeft);
  leftLayout->addWidget(nameLineEdit, 0, 1);
  leftLayout->addWidget(lookInLabel, 1, 0);
  leftLayout->addWidget(lookInLineEdit, 1, 1);
  leftLayout->addWidget(subfolderCheckBox, 2, 0, 1, 2);
  leftLayout->addWidget(tableWidget, 3, 0, 1, 2);
  leftLayout->addWidget(messageLabel, 4, 0, 1, 2);

  QVBoxLayout *rightLayout = new QVBoxLayout;
  rightLayout->addWidget(findButton, 0);
  rightLayout->addWidget(stopButton, 0);
  rightLayout->addWidget(closeButton, 0);
  rightLayout->addStretch();
  rightLayout->addWidget(helpButton, 0);

  QHBoxLayout *mainLayout = new QHBoxLayout;
  mainLayout->addLayout(leftLayout, 0);
  mainLayout->addLayout(rightLayout, 0);
  setLayout(mainLayout);

  setWindowTitle(tr("Find Files or Folders"));
}
