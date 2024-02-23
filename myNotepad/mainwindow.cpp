#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // connect(ui->action_N, &QAction::triggered, this, &QMainWindow::ac)
}

MainWindow::~MainWindow()
{
    delete ui;
}
