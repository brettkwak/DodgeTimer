#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_TButton1_clicked();
    void on_TButton2_clicked();
    void on_TButton3_clicked();
    void on_TButton4_clicked();
    void on_TButton5_clicked();

    void update();

    void on_RButton1_clicked();
    void on_RButton2_clicked();
    void on_RButton3_clicked();
    void on_RButton4_clicked();
    void on_RButton5_clicked();

private:
    Ui::MainWindow *ui;

    void closeEvent(QCloseEvent *event);

    void updateLabels1();
    void updateLabels2();
    void updateLabels3();
    void updateLabels4();
    void updateLabels5();

    void updateTime1();
    void updateTime2();
    void updateTime3();
    void updateTime4();
    void updateTime5();

    QDateTime currentTime;
    int timeDifference1;
    int timeDifference2;
    int timeDifference3;
    int timeDifference4;
    int timeDifference5;

    int dodgeCount1;
    QString stringDodgeTime1;
    QDateTime lastDodgeTime1;
    int dodgeCount2;
    QString stringDodgeTime2;
    QDateTime lastDodgeTime2;
    int dodgeCount3;
    QString stringDodgeTime3;
    QDateTime lastDodgeTime3;
    int dodgeCount4;
    QString stringDodgeTime4;
    QDateTime lastDodgeTime4;
    int dodgeCount5;
    QString stringDodgeTime5;
    QDateTime lastDodgeTime5;

};
#endif // MAINWINDOW_H
