#ifndef MENUWINDOW_H
#define MENUWINDOW_H
#include<QDialog>

#include"changesettingswindow.h"
#include"countcaloriewindow.h"
#include"dailyallowancewindow.h"
#include"burnedcaloriewindow.h"


#include <QMainWindow>

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = 0);
    ~MenuWindow();
private slots:
    void on_changesettings_clicked();
    void on_countcalories_clicked();
    void on_dailyallowance_clicked();
    void on_burnedcalories_clicked();
    void on_exit_clicked();

private:
    Ui::MenuWindow *ui;
    ChangesettingsWindow *changesettingsw;
    CountcalorieWindow *countcaloriew;
    DailyallowanceWindow *dailyallowancew;
    BurnedcalorieWindow *burnedcaloriew;
};

#endif // MENUWINDOW_H
