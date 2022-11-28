#ifndef peddet_dialog_H
#define peddet_dialog_H

#include <QDialog>
#include <QtCore>
#include <QCloseEvent>
#include <QMessageBox>
#include "tsc.h"


namespace Ui {class peddet_dialog;}

class peddet_dialog : public QDialog
{
    Q_OBJECT

public:
    peddet_dialog(QWidget *parent = 0);
    ~peddet_dialog();

protected:
    void closeEvent(QCloseEvent *e);

signals:
    void PeddetDataSend(Peddet);

private slots:
    void PeddetDataInit(Peddet peddet);
    void on_pushButton_confirm_clicked();
    void on_pushButton_cancel_clicked();

private:
    Ui::peddet_dialog *ui;
    Peddet peddet_temp;
};


#endif // split_dialog_H
