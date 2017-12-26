#include "preferencedialog.h"

PreferenceDialog::PreferenceDialog(QWidget *parent)
  :QDialog(parent)
{
  createAppearancePage();
  createWebBrowserPage();
  createMainAndNewsPage();
  createAdvancedPage();

  buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

  listWidget = new QListWidget;
  listWidget->addItem(tr("Appearance"));
  listWidget->addItem(tr("Web Browser"));
  listWidget->addItem(tr("Mail & News"));
  listWidget->addItem(tr("Advanced"));

  stackedLayout = new QStackedLayout;
  /// appearancePage对象的类型为QWidget,下同.
  stackedLayout->addWidget(appearancePage);
  stackedLayout->addWidget(webBrowserPage);
  stackedLayout->addWidget(mailAndNewsPage);
  stackedLayout->addWidget(advancedPage);
  /// 将左右两页进行链接,注意链接的信号和槽.
  connect(listWidget, SIGNAL(currentRowChanged(int)), stackedLayout, SLOT(setCurrentIndex(int)));

  QGridLayout *mainLayout = new QGridLayout;
  mainLayout->setColumnStretch(0, 1);
  mainLayout->setColumnStretch(1, 3);

  /// 添加左上
  mainLayout->addWidget(listWidget, 0, 0);
  /// 添加右上
  mainLayout->addLayout(stackedLayout, 0, 1);
  /// 添加下面的取消和OK键
  mainLayout->addWidget(buttonBox, 1, 0, 1, 2);
  /// 总体的布局
  setLayout(mainLayout);


  connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
  connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

  setWindowTitle(tr("Jin Xiaohai"));
  listWidget->setCurrentRow(0);
}

void PreferenceDialog::createAppearancePage()
{
  /// 创建appearance页面
  appearancePage = new QWidget;

  /// QGroupBox创建一个有标题的组合框
  openGroupBox = new QGroupBox(tr("Open at startup"));
  webBrowserCheckBox = new QCheckBox(tr("Web browser"));
  mailEditorCheckBox = new QCheckBox(tr("Mail editor"));
  newsgroupCheckBox = new QCheckBox(tr("Newsgroups"));

  /// 再创建一个组合框
  toolbarsGroupBox = new QGroupBox(tr("Show toolbars as"));
  picturesAndTextRadioButton = new QRadioButton(tr("Pictures and text"));
  picturesOnlyRadioButton = new QRadioButton(tr("Pictures only"));
  textOnlyRadioButton = new QRadioButton(tr("Text only"));

  tooltipsCheckBox = new QCheckBox(tr("Show tooltips"));
  webSiteIconsCheckBox = new QCheckBox(tr("Show web site icons"));
  resizeImagesCheckBox = new QCheckBox(tr("Resize large images to fit in the window"));

  /// 第一个组合框
  QVBoxLayout *openLayout = new QVBoxLayout;
  /// 将三个ChechBox添加到垂直布局中
  openLayout->addWidget(webBrowserCheckBox);
  openLayout->addWidget(mailEditorCheckBox);
  openLayout->addWidget(newsgroupCheckBox);
  /// 将垂直布局添加到组合框中
  openGroupBox->setLayout(openLayout);

  /// 第二个组合框
  QVBoxLayout *toolbarsLayout = new QVBoxLayout;
  toolbarsLayout->addWidget(picturesAndTextRadioButton);
  toolbarsLayout->addWidget(picturesOnlyRadioButton);
  toolbarsLayout->addWidget(textOnlyRadioButton);
  toolbarsGroupBox->setLayout(toolbarsLayout);

  /// 总的布局
  QVBoxLayout *pageLayout = new QVBoxLayout;
  pageLayout->setMargin(0);
  pageLayout->addWidget(openGroupBox);
  pageLayout->addWidget(toolbarsGroupBox);
  pageLayout->addWidget(tooltipsCheckBox);
  pageLayout->addWidget(webSiteIconsCheckBox);
  pageLayout->addWidget(resizeImagesCheckBox);
  pageLayout->addStretch();
  appearancePage->setLayout(pageLayout);

  webBrowserCheckBox->setChecked(true);
  mailEditorCheckBox->setChecked(true);
  picturesAndTextRadioButton->setChecked(true);
  tooltipsCheckBox->setChecked(true);
  webSiteIconsCheckBox->setChecked(true);
}

void PreferenceDialog::createWebBrowserPage()
{
  webBrowserPage = new QWidget;

  displayGroupBox = new QGroupBox(tr("Display on startup"));
  blankRadioButton = new QRadioButton(tr("Blank page"));
  homeRadioButton = new QRadioButton(tr("Blank page"));
  lastRadioButton = new QRadioButton(tr("Last page visited"));

  homeGroupBox = new QGroupBox(tr("Home Page"));
  locationLabel = new QLabel(tr("Location:"));
  locationLineEdit = new QLineEdit;

  webButtonsGroupBox = new QGroupBox(tr("Select the buttons you want in the toolbar"));
  bookmarksCheckBox = new QCheckBox(tr("Bookmarks"));
  goCheckBox = new QCheckBox(tr("Go"));
  homeCheckBox = new QCheckBox(tr("Home"));
  searchCheckBox = new QCheckBox(tr("Search"));
  printCheckBox = new QCheckBox(tr("Print"));

  /// 最上面的布局
  QVBoxLayout *displayLayout = new QVBoxLayout;
  displayLayout->addWidget(blankRadioButton);
  displayLayout->addWidget(homeRadioButton);
  displayLayout->addWidget(lastRadioButton);
  displayGroupBox->setLayout(displayLayout);

  /// 中间的布局
  QHBoxLayout *homeLayout = new QHBoxLayout;
  homeLayout->addWidget(locationLabel);
  homeLayout->addWidget(locationLineEdit);
  homeGroupBox->setLayout(homeLayout);

  /// 下面的布局
  QGridLayout *webButtonsLayout = new QGridLayout;
  webButtonsLayout->addWidget(bookmarksCheckBox, 0, 0);
  webButtonsLayout->addWidget(goCheckBox, 1, 0);
  webButtonsLayout->addWidget(homeCheckBox, 2, 0);
  webButtonsLayout->addWidget(searchCheckBox, 0, 1);
  webButtonsLayout->addWidget(printCheckBox, 1, 1);
  webButtonsGroupBox->setLayout(webButtonsLayout);

  QVBoxLayout *pageLayout = new QVBoxLayout;
  pageLayout->setMargin(0);
  pageLayout->addWidget(displayGroupBox);
  pageLayout->addWidget(homeGroupBox);
  pageLayout->addWidget(webButtonsGroupBox);
  pageLayout->addStretch();
  webBrowserPage->setLayout(pageLayout);

  homeRadioButton->setChecked(true);
  locationLineEdit->setText("http://www.jinxiaohai.cn");
  bookmarksCheckBox->setChecked(true);
  homeCheckBox->setChecked(true);
  searchCheckBox->setChecked(true);
  printCheckBox->setChecked(true);
}

void PreferenceDialog::createMainAndNewsPage()
{
  mailAndNewsPage = new QWidget;

  generalGroupBox = new QGroupBox(tr("General settings"));
  confirmCheckBox = new QCheckBox(tr("Warn when moving folders to the Trash"));
  rememberCheckBox = new QCheckBox(tr("Remember the last selected message"));

  mailButtonsGroupBox = new QGroupBox(tr("Select the buttons you want in the toolbar"));
  fileCheckBox = new QCheckBox(tr("File"));
  nextCheckBox = new QCheckBox(tr("Next"));
  stopCheckBox = new QCheckBox(tr("Stop"));
  junkCheckBox = new QCheckBox(tr("Junk"));

  QVBoxLayout *generalLayout = new QVBoxLayout;
  generalLayout->addWidget(confirmCheckBox);
  generalLayout->addWidget(rememberCheckBox);
  generalGroupBox->setLayout(generalLayout);

  QGridLayout *mailButtonsLayout = new QGridLayout;
  mailButtonsLayout->addWidget(fileCheckBox, 0, 0);
  mailButtonsLayout->addWidget(nextCheckBox, 1, 0);
  mailButtonsLayout->addWidget(stopCheckBox, 0, 1);
  mailButtonsLayout->addWidget(junkCheckBox, 1, 1);
  mailButtonsGroupBox->setLayout(mailButtonsLayout);

  QVBoxLayout *pageLayout = new QVBoxLayout;
  pageLayout->setMargin(0);
  pageLayout->addWidget(generalGroupBox);
  pageLayout->addWidget(mailButtonsGroupBox);
  pageLayout->addStretch();
  mailAndNewsPage->setLayout(pageLayout);

  confirmCheckBox->setChecked(true);
  rememberCheckBox->setChecked(true);
  nextCheckBox->setChecked(true);
  junkCheckBox->setChecked(true);
}

void PreferenceDialog::createAdvancedPage()
{
  advancedPage = new QWidget;

  featuresGroupBox = new QGroupBox(tr("Features that help interpret web pages"));
  javaCheckBox = new QCheckBox(tr("Enable java"));
  ftpCheckBox = new QCheckBox(tr("Use this email address for anonymous FTP:"));
  ftpLineEdit = new QLineEdit;

  connect(ftpCheckBox, SIGNAL(toggled(bool)), ftpLineEdit, SLOT(setEnabled(bool)));

  QGridLayout *featuresLayout = new QGridLayout;
  featuresLayout->addWidget(javaCheckBox, 0, 0, 1, 2);
  featuresLayout->addWidget(ftpCheckBox, 1, 0, 1, 2);
  featuresLayout->addWidget(ftpLineEdit, 2, 1);
  featuresGroupBox->setLayout(featuresLayout);

  QVBoxLayout *pageLayout = new QVBoxLayout;
  pageLayout->setMargin(0);
  pageLayout->addWidget(featuresGroupBox);
  pageLayout->addStretch();
  advancedPage->setLayout(pageLayout);

  javaCheckBox->setChecked(true);
  ftpLineEdit->setEnabled(false);
}
