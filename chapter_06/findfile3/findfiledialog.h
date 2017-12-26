#ifndef FINDFILEDIALOG_H
#define FINDFILEDIALOG_H

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


class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTableWidget;

class FindFileDialog : public QDialog
{
  Q_OBJECT

public:
  FindFileDialog(QWidget *parent = 0);

private:
  QLabel *nameLabel;
  QLineEdit *nameLineEdit;
  QLabel *lookInLabel;
  QLineEdit *lookInLineEdit;
  QCheckBox *subfolderCheckBox;
  QTableWidget *tableWidget;
  QLabel *messageLabel;
  QPushButton *findButton;
  QPushButton *stopButton;
  QPushButton *closeButton;
  QPushButton *helpButton;
};

#endif // FINDFILEDIALOG
