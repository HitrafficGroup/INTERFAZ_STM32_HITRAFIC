/********************************************************************************
** Form generated from reading UI file 'peddet_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEDDET_DIALOG_H
#define UI_PEDDET_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_peddet_dialog
{
public:
    QLabel *label1;
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_cancel;
    QSpinBox *spinBox_Num;
    QFrame *line;
    QGroupBox *groupBox;
    QSpinBox *spinBox_NoActivity;
    QSpinBox *spinBox_MaxPresence;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QSpinBox *spinBox_CallPhase;
    QSpinBox *spinBox_ErraticCounts;
    QLabel *label5;

    void setupUi(QDialog *peddet_dialog)
    {
        if (peddet_dialog->objectName().isEmpty())
            peddet_dialog->setObjectName(QStringLiteral("peddet_dialog"));
        peddet_dialog->resize(460, 220);
        label1 = new QLabel(peddet_dialog);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(11, 10, 101, 21));
        pushButton_confirm = new QPushButton(peddet_dialog);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        pushButton_confirm->setGeometry(QRect(250, 180, 90, 28));
        pushButton_cancel = new QPushButton(peddet_dialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(350, 180, 90, 28));
        spinBox_Num = new QSpinBox(peddet_dialog);
        spinBox_Num->setObjectName(QStringLiteral("spinBox_Num"));
        spinBox_Num->setGeometry(QRect(110, 10, 71, 21));
        spinBox_Num->setMinimum(1);
        spinBox_Num->setMaximum(8);
        spinBox_Num->setDisplayIntegerBase(10);
        line = new QFrame(peddet_dialog);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(7, 160, 441, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox = new QGroupBox(peddet_dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 50, 441, 111));
        spinBox_NoActivity = new QSpinBox(groupBox);
        spinBox_NoActivity->setObjectName(QStringLiteral("spinBox_NoActivity"));
        spinBox_NoActivity->setEnabled(true);
        spinBox_NoActivity->setGeometry(QRect(350, 30, 71, 21));
        spinBox_NoActivity->setKeyboardTracking(false);
        spinBox_NoActivity->setMinimum(0);
        spinBox_NoActivity->setMaximum(255);
        spinBox_MaxPresence = new QSpinBox(groupBox);
        spinBox_MaxPresence->setObjectName(QStringLiteral("spinBox_MaxPresence"));
        spinBox_MaxPresence->setEnabled(true);
        spinBox_MaxPresence->setGeometry(QRect(150, 70, 71, 21));
        spinBox_MaxPresence->setKeyboardTracking(false);
        spinBox_MaxPresence->setMinimum(0);
        spinBox_MaxPresence->setMaximum(255);
        label2 = new QLabel(groupBox);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(10, 30, 141, 21));
        label2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label3 = new QLabel(groupBox);
        label3->setObjectName(QStringLiteral("label3"));
        label3->setGeometry(QRect(220, 30, 131, 21));
        label3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label4 = new QLabel(groupBox);
        label4->setObjectName(QStringLiteral("label4"));
        label4->setGeometry(QRect(10, 70, 141, 21));
        label4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_CallPhase = new QSpinBox(groupBox);
        spinBox_CallPhase->setObjectName(QStringLiteral("spinBox_CallPhase"));
        spinBox_CallPhase->setEnabled(true);
        spinBox_CallPhase->setGeometry(QRect(150, 30, 71, 21));
        spinBox_CallPhase->setKeyboardTracking(false);
        spinBox_CallPhase->setMinimum(0);
        spinBox_CallPhase->setMaximum(32);
        spinBox_ErraticCounts = new QSpinBox(groupBox);
        spinBox_ErraticCounts->setObjectName(QStringLiteral("spinBox_ErraticCounts"));
        spinBox_ErraticCounts->setEnabled(true);
        spinBox_ErraticCounts->setGeometry(QRect(350, 70, 71, 21));
        spinBox_ErraticCounts->setKeyboardTracking(false);
        spinBox_ErraticCounts->setMinimum(0);
        spinBox_ErraticCounts->setMaximum(255);
        label5 = new QLabel(groupBox);
        label5->setObjectName(QStringLiteral("label5"));
        label5->setGeometry(QRect(220, 70, 131, 21));
        label5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(peddet_dialog);

        QMetaObject::connectSlotsByName(peddet_dialog);
    } // setupUi

    void retranslateUi(QDialog *peddet_dialog)
    {
        peddet_dialog->setWindowTitle(QApplication::translate("peddet_dialog", "\350\241\214\344\272\272\346\243\200\346\265\213\345\231\250", 0));
        label1->setText(QApplication::translate("peddet_dialog", "\346\243\200\346\265\213\345\231\250\347\274\226\345\217\267:", 0));
        pushButton_confirm->setText(QApplication::translate("peddet_dialog", "\347\241\256\345\256\232", 0));
        pushButton_cancel->setText(QApplication::translate("peddet_dialog", "\345\217\226\346\266\210", 0));
        groupBox->setTitle(QApplication::translate("peddet_dialog", "\345\261\236\346\200\247", 0));
        label2->setText(QApplication::translate("peddet_dialog", "\350\257\267\346\261\202\347\233\270\344\275\215:", 0));
        label3->setText(QApplication::translate("peddet_dialog", "\346\227\240\345\223\215\345\272\224\346\227\266\351\227\264:", 0));
        label4->setText(QApplication::translate("peddet_dialog", "\346\234\200\345\244\247\346\214\201\347\273\255\346\227\266\351\227\264:", 0));
        label5->setText(QApplication::translate("peddet_dialog", "\346\204\237\345\272\224\346\225\260/\345\210\206\351\222\237:", 0));
    } // retranslateUi

};

namespace Ui {
    class peddet_dialog: public Ui_peddet_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEDDET_DIALOG_H
