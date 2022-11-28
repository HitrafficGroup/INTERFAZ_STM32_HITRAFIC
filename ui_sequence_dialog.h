/********************************************************************************
** Form generated from reading UI file 'sequence_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEQUENCE_DIALOG_H
#define UI_SEQUENCE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_sequence_dialog
{
public:
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_cancel;
    QLabel *label;
    QSpinBox *spinBox_Ring;
    QListView *listSequence;
    QPushButton *pushButton_up;
    QPushButton *pushButton_down;
    QPushButton *pushButton_addPhase;
    QLabel *label_2;
    QComboBox *comboBox_Phase;
    QPushButton *pushButton_deletePhase;

    void setupUi(QDialog *sequence_dialog)
    {
        if (sequence_dialog->objectName().isEmpty())
            sequence_dialog->setObjectName(QStringLiteral("sequence_dialog"));
        sequence_dialog->resize(237, 400);
        pushButton_confirm = new QPushButton(sequence_dialog);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        pushButton_confirm->setGeometry(QRect(20, 360, 90, 28));
        pushButton_cancel = new QPushButton(sequence_dialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(130, 360, 90, 28));
        label = new QLabel(sequence_dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 31, 20));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_Ring = new QSpinBox(sequence_dialog);
        spinBox_Ring->setObjectName(QStringLiteral("spinBox_Ring"));
        spinBox_Ring->setGeometry(QRect(50, 20, 61, 22));
        spinBox_Ring->setKeyboardTracking(false);
        spinBox_Ring->setMinimum(1);
        spinBox_Ring->setMaximum(4);
        listSequence = new QListView(sequence_dialog);
        listSequence->setObjectName(QStringLiteral("listSequence"));
        listSequence->setGeometry(QRect(20, 50, 91, 301));
        pushButton_up = new QPushButton(sequence_dialog);
        pushButton_up->setObjectName(QStringLiteral("pushButton_up"));
        pushButton_up->setGeometry(QRect(130, 220, 90, 28));
        pushButton_down = new QPushButton(sequence_dialog);
        pushButton_down->setObjectName(QStringLiteral("pushButton_down"));
        pushButton_down->setGeometry(QRect(130, 260, 90, 28));
        pushButton_addPhase = new QPushButton(sequence_dialog);
        pushButton_addPhase->setObjectName(QStringLiteral("pushButton_addPhase"));
        pushButton_addPhase->setGeometry(QRect(130, 90, 90, 28));
        label_2 = new QLabel(sequence_dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 50, 31, 28));
        comboBox_Phase = new QComboBox(sequence_dialog);
        comboBox_Phase->setObjectName(QStringLiteral("comboBox_Phase"));
        comboBox_Phase->setGeometry(QRect(168, 50, 51, 28));
        pushButton_deletePhase = new QPushButton(sequence_dialog);
        pushButton_deletePhase->setObjectName(QStringLiteral("pushButton_deletePhase"));
        pushButton_deletePhase->setGeometry(QRect(130, 180, 90, 28));

        retranslateUi(sequence_dialog);

        QMetaObject::connectSlotsByName(sequence_dialog);
    } // setupUi

    void retranslateUi(QDialog *sequence_dialog)
    {
        sequence_dialog->setWindowTitle(QApplication::translate("sequence_dialog", "\347\233\270\345\272\217\347\274\226\350\276\221", 0));
        pushButton_confirm->setText(QApplication::translate("sequence_dialog", "\347\241\256\345\256\232", 0));
        pushButton_cancel->setText(QApplication::translate("sequence_dialog", "\345\217\226\346\266\210", 0));
        label->setText(QApplication::translate("sequence_dialog", "\347\216\257:", 0));
        pushButton_up->setText(QApplication::translate("sequence_dialog", "\345\220\221\344\270\212", 0));
        pushButton_down->setText(QApplication::translate("sequence_dialog", "\345\220\221\344\270\213", 0));
        pushButton_addPhase->setText(QApplication::translate("sequence_dialog", "\345\242\236\345\212\240", 0));
        label_2->setText(QApplication::translate("sequence_dialog", "\347\233\270\344\275\215\357\274\232", 0));
        pushButton_deletePhase->setText(QApplication::translate("sequence_dialog", "\345\210\240\351\231\244", 0));
    } // retranslateUi

};

namespace Ui {
    class sequence_dialog: public Ui_sequence_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEQUENCE_DIALOG_H
