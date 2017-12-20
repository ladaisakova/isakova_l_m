#ifndef CHECKINWINDOW_H
#define CHECKINWINDOW_H

#include <QDialog>

#include"agreementwindow.h"
#include"menuwindow.h"

#include "QtSql/QSqlDataBase"
#include "QSqlQuery"

#include <QMainWindow>

namespace Ui {
class CheckinWindow;
}

class CheckinWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckinWindow(QWidget *parent = 0);
    ~CheckinWindow();
signals:
    void mainWindow();

private slots:
    void on_returnmain_clicked();

    void on_agreementlink_clicked();

private:
    Ui::CheckinWindow *ui;
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    AgreementWindow *agreementw;
private slots:
    void Checkin();
    //void on_agreecheckBox_clicked(bool checked);
};

#endif // CHECKINWINDOW_H
