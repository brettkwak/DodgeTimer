#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_TButton1_clicked()
{
    QDateTime timeDate = QDateTime::currentDateTime();
    QString timeString = timeDate.toString("yyyy.MM.dd hh:mm:ss");
    ui->TLabel1->setText(timeString);
}

