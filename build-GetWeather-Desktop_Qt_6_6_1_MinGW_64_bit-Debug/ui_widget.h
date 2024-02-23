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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *citylineEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(300, 300);
        Widget->setMinimumSize(QSize(300, 300));
        Widget->setMaximumSize(QSize(300, 300));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../build-GetWeather-Desktop_Qt_6_6_1_MinGW_64_bit-Debug/debug/\345\244\251\346\260\224\346\237\245\350\257\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 50, 261, 191));
        label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: rgb(170, 255, 255);"));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 250, 261, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(80, 40));
        pushButton->setMaximumSize(QSize(80, 40));

        horizontalLayout->addWidget(pushButton);

        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 20, 101, 21));
        citylineEdit = new QLineEdit(Widget);
        citylineEdit->setObjectName("citylineEdit");
        citylineEdit->setGeometry(QRect(120, 10, 80, 30));
        citylineEdit->setMinimumSize(QSize(80, 30));
        citylineEdit->setMaximumSize(QSize(80, 30));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\244\251\346\260\224\346\237\245\350\257\242", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("Widget", "\350\216\267\345\217\226\345\244\251\346\260\224", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:11pt;\">\350\257\267\350\276\223\345\205\245\345\237\216\345\270\202\345\220\215\357\274\232</span></p></body></html>", nullptr));
        citylineEdit->setText(QCoreApplication::translate("Widget", "\345\214\227\344\272\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
