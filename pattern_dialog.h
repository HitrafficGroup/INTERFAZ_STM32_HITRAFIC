#ifndef pattern_dialog_H
#define pattern_dialog_H

#include <QDialog>
#include <QtCore>
#include <QCloseEvent>
#include <QMessageBox>
#include "tsc.h"


namespace Ui {class pattern_dialog;}

class pattern_dialog : public QDialog
{
    Q_OBJECT

public:
    pattern_dialog(QWidget *parent = 0);
    ~pattern_dialog();
    QString WorkModeStr(quint8 mode);

protected:
    void closeEvent(QCloseEvent *e);

signals:
    void PatternDataSend(PatternType);

private slots:
    void PatternDataInit(PatternType pattern);
    void on_pushButton_confirm_clicked();
    void on_pushButton_cancel_clicked();

private:
    Ui::pattern_dialog *ui;
};


#endif // pattern_dialog_H
