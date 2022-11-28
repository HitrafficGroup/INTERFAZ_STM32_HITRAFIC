#include "plan_dialog.h"
#include "ui_plan_dialog.h"

plan_dialog::plan_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::plan_dialog)
{
    ui->setupUi(this);
    for(quint8 row = 1; row <= ActionMax; row++)
    {
        ui->comboBox_Action->addItem(tr("%1").arg(row));
    }
    ui->comboBox_Action->setCurrentIndex(0);
}

void plan_dialog::closeEvent(QCloseEvent *e)
{
    e->accept();
}

plan_dialog::~plan_dialog()
{
    delete ui;
}

void plan_dialog::PlanDataInit(Plan plan)
{
    PlanTemp.EventNum = plan.EventNum;
    PlanTemp.ActionNum = plan.ActionNum;
    PlanTemp.Time.Hour = plan.Time.Hour;
    PlanTemp.Time.Minute = plan.Time.Minute;

    QTime timesedit(PlanTemp.Time.Hour,PlanTemp.Time.Minute,0);
    ui->timeEdit->setTime(timesedit);
    if(PlanTemp.ActionNum > 0)
        ui->comboBox_Action->setCurrentIndex(PlanTemp.ActionNum-1);
    else
        ui->comboBox_Action->setCurrentIndex(0);
}

void plan_dialog::on_pushButton_confirm_clicked()
{
    PlanTemp.Time.Hour = ui->timeEdit->time().hour();
    PlanTemp.Time.Minute = ui->timeEdit->time().minute();
    PlanTemp.ActionNum = ui->comboBox_Action->currentIndex()+1;

    emit PlanDataSend(PlanTemp);
    this->accept();
}

void plan_dialog::on_pushButton_cancel_clicked()
{
    this->accept();
}
