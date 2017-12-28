#include "countcaloriewindow.h"
#include "ui_countcaloriewindow.h"
#include "mainwindow.h"
#include <QDebug>
#include <QSqlError>

CountcalorieWindow::CountcalorieWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CountcalorieWindow)
{
    ui->setupUi(this);
    QString pro[56];
    pro[0]=""; pro[1]="Коньяк"; pro[2]="Ликер"; pro[3]="Шампанское"; pro[4]="Ананасовый сок"; pro[5]="Кофе"; pro[6]="Зеленый чай"; pro[7]="Черный чай"; pro[8]="Гречневая каша"; pro[9]="Сосиски";
    pro[10]="Молоко"; pro[11]="Сыр"; pro[12]="Творог"; pro[13]="Свинина"; pro[14]="Курица"; pro[15]="Баклажан"; pro[16]="Кабачок"; pro[17]="Капуста"; pro[18]="Вареный картофель"; pro[19]="Жареный картофель";
    pro[20]="Морковь"; pro[21]="Огурец"; pro[22]="Томат"; pro[23]="Фасоль"; pro[24]="Арахис"; pro[25]="Изюм"; pro[26]="Курага"; pro[27]="Миндаль"; pro[28]="Финики"; pro[29]="Горбуша";
    pro[30]="Креветка"; pro[31]="Лосось"; pro[32]="Семга"; pro[33]="Вафли"; pro[34]="Зефир"; pro[35]="Мармелад"; pro[36]="Мед"; pro[37]="Мороженое"; pro[38]="Печенье"; pro[39]="Шоколад";
    pro[40]="Ананас"; pro[41]="Апельсин"; pro[42]="Банан"; pro[43]="Виноград"; pro[44]="Грейпфрут"; pro[45]="Груша"; pro[46]="Дыня"; pro[47]="Киви"; pro[48]="Клубника"; pro[49]="Персик";
    pro[50]="Памело"; pro[51]="Слива"; pro[52]="Хурма"; pro[53]="Батон"; pro[54]="Ржаной хлеб"; pro[55]="Яйцо";
    for (int i=0; i<56; i++)
    {
        ui->comboBox->addItem(pro[i]);
        ui->comboBox_2->addItem(pro[i]);
        ui->comboBox_3->addItem(pro[i]);
        ui->comboBox_4->addItem(pro[i]);
        ui->comboBox_5->addItem(pro[i]);
        ui->comboBox_6->addItem(pro[i]);
        ui->comboBox_7->addItem(pro[i]);
        ui->comboBox_8->addItem(pro[i]);
        ui->comboBox_9->addItem(pro[i]);
        ui->comboBox_10->addItem(pro[i]);
        ui->comboBox_11->addItem(pro[i]);
        ui->comboBox_12->addItem(pro[i]);
        ui->comboBox_13->addItem(pro[i]);
        ui->comboBox_14->addItem(pro[i]);
        ui->comboBox_15->addItem(pro[i]);
    }
    db.setDatabaseName("C:/Users/Pupa/Documents/qt prj/countercalorie/db/counter.db");
    db.open();
    connect(ui->counter, &QPushButton::clicked, this, &CountcalorieWindow::Counter);
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
//    QString p[15];
//    p[0]=ui->product1lineEdit->displayText();
//    p[1]=ui->product2lineEdit->displayText();
//    p[2]=ui->product3lineEdit->displayText();
//    p[3]=ui->product4lineEdit->displayText();
//    p[4]=ui->product5lineEdit->displayText();
//    p[5]=ui->product6lineEdit->displayText();
//    p[6]=ui->product7lineEdit->displayText();
//    p[7]=ui->product8lineEdit->displayText();
//    p[8]=ui->product9lineEdit->displayText();
//    p[9]=ui->product10lineEdit->displayText();
//    p[10]=ui->product11lineEdit->displayText();
//    p[11]=ui->product12lineEdit->displayText();
//    p[12]=ui->product13lineEdit->displayText();
//    p[13]=ui->product14lineEdit->displayText();
//    p[14]=ui->product15lineEdit->displayText();
    QString p[15];
    p[0]=ui->comboBox->currentText();
    p[1]=ui->comboBox_2->currentText();
    p[2]=ui->comboBox_3->currentText();
    p[3]=ui->comboBox_4->currentText();
    p[4]=ui->comboBox_5->currentText();
    p[5]=ui->comboBox_6->currentText();
    p[6]=ui->comboBox_7->currentText();
    p[7]=ui->comboBox_8->currentText();
    p[8]=ui->comboBox_9->currentText();
    p[9]=ui->comboBox_10->currentText();
    p[10]=ui->comboBox_11->currentText();
    p[11]=ui->comboBox_12->currentText();
    p[12]=ui->comboBox_13->currentText();
    p[13]=ui->comboBox_14->currentText();
    p[14]=ui->comboBox_15->currentText();
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
       //query=db.exec("SELECT calories, proteins, fats, carbohydrates FROM products WHERE product_name= '" + p[i] + "'");
       //query=db.exec("SELECT calories FROM calories WHERE product_name= '" + p[i] + "'");
       //query=db.exec("SELECT burned_calorie FROM activity WHERE activity_name=\ '" + p[i] + "\'");
       //query.exec("SELECT calorie FROM product WHERE login= '" + l + "'");
       //QVariant a=query.value(0);
       //query.next();
       query.exec("SELECT calories FROM products WHERE product_name= '" + p[i] + "'");
       QVariant a=query.value(0);
       query.exec("SELECT proteins FROM products WHERE product_name= '" + p[i] + "'");
       QVariant b=query.value(0);
       query.exec("SELECT fats FROM products WHERE product_name= '" + p[i] + "'");
       QVariant c=query.value(0);
       query.exec("SELECT carbohydrates FROM products WHERE product_name= '" + p[i] + "'");
       QVariant d=query.value(0);
       query.next();
       at1=a.toInt()*m[i].toInt()/100;
       at2=b.toInt()*m[i].toInt()/100;
       at3=c.toInt()*m[i].toInt()/100;
       at4=d.toInt()*m[i].toInt()/100;
       res1=res1+at1;
       res2=res2+at2;
       res3=res3+at3;
       res4=res4+at4;
//       at1=query.value(0).toInt()*m[i].toInt()/100;
//       res1=res1+at1;
//       at2=query.value(1).toInt()*m[i].toInt()/100;
//       res2=res2+at2;
//       at3=query.value(2).toInt()*m[i].toInt()/100;
//       res3=res3+at3;
//       at4=query.value(3).toInt()*m[i].toInt()/100;
//       res4=res4+at4;
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



