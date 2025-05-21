/**
 * \file    ChequeTesteur.h
 * \brief   Fichier de tests pour la classe Cheque
 * \author  Audrey Valade
 * \date    16 mars 2025, 16 h 37
 */

#include <stdlib.h>
#include <iostream>
#include <gtest/gtest.h>
#include "Date.h"
#include "Cheque.h"
#include "ContratException.h"

using namespace std;
using namespace util;
using namespace bancaire;

/**
 * \brief Test du constructeur Cheque(int, double, double, string, Date, int, double)
 *    cas valide :
 *      Création d'un compte cheque : ParametresValides
 *
 *    cas invalides :
 *      Numero de compte nul ou inferieur a zero -> parametreNumeroCompteInvalide
 *      Taux d'interet inferieur ou egal a zero -> parametreTauxInteretInvalide,
 *      Nombre de transactions inferieur a zero ou superieur a 40 -> parametreNombreTransactionsInvalide
 *      Taux d'interet minimum inferieur ou egal a zero -> parametreTauxInteretMinimumInvalide,
 *      Taux d'interet est inferieur au taux d'interet minimum -> relationOrdreEntreTauxInteretInvalide
 *      Test sur les parametres par default -> parametreParDefault
 */
TEST (Cheque, Constructeur_parametresValides_objetValide) 
{
  Cheque compteChequeTest(10001, 1.2, 500.00, "Cheque", Date(), 0, 0.1);

  ASSERT_EQ(compteChequeTest.reqNoCompte (), 10001);
  ASSERT_EQ(compteChequeTest.reqTauxInteret (), 1.2);
  ASSERT_EQ(compteChequeTest.reqSolde (), 500.00);
  ASSERT_TRUE(compteChequeTest.reqDescription () == "Cheque");
  ASSERT_EQ(compteChequeTest.reqDateOuverture (), Date());
  ASSERT_EQ(compteChequeTest.reqNombreTransactions (), 0);
  ASSERT_EQ(compteChequeTest.reqTauxInteretMinimum (), 0.1);
  ASSERT_GT(compteChequeTest.reqTauxInteret (), compteChequeTest.reqTauxInteretMinimum ());
}

TEST (Cheque, Constructeur_parametreNumeroCompteInvalide_erreurDePrecondition) 
{
  ASSERT_THROW(Cheque(-10001, 1.2, 500.00, "Cheque", Date(), 0, 0.1), PreconditionException);
  ASSERT_THROW(Cheque(0, 0.1, 500.00, "Cheque", Date(), 0, 0.1), PreconditionException);
}

TEST (Cheque, Constructeur_parametreTauxInteretInvalide_erreurDePrecondition)
{
  ASSERT_THROW(Cheque(100001, -1.2, 500.0, "Cheque", Date(), 0, 0.1), PreconditionException);
  ASSERT_THROW(Cheque(100001, 0, 500.0, "Cheque", Date(), 0, 0.1), PreconditionException);
}

TEST (Cheque, Constructeur_parametreNombreTransactionsInvalide_erreurDePrecondition)
{
  ASSERT_THROW(Cheque(10001, 1.2, 500.0, "Cheque", Date(), -1, 0.1), PreconditionException);
  ASSERT_THROW(Cheque(10001, 1.2, 500.0, "Cheque", Date(), 41, 0.1), PreconditionException);
}

TEST (Cheque, Constructeur_parametreTauxInteretMinimumInvalide_erreurDePrecondition)
{
  ASSERT_THROW(Cheque(10001, 1.2, 500.0, "Cheque", Date(), 0, -0.1), PreconditionException);  
  ASSERT_THROW(Cheque(10001, 1.2, 500.0, "Cheque", Date(), 0, 0.0), PreconditionException);
}

TEST (Cheque, Constructeur_relationOrdreEntreTauxInteretInvalide_erreurDePrecondition)
{
  ASSERT_THROW(Cheque(10001, 0.1, 500.0, "Cheque", Date(), 0, 1.2), PreconditionException);
}

TEST (Cheque, constructeur_parametreParDefault_objetValide)
{
  Cheque compteChequeTest(10001, 1.2);
  ASSERT_EQ(compteChequeTest.reqSolde (), 0);
  ASSERT_EQ(compteChequeTest.reqDescription (), "Cheque");
  ASSERT_EQ(compteChequeTest.reqDateOuverture (), Date());
  ASSERT_EQ(compteChequeTest.reqNombreTransactions (), 0);
  ASSERT_EQ(compteChequeTest.reqTauxInteretMinimum (), 0.1);
}

 /**
  * \class UnCompteChequeValide
  * \brief classe Fixture pour des tests sur un compte cheque
  */
 class UnCompteChequeValide : public ::testing::Test
 {
 public:
   UnCompteChequeValide () :
   f_compteTest(10001, 1.2, 500.00, "Cheque", Date(), 0, 0.1) { };
   Cheque f_compteTest;
 };
 
/**
* \brief Test de la méthode void Cheque::asgTauxInteret(double)
*   cas valide : AssignerTauxValide si assignation d'un nombre superieur au taux d'interet minimum
*     	
*   cas invalide : AssignerTauxInvalide si le taux est inferieur au taux d'interet minimum
*/
 TEST_F (UnCompteChequeValide, AssignerTauxValide_objetValide)
 {
   f_compteTest.asgTauxInteret (2.0);
   ASSERT_EQ (f_compteTest.reqTauxInteret (), 2.0);
 }
 
 TEST_F (UnCompteChequeValide, AssignerTauxInvalide_Erreur)
 {
   ASSERT_THROW (f_compteTest.asgTauxInteret (0), PreconditionException);
 }
 
 /**
 * \brief Test de la méthode void Cheque::asgSolde(double)
 *   cas valide : AssignerSoldePositif assignation d'un nombre positif au solde.
 *                AssignerSoldeNegatif assignation d'un nombre negatif au solde.	
 *   cas invalide : Aucun d'identifié
 */
TEST_F (UnCompteChequeValide, AssignerSoldePositif_objetValide)
 {
   f_compteTest.asgSolde(500);
   ASSERT_EQ (f_compteTest.reqSolde(), 500);
 }

TEST_F (UnCompteChequeValide, AssignerSoldeNegatif_objetValide)
 {
   f_compteTest.asgSolde(-500);
   ASSERT_EQ (f_compteTest.reqSolde(), -500);
 }
   
  /**
  * \brief Test de la méthode void Cheque::asgNombreTransaction(int)
  *   cas valide : asgNombreTransactionValide : Assigner un nombre de 0 a 40
  *     	
  *   cas invalide : asgNombreTransactionInvalide : Assigner un nombre inferieur 
  *                  a 0 ou superieur a 40
  */ 
TEST_F (UnCompteChequeValide, asgNombreTransactionValide_ObjetValide)
 {
   f_compteTest.asgNombreTransaction (35);
   ASSERT_EQ (f_compteTest.reqNombreTransactions(), 35);
 }
  
TEST_F (UnCompteChequeValide, asgNombreTransactionInvalide_Erreur)
 {
   ASSERT_THROW (f_compteTest.asgNombreTransaction (-1), PreconditionException);
   ASSERT_THROW (f_compteTest.asgNombreTransaction (41), PreconditionException);
 }

  /**
  * \brief Test de la méthode int Cheque::reqNombreTransactions(void) const
  *   cas valide : Création compte cheque valide connue et test du nombre de transactions
  *     	
  *   cas invalide : Aucun d'identifié
  */ 
TEST_F (UnCompteChequeValide, reqNombreTransaction_NombreValide)
 {
   ASSERT_EQ (f_compteTest.reqNombreTransactions(), 0);
 }

  /**
  * \brief Test de la méthode double Cheque::reqTauxInteretMinimum(void) const
  *   cas valide : Création compte cheque valide connue et test du taux d'interet minimum
  *     	
  *   cas invalide : Aucun d'identifié
  */
 TEST_F (UnCompteChequeValide, reqTauxInteretMinimum_TauxInteretMinimumValide)
 {
   ASSERT_EQ (f_compteTest.reqTauxInteretMinimum(), 0.1);
 }
 
  /**
  * \brief Test de la méthode const std::string Cheque::reqCompteFormate(void) const
  *   cas valide : Création compte cheque valide connue et test du format
  *     	
  *   cas invalide : Aucun d'identifié
  */ 
TEST_F(UnCompteChequeValide, reqCompteFormat_FormatValide)
{
  string expected;
  stringstream ss;
  ss << "Compte Cheque" << endl
     << "Numero : 10001" << endl
     << "Description : Cheque" << endl
     << "Date d'ouverture : " << Date() << endl
     << "Taux d'interet : 1.2" << endl
     << "Solde : 500$" << endl
     << "Nombre de transactions : 0" << endl
     << "Taux d'interet minimum : 0.1" << endl
     << "Interet : 0$" << endl;
  expected = ss.str();
  
  ASSERT_EQ(f_compteTest.reqCompteFormate (), expected);
}
  /**
  * \brief Test de la méthode std::unique_ptr<Compte> Cheque::clone() const override
  *   cas valide : Retourne une copie profonde de l’objet courant
  *     	
  *   cas invalide : Aucun d'identifié
  */
 TEST_F(UnCompteChequeValide, clone_copieIdentique)
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
* \brief Test de la méthode const double Cheque::calculerInteret(void) const
*   cas valide : SoldePositif Solde plus grand que zero
*                SoldeNegatif Solde negatif avec entre 0 et 10 transactions
*                SoldeNegatif Solde negatif avec entre 11 et 25 transactions
*                SoldeNegatif Solde negatif avec entre 26 et 35 transactions
*                SoldeNegatif Solde negatif avec entre 41 et 40 transactions

*   cas invalide : Aucun identifié
*/ 
TEST_F(UnCompteChequeValide, SoldePositif_CalculValide)
{
  f_compteTest.asgSolde (100);
  ASSERT_EQ(f_compteTest.calculerInteret(), 0.0);
}

TEST_F (UnCompteChequeValide, SoldeNegatifTransaction8_CalculValide)
{
  f_compteTest.asgSolde (-100);
  f_compteTest.asgNombreTransaction (8);
  double expected = (100 * 0.1 / 100);
  ASSERT_EQ(f_compteTest.calculerInteret(), expected);
}

TEST_F (UnCompteChequeValide, SoldeNegatifTransaction25_CalculValide)
{
  f_compteTest.asgSolde (-100);
  f_compteTest.asgNombreTransaction (25);
  double expected = (100 * 0.1 * 1.4 / 100);
  ASSERT_EQ(f_compteTest.calculerInteret(), expected);
}

TEST_F (UnCompteChequeValide, SoldeNegatifTransaction35_CalculValide)
{
  f_compteTest.asgSolde (-100);
  f_compteTest.asgNombreTransaction (35);
  double expected = (100 * 0.1 * 1.8 / 100);
  ASSERT_EQ(f_compteTest.calculerInteret(), expected);
}

TEST_F (UnCompteChequeValide, SoldeNegatifTransaction39_CalculValide)
{
  f_compteTest.asgSolde (-100);
  f_compteTest.asgNombreTransaction (39);
  double expected = (100 * 1.2 / 100);
  ASSERT_EQ(f_compteTest.calculerInteret(), expected);
}
