#include "pattern_dialog.h"
#include "ui_pattern_dialog.h"

pattern_dialog::pattern_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::pattern_dialog)
{
    ui->setupUi(this);
    for(quint16 row = 1; row <= PatternMax; row++)
    {
        ui->comboBox_Pattern->addItem(tr("%1").arg(row));
    }
    for(quint16 row = 1; row <= SplitMax; row++)
    {
        ui->comboBox_SplitNumber->addItem(tr("%1").arg(row));
    }
    ui->comboBox_SplitNumber->setCurrentIndex(0);

    //QVariant flags(0);
    //ui->comboBox_WorkMode->setItemData(2, flags, Qt::UserRole - 1);
}

void pattern_dialog::closeEvent(QCloseEvent *e)
{
    e->accept();
}

pattern_dialog::~pattern_dialog()
{
    delete ui;
}

QString pattern_dialog::WorkModeStr(quint8 mode)
{
    QString Str;

    if(mode == FixedTime)Str = "定周期";
    else if(mode == LineCtrl)Str = "绿波控制";
    else if(mode == VehicleSense)Str = "感应控制";
    else if(mode == Flashing)Str = "闪光控制";
    else if(mode == AllRed)Str = "全红模式";
    else if(mode == LampOff)Str = "关灯模式";
    return Str;
}

void pattern_dialog::PatternDataInit(PatternType pattern)
{
    ui->comboBox_Pattern->setCurrentIndex(pattern.Number-1);
    ui->lineEdit_CycleTime->setText(tr("%1").arg(pattern.CycleTime));
    ui->spinBox_OffsetTime->setValue(pattern.OffsetTime);
    ui->comboBox_SplitNumber->setCurrentIndex(pattern.SplitNumber-1);
    ui->spinBox_SequenceNumber->setValue(pattern.SequenceNumber);
    ui->comboBox_WorkMode->setCurrentText(WorkModeStr(pattern.WorkMode));

    if(pattern.Number > 0)ui->comboBox_Pattern->setEnabled(false);
    else ui->comboBox_Pattern->setEnabled(true);
}

void pattern_dialog::on_pushButton_confirm_clicked()
{
    PatternType pattern;
    pattern.Number = ui->comboBox_Pattern->currentIndex()+1;
    pattern.CycleTime = ui->lineEdit_CycleTime->text().toInt();
    pattern.OffsetTime = ui->spinBox_OffsetTime->value();
    pattern.SplitNumber = ui->comboBox_SplitNumber->currentIndex()+1;
    pattern.SequenceNumber = ui->spinBox_SequenceNumber->value();

    if(ui->comboBox_WorkMode->currentText() == tr("定周期"))pattern.WorkMode = FixedTime;
    else if(ui->comboBox_WorkMode->currentText() == tr("绿波控制"))pattern.WorkMode = LineCtrl;
    else if(ui->comboBox_WorkMode->currentText() == tr("感应控制"))pattern.WorkMode = VehicleSense;
    else if(ui->comboBox_WorkMode->currentText() == tr("闪光控制"))pattern.WorkMode = Flashing;
    else if(ui->comboBox_WorkMode->currentText() == tr("全红模式"))pattern.WorkMode = AllRed;
    else if(ui->comboBox_WorkMode->currentText() == tr("关灯模式"))pattern.WorkMode = LampOff;

    qDebug() << "pattern.WorkMode = " << pattern.WorkMode;

    if(pattern.Number > 0 && pattern.SplitNumber > 0 && pattern.SequenceNumber > 0)
        emit PatternDataSend(pattern);
    else
    {
        QMessageBox::warning(this, tr("警告"), tr("方案号，绿信比，相序表不能为空!"), QMessageBox::Ok);
        return;
    }
    this->accept();
}

void pattern_dialog::on_pushButton_cancel_clicked()
{
    this->accept();
}
