#ifndef BURNEDCALORIEWINDOW_H
#define BURNEDCALORIEWINDOW_H


#include <QMainWindow>
#include <QDialog>

#include "QtSql/QSqlDataBase"
#include "QSqlQuery"

#include <QMessageBox>
#include <QPushButton>

namespace Ui {
class BurnedcalorieWindow;
}

class BurnedcalorieWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BurnedcalorieWindow(QWidget *parent = 0);
    ~BurnedcalorieWindow();
signals:
    void menuWindow();
private slots:
    void on_returnmenu_clicked();
    //void on_burnedcounter_clicked();

private:
    Ui::BurnedcalorieWindow *ui;
    //BurnedoutWindow *burnedoutw;
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
private slots:
    void Burned();
};

#endif // BURNEDCALORIEWINDOW_H
