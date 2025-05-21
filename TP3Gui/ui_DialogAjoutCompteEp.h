/********************************************************************************
** Form generated from reading UI file 'DialogAjoutCompteEp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAJOUTCOMPTEEP_H
#define UI_DIALOGAJOUTCOMPTEEP_H

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

class Ui_DialogAjoutCompteEp
{
public:
    QGridLayout *gridLayout;
    QLabel *label_21;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QSpinBox *noCompte;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_15;
    QLineEdit *description;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_16;
    QDoubleSpinBox *solde;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_18;
    QDoubleSpinBox *tauxInteret;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_22;
    QCalendarWidget *dateO;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;

    void setupUi(QDialog *DialogAjoutCompteEp)
    {
        if (DialogAjoutCompteEp->objectName().isEmpty())
            DialogAjoutCompteEp->setObjectName(QString::fromUtf8("DialogAjoutCompteEp"));
        DialogAjoutCompteEp->resize(473, 586);
        gridLayout = new QGridLayout(DialogAjoutCompteEp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_21 = new QLabel(DialogAjoutCompteEp);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(24);
        font.setBold(false);
        font.setWeight(50);
        label_21->setFont(font);
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_21, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(452, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(DialogAjoutCompteEp);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_6->setFont(font1);

        horizontalLayout_5->addWidget(label_6);

        noCompte = new QSpinBox(DialogAjoutCompteEp);
        noCompte->setObjectName(QString::fromUtf8("noCompte"));
        noCompte->setMinimum(1);
        noCompte->setMaximum(99999);
        noCompte->setValue(1);

        horizontalLayout_5->addWidget(noCompte);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_15 = new QLabel(DialogAjoutCompteEp);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font1);

        horizontalLayout_6->addWidget(label_15);

        description = new QLineEdit(DialogAjoutCompteEp);
        description->setObjectName(QString::fromUtf8("description"));
        description->setMaxLength(20);

        horizontalLayout_6->addWidget(description);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_16 = new QLabel(DialogAjoutCompteEp);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font1);

        horizontalLayout_7->addWidget(label_16);

        solde = new QDoubleSpinBox(DialogAjoutCompteEp);
        solde->setObjectName(QString::fromUtf8("solde"));
        solde->setMinimum(0.000000000000000);
        solde->setMaximum(100000000000.000000000000000);
        solde->setValue(0.000000000000000);

        horizontalLayout_7->addWidget(solde);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_18 = new QLabel(DialogAjoutCompteEp);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font1);

        horizontalLayout_8->addWidget(label_18);

        tauxInteret = new QDoubleSpinBox(DialogAjoutCompteEp);
        tauxInteret->setObjectName(QString::fromUtf8("tauxInteret"));
        tauxInteret->setDecimals(1);
        tauxInteret->setMinimum(0.100000000000000);
        tauxInteret->setMaximum(3.500000000000000);
        tauxInteret->setSingleStep(0.100000000000000);
        tauxInteret->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        tauxInteret->setValue(0.100000000000000);

        horizontalLayout_8->addWidget(tauxInteret);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer_2);

        label_22 = new QLabel(DialogAjoutCompteEp);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label_22->setFont(font2);

        verticalLayout_4->addWidget(label_22);

        dateO = new QCalendarWidget(DialogAjoutCompteEp);
        dateO->setObjectName(QString::fromUtf8("dateO"));

        verticalLayout_4->addWidget(dateO);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer_3);


        gridLayout->addLayout(verticalLayout_4, 2, 0, 1, 1);

        pushButton = new QPushButton(DialogAjoutCompteEp);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font1);

        gridLayout->addWidget(pushButton, 3, 0, 1, 1);


        retranslateUi(DialogAjoutCompteEp);
        QObject::connect(pushButton, SIGNAL(clicked()), DialogAjoutCompteEp, SLOT(valider()));

        QMetaObject::connectSlotsByName(DialogAjoutCompteEp);
    } // setupUi

    void retranslateUi(QDialog *DialogAjoutCompteEp)
    {
        DialogAjoutCompteEp->setWindowTitle(QCoreApplication::translate("DialogAjoutCompteEp", "DialogAjoutCompteEp", nullptr));
        label_21->setText(QCoreApplication::translate("DialogAjoutCompteEp", "Ajout d'un nouveau compte epargne", nullptr));
        label_6->setText(QCoreApplication::translate("DialogAjoutCompteEp", "Numero de compte", nullptr));
        label_15->setText(QCoreApplication::translate("DialogAjoutCompteEp", "Description", nullptr));
        label_16->setText(QCoreApplication::translate("DialogAjoutCompteEp", "Solde du compte", nullptr));
        label_18->setText(QCoreApplication::translate("DialogAjoutCompteEp", "Taux d'interet", nullptr));
        label_22->setText(QCoreApplication::translate("DialogAjoutCompteEp", "Date d'ouverture", nullptr));
        pushButton->setText(QCoreApplication::translate("DialogAjoutCompteEp", "Ajouter le compte", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAjoutCompteEp: public Ui_DialogAjoutCompteEp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAJOUTCOMPTEEP_H
