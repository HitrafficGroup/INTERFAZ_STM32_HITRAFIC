#ifndef schedule_dialog_H
#define schedule_dialog_H

#include <QDialog>
#include <QtCore>
#include <QCloseEvent>
#include <QCheckBox>
#include <QMessageBox>
#include "tsc.h"


namespace Ui {class schedule_dialog;}

class schedule_dialog : public QDialog
{
    Q_OBJECT

public:
    schedule_dialog(QWidget *parent = 0);
    ~schedule_dialog();

protected:
    void closeEvent(QCloseEvent *e);

signals:
    void ScheduleDataSend(Schedule);

private slots:
    void monthSelectAll();
    void daySelectAll();
    void date1SelectAll();
    void date2SelectAll();
    void date3SelectAll();
    void date4SelectAll();
    void ScheduleDataInit(Schedule schedule);
    void on_pushButton_confirm_clicked();
    void on_pushButton_cancel_clicked();

private:
    Ui::schedule_dialog *ui;
    QCheckBox *CheckBox_Month[12];
    QCheckBox *CheckBox_Day[7];
    QCheckBox *CheckBox_Date[31];
};


#endif // schedule_dialog_H
