#include <QtWidgets/QAction>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtGui/QKeySequence>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QStatusBar>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  openAction = new QAction(tr("&Open"), this);
  openAction->setShortcuts(QKeySequence::Open);
  openAction->setStatusTip(tr("Open a file."));
  openAction->setIcon(QIcon("/home/xiaohai/Pictures/wangcai.jpg"));
  connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

  QMenu *file = menuBar()->addMenu(tr("&File"));
  file->addAction(openAction);

  QToolBar *toolBar = addToolBar(tr("&File"));
  toolBar->addAction(openAction);

  msgLabel = new QLabel;
  msgLabel->setMinimumSize(msgLabel->sizeHint());
  msgLabel->setAlignment(Qt::AlignHCenter);
  statusBar()->addWidget(msgLabel);
  statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}"));
}

void MainWindow::open()
{
  QMessageBox::information(NULL, tr("Open"), tr("Open a file"));
}

MainWindow::~MainWindow()
{

}
