#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer =new QTimer;
    picId = 2;

    QImage img;
    img.load("C:\\Users\\dalee\\Pictures\\Saved Pictures\\1.jpg");
    ui->label->setPixmap(QPixmap::fromImage(img));

    connect(timer, &QTimer::timeout, this, &Widget::timeoutSlot);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{
    timer->start(TIMEOUT);
}

void Widget::timeoutSlot()
{
    QString path("C:\\Users\\dalee\\Pictures\\Saved Pictures\\");
    path += QString::number(picId);
    path += ".jpg";

    QImage img;
    img.load(path);
    ui->label->setPixmap(QPixmap::fromImage(img));

    picId++;

    if(15 == picId)
    {
        picId = 1;
    }
}

void Widget::on_stopButton_clicked()
{
    timer->stop();
}


void Widget::on_singleButton_clicked()
{
    QTimer::singleShot(1000, this, SLOT(timeoutSlot()));
}

