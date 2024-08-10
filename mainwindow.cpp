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
    QString dodgeTime1;
    dodgeTime1=OpenFile.readLine();

    dodgeCount1 = 0;

    ui->setupUi(this);

    ui->TLabel1->setText(dodgeTime1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_TButton1_clicked()
{
    dodgeCount1++;
    ui->DLabel1->setText(QString::number(dodgeCount1));

    QDateTime timeDate = QDateTime::currentDateTime();
    QString timeString = timeDate.toString("yyyy.MM.dd hh:mm:ss");
    ui->TLabel1->setText(timeString);

    QFile file("record.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << timeString;
}

