#ifndef split_dialog_H
#define split_dialog_H

#include <QDialog>
#include <QtCore>
#include <QCloseEvent>
#include <QMessageBox>
#include "tsc.h"


namespace Ui {class split_dialog;}

class split_dialog : public QDialog
{
    Q_OBJECT

public:
    split_dialog(QWidget *parent = 0);
    ~split_dialog();

protected:
    void closeEvent(QCloseEvent *e);

signals:
    void SplitDataSend(Split);

private slots:
    void SplitDataInit(Split split);
    void on_pushButton_confirm_clicked();
    void on_pushButton_cancel_clicked();

private:
    Ui::split_dialog *ui;
    Split split_temp;
};


#endif // split_dialog_H
