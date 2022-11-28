/********************************************************************************
** Form generated from reading UI file 'schedule_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULE_DIALOG_H
#define UI_SCHEDULE_DIALOG_H

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

class Ui_schedule_dialog
{
public:
    QLabel *label;
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_cancel;
    QLabel *label_3;
    QComboBox *comboBox_ScheduleNum;
    QComboBox *comboBox_DayPlanNum;
    QGroupBox *groupBox_m;
    QCheckBox *checkBox_m1;
    QCheckBox *checkBox_m2;
    QCheckBox *checkBox_m3;
    QCheckBox *checkBox_m4;
    QCheckBox *checkBox_m5;
    QCheckBox *checkBox_m6;
    QCheckBox *checkBox_m8;
    QCheckBox *checkBox_m7;
    QCheckBox *checkBox_m11;
    QCheckBox *checkBox_m9;
    QCheckBox *checkBox_m10;
    QCheckBox *checkBox_m12;
    QCheckBox *checkBox_month;
    QGroupBox *groupBox_d;
    QCheckBox *checkBox_d1;
    QCheckBox *checkBox_d2;
    QCheckBox *checkBox_d5;
    QCheckBox *checkBox_d3;
    QCheckBox *checkBox_d4;
    QCheckBox *checkBox_d6;
    QCheckBox *checkBox_d7;
    QCheckBox *checkBox_d8;
    QCheckBox *checkBox_d9;
    QCheckBox *checkBox_d10;
    QCheckBox *checkBox_d11;
    QCheckBox *checkBox_d14;
    QCheckBox *checkBox_d15;
    QCheckBox *checkBox_d17;
    QCheckBox *checkBox_d18;
    QCheckBox *checkBox_d16;
    QCheckBox *checkBox_d20;
    QCheckBox *checkBox_d19;
    QCheckBox *checkBox_d13;
    QCheckBox *checkBox_d12;
    QCheckBox *checkBox_d21;
    QCheckBox *checkBox_d24;
    QCheckBox *checkBox_d25;
    QCheckBox *checkBox_d27;
    QCheckBox *checkBox_d28;
    QCheckBox *checkBox_d26;
    QCheckBox *checkBox_d30;
    QCheckBox *checkBox_d29;
    QCheckBox *checkBox_d23;
    QCheckBox *checkBox_d22;
    QCheckBox *checkBox_d31;
    QCheckBox *checkBox_date1;
    QCheckBox *checkBox_date2;
    QCheckBox *checkBox_date3;
    QCheckBox *checkBox_date4;
    QGroupBox *groupBox_w;
    QCheckBox *checkBox_w2;
    QCheckBox *checkBox_w3;
    QCheckBox *checkBox_w4;
    QCheckBox *checkBox_w5;
    QCheckBox *checkBox_w6;
    QCheckBox *checkBox_w7;
    QCheckBox *checkBox_w1;
    QCheckBox *checkBox_day;

    void setupUi(QDialog *schedule_dialog)
    {
        if (schedule_dialog->objectName().isEmpty())
            schedule_dialog->setObjectName(QStringLiteral("schedule_dialog"));
        schedule_dialog->resize(458, 466);
        label = new QLabel(schedule_dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 91, 26));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_confirm = new QPushButton(schedule_dialog);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        pushButton_confirm->setGeometry(QRect(260, 430, 90, 28));
        pushButton_cancel = new QPushButton(schedule_dialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(360, 430, 90, 28));
        label_3 = new QLabel(schedule_dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 60, 91, 26));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_ScheduleNum = new QComboBox(schedule_dialog);
        comboBox_ScheduleNum->setObjectName(QStringLiteral("comboBox_ScheduleNum"));
        comboBox_ScheduleNum->setGeometry(QRect(120, 20, 141, 26));
        comboBox_DayPlanNum = new QComboBox(schedule_dialog);
        comboBox_DayPlanNum->setObjectName(QStringLiteral("comboBox_DayPlanNum"));
        comboBox_DayPlanNum->setGeometry(QRect(120, 60, 141, 26));
        groupBox_m = new QGroupBox(schedule_dialog);
        groupBox_m->setObjectName(QStringLiteral("groupBox_m"));
        groupBox_m->setGeometry(QRect(10, 100, 81, 311));
        checkBox_m1 = new QCheckBox(groupBox_m);
        checkBox_m1->setObjectName(QStringLiteral("checkBox_m1"));
        checkBox_m1->setGeometry(QRect(20, 30, 51, 19));
        checkBox_m2 = new QCheckBox(groupBox_m);
        checkBox_m2->setObjectName(QStringLiteral("checkBox_m2"));
        checkBox_m2->setGeometry(QRect(20, 50, 51, 19));
        checkBox_m3 = new QCheckBox(groupBox_m);
        checkBox_m3->setObjectName(QStringLiteral("checkBox_m3"));
        checkBox_m3->setGeometry(QRect(20, 70, 51, 19));
        checkBox_m4 = new QCheckBox(groupBox_m);
        checkBox_m4->setObjectName(QStringLiteral("checkBox_m4"));
        checkBox_m4->setGeometry(QRect(20, 90, 51, 19));
        checkBox_m5 = new QCheckBox(groupBox_m);
        checkBox_m5->setObjectName(QStringLiteral("checkBox_m5"));
        checkBox_m5->setGeometry(QRect(20, 110, 51, 19));
        checkBox_m6 = new QCheckBox(groupBox_m);
        checkBox_m6->setObjectName(QStringLiteral("checkBox_m6"));
        checkBox_m6->setGeometry(QRect(20, 130, 51, 19));
        checkBox_m8 = new QCheckBox(groupBox_m);
        checkBox_m8->setObjectName(QStringLiteral("checkBox_m8"));
        checkBox_m8->setGeometry(QRect(20, 170, 51, 19));
        checkBox_m7 = new QCheckBox(groupBox_m);
        checkBox_m7->setObjectName(QStringLiteral("checkBox_m7"));
        checkBox_m7->setGeometry(QRect(20, 150, 51, 19));
        checkBox_m11 = new QCheckBox(groupBox_m);
        checkBox_m11->setObjectName(QStringLiteral("checkBox_m11"));
        checkBox_m11->setGeometry(QRect(20, 230, 51, 19));
        checkBox_m9 = new QCheckBox(groupBox_m);
        checkBox_m9->setObjectName(QStringLiteral("checkBox_m9"));
        checkBox_m9->setGeometry(QRect(20, 190, 51, 19));
        checkBox_m10 = new QCheckBox(groupBox_m);
        checkBox_m10->setObjectName(QStringLiteral("checkBox_m10"));
        checkBox_m10->setGeometry(QRect(20, 210, 51, 19));
        checkBox_m12 = new QCheckBox(groupBox_m);
        checkBox_m12->setObjectName(QStringLiteral("checkBox_m12"));
        checkBox_m12->setGeometry(QRect(20, 250, 51, 19));
        checkBox_month = new QCheckBox(groupBox_m);
        checkBox_month->setObjectName(QStringLiteral("checkBox_month"));
        checkBox_month->setGeometry(QRect(20, 280, 61, 19));
        groupBox_d = new QGroupBox(schedule_dialog);
        groupBox_d->setObjectName(QStringLiteral("groupBox_d"));
        groupBox_d->setGeometry(QRect(100, 100, 261, 311));
        checkBox_d1 = new QCheckBox(groupBox_d);
        checkBox_d1->setObjectName(QStringLiteral("checkBox_d1"));
        checkBox_d1->setGeometry(QRect(20, 30, 40, 19));
        checkBox_d2 = new QCheckBox(groupBox_d);
        checkBox_d2->setObjectName(QStringLiteral("checkBox_d2"));
        checkBox_d2->setGeometry(QRect(20, 60, 40, 19));
        checkBox_d5 = new QCheckBox(groupBox_d);
        checkBox_d5->setObjectName(QStringLiteral("checkBox_d5"));
        checkBox_d5->setGeometry(QRect(20, 150, 40, 19));
        checkBox_d3 = new QCheckBox(groupBox_d);
        checkBox_d3->setObjectName(QStringLiteral("checkBox_d3"));
        checkBox_d3->setGeometry(QRect(20, 90, 40, 19));
        checkBox_d4 = new QCheckBox(groupBox_d);
        checkBox_d4->setObjectName(QStringLiteral("checkBox_d4"));
        checkBox_d4->setGeometry(QRect(20, 120, 40, 19));
        checkBox_d6 = new QCheckBox(groupBox_d);
        checkBox_d6->setObjectName(QStringLiteral("checkBox_d6"));
        checkBox_d6->setGeometry(QRect(20, 180, 40, 19));
        checkBox_d7 = new QCheckBox(groupBox_d);
        checkBox_d7->setObjectName(QStringLiteral("checkBox_d7"));
        checkBox_d7->setGeometry(QRect(20, 210, 40, 19));
        checkBox_d8 = new QCheckBox(groupBox_d);
        checkBox_d8->setObjectName(QStringLiteral("checkBox_d8"));
        checkBox_d8->setGeometry(QRect(20, 240, 40, 19));
        checkBox_d9 = new QCheckBox(groupBox_d);
        checkBox_d9->setObjectName(QStringLiteral("checkBox_d9"));
        checkBox_d9->setGeometry(QRect(80, 30, 41, 19));
        checkBox_d10 = new QCheckBox(groupBox_d);
        checkBox_d10->setObjectName(QStringLiteral("checkBox_d10"));
        checkBox_d10->setGeometry(QRect(80, 60, 40, 19));
        checkBox_d11 = new QCheckBox(groupBox_d);
        checkBox_d11->setObjectName(QStringLiteral("checkBox_d11"));
        checkBox_d11->setGeometry(QRect(80, 90, 40, 19));
        checkBox_d14 = new QCheckBox(groupBox_d);
        checkBox_d14->setObjectName(QStringLiteral("checkBox_d14"));
        checkBox_d14->setGeometry(QRect(80, 180, 40, 19));
        checkBox_d15 = new QCheckBox(groupBox_d);
        checkBox_d15->setObjectName(QStringLiteral("checkBox_d15"));
        checkBox_d15->setGeometry(QRect(80, 210, 40, 19));
        checkBox_d17 = new QCheckBox(groupBox_d);
        checkBox_d17->setObjectName(QStringLiteral("checkBox_d17"));
        checkBox_d17->setGeometry(QRect(140, 30, 40, 19));
        checkBox_d18 = new QCheckBox(groupBox_d);
        checkBox_d18->setObjectName(QStringLiteral("checkBox_d18"));
        checkBox_d18->setGeometry(QRect(140, 60, 40, 19));
        checkBox_d16 = new QCheckBox(groupBox_d);
        checkBox_d16->setObjectName(QStringLiteral("checkBox_d16"));
        checkBox_d16->setGeometry(QRect(80, 240, 40, 19));
        checkBox_d20 = new QCheckBox(groupBox_d);
        checkBox_d20->setObjectName(QStringLiteral("checkBox_d20"));
        checkBox_d20->setGeometry(QRect(140, 120, 40, 19));
        checkBox_d19 = new QCheckBox(groupBox_d);
        checkBox_d19->setObjectName(QStringLiteral("checkBox_d19"));
        checkBox_d19->setGeometry(QRect(140, 90, 40, 19));
        checkBox_d13 = new QCheckBox(groupBox_d);
        checkBox_d13->setObjectName(QStringLiteral("checkBox_d13"));
        checkBox_d13->setGeometry(QRect(80, 150, 40, 19));
        checkBox_d12 = new QCheckBox(groupBox_d);
        checkBox_d12->setObjectName(QStringLiteral("checkBox_d12"));
        checkBox_d12->setGeometry(QRect(80, 120, 40, 19));
        checkBox_d21 = new QCheckBox(groupBox_d);
        checkBox_d21->setObjectName(QStringLiteral("checkBox_d21"));
        checkBox_d21->setGeometry(QRect(140, 150, 40, 19));
        checkBox_d24 = new QCheckBox(groupBox_d);
        checkBox_d24->setObjectName(QStringLiteral("checkBox_d24"));
        checkBox_d24->setGeometry(QRect(140, 240, 40, 19));
        checkBox_d25 = new QCheckBox(groupBox_d);
        checkBox_d25->setObjectName(QStringLiteral("checkBox_d25"));
        checkBox_d25->setGeometry(QRect(200, 30, 40, 19));
        checkBox_d27 = new QCheckBox(groupBox_d);
        checkBox_d27->setObjectName(QStringLiteral("checkBox_d27"));
        checkBox_d27->setGeometry(QRect(200, 90, 40, 19));
        checkBox_d28 = new QCheckBox(groupBox_d);
        checkBox_d28->setObjectName(QStringLiteral("checkBox_d28"));
        checkBox_d28->setGeometry(QRect(200, 120, 40, 19));
        checkBox_d26 = new QCheckBox(groupBox_d);
        checkBox_d26->setObjectName(QStringLiteral("checkBox_d26"));
        checkBox_d26->setGeometry(QRect(200, 60, 40, 19));
        checkBox_d30 = new QCheckBox(groupBox_d);
        checkBox_d30->setObjectName(QStringLiteral("checkBox_d30"));
        checkBox_d30->setGeometry(QRect(200, 180, 40, 19));
        checkBox_d29 = new QCheckBox(groupBox_d);
        checkBox_d29->setObjectName(QStringLiteral("checkBox_d29"));
        checkBox_d29->setGeometry(QRect(200, 150, 40, 19));
        checkBox_d23 = new QCheckBox(groupBox_d);
        checkBox_d23->setObjectName(QStringLiteral("checkBox_d23"));
        checkBox_d23->setGeometry(QRect(140, 210, 40, 19));
        checkBox_d22 = new QCheckBox(groupBox_d);
        checkBox_d22->setObjectName(QStringLiteral("checkBox_d22"));
        checkBox_d22->setGeometry(QRect(140, 180, 40, 19));
        checkBox_d31 = new QCheckBox(groupBox_d);
        checkBox_d31->setObjectName(QStringLiteral("checkBox_d31"));
        checkBox_d31->setGeometry(QRect(200, 210, 40, 19));
        checkBox_date1 = new QCheckBox(groupBox_d);
        checkBox_date1->setObjectName(QStringLiteral("checkBox_date1"));
        checkBox_date1->setGeometry(QRect(20, 280, 61, 19));
        checkBox_date2 = new QCheckBox(groupBox_d);
        checkBox_date2->setObjectName(QStringLiteral("checkBox_date2"));
        checkBox_date2->setGeometry(QRect(80, 280, 61, 19));
        checkBox_date3 = new QCheckBox(groupBox_d);
        checkBox_date3->setObjectName(QStringLiteral("checkBox_date3"));
        checkBox_date3->setGeometry(QRect(140, 280, 61, 19));
        checkBox_date4 = new QCheckBox(groupBox_d);
        checkBox_date4->setObjectName(QStringLiteral("checkBox_date4"));
        checkBox_date4->setGeometry(QRect(200, 280, 61, 19));
        groupBox_w = new QGroupBox(schedule_dialog);
        groupBox_w->setObjectName(QStringLiteral("groupBox_w"));
        groupBox_w->setGeometry(QRect(370, 100, 81, 311));
        checkBox_w2 = new QCheckBox(groupBox_w);
        checkBox_w2->setObjectName(QStringLiteral("checkBox_w2"));
        checkBox_w2->setGeometry(QRect(20, 60, 51, 19));
        checkBox_w3 = new QCheckBox(groupBox_w);
        checkBox_w3->setObjectName(QStringLiteral("checkBox_w3"));
        checkBox_w3->setGeometry(QRect(20, 90, 51, 19));
        checkBox_w4 = new QCheckBox(groupBox_w);
        checkBox_w4->setObjectName(QStringLiteral("checkBox_w4"));
        checkBox_w4->setGeometry(QRect(20, 120, 51, 19));
        checkBox_w5 = new QCheckBox(groupBox_w);
        checkBox_w5->setObjectName(QStringLiteral("checkBox_w5"));
        checkBox_w5->setGeometry(QRect(20, 150, 51, 19));
        checkBox_w6 = new QCheckBox(groupBox_w);
        checkBox_w6->setObjectName(QStringLiteral("checkBox_w6"));
        checkBox_w6->setGeometry(QRect(20, 180, 51, 19));
        checkBox_w7 = new QCheckBox(groupBox_w);
        checkBox_w7->setObjectName(QStringLiteral("checkBox_w7"));
        checkBox_w7->setGeometry(QRect(20, 210, 51, 19));
        checkBox_w1 = new QCheckBox(groupBox_w);
        checkBox_w1->setObjectName(QStringLiteral("checkBox_w1"));
        checkBox_w1->setGeometry(QRect(20, 30, 51, 19));
        checkBox_day = new QCheckBox(groupBox_w);
        checkBox_day->setObjectName(QStringLiteral("checkBox_day"));
        checkBox_day->setGeometry(QRect(20, 280, 61, 19));

        retranslateUi(schedule_dialog);

        QMetaObject::connectSlotsByName(schedule_dialog);
    } // setupUi

    void retranslateUi(QDialog *schedule_dialog)
    {
        schedule_dialog->setWindowTitle(QApplication::translate("schedule_dialog", "\350\260\203\345\272\246\350\256\241\345\210\222\347\274\226\350\276\221", 0));
        label->setText(QApplication::translate("schedule_dialog", "\350\260\203\345\272\246\350\256\241\345\210\222\345\217\267:", 0));
        pushButton_confirm->setText(QApplication::translate("schedule_dialog", "\347\241\256\345\256\232", 0));
        pushButton_cancel->setText(QApplication::translate("schedule_dialog", "\345\217\226\346\266\210", 0));
        label_3->setText(QApplication::translate("schedule_dialog", "\346\227\266\346\256\265\350\241\250\345\217\267:", 0));
        groupBox_m->setTitle(QApplication::translate("schedule_dialog", "\346\234\210\344\273\275", 0));
        checkBox_m1->setText(QApplication::translate("schedule_dialog", "1", 0));
        checkBox_m2->setText(QApplication::translate("schedule_dialog", "2", 0));
        checkBox_m3->setText(QApplication::translate("schedule_dialog", "3", 0));
        checkBox_m4->setText(QApplication::translate("schedule_dialog", "4", 0));
        checkBox_m5->setText(QApplication::translate("schedule_dialog", "5", 0));
        checkBox_m6->setText(QApplication::translate("schedule_dialog", "6", 0));
        checkBox_m8->setText(QApplication::translate("schedule_dialog", "8", 0));
        checkBox_m7->setText(QApplication::translate("schedule_dialog", "7", 0));
        checkBox_m11->setText(QApplication::translate("schedule_dialog", "11", 0));
        checkBox_m9->setText(QApplication::translate("schedule_dialog", "9", 0));
        checkBox_m10->setText(QApplication::translate("schedule_dialog", "10", 0));
        checkBox_m12->setText(QApplication::translate("schedule_dialog", "12", 0));
        checkBox_month->setText(QApplication::translate("schedule_dialog", "\345\205\250\351\200\211", 0));
        groupBox_d->setTitle(QApplication::translate("schedule_dialog", "\346\227\245\346\234\237", 0));
        checkBox_d1->setText(QApplication::translate("schedule_dialog", "1", 0));
        checkBox_d2->setText(QApplication::translate("schedule_dialog", "2", 0));
        checkBox_d5->setText(QApplication::translate("schedule_dialog", "5", 0));
        checkBox_d3->setText(QApplication::translate("schedule_dialog", "3", 0));
        checkBox_d4->setText(QApplication::translate("schedule_dialog", "4", 0));
        checkBox_d6->setText(QApplication::translate("schedule_dialog", "6", 0));
        checkBox_d7->setText(QApplication::translate("schedule_dialog", "7", 0));
        checkBox_d8->setText(QApplication::translate("schedule_dialog", "8", 0));
        checkBox_d9->setText(QApplication::translate("schedule_dialog", "9", 0));
        checkBox_d10->setText(QApplication::translate("schedule_dialog", "10", 0));
        checkBox_d11->setText(QApplication::translate("schedule_dialog", "11", 0));
        checkBox_d14->setText(QApplication::translate("schedule_dialog", "14", 0));
        checkBox_d15->setText(QApplication::translate("schedule_dialog", "15", 0));
        checkBox_d17->setText(QApplication::translate("schedule_dialog", "17", 0));
        checkBox_d18->setText(QApplication::translate("schedule_dialog", "18", 0));
        checkBox_d16->setText(QApplication::translate("schedule_dialog", "16", 0));
        checkBox_d20->setText(QApplication::translate("schedule_dialog", "20", 0));
        checkBox_d19->setText(QApplication::translate("schedule_dialog", "19", 0));
        checkBox_d13->setText(QApplication::translate("schedule_dialog", "13", 0));
        checkBox_d12->setText(QApplication::translate("schedule_dialog", "12", 0));
        checkBox_d21->setText(QApplication::translate("schedule_dialog", "21", 0));
        checkBox_d24->setText(QApplication::translate("schedule_dialog", "24", 0));
        checkBox_d25->setText(QApplication::translate("schedule_dialog", "25", 0));
        checkBox_d27->setText(QApplication::translate("schedule_dialog", "27", 0));
        checkBox_d28->setText(QApplication::translate("schedule_dialog", "28", 0));
        checkBox_d26->setText(QApplication::translate("schedule_dialog", "26", 0));
        checkBox_d30->setText(QApplication::translate("schedule_dialog", "30", 0));
        checkBox_d29->setText(QApplication::translate("schedule_dialog", "29", 0));
        checkBox_d23->setText(QApplication::translate("schedule_dialog", "23", 0));
        checkBox_d22->setText(QApplication::translate("schedule_dialog", "22", 0));
        checkBox_d31->setText(QApplication::translate("schedule_dialog", "31", 0));
        checkBox_date1->setText(QApplication::translate("schedule_dialog", "\345\205\250\351\200\211", 0));
        checkBox_date2->setText(QApplication::translate("schedule_dialog", "\345\205\250\351\200\211", 0));
        checkBox_date3->setText(QApplication::translate("schedule_dialog", "\345\205\250\351\200\211", 0));
        checkBox_date4->setText(QApplication::translate("schedule_dialog", "\345\205\250\351\200\211", 0));
        groupBox_w->setTitle(QApplication::translate("schedule_dialog", "\346\230\237\346\234\237", 0));
        checkBox_w2->setText(QApplication::translate("schedule_dialog", "1", 0));
        checkBox_w3->setText(QApplication::translate("schedule_dialog", "2", 0));
        checkBox_w4->setText(QApplication::translate("schedule_dialog", "3", 0));
        checkBox_w5->setText(QApplication::translate("schedule_dialog", "4", 0));
        checkBox_w6->setText(QApplication::translate("schedule_dialog", "5", 0));
        checkBox_w7->setText(QApplication::translate("schedule_dialog", "6", 0));
        checkBox_w1->setText(QApplication::translate("schedule_dialog", "\346\227\245", 0));
        checkBox_day->setText(QApplication::translate("schedule_dialog", "\345\205\250\351\200\211", 0));
    } // retranslateUi

};

namespace Ui {
    class schedule_dialog: public Ui_schedule_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULE_DIALOG_H
