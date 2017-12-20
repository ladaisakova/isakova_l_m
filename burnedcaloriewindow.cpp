#include "burnedcaloriewindow.h"
#include "ui_burnedcaloriewindow.h"
#include <QDebug>
#include <QSqlError>

BurnedcalorieWindow::BurnedcalorieWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BurnedcalorieWindow)
{
    ui->setupUi(this);
    //burnedoutw = new BurnedoutWindow();
    //connect(burnedoutw, &BurnedoutWindow::burnedWindow, this, &BurnedcalorieWindow::show);
    db.setDatabaseName("Z:/qt/qtprojects/countercalorie/db/counter.db");
    db.open();
    if (db.isOpen()==false)
    {
       qDebug()<<db.lastError().text();
    }
    else
    {
        connect(ui->burnedcounter, &QPushButton::clicked, this, &BurnedcalorieWindow::Burned);
    }
}

BurnedcalorieWindow::~BurnedcalorieWindow()
{
    delete ui;
}
void BurnedcalorieWindow::on_returnmenu_clicked()
{
    this->close();
    emit menuWindow();
}
void BurnedcalorieWindow::Burned()
{
    QString a[10];
    a[0]=ui->activity1lineEdit->displayText();
    a[1]=ui->activity2lineEdit->displayText();
    a[2]=ui->activity3lineEdit->displayText();
    a[3]=ui->activity4lineEdit->displayText();
    a[4]=ui->activity5lineEdit->displayText();
    a[5]=ui->activity6lineEdit->displayText();
    a[6]=ui->activity7lineEdit->displayText();
    a[7]=ui->activity8lineEdit->displayText();
    a[8]=ui->activity9lineEdit->displayText();
    a[9]=ui->activity10lineEdit->displayText();
    QString t[10];
    t[0]=ui->time1lineEdit->displayText();
    t[1]=ui->time2lineEdit->displayText();
    t[2]=ui->time3lineEdit->displayText();
    t[3]=ui->time4lineEdit->displayText();
    t[4]=ui->time5lineEdit->displayText();
    t[5]=ui->time6lineEdit->displayText();
    t[6]=ui->time7lineEdit->displayText();
    t[7]=ui->time8lineEdit->displayText();
    t[8]=ui->time9lineEdit->displayText();
    t[9]=ui->time10lineEdit->displayText();
    double res=0;
    double at=0;
    for (int i=0; i<10; i+=1)
    {
       QSqlQuery query;
       query=db.exec("SELECT burned_calorie FROM activity WHERE activity_name=\ '" + a[i] + "\'");
       query.next();
       at=query.value(0).toInt()*t[i].toInt()/60;
       res=res+at;
    }
    QString q=QString::number(res);
    ui->burnedlineEdit->setText(q);
    db.close();
    //this->close();
    //BurnedoutWindow *obj=new BurnedoutWindow();
    //obj->show();
}

