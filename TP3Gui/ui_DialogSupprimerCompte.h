/********************************************************************************
** Form generated from reading UI file 'DialogSupprimerCompte.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSUPPRIMERCOMPTE_H
#define UI_DIALOGSUPPRIMERCOMPTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogSupprimerCompte
{
public:
    QLabel *label;
    QSpinBox *noCompteASuppr;
    QPushButton *pushButton;

    void setupUi(QDialog *DialogSupprimerCompte)
    {
        if (DialogSupprimerCompte->objectName().isEmpty())
            DialogSupprimerCompte->setObjectName(QString::fromUtf8("DialogSupprimerCompte"));
        DialogSupprimerCompte->resize(400, 300);
        label = new QLabel(DialogSupprimerCompte);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 120, 221, 16));
        noCompteASuppr = new QSpinBox(DialogSupprimerCompte);
        noCompteASuppr->setObjectName(QString::fromUtf8("noCompteASuppr"));
        noCompteASuppr->setGeometry(QRect(230, 110, 111, 26));
        noCompteASuppr->setMinimum(1000);
        noCompteASuppr->setMaximum(10000);
        pushButton = new QPushButton(DialogSupprimerCompte);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 220, 90, 28));

        retranslateUi(DialogSupprimerCompte);
        QObject::connect(pushButton, SIGNAL(clicked()), DialogSupprimerCompte, SLOT(valider()));

        QMetaObject::connectSlotsByName(DialogSupprimerCompte);
    } // setupUi

    void retranslateUi(QDialog *DialogSupprimerCompte)
    {
        DialogSupprimerCompte->setWindowTitle(QCoreApplication::translate("DialogSupprimerCompte", "DialogSupprimerCompte", nullptr));
        label->setText(QCoreApplication::translate("DialogSupprimerCompte", "Numero du compte a supprimer:", nullptr));
        pushButton->setText(QCoreApplication::translate("DialogSupprimerCompte", "Terminer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSupprimerCompte: public Ui_DialogSupprimerCompte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSUPPRIMERCOMPTE_H
