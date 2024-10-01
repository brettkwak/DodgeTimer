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
    stringDodgeTime1 = OpenFile.readLine();
    dodgeCount1 = OpenFile.readLine().toInt();

    qDebug() << stringDodgeTime1;

    dateDodgeTime1 = QDateTime::fromString(stringDodgeTime1, "yyyy.MM.dd HH:mm:ss");

    qDebug() << dateDodgeTime1;

    ui->setupUi(this);

    ui->TLabel1->setText(stringDodgeTime1);
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
    stringDodgeTime1 = timeDate.toString("yyyy.MM.dd hh:mm:ss");
    ui->TLabel1->setText(timeString);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QFile file("record.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << stringDodgeTime1 << "\n" << dodgeCount1;
}

void MainWindow::on_Button_Reset_clicked()
{
    timeString = "";
    dodgeCount1 = 0;
}

void MainWindow::update(){
    qDebug() << "Update...";

    currentTime = QDateTime::currentDateTime();
    timeDifference = dateDodgeTime1.secsTo(currentTime);
    qDebug() << stringDodgeTime1 << timeDifference << dodgeCount1;
    if (timeDifference > dodgeCount1*43200){
        dodgeCount1 = 0;
        stringDodgeTime1 = "";
        qDebug() << "Reset!";
    }
    ui->DLabel1->setText(QString::number(dodgeCount1));
    ui->TLabel1->setText(stringDodgeTime1);

}
