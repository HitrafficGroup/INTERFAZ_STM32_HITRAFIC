#include "phase_dialog.h"
#include "ui_phase_dialog.h"

phase_dialog::phase_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::phase_dialog)
{
    ui->setupUi(this);
    for(quint8 row = 1; row <= PhaseMax; row++)
    {
        ui->comboBox_Phase->addItem(tr("%1").arg(row));
    }
    ui->comboBox_Phase->setCurrentIndex(0);
    ui->comboBox_Ring->setCurrentIndex(0);
    ui->comboBox_Ring->hide();//相位属于环的编辑，放在相序表当中自动匹配
    ui->label_Ring->hide();

    choose_dlg = new choose_dialog(this);//新建选择对话框
    connect(choose_dlg, SIGNAL(ChooseDataSendSignal(quint32)),this,SLOT(ChooseDataReceive(quint32)));//
    connect(this, SIGNAL(ChooseDataSend(quint32)),choose_dlg, SLOT(ChooseDataInit(quint32)));
}
phase_dialog::~phase_dialog()
{
    delete ui;
}
void phase_dialog::closeEvent(QCloseEvent *e)
{
    e->accept();
}

void phase_dialog::PhaseDataInit(Phase phase)
{
    if(phase.Number > 0)
    {
        ui->comboBox_Phase->setCurrentIndex(phase.Number-1);
        ui->comboBox_Phase->setDisabled(true);
    }
    else
    {
        ui->comboBox_Phase->setDisabled(false);
    }
    if(phase.Ring > 0)
        ui->comboBox_Ring->setCurrentIndex(phase.Ring-1);
    else
        ui->comboBox_Ring->setCurrentIndex(0);

    ui->sp_Walk->setValue(phase.Walk);
    ui->sp_PedestrianClear->setValue(phase.PedestrianClear);
    ui->sp_MinimumGreen->setValue(phase.MinimumGreen);
    ui->sp_Passage->setValue(phase.Passage);
    ui->sp_Maximum1->setValue(phase.Maximum1);
    ui->sp_Maximum2->setValue(phase.Maximum2);
    ui->sp_VehicleClear->setValue(phase.VehicleClear);
    ui->sp_YellowChange->setValue(phase.YellowChange);
    ui->sp_RedClear->setValue(phase.RedClear);
    ui->sp_RedRevert->setValue(phase.RedRevert);
    ui->sp_AddedInitial->setValue(phase.AddedInitial);
    ui->sp_MaximumInitial->setValue(phase.MaximumInitial);
    ui->sp_TimeBeforeReduction->setValue(phase.TimeBeforeReduction);
    ui->sp_CarsBeforeReduction->setValue(phase.CarsBeforeReduction);
    ui->sp_TimeToReduce->setValue(phase.TimeToReduce);
    ui->sp_ReduceBy->setValue(phase.ReduceBy);
    ui->sp_MinimumGap->setValue(phase.MinimumGap);
    ui->sp_DynamicMaxLimit->setValue(phase.DynamicMaxLimit);
    ui->sp_DynamicMaxStep->setValue(phase.DynamicMaxStep);

    if(phase.Startup == 0)
        ui->comboBox_Startup->setCurrentIndex(0);
    else //if(phase.Startup-1 < (ui->comboBox_Startup->size()))
        ui->comboBox_Startup->setCurrentIndex(phase.Startup-1);

    //quint16  Options;
    if(phase.Options & 0x2000)ui->checkBox_KeepPedRelease->setChecked(true);
    else ui->checkBox_KeepPedRelease->setChecked(false);

    QString phaseConcurrencyStr;
    choosedata = phase.Concurrency;

    quint32 temp_var = 0x01;
    for(quint8 row=1; row<=32; row++)
    {
        if(choosedata & temp_var) phaseConcurrencyStr +=tr("%1,").arg(row);
        temp_var <<= 0x01;
    }

    ui->lineEdit_phaseConcurrency->setText(phaseConcurrencyStr);
}

void phase_dialog::on_pushButton_confirm_clicked()
{
    Phase phase;

    phase.Number = ui->comboBox_Phase->currentText().toInt(); //currentIndex()+1;
    phase.Walk = ui->sp_Walk->value();
    phase.PedestrianClear = ui->sp_PedestrianClear->value();
    phase.MinimumGreen = ui->sp_MinimumGreen->value();
    phase.Passage = ui->sp_Passage->value();
    phase.Maximum1 = ui->sp_Maximum1->value();
    phase.Maximum2 = ui->sp_Maximum2->value();
    phase.VehicleClear = ui->sp_VehicleClear->value();
    phase.YellowChange = ui->sp_YellowChange->value();
    phase.RedClear = ui->sp_RedClear->value();
    phase.RedRevert = ui->sp_RedRevert->value();
    phase.AddedInitial = ui->sp_AddedInitial->value();
    phase.MaximumInitial = ui->sp_MaximumInitial->value();
    phase.TimeBeforeReduction = ui->sp_TimeBeforeReduction->value();
    phase.CarsBeforeReduction = ui->sp_CarsBeforeReduction->value();
    phase.TimeToReduce = ui->sp_TimeToReduce->value();
    phase.ReduceBy = ui->sp_ReduceBy->value();
    phase.MinimumGap = ui->sp_MinimumGap->value();
    phase.DynamicMaxLimit = ui->sp_DynamicMaxLimit->value();
    phase.DynamicMaxStep = ui->sp_DynamicMaxStep->value();
    phase.Startup = ui->comboBox_Startup->currentIndex()+1;


    phase.Ring = ui->comboBox_Ring->currentText().toInt(); //currentIndex()+1;

    phase.Options = 0;
    if(ui->checkBox_KeepPedRelease->isChecked()) phase.Options |= 0x2000;

    phase.Concurrency = choosedata;
    phase.ReleasePhase = 0;

    emit PhaseDataSend(phase);
    this->accept();
}
void phase_dialog::on_pushButton_cancel_clicked()
{
    this->accept();
}
void phase_dialog::on_pushButton_phaseConcurrency_clicked()
{
    emit ChooseDataSend(choosedata);

    choose_dlg->setWindowFlags(windowFlags()&~(Qt::CustomizeWindowHint|Qt::WindowContextHelpButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint));
    choose_dlg->setFixedSize(260,280);
    choose_dlg->setModal(true);//设置当前窗口为模态对话框
    choose_dlg->show();
}
void phase_dialog::ChooseDataReceive(quint32 choose_data)
{    
    QString phaseConcurrencyStr;
    choosedata = choose_data;

    quint32 temp_var = 0x01;
    for(quint8 row=1; row<=32; row++)
    {
        if(choosedata & temp_var) phaseConcurrencyStr +=tr("%1,").arg(row);
        temp_var <<= 0x01;
    }

    ui->lineEdit_phaseConcurrency->setText(phaseConcurrencyStr);
}

