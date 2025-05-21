/**
 * \file    fenetrePrincipale.h
 * \brief   Déclaration de la classe fenetrePrincipale, la fenêtre principale de l'application.
 *
 * Cette classe représente l'interface graphique principale de l'application.
 * Elle permet de gérer les interactions avec l'utilisateur pour l'ajout et la suppression de comptes.
 *
 * \author  Équipe 16
 * \date    24 avril 2025, 16 h 37
 */

#ifndef _FENETREPRINCIPALE_H
#define _FENETREPRINCIPALE_H
#include "Client.h"
#include <vector>
#include "ui_fenetrePrincipale.h"
#include "ui_DialogAjoutCompteCh.h"
#include "DialogAjoutCompteCh.h"
#include "ui_DialogAjoutCompteEp.h"
#include "DialogAjoutCompteEp.h"
#include "ui_DialogSupprimerCompte.h"
#include "DialogSupprimerCompte.h"

/**
 * \class fenetrePrincipale
 * \brief Classe représentant la fenêtre principale de l'application.
 */
class fenetrePrincipale : public QMainWindow
{
  Q_OBJECT
public:
  fenetrePrincipale ();
  virtual ~fenetrePrincipale ();
  
  private slots:
    void dialogAjoutCompteCh();
    void dialogAjoutCompteEp();
    void dialogSupprimerCompte();
    
private:
  Ui::fenetrePrincipale widget;
  bancaire::Client m_client;

};

#endif /* _FENETREPRINCIPALE_H */
