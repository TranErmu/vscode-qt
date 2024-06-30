#include <QApplication>
#include <QHBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QMovie>
#include <QPixmap>
#include <QSlider>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <qfont.h>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QWidget      window;
    QVBoxLayout  layout(&window);
    QHBoxLayout  inner_layout;
    QLabel       label_text("this is a demo");
    QLabel       label_image;
    QFont        ft;

    ft.setPointSize(14);
    label_text.setFont(ft);
    inner_layout.addStretch();
    inner_layout.addWidget(&label_text);
    inner_layout.addStretch();
    label_image.setPixmap(QPixmap(":/Image/demo"));
    layout.addLayout(&inner_layout);
    layout.addWidget(&label_image);
    window.show();
    return app.exec();
}
