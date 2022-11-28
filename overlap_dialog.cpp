#include "overlap_dialog.h"
#include "ui_overlap_dialog.h"

overlap_dialog::overlap_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::overlap_dialog)
{
    ui->setupUi(this);
    for(quint8 row = 1; row <= OverlapMax; row++)
    {
        ui->comboBox_OverlapNum->addItem(tr("%1").arg(row));
    }
    ui->comboBox_OverlapNum->setCurrentIndex(0);

    CheckBox_M[0] = ui->checkBox_M1;
    CheckBox_M[1] = ui->checkBox_M2;
    CheckBox_M[2] = ui->checkBox_M3;
    CheckBox_M[3] = ui->checkBox_M4;
    CheckBox_M[4] = ui->checkBox_M5;
    CheckBox_M[5] = ui->checkBox_M6;
    CheckBox_M[6] = ui->checkBox_M7;
    CheckBox_M[7] = ui->checkBox_M8;
    CheckBox_M[8] = ui->checkBox_M9;
    CheckBox_M[9] = ui->checkBox_M10;
    CheckBox_M[10] = ui->checkBox_M11;
    CheckBox_M[11] = ui->checkBox_M12;
    CheckBox_M[12] = ui->checkBox_M13;
    CheckBox_M[13] = ui->checkBox_M14;
    CheckBox_M[14] = ui->checkBox_M15;
    CheckBox_M[15] = ui->checkBox_M16;

    CheckBox_S[0] = ui->checkBox_S1;
    CheckBox_S[1] = ui->checkBox_S2;
    CheckBox_S[2] = ui->checkBox_S3;
    CheckBox_S[3] = ui->checkBox_S4;
    CheckBox_S[4] = ui->checkBox_S5;
    CheckBox_S[5] = ui->checkBox_S6;
    CheckBox_S[6] = ui->checkBox_S7;
    CheckBox_S[7] = ui->checkBox_S8;
    CheckBox_S[8] = ui->checkBox_S9;
    CheckBox_S[9] = ui->checkBox_S10;
    CheckBox_S[10] = ui->checkBox_S11;
    CheckBox_S[11] = ui->checkBox_S12;
    CheckBox_S[12] = ui->checkBox_S13;
    CheckBox_S[13] = ui->checkBox_S14;
    CheckBox_S[14] = ui->checkBox_S15;
    CheckBox_S[15] = ui->checkBox_S16;
}

void overlap_dialog::OverlapDataInit(OverlapType Overlap)
{
    if(Overlap.Num > 0)
    {
        ui->comboBox_OverlapNum->setEnabled(false);
        ui->comboBox_OverlapNum->setCurrentIndex(Overlap.Num-1);
        ui->comboBox_type->setCurrentIndex(Overlap.Type-1);

        ui->spinBox_Green->setValue(Overlap.TrailGreen);
        ui->spinBox_GreenFlash->setValue(Overlap.TrailClear);
        ui->spinBox_Yellow->setValue(Overlap.TrailYellow);
        ui->spinBox_AllRed->setValue(Overlap.TrailRed);

        quint16 temp = 0x0001;
        for(quint8 i=0; i<16; i++)
        {
            if(Overlap.IncludedPhases & temp)
                CheckBox_S[i]->setChecked(true);
            else
                CheckBox_S[i]->setChecked(false);

            if(Overlap.ModifierPhases & temp)
                CheckBox_M[i]->setChecked(true);
            else
                CheckBox_M[i]->setChecked(false);
            temp <<= 1;
        }
    }
    else
    {
        ui->comboBox_OverlapNum->setEnabled(true);
        ui->comboBox_OverlapNum->setCurrentIndex(0);

        ui->spinBox_Green->setValue(0);
        ui->spinBox_Yellow->setValue(0);
        ui->spinBox_AllRed->setValue(0);
        for(quint8 i=0; i<16; i++)
        {
            CheckBox_S[i]->setChecked(false);
            CheckBox_M[i]->setChecked(false);
        }
    }
}

void overlap_dialog::on_pushButton_confirm_clicked()
{
    OverlapType Overlap;
    Overlap.Num = ui->comboBox_OverlapNum->currentIndex()+1;
    Overlap.Type = ui->comboBox_type->currentIndex()+1;

    Overlap.TrailGreen = ui->spinBox_Green->value();
    Overlap.TrailClear = ui->spinBox_GreenFlash->value();
    Overlap.TrailYellow = ui->spinBox_Yellow->value();
    Overlap.TrailRed = ui->spinBox_AllRed->value();

    quint16 temp = 0x0001;
    Overlap.IncludedPhases = 0;
    Overlap.ModifierPhases = 0;
    for(quint8 i=0; i<16; i++)
    {
        if(CheckBox_S[i]->isChecked())Overlap.IncludedPhases |= temp;
        if(CheckBox_M[i]->isChecked())Overlap.ModifierPhases |= temp;
        temp <<= 1;
    }

    emit OverlapDataSend(Overlap);
    this->accept();
}

void overlap_dialog::on_pushButton_cancel_clicked()
{
    this->accept();
}

void overlap_dialog::closeEvent(QCloseEvent *e)
{
    e->accept();
}

overlap_dialog::~overlap_dialog()
{
    delete ui;
}
