/********************************************************************************
** Form generated from reading UI file 'phase_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHASE_DIALOG_H
#define UI_PHASE_DIALOG_H

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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_phase_dialog
{
public:
    QLabel *label;
    QComboBox *comboBox_Phase;
    QPushButton *pushButton_confirm;
    QGroupBox *groupBox_basicTime;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QSpinBox *sp_MinimumGreen;
    QSpinBox *sp_Passage;
    QSpinBox *sp_YellowChange;
    QSpinBox *sp_Maximum1;
    QSpinBox *sp_DynamicMaxLimit;
    QSpinBox *sp_RedClear;
    QSpinBox *sp_DynamicMaxStep;
    QSpinBox *sp_RedRevert;
    QSpinBox *sp_Maximum2;
    QLabel *label_22;
    QSpinBox *sp_VehicleClear;
    QGroupBox *groupBox_flash;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QCheckBox *checkBox_AddedInitialCalc;
    QSpinBox *sp_ReduceBy;
    QSpinBox *sp_AddedInitial;
    QSpinBox *sp_TimeBeforeReduction;
    QSpinBox *sp_MinimumGap;
    QSpinBox *sp_CarsBeforeReduction;
    QSpinBox *sp_TimeToReduce;
    QSpinBox *sp_MaximumInitial;
    QGroupBox *groupBox_dim;
    QLabel *label_20;
    QSpinBox *sp_PedestrianClear;
    QSpinBox *sp_Walk;
    QLabel *label_15;
    QCheckBox *checkBox_KeepPedRelease;
    QPushButton *pushButton_cancel;
    QGroupBox *groupBox_countdown;
    QCheckBox *checkBox_AllowDetectorToShieldRequest;
    QCheckBox *checkBox_GuaranteeFlowDensityExtendGreen;
    QCheckBox *checkBox_DoubleEntryPhase;
    QCheckBox *checkBox_ConditionService;
    QCheckBox *checkBox_SimultaneousVoidFail;
    QLabel *label_2;
    QGroupBox *groupBox;
    QLabel *label_21;
    QLabel *label_23;
    QLabel *label_24;
    QComboBox *comboBox_Startup;
    QComboBox *comboBox_VehicleRequest;
    QComboBox *comboBox_NoneInduction;
    QCheckBox *checkBox_AutoFlashIn;
    QCheckBox *checkBox_AutoFlashOut;
    QCheckBox *checkBox_PedAutoRequest;
    QLabel *label_Ring;
    QComboBox *comboBox_Ring;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_phaseConcurrency;
    QLabel *label_25;
    QLineEdit *lineEdit_phaseConcurrency;

    void setupUi(QDialog *phase_dialog)
    {
        if (phase_dialog->objectName().isEmpty())
            phase_dialog->setObjectName(QStringLiteral("phase_dialog"));
        phase_dialog->resize(800, 680);
        label = new QLabel(phase_dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(11, 20, 61, 20));
        comboBox_Phase = new QComboBox(phase_dialog);
        comboBox_Phase->setObjectName(QStringLiteral("comboBox_Phase"));
        comboBox_Phase->setGeometry(QRect(70, 20, 61, 22));
        pushButton_confirm = new QPushButton(phase_dialog);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        pushButton_confirm->setGeometry(QRect(590, 620, 93, 28));
        groupBox_basicTime = new QGroupBox(phase_dialog);
        groupBox_basicTime->setObjectName(QStringLiteral("groupBox_basicTime"));
        groupBox_basicTime->setGeometry(QRect(10, 60, 571, 181));
        label_3 = new QLabel(groupBox_basicTime);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 30, 91, 16));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(groupBox_basicTime);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 70, 91, 16));
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(groupBox_basicTime);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(170, 110, 121, 20));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(groupBox_basicTime);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(170, 30, 121, 20));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(groupBox_basicTime);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(170, 70, 121, 20));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_8 = new QLabel(groupBox_basicTime);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(360, 110, 121, 20));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_9 = new QLabel(groupBox_basicTime);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(360, 30, 121, 20));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_10 = new QLabel(groupBox_basicTime);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(360, 70, 121, 20));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_11 = new QLabel(groupBox_basicTime);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 150, 91, 16));
        label_11->setLayoutDirection(Qt::LeftToRight);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sp_MinimumGreen = new QSpinBox(groupBox_basicTime);
        sp_MinimumGreen->setObjectName(QStringLiteral("sp_MinimumGreen"));
        sp_MinimumGreen->setGeometry(QRect(100, 25, 71, 26));
        sp_MinimumGreen->setMaximum(255);
        sp_Passage = new QSpinBox(groupBox_basicTime);
        sp_Passage->setObjectName(QStringLiteral("sp_Passage"));
        sp_Passage->setGeometry(QRect(100, 65, 71, 26));
        sp_Passage->setMaximum(255);
        sp_YellowChange = new QSpinBox(groupBox_basicTime);
        sp_YellowChange->setObjectName(QStringLiteral("sp_YellowChange"));
        sp_YellowChange->setGeometry(QRect(290, 105, 71, 26));
        sp_YellowChange->setMaximum(255);
        sp_YellowChange->setValue(3);
        sp_Maximum1 = new QSpinBox(groupBox_basicTime);
        sp_Maximum1->setObjectName(QStringLiteral("sp_Maximum1"));
        sp_Maximum1->setGeometry(QRect(290, 25, 71, 26));
        sp_Maximum1->setMaximum(255);
        sp_DynamicMaxLimit = new QSpinBox(groupBox_basicTime);
        sp_DynamicMaxLimit->setObjectName(QStringLiteral("sp_DynamicMaxLimit"));
        sp_DynamicMaxLimit->setGeometry(QRect(290, 65, 71, 26));
        sp_DynamicMaxLimit->setMaximum(255);
        sp_RedClear = new QSpinBox(groupBox_basicTime);
        sp_RedClear->setObjectName(QStringLiteral("sp_RedClear"));
        sp_RedClear->setGeometry(QRect(480, 105, 71, 26));
        sp_RedClear->setMaximum(255);
        sp_RedClear->setValue(2);
        sp_DynamicMaxStep = new QSpinBox(groupBox_basicTime);
        sp_DynamicMaxStep->setObjectName(QStringLiteral("sp_DynamicMaxStep"));
        sp_DynamicMaxStep->setGeometry(QRect(480, 65, 71, 26));
        sp_DynamicMaxStep->setMaximum(255);
        sp_RedRevert = new QSpinBox(groupBox_basicTime);
        sp_RedRevert->setObjectName(QStringLiteral("sp_RedRevert"));
        sp_RedRevert->setGeometry(QRect(100, 145, 71, 26));
        sp_RedRevert->setMaximum(255);
        sp_Maximum2 = new QSpinBox(groupBox_basicTime);
        sp_Maximum2->setObjectName(QStringLiteral("sp_Maximum2"));
        sp_Maximum2->setGeometry(QRect(480, 25, 71, 26));
        sp_Maximum2->setMaximum(255);
        label_22 = new QLabel(groupBox_basicTime);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(10, 110, 91, 20));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sp_VehicleClear = new QSpinBox(groupBox_basicTime);
        sp_VehicleClear->setObjectName(QStringLiteral("sp_VehicleClear"));
        sp_VehicleClear->setGeometry(QRect(100, 105, 71, 26));
        sp_VehicleClear->setMaximum(255);
        sp_VehicleClear->setValue(3);
        groupBox_flash = new QGroupBox(phase_dialog);
        groupBox_flash->setObjectName(QStringLiteral("groupBox_flash"));
        groupBox_flash->setGeometry(QRect(10, 250, 571, 141));
        label_12 = new QLabel(groupBox_flash);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 30, 91, 20));
        label_12->setLayoutDirection(Qt::LeftToRight);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_13 = new QLabel(groupBox_flash);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 70, 91, 20));
        label_13->setLayoutDirection(Qt::LeftToRight);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_14 = new QLabel(groupBox_flash);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 110, 91, 20));
        label_14->setLayoutDirection(Qt::LeftToRight);
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_16 = new QLabel(groupBox_flash);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(170, 110, 121, 20));
        label_16->setLayoutDirection(Qt::LeftToRight);
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_17 = new QLabel(groupBox_flash);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(170, 70, 121, 20));
        label_17->setLayoutDirection(Qt::LeftToRight);
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_18 = new QLabel(groupBox_flash);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(360, 70, 121, 20));
        label_18->setLayoutDirection(Qt::LeftToRight);
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_19 = new QLabel(groupBox_flash);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(350, 30, 131, 20));
        label_19->setLayoutDirection(Qt::LeftToRight);
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_AddedInitialCalc = new QCheckBox(groupBox_flash);
        checkBox_AddedInitialCalc->setObjectName(QStringLiteral("checkBox_AddedInitialCalc"));
        checkBox_AddedInitialCalc->setGeometry(QRect(220, 30, 131, 16));
        sp_ReduceBy = new QSpinBox(groupBox_flash);
        sp_ReduceBy->setObjectName(QStringLiteral("sp_ReduceBy"));
        sp_ReduceBy->setGeometry(QRect(100, 105, 71, 26));
        sp_ReduceBy->setMaximum(255);
        sp_AddedInitial = new QSpinBox(groupBox_flash);
        sp_AddedInitial->setObjectName(QStringLiteral("sp_AddedInitial"));
        sp_AddedInitial->setGeometry(QRect(100, 25, 71, 26));
        sp_AddedInitial->setMaximum(255);
        sp_TimeBeforeReduction = new QSpinBox(groupBox_flash);
        sp_TimeBeforeReduction->setObjectName(QStringLiteral("sp_TimeBeforeReduction"));
        sp_TimeBeforeReduction->setGeometry(QRect(100, 65, 71, 26));
        sp_TimeBeforeReduction->setMaximum(255);
        sp_MinimumGap = new QSpinBox(groupBox_flash);
        sp_MinimumGap->setObjectName(QStringLiteral("sp_MinimumGap"));
        sp_MinimumGap->setGeometry(QRect(290, 105, 71, 26));
        sp_MinimumGap->setMaximum(255);
        sp_CarsBeforeReduction = new QSpinBox(groupBox_flash);
        sp_CarsBeforeReduction->setObjectName(QStringLiteral("sp_CarsBeforeReduction"));
        sp_CarsBeforeReduction->setGeometry(QRect(290, 65, 71, 26));
        sp_CarsBeforeReduction->setMaximum(255);
        sp_TimeToReduce = new QSpinBox(groupBox_flash);
        sp_TimeToReduce->setObjectName(QStringLiteral("sp_TimeToReduce"));
        sp_TimeToReduce->setGeometry(QRect(480, 65, 71, 26));
        sp_TimeToReduce->setMaximum(255);
        sp_MaximumInitial = new QSpinBox(groupBox_flash);
        sp_MaximumInitial->setObjectName(QStringLiteral("sp_MaximumInitial"));
        sp_MaximumInitial->setGeometry(QRect(480, 25, 71, 26));
        sp_MaximumInitial->setMaximum(255);
        groupBox_dim = new QGroupBox(phase_dialog);
        groupBox_dim->setObjectName(QStringLiteral("groupBox_dim"));
        groupBox_dim->setGeometry(QRect(590, 60, 201, 151));
        label_20 = new QLabel(groupBox_dim);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(20, 30, 61, 20));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sp_PedestrianClear = new QSpinBox(groupBox_dim);
        sp_PedestrianClear->setObjectName(QStringLiteral("sp_PedestrianClear"));
        sp_PedestrianClear->setGeometry(QRect(100, 65, 71, 26));
        sp_PedestrianClear->setMaximum(255);
        sp_Walk = new QSpinBox(groupBox_dim);
        sp_Walk->setObjectName(QStringLiteral("sp_Walk"));
        sp_Walk->setGeometry(QRect(100, 25, 71, 26));
        sp_Walk->setMaximum(255);
        label_15 = new QLabel(groupBox_dim);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(20, 70, 61, 20));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_KeepPedRelease = new QCheckBox(groupBox_dim);
        checkBox_KeepPedRelease->setObjectName(QStringLiteral("checkBox_KeepPedRelease"));
        checkBox_KeepPedRelease->setGeometry(QRect(30, 110, 131, 16));
        pushButton_cancel = new QPushButton(phase_dialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(700, 620, 93, 28));
        groupBox_countdown = new QGroupBox(phase_dialog);
        groupBox_countdown->setObjectName(QStringLiteral("groupBox_countdown"));
        groupBox_countdown->setGeometry(QRect(590, 220, 201, 171));
        checkBox_AllowDetectorToShieldRequest = new QCheckBox(groupBox_countdown);
        checkBox_AllowDetectorToShieldRequest->setObjectName(QStringLiteral("checkBox_AllowDetectorToShieldRequest"));
        checkBox_AllowDetectorToShieldRequest->setGeometry(QRect(20, 20, 171, 16));
        checkBox_GuaranteeFlowDensityExtendGreen = new QCheckBox(groupBox_countdown);
        checkBox_GuaranteeFlowDensityExtendGreen->setObjectName(QStringLiteral("checkBox_GuaranteeFlowDensityExtendGreen"));
        checkBox_GuaranteeFlowDensityExtendGreen->setGeometry(QRect(20, 80, 171, 16));
        checkBox_DoubleEntryPhase = new QCheckBox(groupBox_countdown);
        checkBox_DoubleEntryPhase->setObjectName(QStringLiteral("checkBox_DoubleEntryPhase"));
        checkBox_DoubleEntryPhase->setGeometry(QRect(20, 50, 171, 16));
        checkBox_ConditionService = new QCheckBox(groupBox_countdown);
        checkBox_ConditionService->setObjectName(QStringLiteral("checkBox_ConditionService"));
        checkBox_ConditionService->setGeometry(QRect(20, 110, 171, 16));
        checkBox_SimultaneousVoidFail = new QCheckBox(groupBox_countdown);
        checkBox_SimultaneousVoidFail->setObjectName(QStringLiteral("checkBox_SimultaneousVoidFail"));
        checkBox_SimultaneousVoidFail->setGeometry(QRect(20, 140, 171, 16));
        label_2 = new QLabel(phase_dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(710, 20, 81, 20));
        groupBox = new QGroupBox(phase_dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 400, 781, 111));
        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(270, 30, 121, 22));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_23 = new QLabel(groupBox);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(20, 30, 121, 22));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_24 = new QLabel(groupBox);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(20, 70, 121, 22));
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_Startup = new QComboBox(groupBox);
        comboBox_Startup->setObjectName(QStringLiteral("comboBox_Startup"));
        comboBox_Startup->setGeometry(QRect(150, 30, 121, 22));
        comboBox_VehicleRequest = new QComboBox(groupBox);
        comboBox_VehicleRequest->setObjectName(QStringLiteral("comboBox_VehicleRequest"));
        comboBox_VehicleRequest->setGeometry(QRect(150, 70, 121, 22));
        comboBox_NoneInduction = new QComboBox(groupBox);
        comboBox_NoneInduction->setObjectName(QStringLiteral("comboBox_NoneInduction"));
        comboBox_NoneInduction->setGeometry(QRect(390, 30, 121, 22));
        checkBox_AutoFlashIn = new QCheckBox(groupBox);
        checkBox_AutoFlashIn->setObjectName(QStringLiteral("checkBox_AutoFlashIn"));
        checkBox_AutoFlashIn->setGeometry(QRect(560, 30, 171, 22));
        checkBox_AutoFlashOut = new QCheckBox(groupBox);
        checkBox_AutoFlashOut->setObjectName(QStringLiteral("checkBox_AutoFlashOut"));
        checkBox_AutoFlashOut->setGeometry(QRect(560, 70, 171, 22));
        checkBox_PedAutoRequest = new QCheckBox(groupBox);
        checkBox_PedAutoRequest->setObjectName(QStringLiteral("checkBox_PedAutoRequest"));
        checkBox_PedAutoRequest->setGeometry(QRect(340, 70, 171, 22));
        label_Ring = new QLabel(phase_dialog);
        label_Ring->setObjectName(QStringLiteral("label_Ring"));
        label_Ring->setGeometry(QRect(150, 20, 61, 20));
        comboBox_Ring = new QComboBox(phase_dialog);
        comboBox_Ring->setObjectName(QStringLiteral("comboBox_Ring"));
        comboBox_Ring->setGeometry(QRect(210, 20, 61, 22));
        groupBox_2 = new QGroupBox(phase_dialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 520, 781, 80));
        pushButton_phaseConcurrency = new QPushButton(groupBox_2);
        pushButton_phaseConcurrency->setObjectName(QStringLiteral("pushButton_phaseConcurrency"));
        pushButton_phaseConcurrency->setGeometry(QRect(750, 30, 20, 20));
        label_25 = new QLabel(groupBox_2);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(30, 30, 41, 20));
        lineEdit_phaseConcurrency = new QLineEdit(groupBox_2);
        lineEdit_phaseConcurrency->setObjectName(QStringLiteral("lineEdit_phaseConcurrency"));
        lineEdit_phaseConcurrency->setGeometry(QRect(80, 30, 661, 21));
        lineEdit_phaseConcurrency->setReadOnly(true);

        retranslateUi(phase_dialog);

        QMetaObject::connectSlotsByName(phase_dialog);
    } // setupUi

    void retranslateUi(QDialog *phase_dialog)
    {
        phase_dialog->setWindowTitle(QApplication::translate("phase_dialog", "\347\233\270\344\275\215\347\274\226\350\276\221", 0));
        label->setText(QApplication::translate("phase_dialog", "\347\233\270\344\275\215\345\217\267\357\274\232", 0));
        pushButton_confirm->setText(QApplication::translate("phase_dialog", "\347\241\256\345\256\232", 0));
        groupBox_basicTime->setTitle(QApplication::translate("phase_dialog", "\345\237\272\347\241\200\346\227\266\351\227\264", 0));
        label_3->setText(QApplication::translate("phase_dialog", "\346\234\200\345\260\217\347\273\277:", 0));
        label_4->setText(QApplication::translate("phase_dialog", "\345\215\225\344\275\215\345\273\266\351\225\277\347\273\277:", 0));
        label_5->setText(QApplication::translate("phase_dialog", "\346\234\272\345\212\250\351\273\204\347\201\257:", 0));
        label_6->setText(QApplication::translate("phase_dialog", "\346\234\200\345\244\247\347\273\2771:", 0));
        label_7->setText(QApplication::translate("phase_dialog", "\346\234\200\345\244\247\345\200\274\351\231\220\345\210\266:", 0));
        label_8->setText(QApplication::translate("phase_dialog", "\345\205\250\347\272\242\346\227\266\351\227\264:", 0));
        label_9->setText(QApplication::translate("phase_dialog", "\346\234\200\345\244\247\347\273\2772:", 0));
        label_10->setText(QApplication::translate("phase_dialog", "\345\212\250\346\200\201\346\255\245\351\225\277:", 0));
        label_11->setText(QApplication::translate("phase_dialog", "\347\272\242\347\201\257\344\277\235\346\212\244:", 0));
        label_22->setText(QApplication::translate("phase_dialog", "\346\234\272\345\212\250\346\270\205\347\251\272:", 0));
        groupBox_flash->setTitle(QApplication::translate("phase_dialog", "\345\257\206\345\272\246\346\227\266\351\227\264", 0));
        label_12->setText(QApplication::translate("phase_dialog", "\345\242\236\345\212\240\345\210\235\345\247\213\345\200\274:", 0));
        label_13->setText(QApplication::translate("phase_dialog", "\351\200\222\345\207\217\345\211\215\346\227\266\351\227\264:", 0));
        label_14->setText(QApplication::translate("phase_dialog", "\345\215\225\344\275\215\351\200\222\345\207\217\347\216\207:", 0));
        label_16->setText(QApplication::translate("phase_dialog", "\346\234\200\345\260\217\351\227\264\351\232\224:", 0));
        label_17->setText(QApplication::translate("phase_dialog", "\351\200\222\345\207\217\345\211\215\350\275\246\350\276\206:", 0));
        label_18->setText(QApplication::translate("phase_dialog", "\351\200\222\345\207\217\346\227\266\351\227\264:", 0));
        label_19->setText(QApplication::translate("phase_dialog", "\346\234\200\345\244\247\345\210\235\345\247\213\345\200\274:", 0));
        checkBox_AddedInitialCalc->setText(QApplication::translate("phase_dialog", "\345\242\236\345\212\240\345\210\235\345\247\213\345\200\274\350\256\241\347\256\227", 0));
        groupBox_dim->setTitle(QApplication::translate("phase_dialog", "\350\241\214\344\272\272", 0));
        label_20->setText(QApplication::translate("phase_dialog", "\350\241\214\344\272\272\346\224\276\350\241\214:", 0));
        label_15->setText(QApplication::translate("phase_dialog", "\350\241\214\344\272\272\346\270\205\347\251\272:", 0));
        checkBox_KeepPedRelease->setText(QApplication::translate("phase_dialog", "\344\277\235\346\214\201\350\241\214\344\272\272\346\224\276\350\241\214", 0));
        pushButton_cancel->setText(QApplication::translate("phase_dialog", "\345\217\226\346\266\210", 0));
        groupBox_countdown->setTitle(QApplication::translate("phase_dialog", "\351\200\211\351\241\271", 0));
        checkBox_AllowDetectorToShieldRequest->setText(QApplication::translate("phase_dialog", "\345\205\201\350\256\270\346\243\200\346\265\213\345\231\250\345\261\217\350\224\275\350\257\267\346\261\202", 0));
        checkBox_GuaranteeFlowDensityExtendGreen->setText(QApplication::translate("phase_dialog", "\344\277\235\350\257\201\346\265\201\351\207\217\345\257\206\345\272\246\345\273\266\351\225\277\347\273\277", 0));
        checkBox_DoubleEntryPhase->setText(QApplication::translate("phase_dialog", "\345\217\214\345\205\245\345\217\243\347\233\270\344\275\215", 0));
        checkBox_ConditionService->setText(QApplication::translate("phase_dialog", "\346\234\211\346\235\241\344\273\266\346\234\215\345\212\241\346\234\211\346\225\210", 0));
        checkBox_SimultaneousVoidFail->setText(QApplication::translate("phase_dialog", "\345\220\214\346\227\266\347\251\272\345\275\223\345\244\261\346\225\210", 0));
        label_2->setText(QApplication::translate("phase_dialog", "(\345\215\225\344\275\215\357\274\232\347\247\222)", 0));
        groupBox->setTitle(QApplication::translate("phase_dialog", "\347\273\274\345\220\210", 0));
        label_21->setText(QApplication::translate("phase_dialog", "\351\235\236\346\204\237\345\272\224:", 0));
        label_23->setText(QApplication::translate("phase_dialog", "\345\210\235\345\247\213\345\214\226:", 0));
        label_24->setText(QApplication::translate("phase_dialog", "\346\234\272\345\212\250\350\275\246\350\207\252\345\212\250\350\257\267\346\261\202:", 0));
        comboBox_Startup->clear();
        comboBox_Startup->insertItems(0, QStringList()
         << QApplication::translate("phase_dialog", "\346\234\252\345\220\257\347\224\250", 0)
         << QApplication::translate("phase_dialog", "\347\273\277\347\201\257", 0)
         << QApplication::translate("phase_dialog", "\346\234\272\345\212\250\350\275\246\347\273\277\347\201\257", 0)
         << QApplication::translate("phase_dialog", "\351\273\204\347\201\257", 0)
         << QApplication::translate("phase_dialog", "\347\272\242\347\201\257", 0)
         << QApplication::translate("phase_dialog", "\345\205\263\347\201\257", 0)
        );
        comboBox_VehicleRequest->clear();
        comboBox_VehicleRequest->insertItems(0, QStringList()
         << QApplication::translate("phase_dialog", "\346\234\252\345\256\232\344\271\211", 0)
         << QApplication::translate("phase_dialog", "\346\234\200\345\260\217\350\257\267\346\261\202", 0)
         << QApplication::translate("phase_dialog", "\346\234\200\345\244\247\350\257\267\346\261\202", 0)
         << QApplication::translate("phase_dialog", "\350\275\257\350\257\267\346\261\202", 0)
        );
        comboBox_NoneInduction->clear();
        comboBox_NoneInduction->insertItems(0, QStringList()
         << QApplication::translate("phase_dialog", "\346\234\252\345\256\232\344\271\211", 0)
         << QApplication::translate("phase_dialog", "TS\351\235\236\346\204\237\345\272\2241", 0)
         << QApplication::translate("phase_dialog", "TS\351\235\236\346\204\237\345\272\2242", 0)
         << QApplication::translate("phase_dialog", "TS\351\235\236\346\204\237\345\272\2241-2", 0)
        );
        checkBox_AutoFlashIn->setText(QApplication::translate("phase_dialog", "\350\207\252\345\212\250\351\227\252\345\205\211\350\277\233\345\205\245", 0));
        checkBox_AutoFlashOut->setText(QApplication::translate("phase_dialog", "\350\207\252\345\212\250\351\227\252\345\205\211\351\200\200\345\207\272", 0));
        checkBox_PedAutoRequest->setText(QApplication::translate("phase_dialog", "\350\241\214\344\272\272\350\207\252\345\212\250\350\257\267\346\261\202", 0));
        label_Ring->setText(QApplication::translate("phase_dialog", "\345\261\236\344\272\216\347\216\257\357\274\232", 0));
        comboBox_Ring->clear();
        comboBox_Ring->insertItems(0, QStringList()
         << QApplication::translate("phase_dialog", "1", 0)
         << QApplication::translate("phase_dialog", "2", 0)
         << QApplication::translate("phase_dialog", "3", 0)
         << QApplication::translate("phase_dialog", "4", 0)
        );
        groupBox_2->setTitle(QApplication::translate("phase_dialog", "\345\271\266\345\217\221\347\233\270\344\275\215", 0));
        pushButton_phaseConcurrency->setText(QApplication::translate("phase_dialog", "\342\200\246", 0));
        label_25->setText(QApplication::translate("phase_dialog", "\347\233\270\344\275\215\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class phase_dialog: public Ui_phase_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHASE_DIALOG_H
