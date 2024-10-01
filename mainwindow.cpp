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
    dodgeTime1 = OpenFile.readLine();
    dodgeCount1 = OpenFile.readLine().toInt();

    ui->setupUi(this);

    ui->TLabel1->setText(dodgeTime1);
    ui->DLabel1->setText(QString::number(dodgeCount1));
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
    timeString = timeDate.toString("yyyy.MM.dd hh:mm:ss");
    ui->TLabel1->setText(timeString);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QFile file("record.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << timeString << "\n" << dodgeCount1;
}

void MainWindow::on_Button_Reset_clicked()
{
    timeString = "";
    dodgeCount1 = 0;
}

