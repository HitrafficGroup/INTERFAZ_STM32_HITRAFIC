#include "sequence_dialog.h"
#include "ui_sequence_dialog.h"

sequence_dialog::sequence_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::sequence_dialog)
{
    ui->setupUi(this);
    for(quint8 n = 0; n < 16; n++)
    {
        ui->comboBox_Phase->addItem(tr("%1").arg(n+1));
    }
    ui->listSequence->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->listSequence->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void sequence_dialog::closeEvent(QCloseEvent *e)
{
    e->accept();
}

sequence_dialog::~sequence_dialog()
{
    delete ui;
}
void sequence_dialog::selectSequenceList(void)
{

}
void sequence_dialog::SequenceDataInit(SequenceType sequence)
{
    ui->spinBox_Ring->setValue(sequence.RingNum);
    quint8 row = 0;
    for(quint8 n = 0; n < 16; n++)
    {
        if(sequence.Phase[n]>0) row++;
    }
    SequenceModel = new QStandardItemModel(row,1);
    ui->listSequence->setModel(SequenceModel);

    for(quint8 n = 0; n<row; n++)
    {
        SequenceModel->setData(SequenceModel->index(n, 0), QVariant(sequence.Phase[n]));
    }
}

void sequence_dialog::on_pushButton_confirm_clicked()
{
    bool ringEmpty = true;
    SequenceType sequence;
    sequence.RingNum = ui->spinBox_Ring->value();
    for(quint8 n = 0; n<16; n++)
    {
        sequence.Phase[n] = SequenceModel->data(SequenceModel->index(n,0)).toInt();
        if(sequence.Phase[n] > 0)ringEmpty = false;
    }
    if(ringEmpty == true)
    {
        //sequence.RingNum = 0;
        qDebug()<<"ringEmpty";
    }
    emit SequenceDataSend(sequence);
    this->accept();
}

void sequence_dialog::on_pushButton_cancel_clicked()
{
    this->accept();
}

void sequence_dialog::on_pushButton_up_clicked()
{
    quint8 selectRow = ui->listSequence->currentIndex().row();

    if(selectRow>0)
    {
        quint8 phase = SequenceModel->data(SequenceModel->index(selectRow,0)).toInt();
        QStandardItem *item = new QStandardItem(QString("%1").arg(phase));
        SequenceModel->removeRow(selectRow);
        SequenceModel->insertRow(selectRow-1,item);

        QModelIndex index = SequenceModel->index(selectRow-1,0);
        ui->listSequence->setCurrentIndex(index);
    }
}

void sequence_dialog::on_pushButton_down_clicked()
{
    quint8 selectRow = ui->listSequence->currentIndex().row();

    if(selectRow < SequenceModel->rowCount()-1)
    {
        quint8 phase = SequenceModel->data(SequenceModel->index(selectRow,0)).toInt();
        QStandardItem *item = new QStandardItem(QString("%1").arg(phase));
        SequenceModel->removeRow(selectRow);
        SequenceModel->insertRow(selectRow+1,item);

        QModelIndex index = SequenceModel->index(selectRow+1,0);
        ui->listSequence->setCurrentIndex(index);
    }
}

void sequence_dialog::on_pushButton_addPhase_clicked()
{
    qint8 selectRow = ui->listSequence->currentIndex().row();
    quint8 phase = ui->comboBox_Phase->currentIndex()+1;
    QStandardItem *item = new QStandardItem(QString("%1").arg(phase));
    if(selectRow >= 0 && selectRow < 15)
        SequenceModel->insertRow(selectRow+1,item);
    else
        SequenceModel->insertRow(0,item);
    QModelIndex index = SequenceModel->index(selectRow+1,0);
    ui->listSequence->setCurrentIndex(index);
}

void sequence_dialog::on_pushButton_deletePhase_clicked()
{
    qint8 selectRow = ui->listSequence->currentIndex().row();
    SequenceModel->removeRow(selectRow);
}
