#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->action_N, &QAction::triggered, this, &MainWindow::action_N_Slot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::action_N_Slot()
{
    ui->textEdit->clear();
    this->setWindowTitle("新建文本文档.txt");
}
