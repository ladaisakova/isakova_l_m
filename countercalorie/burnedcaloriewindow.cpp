#include "burnedcaloriewindow.h"
#include "ui_burnedcaloriewindow.h"
#include <QDebug>
#include <QSqlError>
#include "mainwindow.h"

BurnedcalorieWindow::BurnedcalorieWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BurnedcalorieWindow)
{
    ui->setupUi(this);
    QString act[18];
    act[0]=""; act[1]="Уборка"; act[2]="Аэробика"; act[3]="Бадминтон"; act[4]="Баскетбол"; act[5]="Велосипед"; act[6]="Гимнастика"; act[7]="Балет"; act[8]="Бальные танцы"; act[9]="Танцы"; act[10]="Футбол"; act[11]="Пеший шаг"; act[12]="Прыжки"; act[13]="Бег"; act[14]="Лыжи"; act[15]="Коньки"; act[16]="Плавание"; act[17]="Тренажерный зал";
    for (int i=0; i<18; i++)
    {
        ui->comboBox->addItem(act[i]);
        ui->comboBox_2->addItem(act[i]);
        ui->comboBox_3->addItem(act[i]);
        ui->comboBox_4->addItem(act[i]);
        ui->comboBox_5->addItem(act[i]);
        ui->comboBox_6->addItem(act[i]);
        ui->comboBox_7->addItem(act[i]);
        ui->comboBox_8->addItem(act[i]);
        ui->comboBox_9->addItem(act[i]);
        ui->comboBox_10->addItem(act[i]);
    }
    db.setDatabaseName("C:/Users/Pupa/Documents/qt prj/countercalorie/db/counter.db");
    db.open();
    connect(ui->burnedcounter, &QPushButton::clicked, this, &BurnedcalorieWindow::Burned);
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
//    QString act[17];
//    for (int i=1; i<17; i++)
//    {
//        QSqlQuery query;
//        query=db.exec("SELECT activity_name FROM activity WHERE rowid=" + QString::number(i));
//        query.next();
//        act[i]=query.value(0);
//    }
//    QString a[10];
//    a[0]=ui->activity1lineEdit->displayText();
//    a[1]=ui->activity2lineEdit->displayText();
//    a[2]=ui->activity3lineEdit->displayText();
//    a[3]=ui->activity4lineEdit->displayText();
//    a[4]=ui->activity5lineEdit->displayText();
//    a[5]=ui->activity6lineEdit->displayText();
//    a[6]=ui->activity7lineEdit->displayText();
//    a[7]=ui->activity8lineEdit->displayText();
//    a[8]=ui->activity9lineEdit->displayText();
//    a[9]=ui->activity10lineEdit->displayText();
    QString a[10];
    a[0]=ui->comboBox->currentText();
    a[1]=ui->comboBox_2->currentText();
    a[2]=ui->comboBox_3->currentText();
    a[3]=ui->comboBox_4->currentText();
    a[4]=ui->comboBox_5->currentText();
    a[5]=ui->comboBox_6->currentText();
    a[6]=ui->comboBox_7->currentText();
    a[7]=ui->comboBox_8->currentText();
    a[8]=ui->comboBox_9->currentText();
    a[9]=ui->comboBox_10->currentText();
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
}

