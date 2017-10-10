#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSlider>
#include <QtWidgets/QHBoxLayout>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  QWidget *window = new QWidget();
  window->setWindowTitle("Enter your age:");

  QSpinBox *spinBox = new QSpinBox();
  QSlider *sliderBox = new QSlider(Qt::Horizontal);
  spinBox->setRange(0, 100);
  sliderBox->setRange(0, 100);

  QObject::connect(sliderBox, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
  QObject::connect(spinBox, SIGNAL(valueChanged(int)), sliderBox, SLOT(setValue(int)));

  spinBox->setValue(27);
  QHBoxLayout *layout = new QHBoxLayout();
  QVBoxLayout *layout2 = new QVBoxLayout();
  layout->addWidget(spinBox);
  layout->addWidget(sliderBox);
  layout2->addLayout(layout);
  window->setLayout(layout2);

  window->show();

  return app.exec();
}
