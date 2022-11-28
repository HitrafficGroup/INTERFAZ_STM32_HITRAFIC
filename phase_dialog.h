#ifndef phase_dialog_H
#define phase_dialog_H

#include <QDialog>
#include <QtCore>
#include <QCloseEvent>
#include "choose_dialog.h"
#include "tsc.h"


namespace Ui {class phase_dialog;}

class phase_dialog : public QDialog
{
    Q_OBJECT

public:
    phase_dialog(QWidget *parent = 0);
    ~phase_dialog();

protected:
    void closeEvent(QCloseEvent *e);

signals:
    void PhaseDataSend(Phase);
    void ChooseDataSend(quint32);
    void ChooseDataGet();

private slots:
    void PhaseDataInit(Phase phase);
    void ChooseDataReceive(quint32 choose_data);

    void on_pushButton_confirm_clicked();
    void on_pushButton_cancel_clicked();
    void on_pushButton_phaseConcurrency_clicked();

private:
    Ui::phase_dialog *ui;
    choose_dialog *choose_dlg;

    quint32 choosedata;
};


#endif // phase_dialog_H
