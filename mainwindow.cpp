#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mdiArea = new QMdiArea(this);
    this->setCentralWidget(mdiArea);
    //windowTitle
    on_actionOpen_triggered();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setStatusBar(QString str)
{
    ui->statusBar->showMessage(str, 4000);
}

void MainWindow::on_actionNew_triggered()
{
    if(QFile::exists("tsc.db") == false)
    {
        QMessageBox::critical(this, "error","¡El sistema de archivos está dañado!",QMessageBox::Yes,QMessageBox::Yes);
        return;
    }
    QString newtsc;
    for(int n=1;;n++)
    {
        if(QFile::exists(tr("tsc%1.db").arg(n)) == false)
        {
            newtsc = tr("tsc%1.db").arg(n);
            break;
        }
    }
    if(QFile::copy("tsc.db", newtsc))
    {
        main_dialog *newPar_dlg = new main_dialog(this);
        QMdiSubWindow *SubWinPar = mdiArea->addSubWindow(newPar_dlg);
        SubWinPar->setWindowState(Qt::WindowMaximized);
        connect(this,SIGNAL(NewParNameSend(QString)),newPar_dlg,SLOT(OpenDatabase(QString)));
        emit NewParNameSend(newtsc);
        SubWinPar->show();
    }
}

void MainWindow::on_actionSave_triggered()
{
    qDebug()<<"actionSave_triggered";
}

void MainWindow::on_actionOpen_triggered()
{
    //QString filename = QFileDialog::getOpenFileName(this, tr("加载配置文件"), 0, tr("*.db"));  //添加更多的文件类型
    QString filename = QDir::currentPath()+"/tsc.db";
    if(QFile::exists(filename) == false)
    {
        //QMessageBox::critical(this, "错误","文件损坏或者此文件不是信号参数文件！",QMessageBox::Yes,QMessageBox::Yes);
        qDebug()<<filename;
        return;
    }

    main_dialog *newPar_dlg = new main_dialog(this);
    QMdiSubWindow *SubWinPar = mdiArea->addSubWindow(newPar_dlg);
    SubWinPar->resize(QSize(600,480));
    SubWinPar->setWindowState(Qt::WindowMaximized);
    connect(this,SIGNAL(NewParNameSend(QString)),newPar_dlg,SLOT(OpenDatabase(QString)));
    connect(newPar_dlg,SIGNAL(setMainStatusBar(QString)),this,SLOT(setStatusBar(QString)));
    emit NewParNameSend(filename);

    SubWinPar->show();
    //mdiArea->setActiveSubWindow(SubWinPar);
    //SubWinPar->activateWindow();
    //SubWinPar->setFocus();
}

void MainWindow::on_actionConnect_triggered()
{
    connect_dialog *connect_dlg = new connect_dialog(this);
    QMdiSubWindow *SubWinCon = mdiArea->addSubWindow(connect_dlg);
    SubWinCon->setWindowState(Qt::WindowMaximized);
    SubWinCon->show();
    //SubWinCon->setFocus();
}

//QMdiArea为子窗口提供了两种内置布局策略:cascadeSubWindows()和tileSubWindows()。两者都是插槽，很容易连接到菜单项。
void MainWindow::on_actionTileWin_triggered()
{
    if(subwindisplay == true)
    {
        subwindisplay = false;
        mdiArea->tileSubWindows();
    }
    else
    {
        subwindisplay = true;
        mdiArea->cascadeSubWindows();
    }
}
