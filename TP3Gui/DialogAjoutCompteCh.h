/**
 * \file    DialogAjoutCompteCh.h
 * \brief   Déclaration de la classe DialogAjoutCompteCh pour l'ajout d'un compte chèque.
 *
 * Cette classe représente une boîte de dialogue Qt permettant à l'utilisateur
 * de saisir les informations nécessaires à la création d'un compte chèque,
 * telles que le numéro de compte, le solde, les taux d'intérêt, la description,
 * le nombre de transactions et la date d'ouverture.
 *
 * \author  Équipe 16
 * \date    24 avril 2025, 16 h 37
 */

#ifndef _DIALOGAJOUTCOMPTECH_H
#define _DIALOGAJOUTCOMPTECH_H

#include "ui_DialogAjoutCompteCh.h"
#include "Date.h"

/**
 * \class DialogAjoutCompteCh
 * \brief Classe de boîte de dialogue pour l’ajout d’un compte chèque.
 */
class DialogAjoutCompteCh : public QDialog
{
  Q_OBJECT
public:
  DialogAjoutCompteCh ();
  virtual ~DialogAjoutCompteCh ();
 
  int reqNoCompte() const;
  double reqTauxInteret() const;
  double reqSolde() const;
  QString reqDescription() const;
  util::Date reqDateOuverture() const;
  int reqNbTransactions() const;
  double reqTauxInteretMin() const;
  
  
private slots:
    void valider();
  
private:
  Ui::DialogAjoutCompteCh widget;
  util::Date m_dateOuverture;
};

#endif /* _DIALOGAJOUTCOMPTECH_H */
