/**
 * \file    DialogAjoutCompteEp.cpp
 * \brief   Implémentation de la boîte de dialogue pour l'ajout d'un compte épargne dans l'interface graphique.
 * 
 * Cette classe permet de saisir les informations nécessaires à la création d'un compte épargne.
 * Elle inclut des méthodes pour valider les données entrées et récupérer les valeurs des champs.
 *
 * \author  Équipe 16
 * \date    24 avril 2025, 16 h 37
 */


#include "DialogAjoutCompteEp.h"
#include <QMessageBox>
#include "ui_DialogAjoutCompteEp.h"

/**
 * \brief Constructeur de la classe DialogAjoutCompteEp.
 *
 * Initialise l'interface utilisateur associée à la boîte de dialogue.
 */
DialogAjoutCompteEp::DialogAjoutCompteEp ()
{
  widget.setupUi (this);
}

/**
 * \brief Destructeur de la classe DialogAjoutCompteEp.
 */
DialogAjoutCompteEp::~DialogAjoutCompteEp () { }

/**
 * \brief Retourne le numéro du compte saisi.
 * \return Le numéro du compte (entier positif).
 */
int DialogAjoutCompteEp::reqNoCompte() const
{
  return widget.noCompte->value();
}

/**
 * \brief Retourne le taux d'intérêt saisi.
 * \return Le taux d'intérêt (double compris entre 0.1 et 3.5).
 */
double DialogAjoutCompteEp::reqTauxInteret() const
{
  return widget.tauxInteret->value();
}

/**
 * \brief Retourne le solde saisi.
 * \return Le solde du compte (double positif).
 */
double DialogAjoutCompteEp::reqSolde() const
{
  return widget.solde->value();
}

/**
 * \brief Retourne la description saisie.
 * \return La description du compte (QString).
 */
QString DialogAjoutCompteEp::reqDescription() const
{
  return widget.description->text();
}

/**
 * \brief Retourne la date d'ouverture du compte.
 * \return La date d'ouverture (objet de type util::Date).
 */
util::Date DialogAjoutCompteEp::reqDateOuverture() const
{
  return m_dateOuverture;
}

/**
 * \brief Valide les champs saisis dans la boîte de dialogue.
 *
 * Cette méthode effectue plusieurs vérifications sur les données :
 * - Le numéro de compte doit être strictement positif.
 * - La description ne doit pas être vide.
 * - Le taux d'intérêt doit être compris entre 0.1 et 3.5.
 * - Le solde doit être positif.
 * - La date d'ouverture ne doit pas être dans le futur.
 *
 * Si tous les champs sont valides, la boîte est acceptée (accept()).
 * Sinon, un message d'erreur est affiché et la boîte reste ouverte.
 */

void DialogAjoutCompteEp::valider()
{
 if (!(reqNoCompte() > 0)){
     QString message ("Le numero de compte ne doit etre plus grand que 0!");
     QMessageBox::information(this, "Erreur", message);
     return;
   }
   
 if (reqDescription().isEmpty()){
     QString message ("La description ne peut pas être vide!");
     QMessageBox::information(this, "Erreur", message);
     return;
   }
 
 if (!(reqTauxInteret() >= 0.1 && reqTauxInteret() <= 3.5))
   {
     QString message ("Le taux d'intérêt doit se situer entre 0.1 et 3.5!");
     QMessageBox::information(this, "Erreur", message);
     return;
   }

 if (!(reqSolde() >= 0))
   {
     QString message ("Le solde doit être positif!");
     QMessageBox::information(this, "Erreur", message);
     return;
   }

 QDate dateCourante = QDate::currentDate();
 if (widget.dateO->selectedDate() >= dateCourante){
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
  