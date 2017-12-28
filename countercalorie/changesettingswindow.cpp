#include "changesettingswindow.h"
#include "ui_changesettingswindow.h"
#include <QDebug>
#include <QSqlError>

ChangesettingsWindow::ChangesettingsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChangesettingsWindow)
{
    ui->setupUi(this);
    ui->changeactivecheckBox->setChecked(false);
    ui->changepassivecheckBox->setChecked(false);
    db.setDatabaseName("C:/Users/Pupa/Documents/qt prj/countercalorie/db/counter.db");
    db.open();
    connect(ui->savechanges, &QPushButton::clicked, this, &ChangesettingsWindow::SaveChanges);

}

ChangesettingsWindow::~ChangesettingsWindow()
{
    delete ui;
}
void ChangesettingsWindow::on_returnmenu_clicked()
{
    this->close();
    emit menuWindow();
}
void ChangesettingsWindow::SaveChanges()
{
    QString login=ui->changeloginlineEdit->displayText();
    QString age=ui->changeagelineEdit->displayText();
    QString height=ui->changeheightlineEdit->displayText();
    QString weight=ui->changeweightlineEdit->displayText();
    QString lifestyle;
    if (ui->changepassivecheckBox->isChecked()==true)
    {
        lifestyle="пассивный";
        //QString q="UPDATE users SET age = '" + age + "' SET height = '" + height + "' SET weight = '" + weight + "' SET lifestyle = '" + lifestyle + "' WHERE login=\ '" + login + "\' ";
        //QString q="UPDATE users SET age = '" + age + "' WHERE login=\ '" + login + "\' ";
        //QString q="UPDATE users SET height = '" + height + "' WHERE login=\ '" + login + "\' ";
        //QString q="UPDATE users SET weight = '" + weight + "' WHERE login=\ '" + login + "\' ";
        //QString q="UPDATE users SET lifestyle = '" + lifestyle + "' WHERE login=\ '" + login + "\' ";
        //db.exec(q);
        QSqlQuery query;
        query.prepare("UPDATE users SET age = '" + age + "' WHERE login=\ '" + login + "\' ");
        query.prepare("UPDATE users SET height = '" + height + "' WHERE login=\ '" + login + "\' ");
        query.prepare("UPDATE users SET weight = '" + weight + "' WHERE login=\ '" + login + "\' ");
        query.prepare("UPDATE users SET lifestyle = '" + lifestyle + "' WHERE login=\ '" + login + "\' ");
        QMessageBox::information(this, "Success", "Changes saved!");
    }
    else
    {
        if (ui->changeactivecheckBox->isChecked()==true)
        {
            lifestyle="активный";
            //QString q="UPDATE users SET age = '" + age + "' SET height = '" + height + "' SET weight = '" + weight + "' SET lifestyle = '" + lifestyle + "' WHERE login=\ '" + login + "\' ";
            //db.exec(q);
            QSqlQuery query;
            query.prepare("UPDATE users SET age = '" + age + "' WHERE login=\ '" + login + "\' ");
            query.prepare("UPDATE users SET height = '" + height + "' WHERE login=\ '" + login + "\' ");
            query.prepare("UPDATE users SET weight = '" + weight + "' WHERE login=\ '" + login + "\' ");
            query.prepare("UPDATE users SET lifestyle = '" + lifestyle + "' WHERE login=\ '" + login + "\' ");
            QMessageBox::information(this, "Success", "Changes saved!");
        }
        else
        {
            QMessageBox::information(this, "Error", "Changes unsaved!");
        }
    }

}
