#include "connect_dialog.h"
#include "ui_connect_dialog.h"

connect_dialog::connect_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::connect_dialog)
{
    ui->setupUi(this);
    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
    ui->treeView_Area->setModel(model);
    /*
    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
    QTreeView *tree = new QTreeView(splitter);
    tree->setModel(model);
    */
}

void connect_dialog::closeEvent(QCloseEvent *e)
{
    e->accept();
    this->close();
}

connect_dialog::~connect_dialog()
{
    delete ui;
}
