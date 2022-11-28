/********************************************************************************
** Form generated from reading UI file 'channel_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANNEL_DIALOG_H
#define UI_CHANNEL_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_channel_dialog
{
public:
    QLabel *label;
    QComboBox *comboBox_channelNum;
    QPushButton *pushButton_confirm;
    QLabel *label_2;
    QComboBox *comboBox_phase;
    QGroupBox *groupBox_type;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioPhase_vehicle;
    QRadioButton *radioPhase_ped;
    QRadioButton *radioPhase_follow;
    QRadioButton *radioPhase_other;
    QComboBox *comboBox_type;
    QGroupBox *groupBox_flash;
    QRadioButton *radioFlash_alternate;
    QRadioButton *radioFlash_red;
    QRadioButton *radioFlash_yel;
    QRadioButton *radioFlash_oth;
    QGroupBox *groupBox_dim;
    QRadioButton *radiodim_alternate;
    QRadioButton *radiodim_red;
    QRadioButton *radiodim_yel;
    QRadioButton *radiodim_gre;
    QPushButton *pushButton_cancel;
    QGroupBox *groupBox_countdown;
    QLabel *label_countdown;
    QCheckBox *checkBox_countdown;
    QSpinBox *spinBox_id;
    QGroupBox *groupBox;
    QComboBox *comboBox_Position;
    QComboBox *comboBox_Direction;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *channel_dialog)
    {
        if (channel_dialog->objectName().isEmpty())
            channel_dialog->setObjectName(QStringLiteral("channel_dialog"));
        channel_dialog->resize(430, 500);
        label = new QLabel(channel_dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(11, 20, 71, 20));
        comboBox_channelNum = new QComboBox(channel_dialog);
        comboBox_channelNum->setObjectName(QStringLiteral("comboBox_channelNum"));
        comboBox_channelNum->setGeometry(QRect(80, 20, 61, 22));
        pushButton_confirm = new QPushButton(channel_dialog);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        pushButton_confirm->setGeometry(QRect(230, 450, 93, 28));
        label_2 = new QLabel(channel_dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 20, 111, 20));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_phase = new QComboBox(channel_dialog);
        comboBox_phase->setObjectName(QStringLiteral("comboBox_phase"));
        comboBox_phase->setGeometry(QRect(250, 20, 91, 22));
        comboBox_phase->setMaxVisibleItems(6);
        groupBox_type = new QGroupBox(channel_dialog);
        groupBox_type->setObjectName(QStringLiteral("groupBox_type"));
        groupBox_type->setGeometry(QRect(10, 60, 411, 71));
        horizontalLayout = new QHBoxLayout(groupBox_type);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioPhase_vehicle = new QRadioButton(groupBox_type);
        radioPhase_vehicle->setObjectName(QStringLiteral("radioPhase_vehicle"));

        horizontalLayout->addWidget(radioPhase_vehicle);

        radioPhase_ped = new QRadioButton(groupBox_type);
        radioPhase_ped->setObjectName(QStringLiteral("radioPhase_ped"));

        horizontalLayout->addWidget(radioPhase_ped);

        radioPhase_follow = new QRadioButton(groupBox_type);
        radioPhase_follow->setObjectName(QStringLiteral("radioPhase_follow"));

        horizontalLayout->addWidget(radioPhase_follow);

        radioPhase_other = new QRadioButton(groupBox_type);
        radioPhase_other->setObjectName(QStringLiteral("radioPhase_other"));

        horizontalLayout->addWidget(radioPhase_other);

        comboBox_type = new QComboBox(groupBox_type);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));

        horizontalLayout->addWidget(comboBox_type);

        groupBox_flash = new QGroupBox(channel_dialog);
        groupBox_flash->setObjectName(QStringLiteral("groupBox_flash"));
        groupBox_flash->setGeometry(QRect(10, 140, 411, 61));
        radioFlash_alternate = new QRadioButton(groupBox_flash);
        radioFlash_alternate->setObjectName(QStringLiteral("radioFlash_alternate"));
        radioFlash_alternate->setGeometry(QRect(30, 30, 91, 19));
        radioFlash_red = new QRadioButton(groupBox_flash);
        radioFlash_red->setObjectName(QStringLiteral("radioFlash_red"));
        radioFlash_red->setGeometry(QRect(120, 30, 91, 19));
        radioFlash_yel = new QRadioButton(groupBox_flash);
        radioFlash_yel->setObjectName(QStringLiteral("radioFlash_yel"));
        radioFlash_yel->setGeometry(QRect(210, 30, 91, 19));
        radioFlash_oth = new QRadioButton(groupBox_flash);
        radioFlash_oth->setObjectName(QStringLiteral("radioFlash_oth"));
        radioFlash_oth->setGeometry(QRect(300, 30, 101, 19));
        groupBox_dim = new QGroupBox(channel_dialog);
        groupBox_dim->setObjectName(QStringLiteral("groupBox_dim"));
        groupBox_dim->setGeometry(QRect(10, 220, 411, 61));
        radiodim_alternate = new QRadioButton(groupBox_dim);
        radiodim_alternate->setObjectName(QStringLiteral("radiodim_alternate"));
        radiodim_alternate->setGeometry(QRect(30, 30, 91, 19));
        radiodim_red = new QRadioButton(groupBox_dim);
        radiodim_red->setObjectName(QStringLiteral("radiodim_red"));
        radiodim_red->setGeometry(QRect(120, 30, 91, 19));
        radiodim_yel = new QRadioButton(groupBox_dim);
        radiodim_yel->setObjectName(QStringLiteral("radiodim_yel"));
        radiodim_yel->setGeometry(QRect(210, 30, 91, 19));
        radiodim_gre = new QRadioButton(groupBox_dim);
        radiodim_gre->setObjectName(QStringLiteral("radiodim_gre"));
        radiodim_gre->setGeometry(QRect(300, 30, 101, 19));
        pushButton_cancel = new QPushButton(channel_dialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(330, 450, 93, 28));
        groupBox_countdown = new QGroupBox(channel_dialog);
        groupBox_countdown->setObjectName(QStringLiteral("groupBox_countdown"));
        groupBox_countdown->setGeometry(QRect(10, 370, 411, 71));
        label_countdown = new QLabel(groupBox_countdown);
        label_countdown->setObjectName(QStringLiteral("label_countdown"));
        label_countdown->setGeometry(QRect(160, 30, 141, 21));
        label_countdown->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_countdown = new QCheckBox(groupBox_countdown);
        checkBox_countdown->setObjectName(QStringLiteral("checkBox_countdown"));
        checkBox_countdown->setGeometry(QRect(30, 28, 131, 26));
        spinBox_id = new QSpinBox(groupBox_countdown);
        spinBox_id->setObjectName(QStringLiteral("spinBox_id"));
        spinBox_id->setGeometry(QRect(310, 28, 71, 26));
        spinBox_id->setMaximum(31);
        groupBox = new QGroupBox(channel_dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 290, 411, 71));
        comboBox_Position = new QComboBox(groupBox);
        comboBox_Position->setObjectName(QStringLiteral("comboBox_Position"));
        comboBox_Position->setGeometry(QRect(80, 30, 101, 22));
        comboBox_Direction = new QComboBox(groupBox);
        comboBox_Direction->setObjectName(QStringLiteral("comboBox_Direction"));
        comboBox_Direction->setGeometry(QRect(260, 30, 101, 22));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 30, 41, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(210, 30, 41, 20));

        retranslateUi(channel_dialog);

        QMetaObject::connectSlotsByName(channel_dialog);
    } // setupUi

    void retranslateUi(QDialog *channel_dialog)
    {
        channel_dialog->setWindowTitle(QApplication::translate("channel_dialog", "\351\200\232\351\201\223\347\274\226\350\276\221", 0));
        label->setText(QApplication::translate("channel_dialog", "\351\200\232\351\201\223\345\217\267\357\274\232", 0));
        comboBox_channelNum->clear();
        comboBox_channelNum->insertItems(0, QStringList()
         << QApplication::translate("channel_dialog", "1", 0)
         << QApplication::translate("channel_dialog", "2", 0)
         << QApplication::translate("channel_dialog", "3", 0)
         << QApplication::translate("channel_dialog", "4", 0)
         << QApplication::translate("channel_dialog", "5", 0)
         << QApplication::translate("channel_dialog", "6", 0)
         << QApplication::translate("channel_dialog", "7", 0)
         << QApplication::translate("channel_dialog", "8", 0)
         << QApplication::translate("channel_dialog", "9", 0)
         << QApplication::translate("channel_dialog", "10", 0)
         << QApplication::translate("channel_dialog", "11", 0)
         << QApplication::translate("channel_dialog", "12", 0)
         << QApplication::translate("channel_dialog", "13", 0)
         << QApplication::translate("channel_dialog", "14", 0)
         << QApplication::translate("channel_dialog", "15", 0)
         << QApplication::translate("channel_dialog", "16", 0)
         << QApplication::translate("channel_dialog", "17", 0)
         << QApplication::translate("channel_dialog", "18", 0)
         << QApplication::translate("channel_dialog", "19", 0)
         << QApplication::translate("channel_dialog", "20", 0)
         << QApplication::translate("channel_dialog", "21", 0)
         << QApplication::translate("channel_dialog", "22", 0)
         << QApplication::translate("channel_dialog", "23", 0)
         << QApplication::translate("channel_dialog", "24", 0)
         << QApplication::translate("channel_dialog", "25", 0)
         << QApplication::translate("channel_dialog", "26", 0)
         << QApplication::translate("channel_dialog", "27", 0)
         << QApplication::translate("channel_dialog", "28", 0)
         << QApplication::translate("channel_dialog", "29", 0)
         << QApplication::translate("channel_dialog", "30", 0)
         << QApplication::translate("channel_dialog", "31", 0)
         << QApplication::translate("channel_dialog", "32", 0)
        );
        pushButton_confirm->setText(QApplication::translate("channel_dialog", "\347\241\256\345\256\232", 0));
        label_2->setText(QApplication::translate("channel_dialog", "\346\216\247\345\210\266\346\272\220\357\274\232", 0));
        groupBox_type->setTitle(QApplication::translate("channel_dialog", "\346\216\247\345\210\266\347\261\273\345\236\213", 0));
        radioPhase_vehicle->setText(QApplication::translate("channel_dialog", "\346\234\272\345\212\250\350\275\246", 0));
        radioPhase_ped->setText(QApplication::translate("channel_dialog", "\350\241\214\344\272\272", 0));
        radioPhase_follow->setText(QApplication::translate("channel_dialog", "\350\267\237\351\232\217", 0));
        radioPhase_other->setText(QApplication::translate("channel_dialog", "\345\205\266\344\273\226", 0));
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QApplication::translate("channel_dialog", "\345\205\266\344\273\226", 0)
         << QApplication::translate("channel_dialog", "\351\227\252\347\201\257", 0)
         << QApplication::translate("channel_dialog", "\345\270\270\347\273\277", 0)
         << QApplication::translate("channel_dialog", "\345\270\270\347\272\242", 0)
        );
        groupBox_flash->setTitle(QApplication::translate("channel_dialog", "\351\227\252\345\205\211\346\250\241\345\274\217", 0));
        radioFlash_alternate->setText(QApplication::translate("channel_dialog", "\344\272\244\346\233\277", 0));
        radioFlash_red->setText(QApplication::translate("channel_dialog", "\347\272\242\351\227\252", 0));
        radioFlash_yel->setText(QApplication::translate("channel_dialog", "\351\273\204\351\227\252", 0));
        radioFlash_oth->setText(QApplication::translate("channel_dialog", "\345\205\266\344\273\226", 0));
        groupBox_dim->setTitle(QApplication::translate("channel_dialog", "\350\276\211\345\272\246\346\250\241\345\274\217", 0));
        radiodim_alternate->setText(QApplication::translate("channel_dialog", "\344\272\244\346\233\277", 0));
        radiodim_red->setText(QApplication::translate("channel_dialog", "\347\272\242\347\201\257", 0));
        radiodim_yel->setText(QApplication::translate("channel_dialog", "\351\273\204\347\201\257", 0));
        radiodim_gre->setText(QApplication::translate("channel_dialog", "\347\273\277\347\201\257", 0));
        pushButton_cancel->setText(QApplication::translate("channel_dialog", "\345\217\226\346\266\210", 0));
        groupBox_countdown->setTitle(QApplication::translate("channel_dialog", "\350\277\236\346\216\245\345\200\222\350\256\241\346\227\266\347\211\214", 0));
        label_countdown->setText(QApplication::translate("channel_dialog", "\345\200\222\350\256\241\346\227\266\345\234\260\345\235\200\357\274\232", 0));
        checkBox_countdown->setText(QApplication::translate("channel_dialog", "\345\220\257\347\224\250\351\200\232\350\256\257\345\200\222\350\256\241\346\227\266", 0));
        groupBox->setTitle(QApplication::translate("channel_dialog", "\346\216\247\345\210\266\346\226\271\345\220\221", 0));
        comboBox_Position->clear();
        comboBox_Position->insertItems(0, QStringList()
         << QApplication::translate("channel_dialog", "\345\205\266\344\273\226", 0)
         << QApplication::translate("channel_dialog", "\344\270\234", 0)
         << QApplication::translate("channel_dialog", "\345\215\227", 0)
         << QApplication::translate("channel_dialog", "\350\245\277", 0)
         << QApplication::translate("channel_dialog", "\345\214\227", 0)
         << QApplication::translate("channel_dialog", "\344\270\234\345\214\227", 0)
         << QApplication::translate("channel_dialog", "\344\270\234\345\215\227", 0)
         << QApplication::translate("channel_dialog", "\350\245\277\345\215\227", 0)
         << QApplication::translate("channel_dialog", "\350\245\277\345\214\227", 0)
        );
        comboBox_Direction->clear();
        comboBox_Direction->insertItems(0, QStringList()
         << QApplication::translate("channel_dialog", "\345\205\266\344\273\226", 0)
         << QApplication::translate("channel_dialog", "\345\267\246\350\275\254", 0)
         << QApplication::translate("channel_dialog", "\347\233\264\350\241\214", 0)
         << QApplication::translate("channel_dialog", "\345\217\263\350\275\254", 0)
         << QApplication::translate("channel_dialog", "\350\241\214\344\272\272", 0)
         << QApplication::translate("channel_dialog", "\346\216\211\345\244\264", 0)
         << QApplication::translate("channel_dialog", "\351\235\236\346\234\272\345\212\250", 0)
        );
        label_3->setText(QApplication::translate("channel_dialog", "\346\226\271\344\275\215\357\274\232", 0));
        label_4->setText(QApplication::translate("channel_dialog", "\346\226\271\345\220\221\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class channel_dialog: public Ui_channel_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNEL_DIALOG_H
