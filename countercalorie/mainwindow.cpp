#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    db.setDatabaseName("C:/Users/Pupa/Documents/qt prj/countercalorie/db/counter.db");
//    db.open();
    checkinw = new CheckinWindow();
    connect(checkinw, &CheckinWindow::mainWindow, this, &MainWindow::show);
    enterw = new EnterWindow();
    connect(enterw, &EnterWindow::mainWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enter_clicked()
{
    enterw->show();
    this->close();
}

void MainWindow::on_checkin_clicked()
{
    checkinw->show();
    this->close();
}


void MainWindow::on_exit_clicked()
{
    this->close();
}

