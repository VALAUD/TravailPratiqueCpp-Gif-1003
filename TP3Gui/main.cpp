/**
 * \file    main.cpp
 * \brief   Point d’entrée principal de l’application bancaire graphique.
 * 
 * Ce fichier contient la fonction main qui initialise l'application Qt
 * et affiche la fenêtre principale de l'application.
 *
 * \author  Equipe 16
 * \date    24 avril 2025, 16 h 37
 */

#include <QApplication>
#include "fenetrePrincipale.h"

/**
 * \brief Fonction principale de l'application.
 * \return Code de retour de l'application.
 */
int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);

  fenetrePrincipale Fenetre;
  Fenetre.show();
  // create and show your widgets here

  return app.exec ();
}
