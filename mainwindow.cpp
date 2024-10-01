#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDateTime>
#include <QFile>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QFile file("record.txt");
    file.open(QFile::ReadOnly|QFile::Text);
    QTextStream OpenFile(&file);
    dodgeTime1 = OpenFile.readLine();
    dodgeCount1 = OpenFile.readLine().toInt();

    ui->setupUi(this);

    ui->TLabel1->setText(dodgeTime1);
    ui->DLabel1->setText(QString::number(dodgeCount1));

    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_TButton1_clicked()
{
    dodgeCount1++;
    ui->DLabel1->setText(QString::number(dodgeCount1));

    timeDate = QDateTime::currentDateTime();
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

void MainWindow::update(){
    qDebug() << "Update...";

    currentTime = QDateTime::currentDateTime();
    timeDifference = timeDate.secsTo(currentTime);
    qDebug() << timeDifference << dodgeCount1;
    if (timeDifference > dodgeCount1*43200){
        dodgeCount1 = 0;
        dodgeTime1 = "";
        qDebug() << "Reset!";
    }
    ui->DLabel1->setText(QString::number(dodgeCount1));
    ui->TLabel1->setText(dodgeTime1);

}
