/********************************************************************************
** Form generated from reading UI file 'DialogSuprimmerCompte.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSUPRIMMERCOMPTE_H
#define UI_DIALOGSUPRIMMERCOMPTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_DialogSuprimmerCompte
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogSuprimmerCompte)
    {
        if (DialogSuprimmerCompte->objectName().isEmpty())
            DialogSuprimmerCompte->setObjectName(QString::fromUtf8("DialogSuprimmerCompte"));
        DialogSuprimmerCompte->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogSuprimmerCompte);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogSuprimmerCompte);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogSuprimmerCompte, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogSuprimmerCompte, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogSuprimmerCompte);
    } // setupUi

    void retranslateUi(QDialog *DialogSuprimmerCompte)
    {
        DialogSuprimmerCompte->setWindowTitle(QCoreApplication::translate("DialogSuprimmerCompte", "DialogSuprimmerCompte", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSuprimmerCompte: public Ui_DialogSuprimmerCompte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSUPRIMMERCOMPTE_H
