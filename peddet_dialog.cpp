#include "peddet_dialog.h"
#include "ui_peddet_dialog.h"

peddet_dialog::peddet_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::peddet_dialog)
{
    ui->setupUi(this);
    ui->spinBox_Num->setMaximum(PeddetMax);
}

void peddet_dialog::closeEvent(QCloseEvent *e)
{
    e->accept();
}

peddet_dialog::~peddet_dialog()
{
    delete ui;
}

void peddet_dialog::PeddetDataInit(Peddet peddet)
{
    ui->spinBox_Num->setValue(peddet.Num);
    ui->spinBox_CallPhase->setValue(peddet.CallPhase);
    ui->spinBox_NoActivity->setValue(peddet.NoActivity);
    ui->spinBox_MaxPresence->setValue(peddet.MaxPresence);
    ui->spinBox_ErraticCounts->setValue(peddet.ErraticCounts);
}

void peddet_dialog::on_pushButton_confirm_clicked()
{
    peddet_temp.Num = ui->spinBox_Num->value();
    peddet_temp.CallPhase = ui->spinBox_CallPhase->value();
    peddet_temp.NoActivity = ui->spinBox_NoActivity->value();
    peddet_temp.MaxPresence = ui->spinBox_MaxPresence->value();
    peddet_temp.ErraticCounts = ui->spinBox_ErraticCounts->value();
    peddet_temp.Alarms = 0;

    emit PeddetDataSend(peddet_temp);
    this->accept();
}

void peddet_dialog::on_pushButton_cancel_clicked()
{
    this->accept();
}
