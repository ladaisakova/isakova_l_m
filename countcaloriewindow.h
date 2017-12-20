#ifndef COUNTCALORIEWINDOW_H
#define COUNTCALORIEWINDOW_H


#include <QMainWindow>
#include <QDialog>


#include "QtSql/QSqlDataBase"
#include "QSqlQuery"

#include <QMessageBox>
#include <QPushButton>

namespace Ui {
class CountcalorieWindow;
}

class CountcalorieWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CountcalorieWindow(QWidget *parent = 0);
    ~CountcalorieWindow();
signals:
    void menuWindow();
private slots:
    void on_returnmenu_clicked();
    //void on_counter_clicked();

private:
    Ui::CountcalorieWindow *ui;
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    //CounteroutWindow *counteroutw;
private slots:
    void Counter();
};

#endif // COUNTCALORIEWINDOW_H
