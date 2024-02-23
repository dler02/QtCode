#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void onNetworkReply(QNetworkReply *reply);
    void initializeRegionCodeMap();

private:
    Ui::Widget *ui;

    // 获取信息的宏定义
    static const QString DATA_TYPE;

    QMap<QString, QString> regionCodeMap;  // 地区名和行政编码映射表
    QNetworkAccessManager *networkManager;
};
#endif // WIDGET_H
