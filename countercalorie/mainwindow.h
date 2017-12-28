#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QtWidgets/QMainWindow>
#include <QPushButton>

#include"checkinwindow.h"
#include"enterwindow.h"


#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_enter_clicked();

    void on_checkin_clicked();

    void on_exit_clicked();


private:
    Ui::MainWindow *ui;
    EnterWindow *enterw;
    CheckinWindow *checkinw;
};

#endif // MAINWINDOW_H
