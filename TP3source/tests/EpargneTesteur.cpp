/**
 * \file    EpargneTesteur.h
 * \brief   Fichier de tests pour la classe Epargne
 * \author  Audrey Valade
 * \date    16 mars 2025, 16 h 37
 */

#include <stdlib.h>
#include <iostream>
#include <gtest/gtest.h>
#include "Date.h"
#include "Epargne.h"
#include "ContratException.h"

using namespace std;
using namespace util;
using namespace bancaire;

/**
 * \brief Test du constructeur Epargne(int, double, double, string, Date, int, double)
 *    cas valide :
 *      Création d'un compte Epargne : ParametresValides
 *
 *    cas invalides :
 *      Numero de compte nul ou inferieur a zero -> parametreNumeroCompteInvalide
 *      Taux d'interet inferieur a 0.1 ou superieur a 3.5 -> parametreTauxInteretInvalide
 *      Solde inferieur a zero -> parametreSoldeInvalide
 *      Test sur les parametres par default -> parametreParDefault
 */

TEST (Epargne, constructeur_parametresValides_objetValide) 
{
  Epargne compteEpargneTest(10001, 1.2, 500.00, "Epargne", Date());
  ASSERT_EQ(compteEpargneTest.reqNoCompte (), 10001);
  ASSERT_EQ(compteEpargneTest.reqTauxInteret (), 1.2);
  ASSERT_EQ(compteEpargneTest.reqSolde (), 500.00);
  ASSERT_TRUE(compteEpargneTest.reqDescription () == "Epargne");
  ASSERT_EQ(compteEpargneTest.reqDateOuverture (), Date());
}
TEST (Epargne, constructeur_parametreNumeroCompteInvalide_erreurDePrecondition)
{
  ASSERT_THROW(Epargne(-10001, 1.2, 500.00, "Epargne", Date()), PreconditionException);
  ASSERT_THROW(Epargne(0, 1.2, 500.00, "Epargne", Date()), PreconditionException);
}

TEST (Epargne, constructeur_parametreTauxInteretInvalide_erreurDePrecondition)
{
  ASSERT_THROW(Epargne(10001, 0, 500.00, "Epargne", Date()), PreconditionException);
  ASSERT_THROW(Epargne(10001, 3.6, 500.00, "Epargne", Date()), PreconditionException);
}

TEST (Epargne, constructeur_parametreSoldeInvalide_erreurDePrecondition)
{
  ASSERT_THROW(Epargne(10001, 1.2, -500.00, "Epargne", Date()), PreconditionException);
}

TEST (Epargne, Constructeur_parametreParDefault_objetValide)
{
  Epargne compteEpargneTest(10001, 1.2);
  ASSERT_EQ(compteEpargneTest.reqSolde (), 0);
  ASSERT_EQ(compteEpargneTest.reqDescription (), "Epargne");
  ASSERT_EQ(compteEpargneTest.reqDateOuverture (), Date());
}
 /**
 * \class UnCompteEpargneValide
 * \brief classe Fixture pour des tests sur un compte Epargne
 */
 class UnCompteEpargneValide : public ::testing::Test
 {
 public:
   UnCompteEpargneValide () :
   f_compteTest(10001, 1.2, 500.00, "Epargne", Date()) { };
   Epargne f_compteTest;
 };
 
  /**
  * \brief Test de la méthode void Epargne::asgTauxInteret(double)
  *   cas valide : assignerTauxValide si le taux est de 0.1 a 3.5
  *     	
  *   cas invalide : assignerTauxInvalide si le taux est inferieur a 0.1 ou superieur a 3.5
  */
  TEST_F (UnCompteEpargneValide, assignerTauxValide_objetValide)
 {
   f_compteTest.asgTauxInteret (2.0);
   ASSERT_EQ (f_compteTest.reqTauxInteret (), 2.0);
 }
 TEST_F (UnCompteEpargneValide, assignerTauxInvalide_erreurDePrecondition)
 {
   ASSERT_THROW (f_compteTest.asgTauxInteret (0), PreconditionException);
   ASSERT_THROW (f_compteTest.asgTauxInteret (3.6), PreconditionException);
 }
 
 /**
 * \brief Test de la méthode void Epargne::asgSolde(double)
 *   cas valide : assignerSoldePositif assignation d'un nombre positif au solde.
 *                	
 *   cas invalide : assignerSoldeNegatif assignation d'un nombre negatif au solde.
 */
TEST_F (UnCompteEpargneValide, assignerSoldePositif_objetValide)
 {
   f_compteTest.asgSolde(500);
   ASSERT_EQ (f_compteTest.reqSolde(), 500);
 }

TEST_F (UnCompteEpargneValide, assignerSoldeNegatif_erreurDePrecondition)
 {
   ASSERT_THROW (f_compteTest.asgSolde(-500), PreconditionException);
 }
 
  /**
  * \brief Test de la méthode const std::string Epargne::reqCompteFormate(void) const
  *   cas valide : Création compte epargne valide connue et test du format
  *     	
  *   cas invalide : Aucun d'identifié
  */ 
TEST_F(UnCompteEpargneValide, reqCompteFormat_formatValide)
{
  string expected;
  stringstream ss;
  ss << "Compte Epargne" << endl
     << "Numero : 10001" << endl
     << "Description : Epargne" << endl
     << "Date d'ouverture : " << Date() << endl
     << "Taux d'interet : 1.2" << endl
     << "Solde : 500$" << endl
     << "Interet : 6$" << endl;
  expected = ss.str();
  
  ASSERT_EQ(f_compteTest.reqCompteFormate (), expected);
}
    
  /**
  * \brief Test de la méthode std::unique_ptr<Compte> Epargne::clone() const override
  *   cas valide : Retourne une copie profonde de l’objet courant
  *     	
  *   cas invalide : Aucun d'identifié
  */ 
 TEST_F(UnCompteEpargneValide, clone_copieIdentique)
 {
  unique_ptr<Compte> clone = f_compteTest.clone();
  ASSERT_NE(clone.get(), &f_compteTest);
  ASSERT_EQ(clone->reqNoCompte(), f_compteTest.reqNoCompte());
  ASSERT_EQ(clone->reqSolde(), f_compteTest.reqSolde());
  ASSERT_EQ(clone->reqDescription(), f_compteTest.reqDescription());
  ASSERT_EQ(clone->reqDateOuverture(), f_compteTest.reqDateOuverture());
  ASSERT_EQ(clone->reqTauxInteret(), f_compteTest.reqTauxInteret());
  ASSERT_EQ(clone->reqCompteFormate(), f_compteTest.reqCompteFormate());
 }
 
/**
* \brief Test de la méthode const double Epargne::calculerInteret(void) const
*   cas valide : Creation d'un compte epargne valide et calcul des interets
*
*   cas invalide : Aucun identifié
*/ 
TEST_F(UnCompteEpargneValide, calculerInteret_CalculValide)
{
  double expected = 500*1.2/100;
  ASSERT_EQ(f_compteTest.calculerInteret(), expected);
}
