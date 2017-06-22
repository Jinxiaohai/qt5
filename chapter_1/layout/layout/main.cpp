#include <QCoreApplication>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *window = new QWidget;
    window->setWindowTitle("Enter your age");

    QSpinBox *spinBox = new QSpinBox;
    QSlider *slide = new QSlider(Qt::Horizontal);
    spinBox->setRange(0, 130);
    slide->setRange(0, 130);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)), slide, SLOT(setValue(int)));
    QObject::connect(slide, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    spinBox->setValue(35);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slide);
    window->setLayout(layout);
    window->show();

    return a.exec();
}
