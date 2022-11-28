#include "schedule_dialog.h"
#include "ui_schedule_dialog.h"

schedule_dialog::schedule_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::schedule_dialog)
{
    ui->setupUi(this);
    for(quint8 row = 1; row <= ScheduleMax; row++)
    {
        ui->comboBox_ScheduleNum->addItem(tr("%1").arg(row));
    }

    for(quint8 row = 1; row <= PlanMax; row++)
    {
        ui->comboBox_DayPlanNum->addItem(tr("%1").arg(row));
    }
    CheckBox_Month[0] = ui->checkBox_m1;
    CheckBox_Month[1] = ui->checkBox_m2;
    CheckBox_Month[2] = ui->checkBox_m3;
    CheckBox_Month[3] = ui->checkBox_m4;
    CheckBox_Month[4] = ui->checkBox_m5;
    CheckBox_Month[5] = ui->checkBox_m6;
    CheckBox_Month[6] = ui->checkBox_m7;
    CheckBox_Month[7] = ui->checkBox_m8;
    CheckBox_Month[8] = ui->checkBox_m9;
    CheckBox_Month[9] = ui->checkBox_m10;
    CheckBox_Month[10] = ui->checkBox_m11;
    CheckBox_Month[11] = ui->checkBox_m12;

    CheckBox_Day[0] = ui->checkBox_w1;
    CheckBox_Day[1] = ui->checkBox_w2;
    CheckBox_Day[2] = ui->checkBox_w3;
    CheckBox_Day[3] = ui->checkBox_w4;
    CheckBox_Day[4] = ui->checkBox_w5;
    CheckBox_Day[5] = ui->checkBox_w6;
    CheckBox_Day[6] = ui->checkBox_w7;

    CheckBox_Date[0] = ui->checkBox_d1;
    CheckBox_Date[1] = ui->checkBox_d2;
    CheckBox_Date[2] = ui->checkBox_d3;
    CheckBox_Date[3] = ui->checkBox_d4;
    CheckBox_Date[4] = ui->checkBox_d5;
    CheckBox_Date[5] = ui->checkBox_d6;
    CheckBox_Date[6] = ui->checkBox_d7;
    CheckBox_Date[7] = ui->checkBox_d8;
    CheckBox_Date[8] = ui->checkBox_d9;
    CheckBox_Date[9] = ui->checkBox_d10;
    CheckBox_Date[10] = ui->checkBox_d11;
    CheckBox_Date[11] = ui->checkBox_d12;
    CheckBox_Date[12] = ui->checkBox_d13;
    CheckBox_Date[13] = ui->checkBox_d14;
    CheckBox_Date[14] = ui->checkBox_d15;
    CheckBox_Date[15] = ui->checkBox_d16;
    CheckBox_Date[16] = ui->checkBox_d17;
    CheckBox_Date[17] = ui->checkBox_d18;
    CheckBox_Date[18] = ui->checkBox_d19;
    CheckBox_Date[19] = ui->checkBox_d20;
    CheckBox_Date[20] = ui->checkBox_d21;
    CheckBox_Date[21] = ui->checkBox_d22;
    CheckBox_Date[22] = ui->checkBox_d23;
    CheckBox_Date[23] = ui->checkBox_d24;
    CheckBox_Date[24] = ui->checkBox_d25;
    CheckBox_Date[25] = ui->checkBox_d26;
    CheckBox_Date[26] = ui->checkBox_d27;
    CheckBox_Date[27] = ui->checkBox_d28;
    CheckBox_Date[28] = ui->checkBox_d29;
    CheckBox_Date[29] = ui->checkBox_d30;
    CheckBox_Date[30] = ui->checkBox_d31;
    connect(ui->checkBox_month, SIGNAL(clicked()), this, SLOT(monthSelectAll()));
    connect(ui->checkBox_date1, SIGNAL(clicked()), this, SLOT(date1SelectAll()));
    connect(ui->checkBox_date2, SIGNAL(clicked()), this, SLOT(date2SelectAll()));
    connect(ui->checkBox_date3, SIGNAL(clicked()), this, SLOT(date3SelectAll()));
    connect(ui->checkBox_date4, SIGNAL(clicked()), this, SLOT(date4SelectAll()));
    connect(ui->checkBox_day, SIGNAL(clicked()), this, SLOT(daySelectAll()));
}

void schedule_dialog::closeEvent(QCloseEvent *e)
{
    e->accept();
}

schedule_dialog::~schedule_dialog()
{
    delete ui;
}

void schedule_dialog::ScheduleDataInit(Schedule schedule)
{
    if(schedule.Number > 0)
    {
        ui->comboBox_ScheduleNum->setCurrentIndex(schedule.Number-1);
        ui->comboBox_DayPlanNum->setCurrentIndex(schedule.DayPlan-1);
        quint32 temp = 0x0002;
        for(quint8 i=0; i <12; i++)
        {
            if(schedule.Month & temp)CheckBox_Month[i]->setChecked(true);
            else CheckBox_Month[i]->setChecked(false);
            temp <<= 1;
        }
        temp = 0x0002;
        for(quint8 i=0; i <31; i++)
        {
            if(schedule.Date & temp)CheckBox_Date[i]->setChecked(true);
            else CheckBox_Date[i]->setChecked(false);
            temp <<= 1;
        }
        temp = 0x0002;
        for(quint8 i=0; i <7; i++)
        {
            if(schedule.Day & temp)CheckBox_Day[i]->setChecked(true);
            else CheckBox_Day[i]->setChecked(false);
            temp <<= 1;
        }
        ui->comboBox_ScheduleNum->setEnabled(false);
    }
    else
    {
        ui->comboBox_ScheduleNum->setCurrentIndex(schedule.Number-1);
        ui->comboBox_DayPlanNum->setCurrentIndex(schedule.DayPlan-1);
        for(quint8 i=0; i <12; i++)
        {
            CheckBox_Month[i]->setChecked(false);
        }
        for(quint8 i=0; i <31; i++)
        {
            CheckBox_Date[i]->setChecked(false);
        }
        for(quint8 i=0; i <7; i++)
        {
            CheckBox_Day[i]->setChecked(false);
        }
        ui->comboBox_ScheduleNum->setEnabled(true);
    }
    ui->checkBox_month->setChecked(false);
    ui->checkBox_day->setChecked(false);
    ui->checkBox_date1->setChecked(false);
    ui->checkBox_date2->setChecked(false);
    ui->checkBox_date3->setChecked(false);
    ui->checkBox_date4->setChecked(false);
}

void schedule_dialog::on_pushButton_confirm_clicked()
{
    Schedule schedule;
    schedule.Number = ui->comboBox_ScheduleNum->currentIndex()+1;
    schedule.DayPlan = ui->comboBox_DayPlanNum->currentIndex()+1;

    schedule.Month = 0;
    schedule.Date = 0;
    schedule.Day = 0;

    quint32 temp = 0x0002;
    for(quint8 i=0; i <12; i++)
    {
        if(CheckBox_Month[i]->isChecked())schedule.Month |= temp;
        temp <<= 1;
    }
    temp = 0x0002;
    for(quint8 i=0; i <31; i++)
    {
        if(CheckBox_Date[i]->isChecked())schedule.Date |= temp;
        temp <<= 1;
    }
    temp = 0x0002;
    for(quint8 i=0; i <7; i++)
    {
        if(CheckBox_Day[i]->isChecked())schedule.Day |= temp;
        temp <<= 1;
    }
    if(schedule.Number <= 0 || schedule.DayPlan <= 0)
    {
        QMessageBox::warning(this, tr("警告"), tr("调度计划号和时段表号不能为空!"), QMessageBox::Ok);
        return;
    }
    emit ScheduleDataSend(schedule);
    this->accept();
}
void schedule_dialog::date1SelectAll()
{
    if(ui->checkBox_date1->isChecked())
    {
        for(quint8 i=0; i <8; i++)
        {
            CheckBox_Date[i]->setChecked(true);
        }
    }
    else
    {
        for(quint8 i=0; i <8; i++)
        {
            CheckBox_Date[i]->setChecked(false);
        }
    }
}
void schedule_dialog::date2SelectAll()
{
    if(ui->checkBox_date2->isChecked())
    {
        for(quint8 i=8; i <16; i++)
        {
            CheckBox_Date[i]->setChecked(true);
        }
    }
    else
    {
        for(quint8 i=8; i <16; i++)
        {
            CheckBox_Date[i]->setChecked(false);
        }
    }
}
void schedule_dialog::date3SelectAll()
{
    if(ui->checkBox_date3->isChecked())
    {
        for(quint8 i=16; i <24; i++)
        {
            CheckBox_Date[i]->setChecked(true);
        }
    }
    else
    {
        for(quint8 i=16; i <24; i++)
        {
            CheckBox_Date[i]->setChecked(false);
        }
    }
}
void schedule_dialog::date4SelectAll()
{
    if(ui->checkBox_date4->isChecked())
    {
        for(quint8 i=24; i <31; i++)
        {
            CheckBox_Date[i]->setChecked(true);
        }
    }
    else
    {
        for(quint8 i=24; i <31; i++)
        {
            CheckBox_Date[i]->setChecked(false);
        }
    }
}
void schedule_dialog::monthSelectAll()
{
    if(ui->checkBox_month->isChecked())
    {
        for(quint8 i=0; i <12; i++)
        {
            CheckBox_Month[i]->setChecked(true);
        }
    }
    else
    {
        for(quint8 i=0; i <12; i++)
        {
            CheckBox_Month[i]->setChecked(false);
        }
    }
}
void schedule_dialog::daySelectAll()
{
    if(ui->checkBox_day->isChecked())
    {
        for(quint8 i=0; i <7; i++)
        {
            CheckBox_Day[i]->setChecked(true);
        }
    }
    else
    {
        for(quint8 i=0; i <7; i++)
        {
            CheckBox_Day[i]->setChecked(false);
        }
    }
}
void schedule_dialog::on_pushButton_cancel_clicked()
{
    this->accept();
}
