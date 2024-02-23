#include "widget.h"
#include "ui_widget.h"

#define TIMEOUT 1 * 1000

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    picId = 2;

    QPixmap pix("C:\\Users\\dalee\\Pictures\\Saved Pictures\\1.jpg");
    ui->label->setPixmap(pix);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{
    //开启定时器，返回定时器编号
    myTimerId = this->startTimer(TIMEOUT);
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() != myTimerId)
        return;

    QString path("C:\\Users\\dalee\\Pictures\\Saved Pictures\\");
    path += QString::number(picId);
    path += ".jpg";

    QPixmap pix(path);
    ui->label->setPixmap(pix);

    picId++;
    if(15 == picId)
        picId = 1;
}

void Widget::on_stopButton_clicked()
{
    this->killTimer(myTimerId);
}

