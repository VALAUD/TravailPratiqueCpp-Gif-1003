/**
 * \file    DialogAjoutCompteEp.h
 * \brief   Déclaration de la classe DialogAjoutCompteEp pour l'ajout d'un compte épargne.
 *
 * Cette classe représente une boîte de dialogue Qt permettant à l'utilisateur
 * de saisir les informations nécessaires à la création d'un compte épargne,
 * comme le numéro de compte, le solde, le taux d’intérêt, la description
 * et la date d’ouverture.
 *
 * \author  Équipe 16
 * \date    24 avril 2025, 16 h 37
 */

#ifndef _DIALOGAJOUTCOMPTEEP_H
#define _DIALOGAJOUTCOMPTEEP_H
#include "ui_DialogAjoutCompteEp.h"
#include "Date.h"

/**
 * \class DialogAjoutCompteEp
 * \brief Classe de boîte de dialogue pour l’ajout d’un compte épargne.
 */
class DialogAjoutCompteEp : public QDialog
{
  Q_OBJECT
public:
  DialogAjoutCompteEp ();
  virtual ~DialogAjoutCompteEp ();
  
  int reqNoCompte() const;
  double reqTauxInteret() const;
  double reqSolde() const;
  QString reqDescription() const;
  util::Date reqDateOuverture() const;
  
private slots:
    void valider();
    
private:
  Ui::DialogAjoutCompteEp widget;
  util::Date m_dateOuverture;
};

#endif /* _DIALOGAJOUTCOMPTEEP_H */
