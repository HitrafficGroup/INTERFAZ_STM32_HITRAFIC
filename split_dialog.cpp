#include "split_dialog.h"
#include "ui_split_dialog.h"

split_dialog::split_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::split_dialog)
{
    ui->setupUi(this);
    ui->spinBox_PhaseNumber->setMaximum(PhaseMax);
}

void split_dialog::closeEvent(QCloseEvent *e)
{
    e->accept();
}

split_dialog::~split_dialog()
{
    delete ui;
}

void split_dialog::SplitDataInit(Split split)
{
    if(split.Phase > 0)
    {
        ui->spinBox_PhaseNumber->setValue(split.Phase);
        ui->spinBox_PhaseNumber->setEnabled(false);
    }
    else
    {
        ui->spinBox_PhaseNumber->setValue(1);
        ui->spinBox_PhaseNumber->setEnabled(true);
    }
    ui->spinBox_Time->setValue(split.Time);
    if(split.Mode-1 < ui->comboBox_Mode->count())
        ui->comboBox_Mode->setCurrentIndex(split.Mode-1);
    else
        ui->comboBox_Mode->setCurrentIndex(1);

    if(split.Coord == 0)
    {
        ui->checkBox_AsCoordPhase->setChecked(Qt::Unchecked);//Checked
        ui->checkBox_AsKeyPhase->setChecked(Qt::Unchecked);
        ui->checkBox_AsFixedPhase->setChecked(Qt::Unchecked);
    }
    else if(split.Coord == 1)
    {
        ui->checkBox_AsCoordPhase->setChecked(Qt::Checked);//Checked
        ui->checkBox_AsKeyPhase->setChecked(Qt::Unchecked);
        ui->checkBox_AsFixedPhase->setChecked(Qt::Unchecked);
    }
    else if(split.Coord == 2)
    {
        ui->checkBox_AsCoordPhase->setChecked(Qt::Unchecked);//Checked
        ui->checkBox_AsKeyPhase->setChecked(Qt::Checked);
        ui->checkBox_AsFixedPhase->setChecked(Qt::Unchecked);
    }
    else if(split.Coord == 4)
    {
        ui->checkBox_AsCoordPhase->setChecked(Qt::Unchecked);//Checked
        ui->checkBox_AsKeyPhase->setChecked(Qt::Unchecked);
        ui->checkBox_AsFixedPhase->setChecked(Qt::Checked);
    }
}

void split_dialog::on_pushButton_confirm_clicked()
{
    split_temp.Phase = ui->spinBox_PhaseNumber->value();
    split_temp.Time = ui->spinBox_Time->value();
    split_temp.Mode = ui->comboBox_Mode->currentIndex()+1;
    split_temp.Coord = 0;
    if(ui->checkBox_AsCoordPhase->isChecked())  split_temp.Coord |= 0x01;
    if(ui->checkBox_AsKeyPhase->isChecked())    split_temp.Coord |= 0x02;
    if(ui->checkBox_AsFixedPhase->isChecked())  split_temp.Coord |= 0x04;

    if(split_temp.Time > 0)
    {
        emit SplitDataSend(split_temp);
        this->accept();
    }
    else
    {
        QMessageBox::warning(this, tr("警告"), tr("绿信比时间不能为0!"), QMessageBox::Ok);
    }
}

void split_dialog::on_pushButton_cancel_clicked()
{
    this->accept();
    //this->close();
    //Qt5窗口(QDialog、QWidget)关闭:
    //如果QDialog，用accept() 或 reject()
    //如果QWidget，用close()
}
