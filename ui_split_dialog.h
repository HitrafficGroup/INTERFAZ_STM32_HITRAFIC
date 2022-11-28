/********************************************************************************
** Form generated from reading UI file 'split_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLIT_DIALOG_H
#define UI_SPLIT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_split_dialog
{
public:
    QLabel *label_split;
    QPushButton *pushButton_confirm;
    QLabel *label_mode;
    QPushButton *pushButton_cancel;
    QLabel *label_countdown;
    QSpinBox *spinBox_Time;
    QComboBox *comboBox_Mode;
    QCheckBox *checkBox_AsCoordPhase;
    QCheckBox *checkBox_AsFixedPhase;
    QCheckBox *checkBox_AsKeyPhase;
    QLabel *label_phase;
    QSpinBox *spinBox_PhaseNumber;
    QFrame *line;

    void setupUi(QDialog *split_dialog)
    {
        if (split_dialog->objectName().isEmpty())
            split_dialog->setObjectName(QStringLiteral("split_dialog"));
        split_dialog->resize(460, 220);
        label_split = new QLabel(split_dialog);
        label_split->setObjectName(QStringLiteral("label_split"));
        label_split->setGeometry(QRect(11, 60, 61, 21));
        pushButton_confirm = new QPushButton(split_dialog);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        pushButton_confirm->setGeometry(QRect(250, 180, 90, 28));
        label_mode = new QLabel(split_dialog);
        label_mode->setObjectName(QStringLiteral("label_mode"));
        label_mode->setGeometry(QRect(190, 60, 51, 21));
        label_mode->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_cancel = new QPushButton(split_dialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(350, 180, 90, 28));
        label_countdown = new QLabel(split_dialog);
        label_countdown->setObjectName(QStringLiteral("label_countdown"));
        label_countdown->setGeometry(QRect(140, 60, 51, 21));
        spinBox_Time = new QSpinBox(split_dialog);
        spinBox_Time->setObjectName(QStringLiteral("spinBox_Time"));
        spinBox_Time->setGeometry(QRect(70, 60, 71, 21));
        spinBox_Time->setMaximum(255);
        comboBox_Mode = new QComboBox(split_dialog);
        comboBox_Mode->setObjectName(QStringLiteral("comboBox_Mode"));
        comboBox_Mode->setGeometry(QRect(240, 60, 211, 21));
        comboBox_Mode->setMaxVisibleItems(7);
        checkBox_AsCoordPhase = new QCheckBox(split_dialog);
        checkBox_AsCoordPhase->setObjectName(QStringLiteral("checkBox_AsCoordPhase"));
        checkBox_AsCoordPhase->setGeometry(QRect(11, 100, 181, 21));
        checkBox_AsFixedPhase = new QCheckBox(split_dialog);
        checkBox_AsFixedPhase->setObjectName(QStringLiteral("checkBox_AsFixedPhase"));
        checkBox_AsFixedPhase->setGeometry(QRect(11, 130, 181, 21));
        checkBox_AsKeyPhase = new QCheckBox(split_dialog);
        checkBox_AsKeyPhase->setObjectName(QStringLiteral("checkBox_AsKeyPhase"));
        checkBox_AsKeyPhase->setGeometry(QRect(210, 100, 241, 21));
        label_phase = new QLabel(split_dialog);
        label_phase->setObjectName(QStringLiteral("label_phase"));
        label_phase->setGeometry(QRect(10, 20, 61, 21));
        spinBox_PhaseNumber = new QSpinBox(split_dialog);
        spinBox_PhaseNumber->setObjectName(QStringLiteral("spinBox_PhaseNumber"));
        spinBox_PhaseNumber->setEnabled(true);
        spinBox_PhaseNumber->setGeometry(QRect(70, 20, 71, 21));
        spinBox_PhaseNumber->setKeyboardTracking(false);
        spinBox_PhaseNumber->setMinimum(1);
        spinBox_PhaseNumber->setMaximum(32);
        line = new QFrame(split_dialog);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(7, 160, 441, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        retranslateUi(split_dialog);

        comboBox_Mode->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(split_dialog);
    } // setupUi

    void retranslateUi(QDialog *split_dialog)
    {
        split_dialog->setWindowTitle(QApplication::translate("split_dialog", "\347\273\277\344\277\241\346\257\224\347\274\226\350\276\221", 0));
        label_split->setText(QApplication::translate("split_dialog", "\347\273\277\344\277\241\346\257\224:", 0));
        pushButton_confirm->setText(QApplication::translate("split_dialog", "\347\241\256\345\256\232", 0));
        label_mode->setText(QApplication::translate("split_dialog", "\346\250\241\345\274\217:", 0));
        pushButton_cancel->setText(QApplication::translate("split_dialog", "\345\217\226\346\266\210", 0));
        label_countdown->setText(QApplication::translate("split_dialog", "\347\247\222", 0));
        comboBox_Mode->clear();
        comboBox_Mode->insertItems(0, QStringList()
         << QApplication::translate("split_dialog", "\345\205\266\344\273\226", 0)
         << QApplication::translate("split_dialog", "\346\227\240", 0)
         << QApplication::translate("split_dialog", "\346\234\200\345\260\217\350\275\246\350\276\206\345\223\215\345\272\224", 0)
         << QApplication::translate("split_dialog", "\346\234\200\345\244\247\350\275\246\350\276\206\345\223\215\345\272\224", 0)
         << QApplication::translate("split_dialog", "\350\241\214\344\272\272\345\223\215\345\272\224", 0)
         << QApplication::translate("split_dialog", "\346\234\200\345\244\247\350\275\246\350\276\206/\350\241\214\344\272\272\345\223\215\345\272\224", 0)
         << QApplication::translate("split_dialog", "\345\277\275\347\225\245\347\233\270\344\275\215", 0)
        );
        checkBox_AsCoordPhase->setText(QApplication::translate("split_dialog", "\344\275\234\344\270\272\345\215\217\350\260\203\347\233\270\344\275\215", 0));
        checkBox_AsFixedPhase->setText(QApplication::translate("split_dialog", "\344\275\234\344\270\272\345\233\272\345\256\232\347\233\270\344\275\215", 0));
        checkBox_AsKeyPhase->setText(QApplication::translate("split_dialog", "\344\275\234\344\270\272\345\205\263\351\224\256\347\233\270\344\275\215", 0));
        label_phase->setText(QApplication::translate("split_dialog", "\347\233\270\344\275\215:", 0));
    } // retranslateUi

};

namespace Ui {
    class split_dialog: public Ui_split_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLIT_DIALOG_H
