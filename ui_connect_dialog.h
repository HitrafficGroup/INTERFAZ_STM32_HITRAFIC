/********************************************************************************
** Form generated from reading UI file 'connect_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECT_DIALOG_H
#define UI_CONNECT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_connect_dialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QTreeView *treeView_Area;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableOnline;
    QWidget *tab_2;

    void setupUi(QDialog *connect_dialog)
    {
        if (connect_dialog->objectName().isEmpty())
            connect_dialog->setObjectName(QStringLiteral("connect_dialog"));
        connect_dialog->resize(691, 391);
        connect_dialog->setMinimumSize(QSize(500, 300));
        verticalLayout = new QVBoxLayout(connect_dialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(connect_dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        treeView_Area = new QTreeView(tab);
        treeView_Area->setObjectName(QStringLiteral("treeView_Area"));

        verticalLayout_2->addWidget(treeView_Area);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tableOnline = new QTableView(tab_3);
        tableOnline->setObjectName(QStringLiteral("tableOnline"));

        verticalLayout_3->addWidget(tableOnline);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(connect_dialog);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(connect_dialog);
    } // setupUi

    void retranslateUi(QDialog *connect_dialog)
    {
        connect_dialog->setWindowTitle(QApplication::translate("connect_dialog", "\344\277\241\345\217\267\346\234\272\347\275\221\347\273\234\347\256\241\347\220\206", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("connect_dialog", "\345\214\272\345\237\237\347\256\241\347\220\206", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("connect_dialog", "\345\234\250\347\272\277\346\220\234\347\264\242", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("connect_dialog", "\344\277\241\345\217\267\346\234\272\347\275\221\347\273\234\347\212\266\346\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class connect_dialog: public Ui_connect_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECT_DIALOG_H
