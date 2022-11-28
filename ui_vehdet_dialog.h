/********************************************************************************
** Form generated from reading UI file 'vehdet_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEHDET_DIALOG_H
#define UI_VEHDET_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_vehdet_dialog
{
public:
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_cancel;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_4;
    QSpinBox *spinBox_CallPhase;
    QSpinBox *spinBox_SwitchPhase;
    QGroupBox *groupBox_4;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QSpinBox *spinBox_Extend;
    QSpinBox *spinBox_Delay;
    QSpinBox *spinBox_QueueLimit;
    QGroupBox *groupBox_5;
    QCheckBox *checkBox_Red;
    QCheckBox *checkBox_Yellow;
    QGroupBox *groupBox_6;
    QCheckBox *checkBox_RecordFlow;
    QCheckBox *checkBox_StrategicDet;
    QCheckBox *checkBox_UseExtend;
    QCheckBox *checkBox_QueueDet;
    QCheckBox *checkBox_RequestValid;
    QCheckBox *checkBox_RecordOccupancy;
    QGroupBox *groupBox_3;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *spinBox_FailTime;
    QSpinBox *spinBox_NoActivity;
    QSpinBox *spinBox_MaxPresence;
    QSpinBox *spinBox_ErraticCounts;
    QCheckBox *checkBox_Reset;
    QSpinBox *spinBox_Num;
    QLabel *label_11;

    void setupUi(QDialog *vehdet_dialog)
    {
        if (vehdet_dialog->objectName().isEmpty())
            vehdet_dialog->setObjectName(QStringLiteral("vehdet_dialog"));
        vehdet_dialog->resize(460, 460);
        pushButton_confirm = new QPushButton(vehdet_dialog);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        pushButton_confirm->setGeometry(QRect(130, 420, 90, 28));
        pushButton_cancel = new QPushButton(vehdet_dialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(240, 420, 90, 28));
        groupBox = new QGroupBox(vehdet_dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 50, 441, 61));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 20, 71, 26));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(210, 20, 71, 26));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        spinBox_CallPhase = new QSpinBox(groupBox);
        spinBox_CallPhase->setObjectName(QStringLiteral("spinBox_CallPhase"));
        spinBox_CallPhase->setGeometry(QRect(90, 20, 71, 22));
        spinBox_SwitchPhase = new QSpinBox(groupBox);
        spinBox_SwitchPhase->setObjectName(QStringLiteral("spinBox_SwitchPhase"));
        spinBox_SwitchPhase->setGeometry(QRect(280, 20, 71, 22));
        groupBox_4 = new QGroupBox(vehdet_dialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(260, 120, 191, 161));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 60, 81, 26));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 30, 81, 26));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 90, 81, 26));
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        spinBox_Extend = new QSpinBox(groupBox_4);
        spinBox_Extend->setObjectName(QStringLiteral("spinBox_Extend"));
        spinBox_Extend->setGeometry(QRect(110, 90, 71, 22));
        spinBox_Delay = new QSpinBox(groupBox_4);
        spinBox_Delay->setObjectName(QStringLiteral("spinBox_Delay"));
        spinBox_Delay->setGeometry(QRect(110, 30, 71, 22));
        spinBox_QueueLimit = new QSpinBox(groupBox_4);
        spinBox_QueueLimit->setObjectName(QStringLiteral("spinBox_QueueLimit"));
        spinBox_QueueLimit->setGeometry(QRect(110, 60, 71, 22));
        groupBox_5 = new QGroupBox(vehdet_dialog);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(320, 290, 131, 91));
        checkBox_Red = new QCheckBox(groupBox_5);
        checkBox_Red->setObjectName(QStringLiteral("checkBox_Red"));
        checkBox_Red->setGeometry(QRect(20, 30, 101, 16));
        checkBox_Yellow = new QCheckBox(groupBox_5);
        checkBox_Yellow->setObjectName(QStringLiteral("checkBox_Yellow"));
        checkBox_Yellow->setGeometry(QRect(20, 60, 101, 16));
        groupBox_6 = new QGroupBox(vehdet_dialog);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 290, 301, 121));
        checkBox_RecordFlow = new QCheckBox(groupBox_6);
        checkBox_RecordFlow->setObjectName(QStringLiteral("checkBox_RecordFlow"));
        checkBox_RecordFlow->setGeometry(QRect(20, 30, 131, 16));
        checkBox_StrategicDet = new QCheckBox(groupBox_6);
        checkBox_StrategicDet->setObjectName(QStringLiteral("checkBox_StrategicDet"));
        checkBox_StrategicDet->setGeometry(QRect(20, 90, 131, 16));
        checkBox_UseExtend = new QCheckBox(groupBox_6);
        checkBox_UseExtend->setObjectName(QStringLiteral("checkBox_UseExtend"));
        checkBox_UseExtend->setGeometry(QRect(20, 60, 131, 16));
        checkBox_QueueDet = new QCheckBox(groupBox_6);
        checkBox_QueueDet->setObjectName(QStringLiteral("checkBox_QueueDet"));
        checkBox_QueueDet->setGeometry(QRect(160, 90, 131, 16));
        checkBox_RequestValid = new QCheckBox(groupBox_6);
        checkBox_RequestValid->setObjectName(QStringLiteral("checkBox_RequestValid"));
        checkBox_RequestValid->setGeometry(QRect(160, 60, 131, 16));
        checkBox_RecordOccupancy = new QCheckBox(groupBox_6);
        checkBox_RecordOccupancy->setObjectName(QStringLiteral("checkBox_RecordOccupancy"));
        checkBox_RecordOccupancy->setGeometry(QRect(160, 30, 131, 16));
        groupBox_3 = new QGroupBox(vehdet_dialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 120, 241, 161));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 30, 71, 26));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 60, 71, 26));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 90, 71, 26));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 120, 71, 26));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        spinBox_FailTime = new QSpinBox(groupBox_3);
        spinBox_FailTime->setObjectName(QStringLiteral("spinBox_FailTime"));
        spinBox_FailTime->setGeometry(QRect(160, 30, 71, 22));
        spinBox_NoActivity = new QSpinBox(groupBox_3);
        spinBox_NoActivity->setObjectName(QStringLiteral("spinBox_NoActivity"));
        spinBox_NoActivity->setGeometry(QRect(160, 60, 71, 22));
        spinBox_MaxPresence = new QSpinBox(groupBox_3);
        spinBox_MaxPresence->setObjectName(QStringLiteral("spinBox_MaxPresence"));
        spinBox_MaxPresence->setGeometry(QRect(160, 90, 71, 22));
        spinBox_ErraticCounts = new QSpinBox(groupBox_3);
        spinBox_ErraticCounts->setObjectName(QStringLiteral("spinBox_ErraticCounts"));
        spinBox_ErraticCounts->setGeometry(QRect(160, 120, 71, 22));
        checkBox_Reset = new QCheckBox(vehdet_dialog);
        checkBox_Reset->setObjectName(QStringLiteral("checkBox_Reset"));
        checkBox_Reset->setGeometry(QRect(320, 390, 131, 16));
        spinBox_Num = new QSpinBox(vehdet_dialog);
        spinBox_Num->setObjectName(QStringLiteral("spinBox_Num"));
        spinBox_Num->setGeometry(QRect(100, 10, 71, 22));
        spinBox_Num->setMinimum(1);
        spinBox_Num->setMaximum(32);
        label_11 = new QLabel(vehdet_dialog);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 10, 81, 26));
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        retranslateUi(vehdet_dialog);

        QMetaObject::connectSlotsByName(vehdet_dialog);
    } // setupUi

    void retranslateUi(QDialog *vehdet_dialog)
    {
        vehdet_dialog->setWindowTitle(QApplication::translate("vehdet_dialog", "\346\227\266\346\256\265\347\274\226\350\276\221", 0));
        pushButton_confirm->setText(QApplication::translate("vehdet_dialog", "\347\241\256\345\256\232", 0));
        pushButton_cancel->setText(QApplication::translate("vehdet_dialog", "\345\217\226\346\266\210", 0));
        groupBox->setTitle(QApplication::translate("vehdet_dialog", "\347\233\270\344\275\215", 0));
        label_2->setText(QApplication::translate("vehdet_dialog", "\350\257\267\346\261\202\347\233\270\344\275\215:", 0));
        label_4->setText(QApplication::translate("vehdet_dialog", "\345\274\200\345\205\263\347\233\270\344\275\215:", 0));
        groupBox_4->setTitle(QApplication::translate("vehdet_dialog", "\346\227\266\351\227\264\345\217\202\346\225\260", 0));
        label_8->setText(QApplication::translate("vehdet_dialog", "\351\230\237\345\210\227\351\231\220\345\210\266:", 0));
        label_9->setText(QApplication::translate("vehdet_dialog", "\345\273\266\346\227\266(/10\347\247\222):", 0));
        label_10->setText(QApplication::translate("vehdet_dialog", "\345\273\266\351\225\277\347\273\277(/10\347\247\222):", 0));
        groupBox_5->setTitle(QApplication::translate("vehdet_dialog", "\350\257\267\346\261\202\346\234\211\346\225\210\345\214\272\351\227\264", 0));
        checkBox_Red->setText(QApplication::translate("vehdet_dialog", "\347\272\242\347\201\257\345\214\272\351\227\264", 0));
        checkBox_Yellow->setText(QApplication::translate("vehdet_dialog", "\351\273\204\347\201\257\345\214\272\351\227\264", 0));
        groupBox_6->setTitle(QApplication::translate("vehdet_dialog", "\351\200\211\351\241\271", 0));
        checkBox_RecordFlow->setText(QApplication::translate("vehdet_dialog", "\350\256\260\345\275\225\346\265\201\351\207\217", 0));
        checkBox_StrategicDet->setText(QApplication::translate("vehdet_dialog", "\344\275\234\344\270\272\346\210\230\347\225\245\346\243\200\346\265\213\345\231\250", 0));
        checkBox_UseExtend->setText(QApplication::translate("vehdet_dialog", "\344\275\277\347\224\250\346\243\200\346\265\213\345\231\250\347\232\204\345\273\266\351\225\277\347\273\277", 0));
        checkBox_QueueDet->setText(QApplication::translate("vehdet_dialog", "\344\275\234\344\270\272\346\216\222\351\230\237\346\243\200\346\265\213\345\231\250", 0));
        checkBox_RequestValid->setText(QApplication::translate("vehdet_dialog", "\350\257\267\346\261\202\346\234\211\346\225\210", 0));
        checkBox_RecordOccupancy->setText(QApplication::translate("vehdet_dialog", "\350\256\260\345\275\225\345\215\240\346\234\211\347\216\207", 0));
        groupBox_3->setTitle(QApplication::translate("vehdet_dialog", "\346\225\205\351\232\234\346\243\200\346\265\213", 0));
        label_3->setText(QApplication::translate("vehdet_dialog", "\345\244\261\350\264\245\346\227\266\351\227\264:", 0));
        label_5->setText(QApplication::translate("vehdet_dialog", "\346\227\240\345\223\215\345\272\224\346\227\266\351\227\264:", 0));
        label_6->setText(QApplication::translate("vehdet_dialog", "\346\234\200\345\244\247\346\214\201\347\273\255\346\227\266\351\227\264:", 0));
        label_7->setText(QApplication::translate("vehdet_dialog", "\346\204\237\345\272\224\346\225\260/\345\210\206\351\222\237:", 0));
        checkBox_Reset->setText(QApplication::translate("vehdet_dialog", "\351\207\215\347\275\256\346\243\200\346\265\213\345\231\250", 0));
        label_11->setText(QApplication::translate("vehdet_dialog", "\346\243\200\346\265\213\345\231\250\345\217\267:", 0));
    } // retranslateUi

};

namespace Ui {
    class vehdet_dialog: public Ui_vehdet_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEHDET_DIALOG_H
