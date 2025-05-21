/**
 * \file    CompteTesteur.h
 * \brief   Fichier de tests pour la classe abstraite Compte
 * \author  Audrey Valade
 * \date    16 mars 2025, 16 h 37
 */

#include <stdlib.h>
#include <iostream>
#include <gtest/gtest.h>
#include "Date.h"
#include "Compte.h"
#include "ContratException.h"

using namespace std;
using namespace util;
using namespace bancaire;

class CompteTest: public Compte
{
public :
  
  CompteTest(int p_noCompte, double p_tauxInteret, double p_solde, const std::string& p_description, const Date& p_dateOuverture): 
  Compte(p_noCompte, p_tauxInteret, p_solde, p_description, p_dateOuverture)
  {};
  
  virtual const std::string reqCompteFormate(void) const {return Compte::reqCompteFormate();};
  
  virtual std::unique_ptr<Compte> clone() const override
  {
    return std::make_unique<CompteTest>(*this);  // Copie propre de l'objet
  };
  
  virtual ~CompteTest () {};         
};

/**
 * \brief Test du constructeur Compte(int, double, double, string, Date)
 *    cas valide :
 *      Création d'un compte compte : ParametresValides
 *
 *    cas invalides :
 *      Numero de compte nul ou inferieur a zero -> parametreNumeroCompteInvalide
 *      Description vide -> parametreDescriptionVide
 *      Taux d'interet inferieur ou egal a zero -> parametreTauxInteretInvalide,
 */
TEST (CompteTest, constructeur_parametresValides_objetValide) 
{
  CompteTest compteTest(100001, 1.2, 500.00, "Compte", Date());
  ASSERT_EQ(compteTest.reqNoCompte (), 100001);
  ASSERT_EQ(compteTest.reqTauxInteret (), 1.2);
  ASSERT_EQ(compteTest.reqSolde (), 500.00);
  ASSERT_TRUE(compteTest.reqDescription () == "Compte");
  ASSERT_EQ(compteTest.reqDateOuverture (), Date());

}
TEST (CompteTest, constructeur_parametreNumeroCompteInvalide_erreurDePrecondition)
{
  ASSERT_THROW(CompteTest(-100001, 1.2, 500.00, "Compte", Date()), PreconditionException);
  ASSERT_THROW(CompteTest(0, 1.2, 500.00, "Compte", Date()), PreconditionException);

}
TEST (CompteTest, constructeur_parametreDescriptionVide_erreurDePrecondition)
{
  ASSERT_THROW (CompteTest(100001, 1.2, 500.00, "", Date()), PreconditionException);

}
TEST (CompteTest, constructeur_parametreTauxInteretInvalide_erreurDePrecondition)
{
  ASSERT_THROW(CompteTest(100001, 0, 500.00, "Compte", Date()), PreconditionException);
  ASSERT_THROW(CompteTest(100001, -1.2, 500.00, "Compte", Date()), PreconditionException);
}

 /**
  * \class UnCompteValide
  * \brief classe Fixture pour des tests sur la classe abstraite Compte
  */
 class UnCompteValide : public ::testing::Test
 {
 public:
   UnCompteValide () :
   f_compteTest(100001, 1.2, 500.00, "Compte", Date()) { };
   CompteTest f_compteTest;
 };
 

/**
* \brief Test de la méthode void Compte::asgTauxInteret(double)
*   cas valide : assignerTauxInteretNul Si le taux d'interet est nul
*                assignerTauxInteretPositif Si le taux d'interet est positif
*     	
*   cas invalide : assignerTauxInteretInvalide Si le taux d'interet est negatif
*/
TEST_F (UnCompteValide, assignerTauxInteretPositif_objetValide)
 {
   f_compteTest.asgTauxInteret(6);
   ASSERT_EQ (f_compteTest.reqTauxInteret(), 6);
 }
TEST_F (UnCompteValide, assignerTauxInteretNul_objetValide)
 {
   f_compteTest.asgTauxInteret(0);
   ASSERT_EQ (f_compteTest.reqTauxInteret(), 0);
 }
TEST_F (UnCompteValide, assignerTauxInteretInvalide_erreurDePrecondition)
 {
   ASSERT_THROW(f_compteTest.asgTauxInteret(-6), PreconditionException);
 }

/**
* \brief Test de la méthode void Compte::asgSolde(double)
*   cas valide : assignerSoldePositif Assignation d'un nombre positif au solde.
*                assignerSoldeNegatif Assignation d'un nombre negatif au solde.
*     	
*   cas invalide : Aucun d'identifié
*/
TEST_F (UnCompteValide, assignerSoldePositif_objetValide)
 {
   f_compteTest.asgSolde(500);
   ASSERT_EQ (f_compteTest.reqSolde(), 500);
 }
TEST_F (UnCompteValide, assignerSoldeNegatif_objetValide)
 {
   f_compteTest.asgSolde(-500);
   ASSERT_EQ (f_compteTest.reqSolde(), -500);
 }

/**
* \brief Test de la méthode void Compte::asgDescription (string)
*   cas valide : assignerDescriptionValide Assignation d'une description non-vide
*     	
*   cas invalide : assignerDescriptionInvalide Assignation d'une description vide
*/
TEST_F (UnCompteValide, assignerDescriptionValide_objetValide)
{
   f_compteTest.asgDescription("CompteParent");
   ASSERT_EQ (f_compteTest.reqDescription(), "CompteParent");
}
TEST_F (UnCompteValide, assignerDescriptionInvalide_erreurDePrecondition)
 {
   ASSERT_THROW (f_compteTest.asgDescription(""), PreconditionException);
 }

/**
* \brief Test de la méthode int Compte::reqNoCompte(void) const
*   cas valide : Création d'un objet compte valide et test du numero de compte
*     	
*   cas invalide : Aucun d'identifié
*/
TEST_F (UnCompteValide, reqNoCompte_noCompteValide)
{
  ASSERT_EQ (f_compteTest.reqNoCompte(), 100001);
}
 
/**
* \brief Test de la méthode double Compte::reqTauxInteret(void) const
*   cas valide : Création d'un objet compte valide et test du taux d'interet
*     	
*   cas invalide : Aucun d'identifié
*/
TEST_F (UnCompteValide, reqTauxInteret_tauxInteretValide)
{
  ASSERT_EQ (f_compteTest.reqTauxInteret(), 1.2);
}
 
/**
* \brief Test de la méthode double Compte::reqSolde(void) const
*   cas valide : Création d'un objet compte valide et test du solde
*     	
*   cas invalide : Aucun d'identifié
*/
TEST_F (UnCompteValide, reqSolde_soldeValide)
{
  ASSERT_EQ (f_compteTest.reqSolde(), 500);
}

/**
* \brief Test de la méthode const Compte::std::string& reqDescription(void) const;
*   cas valide : Création d'un objet compte valide et test de la description
*     	
*   cas invalide : Aucun d'identifié
*/
TEST_F (UnCompteValide, reqDescription_descriptionValide)
{
  ASSERT_EQ (f_compteTest.reqDescription(), "Compte");
}

/**
* \brief Test de la méthode const util::Date& Compte::reqDateOuverture(void) const;
*   cas valide : Création d'un objet compte valide et test de la date d'ouverture
*     	
*   cas invalide : Aucun d'identifié
*/
TEST_F (UnCompteValide, reqDateOuverture_dateValide)
{
  ASSERT_EQ (f_compteTest.reqDateOuverture(), Date());
}   
      
/**
* \brief Test de la méthode const std::string Compte::reqCompteFormate(void) const; 
*   cas valide : Création d'un objet compte valide et test du format
*     	
*   cas invalide : Aucun d'identifié
*/
TEST_F(UnCompteValide, reqCompteFormat_FormatValide)
{
  string expected;
  stringstream ss;
  ss << "Numero : 100001" << endl
     << "Description : Compte" << endl
     << "Date d'ouverture : " << Date() << endl
     << "Taux d'interet : 1.2" << endl
     << "Solde : 500$" << endl;
  expected = ss.str();
  
  ASSERT_EQ(f_compteTest.reqCompteFormate (), expected);
}
    

/**
* \brief Test de la méthode std::unique_ptr<Compte> Compte::clone() const =0;
*   cas valide : 
*     	
*   cas invalide : 
*/
 TEST_F(UnCompteValide, clone_copieIdentique)
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