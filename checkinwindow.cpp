#include "checkinwindow.h"
#include "ui_checkinwindow.h"
#include <QDebug>
#include <QSqlError>

CheckinWindow::CheckinWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckinWindow)
{
    ui->setupUi(this);
    ui->agreecheckBox->setChecked(false);
    ui->activecheckBox->setChecked(false);
    ui->passivecheckBox->setChecked(false);
    ui->womancheckBox->setChecked(false);
    ui->mancheckBox->setChecked(false);
    db.setDatabaseName("Z:/qt/qtprojects/countercalorie/db/counter.db");
    db.open();
    if (db.isOpen()==false)
    {
       qDebug()<<db.lastError().text();
    }
    else
    {
        connect(ui->tocheckin, &QPushButton::clicked, this, &CheckinWindow::Checkin);
    }
    agreementw = new AgreementWindow();
    connect(agreementw, &AgreementWindow::checkinWindow, this, &CheckinWindow::show);
}

CheckinWindow::~CheckinWindow()
{
    delete ui;
}

void CheckinWindow::on_returnmain_clicked()
{
    this->close();
    emit mainWindow();
}

void CheckinWindow::on_agreementlink_clicked()
{
    agreementw->show();
    this->close();
}
void CheckinWindow::Checkin()
{
    int t=0;
    QString login=ui->loginlineEdit->displayText();
    QString name=ui->namelineEdit->displayText();
    QString surname=ui->surnamelineEdit->displayText();
    QString age=ui->agelineEdit->displayText();
    QString height=ui->heightlineEdit->displayText();
    QString weight=ui->weightlineEdit->displayText();
    QString lifestyle;
    QString sex;
    if (ui->activecheckBox->isChecked()==true) {lifestyle="активный";}
    if (ui->passivecheckBox->isChecked()==true) {lifestyle="пассивный";}
    if (ui->womancheckBox->isChecked()==true) {sex="женский";}
    if (ui->mancheckBox->isChecked()==true) {sex="мужской";}
    QString password=ui->passwordlineEdit->displayText();
    if ((login.length()<8) || (login.length()>12)) {t=1; }
    for (int i=0; i<login.length(); i+=1 )
    {
        if ((login[i].isUpper()) || (login[i].isDigit()) || (login[i].isMark())) {t=1; };
    }
    if (t==1) {QMessageBox::information(this, "Error", "Incorrect login!");}
    if ((name.length()<2) || (name.length()>18) || (name[0].isLower()) || (name[0].isDigit()) || (name[0].isMark())) {t=2;}
    for (int i=1; i<name.length(); i+=1 )
    {
        if ((name[i].isUpper()) || (name[i].isDigit()) || (name[i].isMark())) {t=2;}
    }
    if (t==2) {QMessageBox::information(this, "Error", "Incorrect name!");}
    if ((surname.length()<1) || (surname.length()>20) || (surname[0].isLower()) || (surname[0].isDigit()) || (surname[0].isMark())) {t=3;}
    for (int i=1; i<surname.length(); i+=1)
    {
        if ((surname[i].isUpper()) || (surname[i].isDigit()) || (surname[i].isMark())) {t=3;}
    }
    if (t==3) {QMessageBox::information(this, "Error", "Incorrect surname!");}
    if ((age.toInt()<18) || (age.toInt()>100)) {t=4;}
    for (int i=0; i<age.length(); i+=1)
    {
        if ((age[i].isLetter()) || (age[i].isMark())) {t=4;}
    }
    if (t==4) {QMessageBox::information(this, "Error", "Incorrect age!");}
    if ((height.toInt()<120) || (height.toInt()>230)) {t=5;}
    for (int i=0; i<height.length(); i+=1)
    {
        if ((height[i].isLetter()) || (height[i].isMark())) {t=5;}
    }
    if (t==5) {QMessageBox::information(this, "Error", "Incorrect height!");}
    if ((weight.toInt()<40) || (weight.toInt()>150)) {t=6;}
    for (int i=0; i<weight.length(); i+=1)
    {
        if ((weight[i].isLetter()) || (weight[i].isMark())) {t=6;}
    }
    if (t==6) {QMessageBox::information(this, "Error", "Incorrect weight!");}
    if ((password.length()<8) || (password.length()>20)) {t=7;}
    for (int i=0; i<password.length(); i+=1)
    {
        if (password[i].isMark()) {t=7;}
    }
    if (t==7) {QMessageBox::information(this, "Error", "Incorrect password!");}
    if (ui->agreecheckBox->isChecked()==false) {t=8;}
    if (t==8) {QMessageBox::information(this, "Error", "You should agree!");}
    if ((ui->activecheckBox->isChecked()==true) && (ui->passivecheckBox->isChecked()==true)) {t=9;}
    if ((ui->womancheckBox->isChecked()==true) && (ui->mancheckBox->isChecked()==true)) {t=9;}
    if ((ui->activecheckBox->isChecked()==false) && (ui->passivecheckBox->isChecked()==false)) {t=9;}
    if ((ui->womancheckBox->isChecked()==false) && (ui->mancheckBox->isChecked()==false)) {t=9;}
    if (t==9) {QMessageBox::information(this, "Error", "You should choose one!");}
    QSqlQuery query;
    query.prepare("INSERT INTO users(login, name, surname, age, height, weight, sex, password, lifestyle)" "VALUES('" + login + "', '" + name + "', '" + surname + "', '" + age + "', '" + height + "', '" + weight + "', '" + sex + "', '" + password + "', '" + lifestyle + "')");
    //QString q="INSERT INTO users(login, name, surname, age, height, weight, sex, password, lifestyle) VALUES('" + login + "', '" + name + "', '" + surname + "', '" + age + "', '" + height + "', '" + weight + "', '" + sex + "', '" + password + "', '" + lifestyle + "')";
    //db.exec(q);
    //db.exec(query);
    if (t==0)
    {
    this->close();
    MenuWindow *obj=new MenuWindow();
    obj->show();
    }
}


