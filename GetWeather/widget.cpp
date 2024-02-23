#include "widget.h"
#include "ui_widget.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QLineEdit>
#include <QFile>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget),
    networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);



    // 初始化映射表格
    initializeRegionCodeMap();

    // 连接网络请求完成信号到处理函数
    connect(networkManager, &QNetworkAccessManager::finished, this, &Widget::onNetworkReply);
}

//请求数据类型。数据类型有：now/fc/index/alert/fc_hour/all，控制返回内容
const QString Widget::DATA_TYPE = "now";

Widget::~Widget()
{
    delete ui;
}

void Widget::initializeRegionCodeMap()
{
    // 当前应用程序所在的目录中读取CSV文件，并构建地区名和行政编码的映射表格

    QFile file(QCoreApplication::applicationDirPath() + "/weather_district_id.csv");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        // 跳过表头行
        in.readLine();
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split(',');

            // 假设CSV文件的格式为：district_geocode district
            // 检查是否包含足够的字段
            if (parts.size() >= 2)
            {
                QString district = parts[0].trimmed();         // 行政区名称
                QString districtGeocode = parts[1].trimmed();  // 行政区地理编码


                // 存储行政区和对应的地理编码
                regionCodeMap[district] = districtGeocode;
            }
        }

        file.close();
    }
}

// 按钮的点击事件到获取天气的槽函数
void Widget::on_pushButton_clicked()
{
    // 获取用户输入的地区名
    QString userInputRegion = ui->citylineEdit->text();

    // 检查用户输入的地区是否存在于映射表格中
    if (regionCodeMap.contains(userInputRegion))
    {
        // 存在，获取对应的行政编码
        QString regionCode = regionCodeMap[userInputRegion];

        QString apiKey = "Nl18Gs8i74LecCFI4rVeELpj3zu9Z0F6";

        // 使用百度天气API的URL
        // QString apiUrl = "https://api.map.baidu.com/weather/v1/?district_id=110100&data_type=now&ak=Nl18Gs8i74LecCFI4rVeELpj3zu9Z0F6";   //For Browser Test
        QString apiUrl = "https://api.map.baidu.com/weather/v1/?district_id="+ regionCode +"&data_type=" + DATA_TYPE + "&ak="+ apiKey +"";

        // 创建网络请求
        QNetworkRequest request;
        request.setUrl(QUrl(apiUrl));

        // 发送 GET 请求
        networkManager->get(request);
    }
    else
    {
        // 不存在，提示用户输入正确的地区名
        QMessageBox::warning(this, tr("Error"), tr("Please enter a valid region name."));
    }
}



void Widget::onNetworkReply(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        // 读取所有返回的数据
        QByteArray responseData = reply->readAll();

        // 解析 JSON 数据
        QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);

        QJsonObject jsonObject = jsonResponse.object();

        // 获取天气信息
        // Check if "status" key exists and has value 0
        if (jsonObject.contains("status") && jsonObject["status"].toInt() == 0)
        {
            // Extract information from "result" object
            QJsonObject resultObject = jsonObject["result"].toObject();

            // Extract information from "location" object
            QJsonObject locationObject = resultObject["location"].toObject();
            QString country = locationObject["country"].toString();
            QString province = locationObject["province"].toString();
            QString city = locationObject["city"].toString();
            QString name = locationObject["name"].toString();
            QString id = locationObject["id"].toString();

            // Extract information from "now" object
            QJsonObject nowObject = resultObject["now"].toObject();
            QString text = nowObject["text"].toString();
            int temp = nowObject["temp"].toInt();
            int feelsLike = nowObject["feels_like"].toInt();
            int rh = nowObject["rh"].toInt();
            QString windClass = nowObject["wind_class"].toString();
            QString windDir = nowObject["wind_dir"].toString();
            QString uptimeString = nowObject["uptime"].toString();

            // Convert the "uptime" string to QDateTime
            QDateTime uptimeDateTime = QDateTime::fromString(uptimeString, "yyyyMMddhhmmss");

            // Format QDateTime as a standard time string
            QString formattedUptime = uptimeDateTime.toString("yyyy-MM-dd hh:mm:ss");

            // Output or use formattedUptime
            qDebug() << "Formatted Uptime: " << formattedUptime;

            // 在解析数据后将信息显示在 QLabel 中
            ui->label->setText(QString("Country: %1\nProvince: %2\nCity: %3\nName: %4\nID: %5\n"
                                       "Text: %6\nTemperature: %7\nFeels Like: %8\nRelative Humidity: %9\n"
                                       "Wind Class: %10\nWind Direction: %11\nUptime: %12\n")
                                   .arg(country, province, city, name, id, text, QString::number(temp),
                                        QString::number(feelsLike), QString::number(rh), windClass, windDir, formattedUptime));
        }
    }
    else
    {
        // 处理网络错误
        QMessageBox::warning(this, tr("Error"), tr("Network error: %1").arg(reply->errorString()));
    }

    // 清理网络回复对象
    reply->deleteLater();
}

