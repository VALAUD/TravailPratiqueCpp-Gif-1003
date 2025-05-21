/**
 * \file    DialogAjoutCompteCh.cpp
 * \brief   Implémentation de la boîte de dialogue pour l'ajout d'un compte chèque dans l'interface graphique.
 *
 * Cette classe permet de saisir les informations nécessaires à la création d'un compte chèque.
 * Elle inclut des méthodes pour valider les données entrées et récupérer les valeurs des champs.
 *
 * \author  Equipe 16
 * \date    24 avril 2025, 16 h 37
 */

#include "DialogAjoutCompteCh.h"
#include "ui_DialogAjoutCompteCh.h"
#include <QMessageBox>

/**
 * \brief Constructeur de la classe DialogAjoutCompteCh.
 *
 * Initialise l'interface utilisateur associée à la boîte de dialogue.
 */
DialogAjoutCompteCh::DialogAjoutCompteCh()
{
  widget.setupUi (this);
}

/**
 * \brief Destructeur de la classe DialogAjoutCompteCh.
 */
DialogAjoutCompteCh::~DialogAjoutCompteCh() {}

/**
 * \brief Retourne le numéro du compte saisi.
 * \return Le numéro du compte (entier positif).
 */
int DialogAjoutCompteCh::reqNoCompte() const
{
  return widget.noCompte->value();
}

/**
 * \brief Retourne le taux d'intérêt régulier saisi.
 * \return Le taux d'intérêt régulier (double).
 */   
double DialogAjoutCompteCh::reqTauxInteret() const
{
  return widget.tauxInteret->value();
}

/**
 * \brief Retourne le solde saisi.
 * \return Le solde du compte (double).
 */
double DialogAjoutCompteCh::reqSolde() const
{
  return widget.solde->value();
}

/**
 * \brief Retourne la description saisie.
 * \return La description du compte (QString).
 */
QString DialogAjoutCompteCh::reqDescription() const
{
  return widget.description->text();
}

/**
 * \brief Retourne le nombre de transactions permis.
 * \return Le nombre de transactions (entre 0 et 40).
 */
int DialogAjoutCompteCh::reqNbTransactions() const
{
  return widget.nbTransactions->value();
}

/**
 * \brief Retourne le taux d'intérêt minimum saisi.
 * \return Le taux d'intérêt minimum (double).
 */
double DialogAjoutCompteCh::reqTauxInteretMin() const
{
  return widget.tauxInteretMin->value();
}

/**
 * \brief Retourne la date d'ouverture du compte.
 * \return La date d'ouverture (objet de type util::Date).
 */
util::Date DialogAjoutCompteCh::reqDateOuverture() const
{
  return m_dateOuverture;
}

/**
 * \brief Valide les champs saisis dans la boîte de dialogue.
 *
 * Cette méthode effectue plusieurs vérifications sur les données :
 * - Le numéro de compte doit être strictement positif.
 * - La description ne doit pas être vide.
 * - Le taux d'intérêt minimum doit être strictement positif.
 * - Le taux d'intérêt régulier doit être supérieur au taux minimum.
 * - Le nombre de transactions doit être entre 0 et 40.
 * - La date d'ouverture ne doit pas être dans le futur.
 *
 * Si tous les champs sont valides, la boîte est acceptée.
 * Sinon, un message d'erreur est affiché et la boîte reste ouverte.
 */
void DialogAjoutCompteCh::valider()
{
 if (!(reqNoCompte() > 0))
   {
     QString message ("Le numero de compte ne doit etre plus grand que 0!");
     QMessageBox::information(this, "Erreur", message);
     return;
   }
 
 if (reqDescription().isEmpty()){
     QString message ("La description ne peut pas être vide!");
     QMessageBox::information(this, "Erreur", message);
     return;
   }
 
 if (!(reqTauxInteretMin() > 0))
   {
     QString message ("Le taux d'intérêt minimum doit être plus grand que 0!");
     QMessageBox::information(this, "Erreur", message);
     return;
   }

 if (!(reqTauxInteret() > reqTauxInteretMin()))
   {
     QString message ("Le taux d'intérêt régulier doit être plus grand que le taux d'intérêt minimum!");
     QMessageBox::information(this, "Erreur", message);
     return;
   }
 
 if (!(reqNbTransactions() >= 0 && reqNbTransactions() <= 40))
   {
     QString message ("Le nombre de transactions doit se situer entre 0 et 40!");
     QMessageBox::information(this, "Erreur", message);
     return;
   }
   
 QDate dateCourante = QDate::currentDate();
 if (widget.dateO->selectedDate() >= dateCourante)
   {
     QString message ("La date ne doit pas etre dans le futur!");
     QMessageBox::information(this, "Erreur", message);
     return;
   } 
 else
   {
     m_dateOuverture.asgDate(widget.dateO->selectedDate().day(),
                             widget.dateO->selectedDate().month(),
                             widget.dateO->selectedDate().year());
   }
 accept();
}
