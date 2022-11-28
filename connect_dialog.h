#ifndef connect_dialog_H
#define connect_dialog_H

#include <QDialog>
#include <QtCore>
#include <QCloseEvent>
#include <QFileSystemModel>

#include "tsc.h"


namespace Ui {class connect_dialog;}

class connect_dialog : public QDialog
{
    Q_OBJECT

public:
    connect_dialog(QWidget *parent = 0);
    ~connect_dialog();

protected:
    void closeEvent(QCloseEvent *e);

signals:
    //void ActionDataSend(ActionType);

private slots:
    //void ActionDataInit(ActionType Action);
    //void on_pushButton_confirm_clicked();
    //void on_pushButton_cancel_clicked();

private:
    Ui::connect_dialog *ui;

};


#endif // connect_dialog
