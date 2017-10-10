#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QAction>
#include <QtWidgets/QLabel>

class QAction;

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();

 private slots:
  void open();

private:
  QAction *openAction;
  QLabel *msgLabel;
};


#endif /* MAINWINDOW_H */
