#ifndef CHANGESETTINGSWINDOW_H
#define CHANGESETTINGSWINDOW_H
#include <QDialog>
#include <QMainWindow>


#include "QtSql/QSqlDataBase"
#include "QSqlQuery"

#include <QMessageBox>
#include <QPushButton>

namespace Ui {
class ChangesettingsWindow;
}

class ChangesettingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChangesettingsWindow(QWidget *parent = 0);
    ~ChangesettingsWindow();
signals:
    void menuWindow();
private slots:
    void on_returnmenu_clicked();

private:
    Ui::ChangesettingsWindow *ui;
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
private slots:
    void SaveChanges();
};

#endif // CHANGESETTINGSWINDOW_H
