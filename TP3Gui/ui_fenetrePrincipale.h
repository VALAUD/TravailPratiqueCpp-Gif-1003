/********************************************************************************
** Form generated from reading UI file 'fenetrePrincipale.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENETREPRINCIPALE_H
#define UI_FENETREPRINCIPALE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fenetrePrincipale
{
public:
    QAction *actionSupprimer_compte_bancaire;
    QAction *actionQuitter;
    QAction *actionCompte_Cheque;
    QAction *actionCompte_Epargne;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *affichage;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter_compte;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *fenetrePrincipale)
    {
        if (fenetrePrincipale->objectName().isEmpty())
            fenetrePrincipale->setObjectName(QString::fromUtf8("fenetrePrincipale"));
        fenetrePrincipale->resize(1103, 725);
        actionSupprimer_compte_bancaire = new QAction(fenetrePrincipale);
        actionSupprimer_compte_bancaire->setObjectName(QString::fromUtf8("actionSupprimer_compte_bancaire"));
        actionQuitter = new QAction(fenetrePrincipale);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionCompte_Cheque = new QAction(fenetrePrincipale);
        actionCompte_Cheque->setObjectName(QString::fromUtf8("actionCompte_Cheque"));
        actionCompte_Epargne = new QAction(fenetrePrincipale);
        actionCompte_Epargne->setObjectName(QString::fromUtf8("actionCompte_Epargne"));
        centralwidget = new QWidget(fenetrePrincipale);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        affichage = new QTextEdit(centralwidget);
        affichage->setObjectName(QString::fromUtf8("affichage"));

        gridLayout->addWidget(affichage, 0, 0, 1, 1);

        fenetrePrincipale->setCentralWidget(centralwidget);
        menubar = new QMenuBar(fenetrePrincipale);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1103, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjouter_compte = new QMenu(menuMenu);
        menuAjouter_compte->setObjectName(QString::fromUtf8("menuAjouter_compte"));
        fenetrePrincipale->setMenuBar(menubar);
        statusbar = new QStatusBar(fenetrePrincipale);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        fenetrePrincipale->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAjouter_compte->menuAction());
        menuMenu->addAction(actionSupprimer_compte_bancaire);
        menuMenu->addAction(actionQuitter);
        menuAjouter_compte->addAction(actionCompte_Cheque);
        menuAjouter_compte->addAction(actionCompte_Epargne);

        retranslateUi(fenetrePrincipale);
        QObject::connect(actionQuitter, SIGNAL(triggered()), fenetrePrincipale, SLOT(close()));
        QObject::connect(actionCompte_Cheque, SIGNAL(triggered()), fenetrePrincipale, SLOT(dialogAjoutCompteCh()));
        QObject::connect(actionCompte_Epargne, SIGNAL(triggered()), fenetrePrincipale, SLOT(dialogAjoutCompteEp()));
        QObject::connect(actionSupprimer_compte_bancaire, SIGNAL(triggered()), fenetrePrincipale, SLOT(dialogSupprimerCompte()));

        QMetaObject::connectSlotsByName(fenetrePrincipale);
    } // setupUi

    void retranslateUi(QMainWindow *fenetrePrincipale)
    {
        fenetrePrincipale->setWindowTitle(QCoreApplication::translate("fenetrePrincipale", "fenetrePrincipale", nullptr));
        actionSupprimer_compte_bancaire->setText(QCoreApplication::translate("fenetrePrincipale", "Supprimer compte bancaire", nullptr));
        actionQuitter->setText(QCoreApplication::translate("fenetrePrincipale", "Quitter", nullptr));
        actionCompte_Cheque->setText(QCoreApplication::translate("fenetrePrincipale", "Compte Cheque", nullptr));
        actionCompte_Epargne->setText(QCoreApplication::translate("fenetrePrincipale", "Compte Epargne", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("fenetrePrincipale", "Operations", nullptr));
        menuAjouter_compte->setTitle(QCoreApplication::translate("fenetrePrincipale", "Ajouter compte", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fenetrePrincipale: public Ui_fenetrePrincipale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENETREPRINCIPALE_H
