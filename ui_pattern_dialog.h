/********************************************************************************
** Form generated from reading UI file 'pattern_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATTERN_DIALOG_H
#define UI_PATTERN_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_pattern_dialog
{
public:
    QLabel *label;
    QComboBox *comboBox_Pattern;
    QPushButton *pushButton_confirm;
    QLabel *label_2;
    QPushButton *pushButton_cancel;
    QSpinBox *spinBox_SequenceNumber;
    QComboBox *comboBox_SplitNumber;
    QLabel *label_3;
    QLineEdit *lineEdit_CycleTime;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *spinBox_OffsetTime;
    QLabel *label_6;
    QComboBox *comboBox_WorkMode;

    void setupUi(QDialog *pattern_dialog)
    {
        if (pattern_dialog->objectName().isEmpty())
            pattern_dialog->setObjectName(QStringLiteral("pattern_dialog"));
        pattern_dialog->resize(330, 240);
        label = new QLabel(pattern_dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 81, 20));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_Pattern = new QComboBox(pattern_dialog);
        comboBox_Pattern->setObjectName(QStringLiteral("comboBox_Pattern"));
        comboBox_Pattern->setGeometry(QRect(90, 20, 71, 22));
        pushButton_confirm = new QPushButton(pattern_dialog);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        pushButton_confirm->setGeometry(QRect(120, 200, 93, 28));
        label_2 = new QLabel(pattern_dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 20, 61, 20));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_cancel = new QPushButton(pattern_dialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(220, 200, 93, 28));
        spinBox_SequenceNumber = new QSpinBox(pattern_dialog);
        spinBox_SequenceNumber->setObjectName(QStringLiteral("spinBox_SequenceNumber"));
        spinBox_SequenceNumber->setGeometry(QRect(90, 100, 71, 21));
        spinBox_SequenceNumber->setMinimum(1);
        spinBox_SequenceNumber->setMaximum(32);
        comboBox_SplitNumber = new QComboBox(pattern_dialog);
        comboBox_SplitNumber->setObjectName(QStringLiteral("comboBox_SplitNumber"));
        comboBox_SplitNumber->setEnabled(true);
        comboBox_SplitNumber->setGeometry(QRect(230, 20, 81, 22));
        label_3 = new QLabel(pattern_dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 60, 81, 20));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_CycleTime = new QLineEdit(pattern_dialog);
        lineEdit_CycleTime->setObjectName(QStringLiteral("lineEdit_CycleTime"));
        lineEdit_CycleTime->setEnabled(false);
        lineEdit_CycleTime->setGeometry(QRect(90, 60, 71, 21));
        label_4 = new QLabel(pattern_dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(170, 60, 61, 20));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(pattern_dialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 100, 81, 20));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_OffsetTime = new QSpinBox(pattern_dialog);
        spinBox_OffsetTime->setObjectName(QStringLiteral("spinBox_OffsetTime"));
        spinBox_OffsetTime->setGeometry(QRect(230, 60, 81, 21));
        spinBox_OffsetTime->setMinimum(0);
        spinBox_OffsetTime->setMaximum(255);
        spinBox_OffsetTime->setValue(0);
        label_6 = new QLabel(pattern_dialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 143, 81, 20));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_WorkMode = new QComboBox(pattern_dialog);
        comboBox_WorkMode->setObjectName(QStringLiteral("comboBox_WorkMode"));
        comboBox_WorkMode->setEnabled(true);
        comboBox_WorkMode->setGeometry(QRect(90, 140, 221, 26));

        retranslateUi(pattern_dialog);

        comboBox_SplitNumber->setCurrentIndex(-1);
        comboBox_WorkMode->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(pattern_dialog);
    } // setupUi

    void retranslateUi(QDialog *pattern_dialog)
    {
        pattern_dialog->setWindowTitle(QApplication::translate("pattern_dialog", "\346\226\271\346\241\210\347\274\226\350\276\221", 0));
        label->setText(QApplication::translate("pattern_dialog", "\346\226\271\346\241\210\345\217\267:", 0));
        pushButton_confirm->setText(QApplication::translate("pattern_dialog", "\347\241\256\345\256\232", 0));
        label_2->setText(QApplication::translate("pattern_dialog", "\347\273\277\344\277\241\346\257\224:", 0));
        pushButton_cancel->setText(QApplication::translate("pattern_dialog", "\345\217\226\346\266\210", 0));
        label_3->setText(QApplication::translate("pattern_dialog", "\345\221\250\346\234\237\351\225\277:", 0));
        label_4->setText(QApplication::translate("pattern_dialog", "\347\233\270\344\275\215\345\267\256:", 0));
        label_5->setText(QApplication::translate("pattern_dialog", "\347\233\270\345\272\217\350\241\250:", 0));
        label_6->setText(QApplication::translate("pattern_dialog", "\346\250\241  \345\274\217:", 0));
        comboBox_WorkMode->clear();
        comboBox_WorkMode->insertItems(0, QStringList()
         << QApplication::translate("pattern_dialog", "\345\256\232\345\221\250\346\234\237", 0)
         << QApplication::translate("pattern_dialog", "\347\273\277\346\263\242\346\216\247\345\210\266", 0)
         << QApplication::translate("pattern_dialog", "\346\204\237\345\272\224\346\216\247\345\210\266", 0)
         << QApplication::translate("pattern_dialog", "\351\227\252\345\205\211\346\216\247\345\210\266", 0)
         << QApplication::translate("pattern_dialog", "\345\205\250\347\272\242\346\250\241\345\274\217", 0)
         << QApplication::translate("pattern_dialog", "\345\205\263\347\201\257\346\250\241\345\274\217", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class pattern_dialog: public Ui_pattern_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATTERN_DIALOG_H
