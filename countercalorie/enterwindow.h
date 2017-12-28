#ifndef ENTERWINDOW_H
#define ENTERWINDOW_H

#include <QDialog>

#include <QMainWindow>
#include"menuwindow.h"

#include "QtSql/QSqlDataBase"
#include "QSqlQuery"
#include <QDialog>
#include <QDebug>
#include <QFileInfo>

#include <QMessageBox>
#include <QPushButton>

namespace Ui {
class EnterWindow;
}

class EnterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EnterWindow(QWidget *parent = 0);
    ~EnterWindow();
signals:
    void mainWindow();

private slots:
    void on_returnmain_clicked();

private:
    Ui::EnterWindow *ui;
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
private slots:
    void Enter();
};

#endif // ENTERWINDOW_H
