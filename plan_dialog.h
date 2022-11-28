#ifndef plan_dialog_H
#define plan_dialog_H

#include <QDialog>
#include <QtCore>
#include <QCloseEvent>
#include "tsc.h"


namespace Ui {class plan_dialog;}

class plan_dialog : public QDialog
{
    Q_OBJECT

public:
    plan_dialog(QWidget *parent = 0);
    ~plan_dialog();

protected:
    void closeEvent(QCloseEvent *e);

signals:
    void PlanDataSend(Plan);

private slots:
    void PlanDataInit(Plan plan);
    void on_pushButton_confirm_clicked();
    void on_pushButton_cancel_clicked();

private:
    Ui::plan_dialog *ui;
    Plan PlanTemp;
};


#endif //Plan_dialog_H
