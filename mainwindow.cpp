#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDateTime>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QFile file("record.txt");
    file.open(QFile::ReadOnly|QFile::Text);
    QTextStream OpenFile(&file);
    QString ConfigText;
    ConfigText=OpenFile.readLine();

    ui->setupUi(this);

    ui->TLabel1->setText(ConfigText);
}

MainWindow::~MainWindow()
{
    QFile("A.txt");
    delete ui;
}


void MainWindow::on_TButton1_clicked()
{
    QDateTime timeDate = QDateTime::currentDateTime();
    QString timeString = timeDate.toString("yyyy.MM.dd hh:mm:ss");
    ui->TLabel1->setText(timeString);

    QFile file("record.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << timeString;
}

