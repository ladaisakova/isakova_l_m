#include "dailyallowancewindow.h"
#include "ui_dailyallowancewindow.h"
#include <QDebug>
#include <QSqlError>
#include "mainwindow.h"

DailyallowanceWindow::DailyallowanceWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DailyallowanceWindow)
{
    ui->setupUi(this);
    ui->womancheckBox->setChecked(false);
    ui->mancheckBox->setChecked(false);
    db.setDatabaseName("C:/Users/Pupa/Documents/qt prj/countercalorie/db/counter.db");
    db.open();
    connect(ui->count, &QPushButton::clicked, this, &DailyallowanceWindow::Daily);
}

DailyallowanceWindow::~DailyallowanceWindow()
{
    delete ui;
}
void DailyallowanceWindow::on_returnmenu_clicked()
{
    this->close();
    emit menuWindow();
}
void DailyallowanceWindow::Daily()
{
    QString l=ui->loginlineEdit->displayText();
    double res=0;
    if (ui->womancheckBox->isChecked()==true)
    {
        QSqlQuery query;
        //query=db.exec("SELECT age, height, weight FROM users WHERE login= '" + l + "'");
        //query.next();
        query.exec("SELECT age FROM users WHERE login= '" + l + "'");
        QVariant a=query.value(0);
        query.exec("SELECT height FROM users WHERE login= '" + l + "'");
        QVariant h=query.value(0);
        query.exec("SELECT weight FROM users WHERE login= '" + l + "'");
        QVariant w=query.value(0);
        res=10*w.toInt()+6.25*h.toInt()-5*a.toInt()-161;
        //res=10*query.value(2).toInt()+6.25*query.value(1).toInt()-5*query.value(0).toInt()-161;
    }
    else
    {
        QSqlQuery query;
        //query=db.exec("SELECT age, height, weight FROM users WHERE login= '" + l + "'");
        //query.next();
        //res=10*query.value(2).toInt()+6.25*query.value(1).toInt()-5*query.value(0).toInt()+5;
        query.exec("SELECT age FROM users WHERE login= '" + l + "'");
        QVariant a=query.value(0);
        query.exec("SELECT height FROM users WHERE login= '" + l + "'");
        QVariant h=query.value(0);
        query.exec("SELECT weight FROM users WHERE login= '" + l + "'");
        QVariant w=query.value(0);
        res=10*w.toInt()+6.25*h.toInt()-5*a.toInt()+5;
    }
    QString q=QString::number(res);
    ui->dailycalorielineEdit->setText(q);
}
