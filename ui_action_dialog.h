/********************************************************************************
** Form generated from reading UI file 'action_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTION_DIALOG_H
#define UI_ACTION_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_action_dialog
{
public:
    QLabel *label;
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_cancel;
    QLabel *label_3;
    QComboBox *comboBox_Action;
    QComboBox *comboBox_Pattern;
    QGroupBox *groupBox_Auxillary;
    QCheckBox *checkBox_A1;
    QCheckBox *checkBox_A2;
    QCheckBox *checkBox_A3;
    QCheckBox *checkBox_A4;
    QGroupBox *groupBox_Special;
    QCheckBox *checkBox_S1;
    QCheckBox *checkBox_S2;
    QCheckBox *checkBox_S5;
    QCheckBox *checkBox_S3;
    QCheckBox *checkBox_S4;
    QCheckBox *checkBox_S6;
    QCheckBox *checkBox_S7;
    QCheckBox *checkBox_S8;

    void setupUi(QDialog *action_dialog)
    {
        if (action_dialog->objectName().isEmpty())
            action_dialog->setObjectName(QStringLiteral("action_dialog"));
        action_dialog->resize(430, 340);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        action_dialog->setFont(font);
        label = new QLabel(action_dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 71, 26));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pushButton_confirm = new QPushButton(action_dialog);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        pushButton_confirm->setGeometry(QRect(230, 300, 90, 28));
        pushButton_cancel = new QPushButton(action_dialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(330, 300, 90, 28));
        label_3 = new QLabel(action_dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 60, 71, 26));
        comboBox_Action = new QComboBox(action_dialog);
        comboBox_Action->setObjectName(QStringLiteral("comboBox_Action"));
        comboBox_Action->setGeometry(QRect(90, 20, 81, 26));
        comboBox_Pattern = new QComboBox(action_dialog);
        comboBox_Pattern->setObjectName(QStringLiteral("comboBox_Pattern"));
        comboBox_Pattern->setGeometry(QRect(90, 60, 141, 26));
        groupBox_Auxillary = new QGroupBox(action_dialog);
        groupBox_Auxillary->setObjectName(QStringLiteral("groupBox_Auxillary"));
        groupBox_Auxillary->setEnabled(true);
        groupBox_Auxillary->setGeometry(QRect(10, 110, 411, 71));
        groupBox_Auxillary->setFont(font);
        groupBox_Auxillary->setMouseTracking(false);
        checkBox_A1 = new QCheckBox(groupBox_Auxillary);
        checkBox_A1->setObjectName(QStringLiteral("checkBox_A1"));
        checkBox_A1->setGeometry(QRect(40, 30, 51, 19));
        checkBox_A2 = new QCheckBox(groupBox_Auxillary);
        checkBox_A2->setObjectName(QStringLiteral("checkBox_A2"));
        checkBox_A2->setGeometry(QRect(110, 30, 51, 19));
        checkBox_A3 = new QCheckBox(groupBox_Auxillary);
        checkBox_A3->setObjectName(QStringLiteral("checkBox_A3"));
        checkBox_A3->setGeometry(QRect(180, 30, 51, 19));
        checkBox_A4 = new QCheckBox(groupBox_Auxillary);
        checkBox_A4->setObjectName(QStringLiteral("checkBox_A4"));
        checkBox_A4->setGeometry(QRect(250, 30, 151, 19));
        groupBox_Special = new QGroupBox(action_dialog);
        groupBox_Special->setObjectName(QStringLiteral("groupBox_Special"));
        groupBox_Special->setGeometry(QRect(10, 190, 411, 91));
        groupBox_Special->setContextMenuPolicy(Qt::NoContextMenu);
        groupBox_Special->setAcceptDrops(false);
        groupBox_Special->setAutoFillBackground(false);
        checkBox_S1 = new QCheckBox(groupBox_Special);
        checkBox_S1->setObjectName(QStringLiteral("checkBox_S1"));
        checkBox_S1->setGeometry(QRect(40, 30, 51, 19));
        checkBox_S2 = new QCheckBox(groupBox_Special);
        checkBox_S2->setObjectName(QStringLiteral("checkBox_S2"));
        checkBox_S2->setGeometry(QRect(110, 30, 51, 19));
        checkBox_S5 = new QCheckBox(groupBox_Special);
        checkBox_S5->setObjectName(QStringLiteral("checkBox_S5"));
        checkBox_S5->setGeometry(QRect(40, 60, 51, 19));
        checkBox_S3 = new QCheckBox(groupBox_Special);
        checkBox_S3->setObjectName(QStringLiteral("checkBox_S3"));
        checkBox_S3->setGeometry(QRect(180, 30, 51, 19));
        checkBox_S4 = new QCheckBox(groupBox_Special);
        checkBox_S4->setObjectName(QStringLiteral("checkBox_S4"));
        checkBox_S4->setGeometry(QRect(250, 30, 51, 19));
        checkBox_S6 = new QCheckBox(groupBox_Special);
        checkBox_S6->setObjectName(QStringLiteral("checkBox_S6"));
        checkBox_S6->setGeometry(QRect(110, 60, 51, 19));
        checkBox_S7 = new QCheckBox(groupBox_Special);
        checkBox_S7->setObjectName(QStringLiteral("checkBox_S7"));
        checkBox_S7->setGeometry(QRect(180, 60, 51, 19));
        checkBox_S8 = new QCheckBox(groupBox_Special);
        checkBox_S8->setObjectName(QStringLiteral("checkBox_S8"));
        checkBox_S8->setGeometry(QRect(250, 60, 51, 19));

        retranslateUi(action_dialog);

        QMetaObject::connectSlotsByName(action_dialog);
    } // setupUi

    void retranslateUi(QDialog *action_dialog)
    {
        action_dialog->setWindowTitle(QApplication::translate("action_dialog", "\345\212\250\344\275\234\347\274\226\350\276\221", 0));
        label->setText(QApplication::translate("action_dialog", "\345\212\250\344\275\234\345\217\267:", 0));
        pushButton_confirm->setText(QApplication::translate("action_dialog", "\347\241\256\345\256\232", 0));
        pushButton_cancel->setText(QApplication::translate("action_dialog", "\345\217\226\346\266\210", 0));
        label_3->setText(QApplication::translate("action_dialog", "\346\226\271\346\241\210:", 0));
        groupBox_Auxillary->setTitle(QApplication::translate("action_dialog", "\350\276\205\345\212\251\345\212\237\350\203\275", 0));
        checkBox_A1->setText(QApplication::translate("action_dialog", "1", 0));
        checkBox_A2->setText(QApplication::translate("action_dialog", "2", 0));
        checkBox_A3->setText(QApplication::translate("action_dialog", "3", 0));
        checkBox_A4->setText(QApplication::translate("action_dialog", "\350\276\211\345\272\246\350\260\203\350\212\202", 0));
        groupBox_Special->setTitle(QApplication::translate("action_dialog", "\347\211\271\346\256\212\345\212\237\350\203\275", 0));
        checkBox_S1->setText(QApplication::translate("action_dialog", "1", 0));
        checkBox_S2->setText(QApplication::translate("action_dialog", "2", 0));
        checkBox_S5->setText(QApplication::translate("action_dialog", "5", 0));
        checkBox_S3->setText(QApplication::translate("action_dialog", "3", 0));
        checkBox_S4->setText(QApplication::translate("action_dialog", "4", 0));
        checkBox_S6->setText(QApplication::translate("action_dialog", "6", 0));
        checkBox_S7->setText(QApplication::translate("action_dialog", "7", 0));
        checkBox_S8->setText(QApplication::translate("action_dialog", "8", 0));
    } // retranslateUi

};

namespace Ui {
    class action_dialog: public Ui_action_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTION_DIALOG_H
