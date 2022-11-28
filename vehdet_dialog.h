#ifndef vehdet_dialog_H
#define vehdet_dialog_H

#include <QDialog>
#include <QtCore>
#include <QCloseEvent>
#include "tsc.h"


namespace Ui {class vehdet_dialog;}

class vehdet_dialog : public QDialog
{
    Q_OBJECT

public:
    vehdet_dialog(QWidget *parent = 0);
    ~vehdet_dialog();

protected:
    void closeEvent(QCloseEvent *e);

signals:
    void VehdetDataSend(Vehdet);

private slots:
    void VehdetDataInit(Vehdet vehdet);
    void on_pushButton_confirm_clicked();
    void on_pushButton_cancel_clicked();

private:
    Ui::vehdet_dialog *ui;
    Vehdet vehdet_Temp;
};


#endif //vehdet_dialog_H
