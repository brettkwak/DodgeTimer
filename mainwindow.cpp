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

    lastDodgeTime1 = QDateTime::fromString(stringDodgeTime1, "yyyy.MM.dd HH:mm:ss");

    ui->setupUi(this);

    updateLabels();

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
    lastDodgeTime1 = QDateTime::currentDateTime();
    stringDodgeTime1 = lastDodgeTime1.toString("yyyy.MM.dd hh:mm:ss");

    updateLabels();
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
    stringDodgeTime1 = "No Penalty";
    dodgeCount1 = 0;
    updateLabels();
}

void MainWindow::update(){
    qDebug() << "Update...";

    currentTime = QDateTime::currentDateTime();
    timeDifference = lastDodgeTime1.secsTo(currentTime);
    qDebug() << "String1 :" << stringDodgeTime1;
    qDebug() << "Differ1 :" <<timeDifference;
    qDebug() << "Count1 :" << dodgeCount1;
    if (timeDifference > 43200){
        dodgeCount1--;

        lastDodgeTime1 = lastDodgeTime1.addSecs(43200);
        qDebug() << "Reset!";
    }

    if (dodgeCount1 == 0){
        stringDodgeTime1 = "No Penalty";
    }
    else {
        stringDodgeTime1 = lastDodgeTime1.toString("yyyy.MM.dd hh:mm:ss");
    }

    updateLabels();

}

void MainWindow::updateLabels(){
    ui->DLabel1->setText(QString::number(dodgeCount1));
    ui->TLabel1->setText(stringDodgeTime1);
}
