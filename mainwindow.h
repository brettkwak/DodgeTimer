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

    void on_Button_Reset_clicked();
    void update();

private:
    Ui::MainWindow *ui;

    int dodgeCount1;

    void closeEvent(QCloseEvent *event);

    QString timeString;

    QDateTime timeDate;
    QDateTime currentTime;
    int timeDifference;
};
#endif // MAINWINDOW_H
