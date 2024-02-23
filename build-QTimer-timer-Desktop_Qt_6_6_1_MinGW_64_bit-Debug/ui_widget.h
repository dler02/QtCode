/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *singleButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(437, 367);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 20, 351, 241));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));
        label->setScaledContents(true);
        startButton = new QPushButton(Widget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(70, 290, 71, 41));
        stopButton = new QPushButton(Widget);
        stopButton->setObjectName("stopButton");
        stopButton->setGeometry(QRect(270, 290, 71, 41));
        singleButton = new QPushButton(Widget);
        singleButton->setObjectName("singleButton");
        singleButton->setGeometry(QRect(170, 290, 71, 41));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QString());
        startButton->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213", nullptr));
        stopButton->setText(QCoreApplication::translate("Widget", "\347\273\223\346\235\237", nullptr));
        singleButton->setText(QCoreApplication::translate("Widget", "\345\215\225\346\254\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
