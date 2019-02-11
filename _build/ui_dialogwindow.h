/********************************************************************************
** Form generated from reading UI file 'dialogwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGWINDOW_H
#define UI_DIALOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;

    void setupUi(QDialog *DialogWindow)
    {
        if (DialogWindow->objectName().isEmpty())
            DialogWindow->setObjectName(QStringLiteral("DialogWindow"));
        DialogWindow->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(DialogWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 100, 211, 81));

        retranslateUi(DialogWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogWindow);
    } // setupUi

    void retranslateUi(QDialog *DialogWindow)
    {
        DialogWindow->setWindowTitle(QApplication::translate("DialogWindow", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogWindow: public Ui_DialogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGWINDOW_H
