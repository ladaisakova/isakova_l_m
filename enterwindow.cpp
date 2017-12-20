#include "enterwindow.h"
#include "ui_enterwindow.h"
#include <QDebug>
#include <QSqlError>

EnterWindow::EnterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EnterWindow)
{
    ui->setupUi(this);
    db.setDatabaseName("Z:/qt/qtprojects/countercalorie/db/counter.db");
    db.open();
    if (db.isOpen()==false)
    {
       qDebug()<<db.lastError().text();
    }
    else
    {
        connect(ui->enter, &QPushButton::clicked, this, &EnterWindow::Enter);
    }
}

EnterWindow::~EnterWindow()
{
    delete ui;
}

void EnterWindow::on_returnmain_clicked()
{
    this->close();
    emit mainWindow();
}

void EnterWindow::Enter()
{
    QString login=ui->loginlineEdit->displayText();
    QString password=ui->passwordlineEdit->displayText();

    QSqlQuery query;
    if (query.exec("SELECT login, password FROM users WHERE login=\ '" + login + "\' AND password=\'" + password + "\' "))
    {
        if (query.next())
        {
            this->close();
            db.close();
            MenuWindow *obj= new MenuWindow();
            obj->show();
        }
        else
        {
            QMessageBox::information(this, "Error", "Incorrect login or password");
        }
    }
    else
    {
        QMessageBox::information(this, "Error", "Wrong query");
    }
}
