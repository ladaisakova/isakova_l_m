#include "menuwindow.h"
#include "ui_menuwindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
//    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:/Users/Pupa/Documents/qt prj/countercalorie/db/counter.db");
//    db.open();
    changesettingsw = new ChangesettingsWindow();
    connect(changesettingsw, &ChangesettingsWindow::menuWindow, this, &MenuWindow::show);
    countcaloriew = new CountcalorieWindow();
    connect(countcaloriew, &CountcalorieWindow::menuWindow, this, &MenuWindow::show);
    dailyallowancew = new DailyallowanceWindow();
    connect(dailyallowancew, &DailyallowanceWindow::menuWindow, this, &MenuWindow::show);
    burnedcaloriew = new BurnedcalorieWindow();
    connect(burnedcaloriew, &BurnedcalorieWindow::menuWindow, this, &MenuWindow::show);
}

MenuWindow::~MenuWindow()
{
    delete ui;
}
void MenuWindow::on_changesettings_clicked()
{
    changesettingsw->show();
    this->close();
}
void MenuWindow::on_countcalories_clicked()
{
    countcaloriew->show();
    this->close();
}
void MenuWindow::on_dailyallowance_clicked()
{
    dailyallowancew->show();
    this->close();
}
void MenuWindow::on_burnedcalories_clicked()
{
    burnedcaloriew->show();
    this->close();
}
void MenuWindow::on_exit_clicked()
{
    this->close();
}
