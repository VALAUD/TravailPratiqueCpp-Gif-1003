/********************************************************************************
** Form generated from reading UI file 'DialogAjoutCompteCh.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAJOUTCOMPTECH_H
#define UI_DIALOGAJOUTCOMPTECH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogAjoutCompteCh
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpinBox *noCompte;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLineEdit *description;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QDoubleSpinBox *solde;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_13;
    QSpinBox *nbTransactions;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QCalendarWidget *dateO;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_10;
    QLabel *label_12;
    QDoubleSpinBox *tauxInteret;
    QLabel *label_11;
    QDoubleSpinBox *tauxInteretMin;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *DialogAjoutCompteCh)
    {
        if (DialogAjoutCompteCh->objectName().isEmpty())
            DialogAjoutCompteCh->setObjectName(QString::fromUtf8("DialogAjoutCompteCh"));
        DialogAjoutCompteCh->resize(459, 597);
        gridLayout = new QGridLayout(DialogAjoutCompteCh);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 0, 1, 3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(DialogAjoutCompteCh);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        noCompte = new QSpinBox(DialogAjoutCompteCh);
        noCompte->setObjectName(QString::fromUtf8("noCompte"));
        noCompte->setMinimum(1);
        noCompte->setMaximum(99999);

        horizontalLayout_3->addWidget(noCompte);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_9 = new QLabel(DialogAjoutCompteCh);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        horizontalLayout_4->addWidget(label_9);

        description = new QLineEdit(DialogAjoutCompteCh);
        description->setObjectName(QString::fromUtf8("description"));
        description->setMaxLength(20);

        horizontalLayout_4->addWidget(description);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_8 = new QLabel(DialogAjoutCompteCh);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        horizontalLayout->addWidget(label_8);

        solde = new QDoubleSpinBox(DialogAjoutCompteCh);
        solde->setObjectName(QString::fromUtf8("solde"));
        solde->setMinimum(-100000000000.000000000000000);
        solde->setMaximum(100000000000.000000000000000);
        solde->setValue(0.000000000000000);

        horizontalLayout->addWidget(solde);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_13 = new QLabel(DialogAjoutCompteCh);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);

        horizontalLayout_2->addWidget(label_13);

        nbTransactions = new QSpinBox(DialogAjoutCompteCh);
        nbTransactions->setObjectName(QString::fromUtf8("nbTransactions"));
        nbTransactions->setMaximum(40);

        horizontalLayout_2->addWidget(nbTransactions);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_2, 2, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_7 = new QLabel(DialogAjoutCompteCh);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label_7->setFont(font1);

        verticalLayout_3->addWidget(label_7);

        dateO = new QCalendarWidget(DialogAjoutCompteCh);
        dateO->setObjectName(QString::fromUtf8("dateO"));

        verticalLayout_3->addWidget(dateO);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(DialogAjoutCompteCh);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        verticalLayout_3->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout_3, 4, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 3);

        label_2 = new QLabel(DialogAjoutCompteCh);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font2.setPointSize(24);
        font2.setBold(false);
        font2.setWeight(50);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_10 = new QLabel(DialogAjoutCompteCh);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        verticalLayout->addWidget(label_10);

        label_12 = new QLabel(DialogAjoutCompteCh);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setWeight(50);
        label_12->setFont(font3);

        verticalLayout->addWidget(label_12);

        tauxInteret = new QDoubleSpinBox(DialogAjoutCompteCh);
        tauxInteret->setObjectName(QString::fromUtf8("tauxInteret"));
        tauxInteret->setDecimals(1);
        tauxInteret->setMinimum(0.200000000000000);

        verticalLayout->addWidget(tauxInteret);

        label_11 = new QLabel(DialogAjoutCompteCh);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font4;
        font4.setPointSize(11);
        label_11->setFont(font4);

        verticalLayout->addWidget(label_11);

        tauxInteretMin = new QDoubleSpinBox(DialogAjoutCompteCh);
        tauxInteretMin->setObjectName(QString::fromUtf8("tauxInteretMin"));
        tauxInteretMin->setDecimals(1);
        tauxInteretMin->setMinimum(0.100000000000000);

        verticalLayout->addWidget(tauxInteretMin);


        gridLayout->addLayout(verticalLayout, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);


        retranslateUi(DialogAjoutCompteCh);
        QObject::connect(pushButton, SIGNAL(clicked()), DialogAjoutCompteCh, SLOT(valider()));

        QMetaObject::connectSlotsByName(DialogAjoutCompteCh);
    } // setupUi

    void retranslateUi(QDialog *DialogAjoutCompteCh)
    {
        DialogAjoutCompteCh->setWindowTitle(QCoreApplication::translate("DialogAjoutCompteCh", "DialogAjoutCompteCh", nullptr));
        label->setText(QCoreApplication::translate("DialogAjoutCompteCh", "Numero de compte", nullptr));
        label_9->setText(QCoreApplication::translate("DialogAjoutCompteCh", "Description", nullptr));
        description->setText(QString());
        description->setPlaceholderText(QString());
        label_8->setText(QCoreApplication::translate("DialogAjoutCompteCh", "Solde du compte", nullptr));
        label_13->setText(QCoreApplication::translate("DialogAjoutCompteCh", "Nombre de transactions", nullptr));
        label_7->setText(QCoreApplication::translate("DialogAjoutCompteCh", "Date d'ouverture", nullptr));
        pushButton->setText(QCoreApplication::translate("DialogAjoutCompteCh", "Ajouter le compte", nullptr));
        label_2->setText(QCoreApplication::translate("DialogAjoutCompteCh", "Ajout d'un nouveau compte cheque", nullptr));
        label_10->setText(QCoreApplication::translate("DialogAjoutCompteCh", "Taux d'interet", nullptr));
        label_12->setText(QCoreApplication::translate("DialogAjoutCompteCh", "Taux regulier", nullptr));
        label_11->setText(QCoreApplication::translate("DialogAjoutCompteCh", "Taux minimum", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAjoutCompteCh: public Ui_DialogAjoutCompteCh {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAJOUTCOMPTECH_H
