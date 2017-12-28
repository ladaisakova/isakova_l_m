#ifndef AGREEMENTWINDOW_H
#define AGREEMENTWINDOW_H

#include <QMainWindow>

namespace Ui {
class AgreementWindow;
}

class AgreementWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AgreementWindow(QWidget *parent = 0);
    ~AgreementWindow();
signals:
    void checkinWindow();
private slots:
    void on_returncheckin_clicked();

private:
    Ui::AgreementWindow *ui;
};

#endif // AGREEMENTWINDOW_H
