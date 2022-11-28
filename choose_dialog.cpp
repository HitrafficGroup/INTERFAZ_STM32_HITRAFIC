#include "choose_dialog.h"
#include "ui_choose_dialog.h"

choose_dialog::choose_dialog(QWidget *parent) :QDialog(parent), ui(new Ui::choose_dialog)
{
    ui->setupUi(this);
    CheckBoxPoint();
}
choose_dialog::~choose_dialog()
{
    delete ui;
}
void choose_dialog::closeEvent(QCloseEvent *e)
{
    e->accept();
}

void choose_dialog::CheckBoxPoint(void)
{
    checkBox[0] = ui->checkBox1;
    checkBox[1] = ui->checkBox2;
    checkBox[2] = ui->checkBox3;
    checkBox[3] = ui->checkBox4;
    checkBox[4] = ui->checkBox5;
    checkBox[5] = ui->checkBox6;
    checkBox[6] = ui->checkBox7;
    checkBox[7] = ui->checkBox8;
    checkBox[8] = ui->checkBox9;
    checkBox[9] = ui->checkBox10;
    checkBox[10] = ui->checkBox11;
    checkBox[11] = ui->checkBox12;
    checkBox[12] = ui->checkBox13;
    checkBox[13] = ui->checkBox14;
    checkBox[14] = ui->checkBox15;
    checkBox[15] = ui->checkBox16;

    checkBox[16] = ui->checkBox17;
    checkBox[17] = ui->checkBox18;
    checkBox[18] = ui->checkBox19;
    checkBox[19] = ui->checkBox20;
    checkBox[20] = ui->checkBox21;
    checkBox[21] = ui->checkBox22;
    checkBox[22] = ui->checkBox23;
    checkBox[23] = ui->checkBox24;
    checkBox[24] = ui->checkBox25;
    checkBox[25] = ui->checkBox26;
    checkBox[26] = ui->checkBox27;
    checkBox[27] = ui->checkBox28;
    checkBox[28] = ui->checkBox29;
    checkBox[29] = ui->checkBox30;
    checkBox[30] = ui->checkBox31;
    checkBox[31] = ui->checkBox32;

    connect(ui->checkBoxCol1,SIGNAL(stateChanged(int)),this,SLOT(checkBoxCol1StateChanged(int)));
    connect(ui->checkBoxCol2,SIGNAL(stateChanged(int)),this,SLOT(checkBoxCol2StateChanged(int)));
    connect(ui->checkBoxCol3,SIGNAL(stateChanged(int)),this,SLOT(checkBoxCol3StateChanged(int)));
    connect(ui->checkBoxCol4,SIGNAL(stateChanged(int)),this,SLOT(checkBoxCol4StateChanged(int)));
}


void choose_dialog::ChooseDataInit(quint32 choose_data)
{
    ui->checkBoxCol1->setChecked(false);
    ui->checkBoxCol2->setChecked(false);
    ui->checkBoxCol3->setChecked(false);
    ui->checkBoxCol4->setChecked(false);

    quint32 temp_var = 0x01;
    for(quint8 i=0; i<32; i++)
    {
        checkBox[i]->setChecked(choose_data & temp_var);
        temp_var <<= 0x01;
    }
}

void choose_dialog::on_pushButton_confirm_clicked()
{
    quint32 temp_var = 0x01;
    quint32 choose_data = 0;

    for(quint8 i=0; i<32; i++)
    {
        if(checkBox[i]->isChecked()) choose_data |= temp_var;
        else choose_data &= ~temp_var;
        temp_var <<= 0x01;
    }

    emit ChooseDataSendSignal(choose_data);
    this->accept();
}

void choose_dialog::on_pushButton_cancel_clicked()
{
    this->accept();
}

void choose_dialog::checkBoxCol1StateChanged(int state)
{
    for(quint8 row=0;row<8;row++)
    {
        checkBox[row]->setChecked(state);
    }
}
void choose_dialog::checkBoxCol2StateChanged(int state)
{
    for(quint8 row=8;row<16;row++)
    {
        checkBox[row]->setChecked(state);
    }
}
void choose_dialog::checkBoxCol3StateChanged(int state)
{
    for(quint8 row=16;row<24;row++)
    {
        checkBox[row]->setChecked(state);
    }
}
void choose_dialog::checkBoxCol4StateChanged(int state)
{
    for(quint8 row=24;row<32;row++)
    {
        checkBox[row]->setChecked(state);
    }
}
