#ifndef DAILYALLOWANCEWINDOW_H
#define DAILYALLOWANCEWINDOW_H

#include <QMainWindow>
#include <QDialog>

#include "QtSql/QSqlDataBase"
#include "QSqlQuery"

#include <QMessageBox>
#include <QPushButton>

namespace Ui {
class DailyallowanceWindow;
}

class DailyallowanceWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DailyallowanceWindow(QWidget *parent = 0);
    ~DailyallowanceWindow();
signals:
    void menuWindow();
private slots:
    void on_returnmenu_clicked();

private:
    Ui::DailyallowanceWindow *ui;
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
private slots:
    void Daily();
};

#endif // DAILYALLOWANCEWINDOW_H
