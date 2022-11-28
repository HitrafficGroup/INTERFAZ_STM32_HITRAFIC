#ifndef action_dialog_H
#define action_dialog_H

#include <QDialog>
#include <QtCore>
#include <QCloseEvent>
#include "tsc.h"


namespace Ui {class action_dialog;}

class action_dialog : public QDialog
{
    Q_OBJECT

public:
    action_dialog(QWidget *parent = 0);
    ~action_dialog();

protected:
    void closeEvent(QCloseEvent *e);

signals:
    void ActionDataSend(ActionType);

private slots:
    void ActionDataInit(ActionType Action);
    void on_pushButton_confirm_clicked();
    void on_pushButton_cancel_clicked();

private:
    Ui::action_dialog *ui;

};


#endif // action_dialog_H
