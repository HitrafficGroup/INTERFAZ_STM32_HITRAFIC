#ifndef choose_dialog_H
#define choose_dialog_H

#include <QDialog>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QtCore>
#include <QCloseEvent>
#include "tsc.h"


namespace Ui { class choose_dialog;}

class choose_dialog : public QDialog
{
    Q_OBJECT

public:
    choose_dialog(QWidget *parent = 0);
    ~choose_dialog();

protected:
    void closeEvent(QCloseEvent *e);
    void CheckBoxPoint(void);
signals:
    void ChooseDataSendSignal(quint32);

public slots:
    void on_pushButton_confirm_clicked();
    void on_pushButton_cancel_clicked();

private slots:
    void ChooseDataInit(quint32 choose_data);

    void checkBoxCol1StateChanged(int state);
    void checkBoxCol2StateChanged(int state);
    void checkBoxCol3StateChanged(int state);
    void checkBoxCol4StateChanged(int state);

private:
    Ui::choose_dialog *ui;

    QCheckBox *checkBox[32];

};


#endif //choose_dialog_H
