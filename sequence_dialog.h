#ifndef sequence_dialog_H
#define sequence_dialog_H

#include <QDialog>
#include <QtCore>
#include <QCloseEvent>
#include <QStandardItemModel>
#include "tsc.h"


namespace Ui {class sequence_dialog;}

class sequence_dialog : public QDialog
{
    Q_OBJECT

public:
    sequence_dialog(QWidget *parent = 0);
    ~sequence_dialog();

protected:
    void closeEvent(QCloseEvent *e);

signals:
    void SequenceDataSend(SequenceType);

private slots:
    void selectSequenceList(void);

    void SequenceDataInit(SequenceType sequence);
    void on_pushButton_confirm_clicked();
    void on_pushButton_cancel_clicked();
    void on_pushButton_up_clicked();
    void on_pushButton_down_clicked();
    void on_pushButton_addPhase_clicked();

    void on_pushButton_deletePhase_clicked();

private:
    Ui::sequence_dialog *ui;
    QStandardItemModel *SequenceModel;
};


#endif // sequence_dialog_H
