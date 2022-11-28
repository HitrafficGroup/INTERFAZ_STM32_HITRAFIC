#include "action_dialog.h"
#include "ui_action_dialog.h"

action_dialog::action_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::action_dialog)
{
    ui->setupUi(this);
    for(quint8 row = 1; row <= ActionMax; row++)
    {
        ui->comboBox_Action->addItem(tr("%1").arg(row));
    }
    for(quint8 row = 1; row <= PatternMax; row++)
    {
        ui->comboBox_Pattern->addItem(tr("%1").arg(row));
    }
}

void action_dialog::closeEvent(QCloseEvent *e)
{
    e->accept();
}

action_dialog::~action_dialog()
{
    delete ui;
}

void action_dialog::ActionDataInit(ActionType Action)
{
    if(Action.Num > 0)
    {
        ui->comboBox_Action->setEnabled(false);
        ui->comboBox_Action->setCurrentIndex(Action.Num-1);
        ui->comboBox_Pattern->setCurrentIndex(Action.PatternNum-1);

        /* 辅助功能初始化 */
        if(Action.Auxillary & 0x01)ui->checkBox_A1->setChecked(true);
        else ui->checkBox_A1->setChecked(false);
        if(Action.Auxillary & 0x02)ui->checkBox_A2->setChecked(true);
        else ui->checkBox_A2->setChecked(false);
        if(Action.Auxillary & 0x04)ui->checkBox_A3->setChecked(true);
        else ui->checkBox_A3->setChecked(false);
        if(Action.Auxillary & 0x08)ui->checkBox_A4->setChecked(true);
        else ui->checkBox_A4->setChecked(false);

        /* 特殊功能初始化 */
        if(Action.Special & 0x01)ui->checkBox_S1->setChecked(true);
        else ui->checkBox_S1->setChecked(false);
        if(Action.Special & 0x02)ui->checkBox_S2->setChecked(true);
        else ui->checkBox_S2->setChecked(false);
        if(Action.Special & 0x04)ui->checkBox_S3->setChecked(true);
        else ui->checkBox_S3->setChecked(false);
        if(Action.Special & 0x08)ui->checkBox_S4->setChecked(true);
        else ui->checkBox_S4->setChecked(false);
        if(Action.Special & 0x10)ui->checkBox_S5->setChecked(true);
        else ui->checkBox_S5->setChecked(false);
        if(Action.Special & 0x20)ui->checkBox_S6->setChecked(true);
        else ui->checkBox_S6->setChecked(false);
        if(Action.Special & 0x40)ui->checkBox_S7->setChecked(true);
        else ui->checkBox_S7->setChecked(false);
        if(Action.Special & 0x80)ui->checkBox_S8->setChecked(true);
        else ui->checkBox_S8->setChecked(false);
    }
    else
    {
        ui->comboBox_Action->setEnabled(true);
        ui->comboBox_Action->setCurrentIndex(0);
        ui->comboBox_Pattern->setCurrentIndex(0);

        ui->checkBox_A1->setChecked(false);
        ui->checkBox_A2->setChecked(false);
        ui->checkBox_A3->setChecked(false);
        ui->checkBox_A4->setChecked(false);

        ui->checkBox_S1->setChecked(false);
        ui->checkBox_S2->setChecked(false);
        ui->checkBox_S3->setChecked(false);
        ui->checkBox_S4->setChecked(false);
        ui->checkBox_S5->setChecked(false);
        ui->checkBox_S6->setChecked(false);
        ui->checkBox_S7->setChecked(false);
        ui->checkBox_S8->setChecked(false);
    }
}

void action_dialog::on_pushButton_confirm_clicked()
{
    ActionType Action;
    Action.Num = ui->comboBox_Action->currentIndex()+1;
    Action.PatternNum = ui->comboBox_Pattern->currentIndex()+1;//
    Action.Auxillary = 0;
    if(ui->checkBox_A1->isChecked())Action.Auxillary |= 0x01;
    if(ui->checkBox_A2->isChecked())Action.Auxillary |= 0x02;
    if(ui->checkBox_A3->isChecked())Action.Auxillary |= 0x04;
    if(ui->checkBox_A4->isChecked())Action.Auxillary |= 0x08;
    Action.Special = 0;
    if(ui->checkBox_S1->isChecked())Action.Special |= 0x01;
    if(ui->checkBox_S2->isChecked())Action.Special |= 0x02;
    if(ui->checkBox_S3->isChecked())Action.Special |= 0x04;
    if(ui->checkBox_S4->isChecked())Action.Special |= 0x08;
    if(ui->checkBox_S5->isChecked())Action.Special |= 0x10;
    if(ui->checkBox_S6->isChecked())Action.Special |= 0x20;
    if(ui->checkBox_S7->isChecked())Action.Special |= 0x40;
    if(ui->checkBox_S8->isChecked())Action.Special |= 0x80;
    emit ActionDataSend(Action);
    this->accept();
}

void action_dialog::on_pushButton_cancel_clicked()
{
    this->accept();
}
