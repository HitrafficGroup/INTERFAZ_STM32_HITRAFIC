/********************************************************************************
** Form generated from reading UI file 'plan_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAN_DIALOG_H
#define UI_PLAN_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_plan_dialog
{
public:
    QLabel *label;
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_cancel;
    QLabel *label_3;
    QTimeEdit *timeEdit;
    QComboBox *comboBox_Action;

    void setupUi(QDialog *plan_dialog)
    {
        if (plan_dialog->objectName().isEmpty())
            plan_dialog->setObjectName(QStringLiteral("plan_dialog"));
        plan_dialog->resize(250, 180);
        label = new QLabel(plan_dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 80, 71, 26));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pushButton_confirm = new QPushButton(plan_dialog);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        pushButton_confirm->setGeometry(QRect(30, 130, 90, 28));
        pushButton_cancel = new QPushButton(plan_dialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(140, 130, 90, 28));
        label_3 = new QLabel(plan_dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 30, 71, 26));
        timeEdit = new QTimeEdit(plan_dialog);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(110, 30, 101, 26));
        comboBox_Action = new QComboBox(plan_dialog);
        comboBox_Action->setObjectName(QStringLiteral("comboBox_Action"));
        comboBox_Action->setGeometry(QRect(110, 80, 101, 26));

        retranslateUi(plan_dialog);

        QMetaObject::connectSlotsByName(plan_dialog);
    } // setupUi

    void retranslateUi(QDialog *plan_dialog)
    {
        plan_dialog->setWindowTitle(QApplication::translate("plan_dialog", "\346\227\266\346\256\265\347\274\226\350\276\221", 0));
        label->setText(QApplication::translate("plan_dialog", "\345\212\250 \344\275\234 \345\217\267:", 0));
        pushButton_confirm->setText(QApplication::translate("plan_dialog", "\347\241\256\345\256\232", 0));
        pushButton_cancel->setText(QApplication::translate("plan_dialog", "\345\217\226\346\266\210", 0));
        label_3->setText(QApplication::translate("plan_dialog", "\350\265\267\345\247\213\346\227\266\351\227\264:", 0));
        timeEdit->setDisplayFormat(QApplication::translate("plan_dialog", "HH:mm", 0));
    } // retranslateUi

};

namespace Ui {
    class plan_dialog: public Ui_plan_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAN_DIALOG_H
