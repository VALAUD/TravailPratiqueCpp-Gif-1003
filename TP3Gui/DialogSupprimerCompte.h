/**
 
\file    DialogSupprimerCompte.h
\brief
\author  Equipe 16
\date    24 avril 2025, 16 h 37*/

#ifndef _DIALOGSUPPRIMERCOMPTE_H
#define _DIALOGSUPPRIMERCOMPTE_H

#include "ui_DialogSupprimerCompte.h"


class DialogSupprimerCompte : public QDialog
{
  Q_OBJECT
public:
  DialogSupprimerCompte ();
  virtual ~DialogSupprimerCompte ();

  void supprimerCompte(int p_noCompte);
  
  int reqNoCompte() const;
  
  private slots:
    void valider();

private:
  Ui::DialogSupprimerCompte widget;
};

#endif /* _DIALOGSUPRIMERCOMPTE_H */