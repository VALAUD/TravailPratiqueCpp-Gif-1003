/**
 * \file    fenetrePrincipale.cpp
 * \brief   Implémentation de la fenêtre principale de l'application bancaire.
 *
 * Ce fichier implémente les interactions principales entre l'utilisateur et l'application,
 * y compris l'ajout de comptes chèques et épargne via des boîtes de dialogue.
 * La classe `fenetrePrincipale` agit comme interface centrale pour la gestion du client et de ses comptes.
 *
 * \author  Équipe 16
 * \date    24 avril 2025, 16 h 37
 */

#include "fenetrePrincipale.h"
#include "DialogAjoutCompteCh.h"
#include "DialogAjoutCompteEp.h"
#include "DialogSupprimerCompte.h"
#include "CompteException.h"

#include "Date.h"
#include "Compte.h"
#include "Cheque.h"
#include "Epargne.h"
#include <vector>
#include <iostream>
#include <QString>
#include <iostream>
#include <QMessageBox>

fenetrePrincipale::fenetrePrincipale (): m_client(1001, "Carpenter", "Sabrina", "111-111-1111", util::Date(01,01,1990))
{
  widget.setupUi (this);
}

/**
 * \brief Destructeur de la classe fenetrePrincipale.
 */
fenetrePrincipale::~fenetrePrincipale (){}

/**
 * \brief Ouvre une boîte de dialogue pour ajouter un compte chèque.
 *
 * Si l'utilisateur valide la boîte de dialogue, un objet `Cheque` est créé avec les informations fournies.
 * Ce compte est ensuite ajouté au client, sauf s'il existe déjà (ce qui déclenche une exception).
 */
void fenetrePrincipale::dialogAjoutCompteCh()
{
  DialogAjoutCompteCh compteCh;
  if (compteCh.exec())
    {
      try
        {
          bancaire::Cheque nouveauCompteCh(compteCh.reqNoCompte(), 
                                           compteCh.reqTauxInteret(), 
                                           compteCh.reqSolde(), 
                                           compteCh.reqDescription().toStdString(),
                                           compteCh.reqDateOuverture(), 
                                           compteCh.reqNbTransactions(), 
                                           compteCh.reqTauxInteretMin());
          m_client.ajouterCompte(nouveauCompteCh);
          widget.affichage->setText(m_client.reqReleves().c_str());
        }
      catch (bancaire::CompteDejaPresentException& e)   
        {
          QMessageBox::information(this, "Erreur", e.what());
          return;
        }
      catch (...)
        {
          QMessageBox::critical(this, "Erreur", "Une erreur imprévue est survenue lors de l'ajout du compte cheque.");
        }
      
    }
}

/**
 * \brief Ouvre une boîte de dialogue pour ajouter un compte épargne.
 *
 * Si l'utilisateur valide la boîte de dialogue, un objet `Epargne` est créé avec les informations fournies.
 * Ce compte est ensuite ajouté au client, sauf s'il existe déjà (ce qui déclenche une exception).
 */
void fenetrePrincipale::dialogAjoutCompteEp()
{
  DialogAjoutCompteEp compteEp;
  if (compteEp.exec())
    {
      try
        {
          bancaire::Epargne nouveauCompteEp(compteEp.reqNoCompte(), 
                                            compteEp.reqTauxInteret(), 
                                            compteEp.reqSolde(), 
                                            compteEp.reqDescription().toStdString(),
                                            compteEp.reqDateOuverture());
          m_client.ajouterCompte(nouveauCompteEp);
          widget.affichage->setText(m_client.reqReleves().c_str());
        }
      catch (bancaire::CompteDejaPresentException& e)   
        {
          QMessageBox::information(this, "Erreur", e.what());
          return;
        }
      catch (...)
        {
          QMessageBox::critical(this, "Erreur", "Une erreur imprévue est survenue lors de l'ajout du compte epargne.");
        }
    }
}
   

void fenetrePrincipale::dialogSupprimerCompte()
{
  DialogSupprimerCompte Supp;
  if (Supp.exec())
    {
      m_client.supprimerCompte(Supp.reqNoCompte());
      widget.affichage->setPlainText(m_client.reqReleves().c_str());
      std::cout << "Compte supprimé: " << Supp.reqNoCompte();
    }
}
