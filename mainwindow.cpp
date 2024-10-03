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
    stringDodgeTime2 = OpenFile.readLine();
    dodgeCount2 = OpenFile.readLine().toInt();
    stringDodgeTime3 = OpenFile.readLine();
    dodgeCount3 = OpenFile.readLine().toInt();
    stringDodgeTime4 = OpenFile.readLine();
    dodgeCount4 = OpenFile.readLine().toInt();
    stringDodgeTime5 = OpenFile.readLine();
    dodgeCount5 = OpenFile.readLine().toInt();

    lastDodgeTime1 = QDateTime::fromString(stringDodgeTime1, "yyyy.MM.dd HH:mm:ss");
    lastDodgeTime2 = QDateTime::fromString(stringDodgeTime2, "yyyy.MM.dd HH:mm:ss");
    lastDodgeTime3 = QDateTime::fromString(stringDodgeTime3, "yyyy.MM.dd HH:mm:ss");
    lastDodgeTime4 = QDateTime::fromString(stringDodgeTime4, "yyyy.MM.dd HH:mm:ss");
    lastDodgeTime5 = QDateTime::fromString(stringDodgeTime5, "yyyy.MM.dd HH:mm:ss");

    ui->setupUi(this);

    updateLabels1();
    updateLabels2();
    updateLabels3();
    updateLabels4();
    updateLabels5();

    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QFile file("record.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << stringDodgeTime1 << "\n" << dodgeCount1 << "\n";
    out << stringDodgeTime2 << "\n" << dodgeCount2 << "\n";
    out << stringDodgeTime3 << "\n" << dodgeCount3 << "\n";
    out << stringDodgeTime4 << "\n" << dodgeCount4 << "\n";
    out << stringDodgeTime5 << "\n" << dodgeCount5 << "\n";
}

void MainWindow::update(){
    qDebug() << "Update...";

    currentTime = QDateTime::currentDateTime();

    updateTime1();
    updateTime2();
    updateTime3();
    updateTime4();
    updateTime5();

    updateLabels1();
    updateLabels2();
    updateLabels3();
    updateLabels4();
    updateLabels5();
}


void MainWindow::on_TButton1_clicked()
{
    dodgeCount1++;
    lastDodgeTime1 = QDateTime::currentDateTime();
    stringDodgeTime1 = lastDodgeTime1.toString("yyyy.MM.dd hh:mm:ss");

    updateLabels1();
}

void MainWindow::on_TButton2_clicked()
{
    dodgeCount2++;
    lastDodgeTime2 = QDateTime::currentDateTime();
    stringDodgeTime2 = lastDodgeTime2.toString("yyyy.MM.dd hh:mm:ss");

    updateLabels2();
}

void MainWindow::on_TButton3_clicked()
{
    dodgeCount3++;
    lastDodgeTime3 = QDateTime::currentDateTime();
    stringDodgeTime3 = lastDodgeTime3.toString("yyyy.MM.dd hh:mm:ss");

    updateLabels3();
}

void MainWindow::on_TButton4_clicked()
{
    dodgeCount4++;
    lastDodgeTime4 = QDateTime::currentDateTime();
    stringDodgeTime4 = lastDodgeTime4.toString("yyyy.MM.dd hh:mm:ss");

    updateLabels4();
}

void MainWindow::on_TButton5_clicked()
{
    dodgeCount5++;
    lastDodgeTime5 = QDateTime::currentDateTime();
    stringDodgeTime5 = lastDodgeTime5.toString("yyyy.MM.dd hh:mm:ss");

    updateLabels5();
}


void MainWindow::updateLabels1(){
    ui->CLabel1->setText(QString::number(dodgeCount1));
    ui->TLabel1->setText(stringDodgeTime1);
}

void MainWindow::updateLabels2(){
    ui->CLabel2->setText(QString::number(dodgeCount2));
    ui->TLabel2->setText(stringDodgeTime2);
}

void MainWindow::updateLabels3(){
    ui->CLabel3->setText(QString::number(dodgeCount3));
    ui->TLabel3->setText(stringDodgeTime3);
}

void MainWindow::updateLabels4(){
    ui->CLabel4->setText(QString::number(dodgeCount4));
    ui->TLabel4->setText(stringDodgeTime4);
}

void MainWindow::updateLabels5(){
    ui->CLabel5->setText(QString::number(dodgeCount5));
    ui->TLabel5->setText(stringDodgeTime5);
}


void MainWindow::on_RButton1_clicked()
{
    stringDodgeTime1 = "No Penalty";
    dodgeCount1 = 0;
    updateLabels1();
}

void MainWindow::on_RButton2_clicked()
{
    stringDodgeTime2 = "No Penalty";
    dodgeCount2 = 0;
    updateLabels2();
}

void MainWindow::on_RButton3_clicked()
{
    stringDodgeTime3 = "No Penalty";
    dodgeCount3 = 0;
    updateLabels3();
}

void MainWindow::on_RButton4_clicked()
{
    stringDodgeTime4 = "No Penalty";
    dodgeCount4 = 0;
    updateLabels4();
}

void MainWindow::on_RButton5_clicked()
{
    stringDodgeTime5 = "No Penalty";
    dodgeCount5 = 0;
    updateLabels5();
}


void MainWindow::updateTime1(){
    timeDifference1 = lastDodgeTime1.secsTo(currentTime);
    if (timeDifference1 > 43200){
        dodgeCount1--;

        lastDodgeTime1 = lastDodgeTime1.addSecs(43200);
        qDebug() << "Reset 1!";
    }
    if (dodgeCount1 == 0){
        stringDodgeTime1 = "No Penalty";
    }
    else {
        stringDodgeTime1 = lastDodgeTime1.toString("yyyy.MM.dd hh:mm:ss");
    }
}

void MainWindow::updateTime2(){
    timeDifference2 = lastDodgeTime2.secsTo(currentTime);
    if (timeDifference2 > 43200){
        dodgeCount2--;

        lastDodgeTime2 = lastDodgeTime2.addSecs(43200);
        qDebug() << "Reset 2!";
    }
    if (dodgeCount2 == 0){
        stringDodgeTime2 = "No Penalty";
    }
    else {
        stringDodgeTime2 = lastDodgeTime2.toString("yyyy.MM.dd hh:mm:ss");
    }
}

void MainWindow::updateTime3(){
    timeDifference3 = lastDodgeTime3.secsTo(currentTime);
    if (timeDifference3 > 43200){
        dodgeCount3--;

        lastDodgeTime3 = lastDodgeTime3.addSecs(43200);
        qDebug() << "Reset 3!";
    }
    if (dodgeCount3 == 0){
        stringDodgeTime3 = "No Penalty";
    }
    else {
        stringDodgeTime3 = lastDodgeTime3.toString("yyyy.MM.dd hh:mm:ss");
    }
}

void MainWindow::updateTime4(){
    timeDifference4 = lastDodgeTime4.secsTo(currentTime);
    if (timeDifference4 > 43200){
        dodgeCount4--;

        lastDodgeTime4 = lastDodgeTime4.addSecs(43200);
        qDebug() << "Reset 4!";
    }
    if (dodgeCount4 == 0){
        stringDodgeTime4 = "No Penalty";
    }
    else {
        stringDodgeTime4 = lastDodgeTime4.toString("yyyy.MM.dd hh:mm:ss");
    }
}

void MainWindow::updateTime5(){
    timeDifference5 = lastDodgeTime5.secsTo(currentTime);
    if (timeDifference5 > 43200){
        dodgeCount5--;

        lastDodgeTime5 = lastDodgeTime5.addSecs(43200);
        qDebug() << "Reset 5!";
    }
    if (dodgeCount5 == 0){
        stringDodgeTime5 = "No Penalty";
    }
    else {
        stringDodgeTime5 = lastDodgeTime5.toString("yyyy.MM.dd hh:mm:ss");
    }
}
