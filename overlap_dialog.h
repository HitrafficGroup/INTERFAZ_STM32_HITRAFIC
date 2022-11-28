#ifndef overlap_dialog_H
#define overlap_dialog_H

#include <QDialog>
#include <QtCore>
#include <QCheckBox>
#include <QCloseEvent>

#include "tsc.h"


namespace Ui {class overlap_dialog;}

class overlap_dialog : public QDialog
{
    Q_OBJECT

public:
    overlap_dialog(QWidget *parent = 0);
    ~overlap_dialog();

protected:
    void closeEvent(QCloseEvent *e);

signals:
    void OverlapDataSend(OverlapType);

private slots:
    void OverlapDataInit(OverlapType Overlap);

    void on_pushButton_confirm_clicked();
    void on_pushButton_cancel_clicked();

private:
    Ui::overlap_dialog *ui;
    QCheckBox *CheckBox_S[16];
    QCheckBox *CheckBox_M[16];
};


#endif // overlap_dialog_H
