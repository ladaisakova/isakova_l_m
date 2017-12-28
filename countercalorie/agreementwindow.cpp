#include "agreementwindow.h"
#include "ui_agreementwindow.h"

AgreementWindow::AgreementWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AgreementWindow)
{
    ui->setupUi(this);
}

AgreementWindow::~AgreementWindow()
{
    delete ui;
}
void AgreementWindow::on_returncheckin_clicked()
{
    this->close();
    emit checkinWindow();
}
