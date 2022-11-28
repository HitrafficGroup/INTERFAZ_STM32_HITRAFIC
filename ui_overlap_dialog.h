/********************************************************************************
** Form generated from reading UI file 'overlap_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERLAP_DIALOG_H
#define UI_OVERLAP_DIALOG_H

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
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_overlap_dialog
{
public:
    QLabel *label;
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_cancel;
    QComboBox *comboBox_OverlapNum;
    QGroupBox *groupBox_Auxillary;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *spinBox_Green;
    QSpinBox *spinBox_Yellow;
    QSpinBox *spinBox_AllRed;
    QLabel *label_8;
    QSpinBox *spinBox_GreenFlash;
    QGroupBox *groupBox_Special;
    QCheckBox *checkBox_S1;
    QCheckBox *checkBox_S2;
    QCheckBox *checkBox_S5;
    QCheckBox *checkBox_S3;
    QCheckBox *checkBox_S4;
    QCheckBox *checkBox_S6;
    QCheckBox *checkBox_S7;
    QCheckBox *checkBox_S8;
    QCheckBox *checkBox_S11;
    QCheckBox *checkBox_S15;
    QCheckBox *checkBox_S16;
    QCheckBox *checkBox_S12;
    QCheckBox *checkBox_S13;
    QCheckBox *checkBox_S14;
    QCheckBox *checkBox_S9;
    QCheckBox *checkBox_S10;
    QGroupBox *groupBox_Special_2;
    QCheckBox *checkBox_M1;
    QCheckBox *checkBox_M2;
    QCheckBox *checkBox_M5;
    QCheckBox *checkBox_M3;
    QCheckBox *checkBox_M4;
    QCheckBox *checkBox_M6;
    QCheckBox *checkBox_M7;
    QCheckBox *checkBox_M8;
    QCheckBox *checkBox_M11;
    QCheckBox *checkBox_M15;
    QCheckBox *checkBox_M16;
    QCheckBox *checkBox_M12;
    QCheckBox *checkBox_M13;
    QCheckBox *checkBox_M14;
    QCheckBox *checkBox_M9;
    QCheckBox *checkBox_M10;
    QLabel *label_5;
    QComboBox *comboBox_type;

    void setupUi(QDialog *overlap_dialog)
    {
        if (overlap_dialog->objectName().isEmpty())
            overlap_dialog->setObjectName(QStringLiteral("overlap_dialog"));
        overlap_dialog->resize(390, 380);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        overlap_dialog->setFont(font);
        label = new QLabel(overlap_dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 81, 26));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_confirm = new QPushButton(overlap_dialog);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        pushButton_confirm->setGeometry(QRect(190, 340, 90, 28));
        pushButton_cancel = new QPushButton(overlap_dialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(290, 340, 90, 28));
        comboBox_OverlapNum = new QComboBox(overlap_dialog);
        comboBox_OverlapNum->setObjectName(QStringLiteral("comboBox_OverlapNum"));
        comboBox_OverlapNum->setGeometry(QRect(90, 10, 61, 26));
        groupBox_Auxillary = new QGroupBox(overlap_dialog);
        groupBox_Auxillary->setObjectName(QStringLiteral("groupBox_Auxillary"));
        groupBox_Auxillary->setEnabled(true);
        groupBox_Auxillary->setGeometry(QRect(10, 50, 371, 101));
        groupBox_Auxillary->setFont(font);
        groupBox_Auxillary->setMouseTracking(false);
        label_4 = new QLabel(groupBox_Auxillary);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 30, 81, 26));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(groupBox_Auxillary);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 60, 81, 26));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(groupBox_Auxillary);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(160, 60, 91, 26));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_Green = new QSpinBox(groupBox_Auxillary);
        spinBox_Green->setObjectName(QStringLiteral("spinBox_Green"));
        spinBox_Green->setGeometry(QRect(100, 30, 51, 24));
        spinBox_Green->setMaximum(255);
        spinBox_Yellow = new QSpinBox(groupBox_Auxillary);
        spinBox_Yellow->setObjectName(QStringLiteral("spinBox_Yellow"));
        spinBox_Yellow->setGeometry(QRect(100, 60, 51, 24));
        spinBox_Yellow->setMinimum(3);
        spinBox_Yellow->setMaximum(25);
        spinBox_AllRed = new QSpinBox(groupBox_Auxillary);
        spinBox_AllRed->setObjectName(QStringLiteral("spinBox_AllRed"));
        spinBox_AllRed->setGeometry(QRect(260, 60, 51, 24));
        spinBox_AllRed->setMaximum(25);
        label_8 = new QLabel(groupBox_Auxillary);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(160, 30, 91, 26));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_GreenFlash = new QSpinBox(groupBox_Auxillary);
        spinBox_GreenFlash->setObjectName(QStringLiteral("spinBox_GreenFlash"));
        spinBox_GreenFlash->setGeometry(QRect(260, 30, 51, 24));
        spinBox_GreenFlash->setMinimum(3);
        spinBox_GreenFlash->setMaximum(25);
        groupBox_Special = new QGroupBox(overlap_dialog);
        groupBox_Special->setObjectName(QStringLiteral("groupBox_Special"));
        groupBox_Special->setGeometry(QRect(10, 160, 371, 81));
        groupBox_Special->setContextMenuPolicy(Qt::NoContextMenu);
        groupBox_Special->setAcceptDrops(false);
        groupBox_Special->setAutoFillBackground(false);
        checkBox_S1 = new QCheckBox(groupBox_Special);
        checkBox_S1->setObjectName(QStringLiteral("checkBox_S1"));
        checkBox_S1->setGeometry(QRect(40, 20, 31, 19));
        checkBox_S2 = new QCheckBox(groupBox_Special);
        checkBox_S2->setObjectName(QStringLiteral("checkBox_S2"));
        checkBox_S2->setGeometry(QRect(80, 20, 31, 19));
        checkBox_S5 = new QCheckBox(groupBox_Special);
        checkBox_S5->setObjectName(QStringLiteral("checkBox_S5"));
        checkBox_S5->setGeometry(QRect(200, 20, 31, 19));
        checkBox_S3 = new QCheckBox(groupBox_Special);
        checkBox_S3->setObjectName(QStringLiteral("checkBox_S3"));
        checkBox_S3->setGeometry(QRect(120, 20, 31, 19));
        checkBox_S4 = new QCheckBox(groupBox_Special);
        checkBox_S4->setObjectName(QStringLiteral("checkBox_S4"));
        checkBox_S4->setGeometry(QRect(160, 20, 31, 19));
        checkBox_S6 = new QCheckBox(groupBox_Special);
        checkBox_S6->setObjectName(QStringLiteral("checkBox_S6"));
        checkBox_S6->setGeometry(QRect(240, 20, 31, 19));
        checkBox_S7 = new QCheckBox(groupBox_Special);
        checkBox_S7->setObjectName(QStringLiteral("checkBox_S7"));
        checkBox_S7->setGeometry(QRect(280, 20, 31, 19));
        checkBox_S8 = new QCheckBox(groupBox_Special);
        checkBox_S8->setObjectName(QStringLiteral("checkBox_S8"));
        checkBox_S8->setGeometry(QRect(320, 20, 31, 19));
        checkBox_S11 = new QCheckBox(groupBox_Special);
        checkBox_S11->setObjectName(QStringLiteral("checkBox_S11"));
        checkBox_S11->setGeometry(QRect(120, 50, 31, 19));
        checkBox_S15 = new QCheckBox(groupBox_Special);
        checkBox_S15->setObjectName(QStringLiteral("checkBox_S15"));
        checkBox_S15->setGeometry(QRect(280, 50, 31, 19));
        checkBox_S16 = new QCheckBox(groupBox_Special);
        checkBox_S16->setObjectName(QStringLiteral("checkBox_S16"));
        checkBox_S16->setGeometry(QRect(320, 50, 31, 19));
        checkBox_S12 = new QCheckBox(groupBox_Special);
        checkBox_S12->setObjectName(QStringLiteral("checkBox_S12"));
        checkBox_S12->setGeometry(QRect(160, 50, 31, 19));
        checkBox_S13 = new QCheckBox(groupBox_Special);
        checkBox_S13->setObjectName(QStringLiteral("checkBox_S13"));
        checkBox_S13->setGeometry(QRect(200, 50, 31, 19));
        checkBox_S14 = new QCheckBox(groupBox_Special);
        checkBox_S14->setObjectName(QStringLiteral("checkBox_S14"));
        checkBox_S14->setGeometry(QRect(240, 50, 31, 19));
        checkBox_S9 = new QCheckBox(groupBox_Special);
        checkBox_S9->setObjectName(QStringLiteral("checkBox_S9"));
        checkBox_S9->setGeometry(QRect(40, 50, 31, 19));
        checkBox_S10 = new QCheckBox(groupBox_Special);
        checkBox_S10->setObjectName(QStringLiteral("checkBox_S10"));
        checkBox_S10->setGeometry(QRect(80, 50, 31, 19));
        groupBox_Special_2 = new QGroupBox(overlap_dialog);
        groupBox_Special_2->setObjectName(QStringLiteral("groupBox_Special_2"));
        groupBox_Special_2->setGeometry(QRect(10, 250, 371, 81));
        groupBox_Special_2->setContextMenuPolicy(Qt::NoContextMenu);
        groupBox_Special_2->setAcceptDrops(false);
        groupBox_Special_2->setAutoFillBackground(false);
        checkBox_M1 = new QCheckBox(groupBox_Special_2);
        checkBox_M1->setObjectName(QStringLiteral("checkBox_M1"));
        checkBox_M1->setGeometry(QRect(40, 20, 31, 19));
        checkBox_M2 = new QCheckBox(groupBox_Special_2);
        checkBox_M2->setObjectName(QStringLiteral("checkBox_M2"));
        checkBox_M2->setGeometry(QRect(80, 20, 31, 19));
        checkBox_M5 = new QCheckBox(groupBox_Special_2);
        checkBox_M5->setObjectName(QStringLiteral("checkBox_M5"));
        checkBox_M5->setGeometry(QRect(200, 20, 31, 19));
        checkBox_M3 = new QCheckBox(groupBox_Special_2);
        checkBox_M3->setObjectName(QStringLiteral("checkBox_M3"));
        checkBox_M3->setGeometry(QRect(120, 20, 31, 19));
        checkBox_M4 = new QCheckBox(groupBox_Special_2);
        checkBox_M4->setObjectName(QStringLiteral("checkBox_M4"));
        checkBox_M4->setGeometry(QRect(160, 20, 31, 19));
        checkBox_M6 = new QCheckBox(groupBox_Special_2);
        checkBox_M6->setObjectName(QStringLiteral("checkBox_M6"));
        checkBox_M6->setGeometry(QRect(240, 20, 31, 19));
        checkBox_M7 = new QCheckBox(groupBox_Special_2);
        checkBox_M7->setObjectName(QStringLiteral("checkBox_M7"));
        checkBox_M7->setGeometry(QRect(280, 20, 31, 19));
        checkBox_M8 = new QCheckBox(groupBox_Special_2);
        checkBox_M8->setObjectName(QStringLiteral("checkBox_M8"));
        checkBox_M8->setGeometry(QRect(320, 20, 31, 19));
        checkBox_M11 = new QCheckBox(groupBox_Special_2);
        checkBox_M11->setObjectName(QStringLiteral("checkBox_M11"));
        checkBox_M11->setGeometry(QRect(120, 50, 31, 19));
        checkBox_M15 = new QCheckBox(groupBox_Special_2);
        checkBox_M15->setObjectName(QStringLiteral("checkBox_M15"));
        checkBox_M15->setGeometry(QRect(280, 50, 31, 19));
        checkBox_M16 = new QCheckBox(groupBox_Special_2);
        checkBox_M16->setObjectName(QStringLiteral("checkBox_M16"));
        checkBox_M16->setGeometry(QRect(320, 50, 31, 19));
        checkBox_M12 = new QCheckBox(groupBox_Special_2);
        checkBox_M12->setObjectName(QStringLiteral("checkBox_M12"));
        checkBox_M12->setGeometry(QRect(160, 50, 31, 19));
        checkBox_M13 = new QCheckBox(groupBox_Special_2);
        checkBox_M13->setObjectName(QStringLiteral("checkBox_M13"));
        checkBox_M13->setGeometry(QRect(200, 50, 31, 19));
        checkBox_M14 = new QCheckBox(groupBox_Special_2);
        checkBox_M14->setObjectName(QStringLiteral("checkBox_M14"));
        checkBox_M14->setGeometry(QRect(240, 50, 31, 19));
        checkBox_M9 = new QCheckBox(groupBox_Special_2);
        checkBox_M9->setObjectName(QStringLiteral("checkBox_M9"));
        checkBox_M9->setGeometry(QRect(40, 50, 31, 19));
        checkBox_M10 = new QCheckBox(groupBox_Special_2);
        checkBox_M10->setObjectName(QStringLiteral("checkBox_M10"));
        checkBox_M10->setGeometry(QRect(80, 50, 31, 19));
        label_5 = new QLabel(overlap_dialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(150, 10, 71, 26));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_type = new QComboBox(overlap_dialog);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));
        comboBox_type->setGeometry(QRect(220, 10, 151, 26));

        retranslateUi(overlap_dialog);

        QMetaObject::connectSlotsByName(overlap_dialog);
    } // setupUi

    void retranslateUi(QDialog *overlap_dialog)
    {
        overlap_dialog->setWindowTitle(QApplication::translate("overlap_dialog", "\350\267\237\351\232\217\347\233\270\344\275\215\347\274\226\350\276\221", 0));
        label->setText(QApplication::translate("overlap_dialog", "\350\267\237\351\232\217\347\233\270\344\275\215\357\274\232", 0));
        pushButton_confirm->setText(QApplication::translate("overlap_dialog", "\347\241\256\345\256\232", 0));
        pushButton_cancel->setText(QApplication::translate("overlap_dialog", "\345\217\226\346\266\210", 0));
        groupBox_Auxillary->setTitle(QApplication::translate("overlap_dialog", "\346\227\266\351\227\264\357\274\210\345\215\225\344\275\215\357\274\232\347\247\222\357\274\211", 0));
        label_4->setText(QApplication::translate("overlap_dialog", "\347\273\277\347\201\257\357\274\232", 0));
        label_6->setText(QApplication::translate("overlap_dialog", "\351\273\204\347\201\257\357\274\232", 0));
        label_7->setText(QApplication::translate("overlap_dialog", "\345\205\250\347\272\242\357\274\232", 0));
        label_8->setText(QApplication::translate("overlap_dialog", "\347\273\277\351\227\252\357\274\232", 0));
        groupBox_Special->setTitle(QApplication::translate("overlap_dialog", "\346\257\215\347\233\270\344\275\215", 0));
        checkBox_S1->setText(QApplication::translate("overlap_dialog", "1", 0));
        checkBox_S2->setText(QApplication::translate("overlap_dialog", "2", 0));
        checkBox_S5->setText(QApplication::translate("overlap_dialog", "5", 0));
        checkBox_S3->setText(QApplication::translate("overlap_dialog", "3", 0));
        checkBox_S4->setText(QApplication::translate("overlap_dialog", "4", 0));
        checkBox_S6->setText(QApplication::translate("overlap_dialog", "6", 0));
        checkBox_S7->setText(QApplication::translate("overlap_dialog", "7", 0));
        checkBox_S8->setText(QApplication::translate("overlap_dialog", "8", 0));
        checkBox_S11->setText(QApplication::translate("overlap_dialog", "11", 0));
        checkBox_S15->setText(QApplication::translate("overlap_dialog", "15", 0));
        checkBox_S16->setText(QApplication::translate("overlap_dialog", "16", 0));
        checkBox_S12->setText(QApplication::translate("overlap_dialog", "12", 0));
        checkBox_S13->setText(QApplication::translate("overlap_dialog", "13", 0));
        checkBox_S14->setText(QApplication::translate("overlap_dialog", "14", 0));
        checkBox_S9->setText(QApplication::translate("overlap_dialog", "9", 0));
        checkBox_S10->setText(QApplication::translate("overlap_dialog", "10", 0));
        groupBox_Special_2->setTitle(QApplication::translate("overlap_dialog", "\344\277\256\346\255\243\347\233\270\344\275\215", 0));
        checkBox_M1->setText(QApplication::translate("overlap_dialog", "1", 0));
        checkBox_M2->setText(QApplication::translate("overlap_dialog", "2", 0));
        checkBox_M5->setText(QApplication::translate("overlap_dialog", "5", 0));
        checkBox_M3->setText(QApplication::translate("overlap_dialog", "3", 0));
        checkBox_M4->setText(QApplication::translate("overlap_dialog", "4", 0));
        checkBox_M6->setText(QApplication::translate("overlap_dialog", "6", 0));
        checkBox_M7->setText(QApplication::translate("overlap_dialog", "7", 0));
        checkBox_M8->setText(QApplication::translate("overlap_dialog", "8", 0));
        checkBox_M11->setText(QApplication::translate("overlap_dialog", "11", 0));
        checkBox_M15->setText(QApplication::translate("overlap_dialog", "15", 0));
        checkBox_M16->setText(QApplication::translate("overlap_dialog", "16", 0));
        checkBox_M12->setText(QApplication::translate("overlap_dialog", "12", 0));
        checkBox_M13->setText(QApplication::translate("overlap_dialog", "13", 0));
        checkBox_M14->setText(QApplication::translate("overlap_dialog", "14", 0));
        checkBox_M9->setText(QApplication::translate("overlap_dialog", "9", 0));
        checkBox_M10->setText(QApplication::translate("overlap_dialog", "10", 0));
        label_5->setText(QApplication::translate("overlap_dialog", "\347\261\273\345\236\213\357\274\232", 0));
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QApplication::translate("overlap_dialog", "\345\205\266\344\273\226", 0)
         << QApplication::translate("overlap_dialog", "\345\270\270\350\247\204", 0)
         << QApplication::translate("overlap_dialog", "\351\273\204\347\273\277\345\201\234\346\255\242", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class overlap_dialog: public Ui_overlap_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERLAP_DIALOG_H
