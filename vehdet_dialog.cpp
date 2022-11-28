#include "vehdet_dialog.h"
#include "ui_vehdet_dialog.h"

vehdet_dialog::vehdet_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::vehdet_dialog)
{
    ui->setupUi(this);
}

void vehdet_dialog::closeEvent(QCloseEvent *e)
{
    e->accept();
}

vehdet_dialog::~vehdet_dialog()
{
    delete ui;
    delete &vehdet_Temp;
}

void vehdet_dialog::VehdetDataInit(Vehdet vehdet)
{
    vehdet_Temp = vehdet;
    //vehdet_Temp -> ui
    if(vehdet_Temp.Num)ui->spinBox_Num->setValue(vehdet_Temp.Num);
    ui->spinBox_CallPhase->setValue(vehdet_Temp.CallPhase);
    ui->spinBox_SwitchPhase->setValue(vehdet_Temp.SwitchPhase);

    ui->spinBox_Delay->setValue(vehdet_Temp.Delay);
    ui->spinBox_QueueLimit->setValue(vehdet_Temp.QueueLimit);
    ui->spinBox_Extend->setValue(vehdet_Temp.Extend);

    ui->spinBox_FailTime->setValue(vehdet_Temp.FailTime);
    ui->spinBox_NoActivity->setValue(vehdet_Temp.NoActivity);
    ui->spinBox_MaxPresence->setValue(vehdet_Temp.MaxPresence);
    ui->spinBox_ErraticCounts->setValue(vehdet_Temp.ErraticCounts);

    ui->checkBox_RecordFlow->setChecked(vehdet_Temp.Options&VDO_recordFlow);
    ui->checkBox_RecordOccupancy->setChecked(vehdet_Temp.Options&VDO_recordOccupancy);
    ui->checkBox_UseExtend->setChecked(vehdet_Temp.Options&VDO_extend);
    ui->checkBox_RequestValid->setChecked(vehdet_Temp.Options&VDO_require);
    ui->checkBox_StrategicDet->setChecked(vehdet_Temp.Options&VDO_strategy);
    ui->checkBox_QueueDet->setChecked(vehdet_Temp.Options&VDO_queue);
    ui->checkBox_Red->setChecked(vehdet_Temp.Options&VDO_redRequireLock);
    ui->checkBox_Yellow->setChecked(vehdet_Temp.Options&VDO_yellowRequireLock);

    ui->checkBox_Reset->setChecked(vehdet_Temp.Reset);
}

void vehdet_dialog::on_pushButton_confirm_clicked()
{
    //ui -> vehdet_Temp
    vehdet_Temp.Num = ui->spinBox_Num->value();
    vehdet_Temp.CallPhase = ui->spinBox_CallPhase->value();
    vehdet_Temp.SwitchPhase = ui->spinBox_SwitchPhase->value();

    vehdet_Temp.Delay = ui->spinBox_Delay->value();
    vehdet_Temp.QueueLimit = ui->spinBox_QueueLimit->value();
    vehdet_Temp.Extend = ui->spinBox_Extend->value();

    vehdet_Temp.FailTime = ui->spinBox_FailTime->value();
    vehdet_Temp.NoActivity = ui->spinBox_NoActivity->value();
    vehdet_Temp.MaxPresence = ui->spinBox_MaxPresence->value();
    vehdet_Temp.ErraticCounts = ui->spinBox_ErraticCounts->value();

    vehdet_Temp.Options = 0;
    if(ui->checkBox_RecordFlow->isChecked())        vehdet_Temp.Options |= VDO_recordFlow;
    if(ui->checkBox_RecordOccupancy->isChecked())   vehdet_Temp.Options |= VDO_recordOccupancy;
    if(ui->checkBox_UseExtend->isChecked())         vehdet_Temp.Options |= VDO_extend;
    if(ui->checkBox_RequestValid->isChecked())      vehdet_Temp.Options |= VDO_require;
    if(ui->checkBox_StrategicDet->isChecked())      vehdet_Temp.Options |= VDO_strategy;
    if(ui->checkBox_QueueDet->isChecked())          vehdet_Temp.Options |= VDO_queue;
    if(ui->checkBox_Red->isChecked())               vehdet_Temp.Options |= VDO_redRequireLock;
    if(ui->checkBox_Yellow->isChecked())            vehdet_Temp.Options |= VDO_yellowRequireLock;

    if(ui->checkBox_Reset->isChecked())             vehdet_Temp.Reset = 1;

    emit VehdetDataSend(vehdet_Temp);
    this->accept();
}

void vehdet_dialog::on_pushButton_cancel_clicked()
{
    this->accept();
}
