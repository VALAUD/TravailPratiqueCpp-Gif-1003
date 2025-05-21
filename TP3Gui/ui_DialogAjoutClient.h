/********************************************************************************
** Form generated from reading UI file 'DialogAjoutClient.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAJOUTCLIENT_H
#define UI_DIALOGAJOUTCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogAjoutClient
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *nom;
    QLineEdit *prenom;
    QLineEdit *noTelephone;
    QCalendarWidget *dateN;
    QSpinBox *noFolio;
    QPushButton *pushButton;

    void setupUi(QDialog *DialogAjoutClient)
    {
        if (DialogAjoutClient->objectName().isEmpty())
            DialogAjoutClient->setObjectName(QString::fromUtf8("DialogAjoutClient"));
        DialogAjoutClient->resize(707, 607);
        label = new QLabel(DialogAjoutClient);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 60, 141, 16));
        label_2 = new QLabel(DialogAjoutClient);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 100, 58, 16));
        label_3 = new QLabel(DialogAjoutClient);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 140, 58, 16));
        label_4 = new QLabel(DialogAjoutClient);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 180, 191, 16));
        label_5 = new QLabel(DialogAjoutClient);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 360, 171, 16));
        nom = new QLineEdit(DialogAjoutClient);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(210, 90, 171, 28));
        prenom = new QLineEdit(DialogAjoutClient);
        prenom->setObjectName(QString::fromUtf8("prenom"));
        prenom->setGeometry(QRect(210, 130, 171, 28));
        noTelephone = new QLineEdit(DialogAjoutClient);
        noTelephone->setObjectName(QString::fromUtf8("noTelephone"));
        noTelephone->setGeometry(QRect(210, 170, 171, 28));
        dateN = new QCalendarWidget(DialogAjoutClient);
        dateN->setObjectName(QString::fromUtf8("dateN"));
        dateN->setGeometry(QRect(190, 250, 461, 221));
        noFolio = new QSpinBox(DialogAjoutClient);
        noFolio->setObjectName(QString::fromUtf8("noFolio"));
        noFolio->setGeometry(QRect(210, 50, 71, 26));
        noFolio->setMinimum(1000);
        noFolio->setMaximum(10000);
        pushButton = new QPushButton(DialogAjoutClient);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 530, 90, 28));

        retranslateUi(DialogAjoutClient);
        QObject::connect(pushButton, SIGNAL(clicked()), DialogAjoutClient, SLOT(valider()));

        QMetaObject::connectSlotsByName(DialogAjoutClient);
    } // setupUi

    void retranslateUi(QDialog *DialogAjoutClient)
    {
        DialogAjoutClient->setWindowTitle(QCoreApplication::translate("DialogAjoutClient", "DialogAjoutClient", nullptr));
        label->setText(QCoreApplication::translate("DialogAjoutClient", "Numero de folio:", nullptr));
        label_2->setText(QCoreApplication::translate("DialogAjoutClient", "Nom:", nullptr));
        label_3->setText(QCoreApplication::translate("DialogAjoutClient", "Prenom:", nullptr));
        label_4->setText(QCoreApplication::translate("DialogAjoutClient", "Numero de telephone: ", nullptr));
        label_5->setText(QCoreApplication::translate("DialogAjoutClient", "Date de naissance:", nullptr));
        pushButton->setText(QCoreApplication::translate("DialogAjoutClient", "Terminer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAjoutClient: public Ui_DialogAjoutClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAJOUTCLIENT_H
