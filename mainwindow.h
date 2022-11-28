#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMdiArea>
#include <QMdiSubWindow>

#include "main_dialog.h"
#include "connect_dialog.h"

namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:

signals:
    void NewParNameSend(QString);
private slots:
    void setStatusBar(QString str);
    void on_actionSave_triggered();
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionConnect_triggered();
    void on_actionTileWin_triggered();

private:
    Ui::MainWindow  *ui;
    QMdiArea        *mdiArea;

    QMdiSubWindow   *SubWinCon;
    connect_dialog  *connect_dlg;
    bool subwindisplay;
};


#endif // MAINWINDOW_H
