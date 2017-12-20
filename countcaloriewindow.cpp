#include "countcaloriewindow.h"
#include "ui_countcaloriewindow.h"
#include <QDebug>
#include <QSqlError>

CountcalorieWindow::CountcalorieWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CountcalorieWindow)
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
        connect(ui->counter, &QPushButton::clicked, this, &CountcalorieWindow::Counter);
    }
}

CountcalorieWindow::~CountcalorieWindow()
{
    delete ui;
}
void CountcalorieWindow::on_returnmenu_clicked()
{
    this->close();
    emit menuWindow();
}
void CountcalorieWindow::Counter()
{
    QString p[15];
    p[0]=ui->product1lineEdit->displayText();
    p[1]=ui->product2lineEdit->displayText();
    p[2]=ui->product3lineEdit->displayText();
    p[3]=ui->product4lineEdit->displayText();
    p[4]=ui->product5lineEdit->displayText();
    p[5]=ui->product6lineEdit->displayText();
    p[6]=ui->product7lineEdit->displayText();
    p[7]=ui->product8lineEdit->displayText();
    p[8]=ui->product9lineEdit->displayText();
    p[9]=ui->product10lineEdit->displayText();
    p[10]=ui->product11lineEdit->displayText();
    p[11]=ui->product12lineEdit->displayText();
    p[12]=ui->product13lineEdit->displayText();
    p[13]=ui->product14lineEdit->displayText();
    p[14]=ui->product15lineEdit->displayText();
    QString m[15];
    m[0]=ui->tons1lineEdit->displayText();
    m[1]=ui->tons2lineEdit->displayText();
    m[2]=ui->tons3lineEdit->displayText();
    m[3]=ui->tons4lineEdit->displayText();
    m[4]=ui->tons5lineEdit->displayText();
    m[5]=ui->tons6lineEdit->displayText();
    m[6]=ui->tons7lineEdit->displayText();
    m[7]=ui->tons8lineEdit->displayText();
    m[8]=ui->tons9lineEdit->displayText();
    m[9]=ui->tons10lineEdit->displayText();
    m[10]=ui->tons11lineEdit->displayText();
    m[11]=ui->tons12lineEdit->displayText();
    m[12]=ui->tons13lineEdit->displayText();
    m[13]=ui->tons14lineEdit->displayText();
    m[14]=ui->tons15lineEdit->displayText();
    double at1=0;
    double at2=0;
    double at3=0;
    double at4=0;
    double res1=0;
    double res2=0;
    double res3=0;
    double res4=0;
    for (int i=0; i<15; i+=1)
    {
       QSqlQuery query;
       query=db.exec("SELECT calories, proteins, fats, carbohydrates FROM calories WHERE product_name=\ '" + p[i] + "\'");
       query.next();
       at1=query.value(0).toInt()*m[i].toInt()/100;
       res1=res1+at1;
       at2=query.value(1).toInt()*m[i].toInt()/100;
       res2=res2+at2;
       at3=query.value(2).toInt()*m[i].toInt()/100;
       res3=res3+at3;
       at4=query.value(3).toInt()*m[i].toInt()/100;
       res4=res4+at4;
    }
    QString q1=QString::number(res1);
    ui->calorielineEdit->setText(q1);
    QString q2=QString::number(res2);
    ui->proteinlineEdit->setText(q2);
    QString q3=QString::number(res3);
    ui->fatlineEdit->setText(q3);
    QString q4=QString::number(res4);
    ui->carbohydratelineEdit->setText(q4);
}

