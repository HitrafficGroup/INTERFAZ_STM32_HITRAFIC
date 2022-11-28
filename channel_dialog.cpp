#include "channel_dialog.h"
#include "ui_channel_dialog.h"

channel_dialog::channel_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::channel_dialog)
{
    ui->setupUi(this);
    ui->comboBox_channelNum->setDisabled(true);
    for(quint8 row = 0; row <= PhaseMax; row++)
    {
        ui->comboBox_phase->addItem(tr("%1").arg(row));
    }
}

void channel_dialog::closeEvent(QCloseEvent *e)
{
    e->accept();
}

channel_dialog::~channel_dialog()
{
    delete ui;
}

void channel_dialog::ChannelDataInit(Channel channel)
{
    ui->comboBox_channelNum->setCurrentIndex(channel.Num-1);
    ui->comboBox_phase->setCurrentIndex(channel.ControlSource);

    ui->checkBox_countdown->setChecked(channel.CountdownID & 0x80);
    ui->spinBox_id->setValue(channel.CountdownID & 0x7f);

    ui->comboBox_Position->setCurrentIndex(channel.Position);
    ui->comboBox_Direction->setCurrentIndex(channel.Direction);

    ui->comboBox_type->setCurrentIndex(0);
    if( channel.ControlType==CCT_VEHICLE )ui->radioPhase_vehicle->setChecked(true);
    else if( channel.ControlType==CCT_PEDESTRIAN )ui->radioPhase_ped->setChecked(true);
    else if( channel.ControlType==CCT_OVERLAP )ui->radioPhase_follow->setChecked(true);
    else
    {
        ui->radioPhase_other->setChecked(true);
        if( channel.ControlType==CCT_FLASH )ui->comboBox_type->setCurrentIndex(1);
        else if( channel.ControlType==CCT_GREEN )ui->comboBox_type->setCurrentIndex(2);
        else if( channel.ControlType==CCT_RED )ui->comboBox_type->setCurrentIndex(3);
    }

         if( channel.Flash & 0x02 )ui->radioFlash_yel->setChecked(true);
    else if( channel.Flash & 0x04 )ui->radioFlash_red->setChecked(true);
    else if( channel.Flash & 0x08 )ui->radioFlash_alternate->setChecked(true);
    else ui->radioFlash_oth->setChecked(true);

         if( channel.Dim & 0x01 )ui->radiodim_gre->setChecked(true);
    else if( channel.Dim & 0x02 )ui->radiodim_yel->setChecked(true);
    else if( channel.Dim & 0x04 )ui->radiodim_red->setChecked(true);
    else if( channel.Dim & 0x08 )ui->radiodim_alternate->setChecked(true);
}

void channel_dialog::on_pushButton_confirm_clicked()
{
    Channel channel;

    channel.Num = ui->comboBox_channelNum->currentIndex()+1;
    channel.ControlSource = ui->comboBox_phase->currentIndex();
    channel.Position = ui->comboBox_Position->currentIndex();
    channel.Direction = ui->comboBox_Direction->currentIndex();

    if(ui->checkBox_countdown->isChecked())
        channel.CountdownID = 0x80 | ui->spinBox_id->value();
    else
        channel.CountdownID = 0x7f & ui->spinBox_id->value();

    if(ui->radioPhase_vehicle->isChecked())channel.ControlType = CCT_VEHICLE;
    else if(ui->radioPhase_ped->isChecked())channel.ControlType = CCT_PEDESTRIAN;
    else if(ui->radioPhase_follow->isChecked())channel.ControlType = CCT_OVERLAP;
    else
    {
        if(ui->comboBox_type->currentIndex() == 0)
            channel.ControlType = CCT_OTHER;
        else if(ui->comboBox_type->currentIndex() == 1)
            channel.ControlType = CCT_FLASH;
        else if(ui->comboBox_type->currentIndex() == 2)
            channel.ControlType = CCT_GREEN;
        else if(ui->comboBox_type->currentIndex() == 3)
            channel.ControlType = CCT_RED;
    }
    if(ui->radioFlash_alternate->isChecked())channel.Flash = 0x08;
    else if(ui->radioFlash_red->isChecked())channel.Flash = 0x04;
    else if(ui->radioFlash_yel->isChecked())channel.Flash = 0x02;
    else channel.Flash = 0x01;

    if(ui->radiodim_alternate->isChecked())channel.Dim = 0x08;
    else if(ui->radiodim_red->isChecked())channel.Dim = 0x04;
    else if(ui->radiodim_yel->isChecked())channel.Dim = 0x02;
    else if(ui->radiodim_gre->isChecked())channel.Dim = 0x01;
    else channel.Dim = 0x00;

    emit ChannelDataSend(channel);
    this->accept();
}

void channel_dialog::on_pushButton_cancel_clicked()
{
    this->accept();
    //this->close();
    //Qt5窗口(QDialog、QWidget)关闭:
    //如果QDialog，用accept() 或 reject()
    //如果QWidget，用close()
}
