/**
 * \file    DialogSupprimerCompte.cpp
 * \brief   
 * \author  Equipe 16
 * \date    24 avril 2025, 16 h 37
 */

#include "DialogSupprimerCompte.h"
#include "ui_DialogSupprimerCompte.h"
#include <QMessageBox>

DialogSupprimerCompte::DialogSupprimerCompte ()
{
  widget.setupUi (this);
}

DialogSupprimerCompte::~DialogSupprimerCompte () { }

int DialogSupprimerCompte::reqNoCompte() const{
  return widget.noCompteASuppr->value();
}

void DialogSupprimerCompte::valider(){
  if (!(reqNoCompte() > 0)){
      QString message ("Le numero de compte doit etre entre 1000 et 10000!");
      QMessageBox::information (this, "Erreur", message);
      return;
    }
  accept();
}