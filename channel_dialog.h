#ifndef CHANNEL_DIALOG_H
#define CHANNEL_DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QCloseEvent>
#include "tsc.h"


//控制类型CHANNEL_CONTROL_TYPE
typedef enum
{
    CCT_OTHER = 1,      //其他
    CCT_VEHICLE,        //机动
    CCT_PEDESTRIAN,     //行人
    CCT_OVERLAP,        //跟随
    CCT_FLASH,
    CCT_GREEN,
    CCT_RED,
}CHANNEL_CONTROL_TYPE;  //通道控制类型


namespace Ui {
    class channel_dialog;
}

class channel_dialog : public QDialog
{
    Q_OBJECT

public:
    channel_dialog(QWidget *parent = 0);
    ~channel_dialog();

protected:
    void closeEvent(QCloseEvent *e);

signals:
    void ChannelDataSend(Channel);

private slots:
    void ChannelDataInit(Channel channel);
    void on_pushButton_confirm_clicked();
    void on_pushButton_cancel_clicked();

private:
    Ui::channel_dialog *ui;

};


#endif // CHANNEL_DIALOG_H
