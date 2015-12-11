/********************************************************************************
** Form generated from reading UI file 'optionselectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSELECTDIALOG_H
#define UI_OPTIONSELECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_OptionSelectDialog
{
public:

    void setupUi(QDialog *OptionSelectDialog)
    {
        if (OptionSelectDialog->objectName().isEmpty())
            OptionSelectDialog->setObjectName(QStringLiteral("OptionSelectDialog"));
        OptionSelectDialog->resize(240, 320);

        retranslateUi(OptionSelectDialog);

        QMetaObject::connectSlotsByName(OptionSelectDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionSelectDialog)
    {
        OptionSelectDialog->setWindowTitle(QApplication::translate("OptionSelectDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class OptionSelectDialog: public Ui_OptionSelectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSELECTDIALOG_H
