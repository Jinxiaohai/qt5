#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include <QtWidgets/QDialogButtonBox>
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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QProgressDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedLayout>
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
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QListWidget;
class QRadioButton;
class QStackedLayout;

class PreferenceDialog : public QDialog
{
  Q_OBJECT

public:
  PreferenceDialog(QWidget *parent = 0);

private:
  void createAppearancePage();
  void createWebBrowserPage();
  void createMainAndNewsPage();
  void createAdvancedPage();

  QStackedLayout *stackedLayout;
  QListWidget *listWidget;
  QWidget *appearancePage;
  QWidget *webBrowserPage;
  QWidget *mailAndNewsPage;
  QWidget *advancedPage;
  QDialogButtonBox *buttonBox;

  QGroupBox *openGroupBox;
  QCheckBox *webBrowserCheckBox;
  QCheckBox *mailEditorCheckBox;
  QCheckBox *newsgroupCheckBox;
  QGroupBox *toolbarsGroupBox;
  QRadioButton *picturesAndTextRadioButton;
  QRadioButton *picturesOnlyRadioButton;
  QRadioButton *textOnlyRadioButton;
  QCheckBox *tooltipsCheckBox;
  QCheckBox *webSiteIconsCheckBox;
  QCheckBox *resizeImagesCheckBox;

  QGroupBox *displayGroupBox;
  QRadioButton *blankRadioButton;
  QRadioButton *homeRadioButton;
  QRadioButton *lastRadioButton;
  QGroupBox *homeGroupBox;
  QLabel *locationLabel;
  QLineEdit *locationLineEdit;
  QGroupBox *webButtonsGroupBox;
  QCheckBox *bookmarksCheckBox;
  QCheckBox *goCheckBox;
  QCheckBox *homeCheckBox;
  QCheckBox *searchCheckBox;
  QCheckBox *printCheckBox;

  QGroupBox *generalGroupBox;
  QCheckBox *confirmCheckBox;
  QCheckBox *rememberCheckBox;
  QGroupBox *mailButtonsGroupBox;
  QCheckBox *fileCheckBox;
  QCheckBox *nextCheckBox;
  QCheckBox *stopCheckBox;
  QCheckBox *junkCheckBox;

  QGroupBox *featuresGroupBox;
  QCheckBox *javaCheckBox;
  QCheckBox *ftpCheckBox;
  QLineEdit *ftpLineEdit;
};

#endif // MAINWINDOW_H
