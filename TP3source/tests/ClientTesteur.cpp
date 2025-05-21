/**
 * \file    ClientTesteur.h
 * \brief   Fichier de tests pour la classe Client
 * \author  Audrey Valade
 * \date    16 mars 2025, 16 h 37
 */

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <gtest/gtest.h>
#include "Date.h"
#include "Client.h"
#include "Cheque.h"
#include "Epargne.h"
#include "ContratException.h"
#include "CompteException.h"

using namespace std;
using namespace util;
using namespace bancaire;

/**
 * \brief Test du constructeur Client(int, string, string, string, Date)
 *    cas valide :
 *      Création d'un compte cheque : ParametresValides
 *
 *    cas invalides :
 *      Numero de folio inferieur a 1000 ou superieur a 10 000 -> parametreNumeroFolioInvalide
 *      nom invalide(avec nombre, ou vide) -> parametreNomInvalideVide
 *      prenom invalide(avec nombre, ou vide) -> parametrePrenomInvalideVide
 *      Telephone vide -> parametreTelephoneInvalide
 *      Date de naissance superieur a la date d'aujourd'hui -> parametreDateNaissanceInvalide,
 */
TEST (Client, constructeur_parametresValides_objetValide) 
{
  Client clientTest(1000, "Del Rey", "Lana", "1234567890", Date(21,06,1985));

  ASSERT_EQ(clientTest.reqNoFolio (), 1000);
  ASSERT_EQ(clientTest.reqNom (), "Del Rey");
  ASSERT_EQ(clientTest.reqPrenom (), "Lana");
  ASSERT_EQ(clientTest.reqTelephone (), "1234567890");
  ASSERT_EQ(clientTest.reqDateNaissance (), Date(21,06,1985));
}

TEST (Client, constructeur_parametreNumeroFolioInvalide_erreurDePrecondition)
{
  ASSERT_THROW(Client(999, "Del Rey", "Lana", "1234567890", Date(21,06,1985)), PreconditionException);
  ASSERT_THROW(Client(10001, "Del Rey", "Lana", "1234567890", Date(21,06,1985)), PreconditionException);
}
TEST (Client, constructeur_parametreNomInvalideVide_erreurDePrecondition)
{
  ASSERT_THROW(Client(1001, "Del 8", "Lana", "1234567890", Date(21,06,1985)), PreconditionException);
}
TEST (Client, constructeur_parametrePrenomInvalideVide_erreurDePrecondition)
{
  ASSERT_THROW(Client(1001, "Del Rey", "*", "1234567890", Date(21,06,1985)), PreconditionException);
}
TEST (Client, constructeur_parametreTelephoneInvalide_erreurDePrecondition)
{
  ASSERT_THROW(Client(1001, "Del Rey", "Lana", "", Date(21,06,1985)), PreconditionException);
}

TEST (Client, constructeur_parametreDateNaissanceInvalide_erreurDePrecondition)
{
  ASSERT_THROW(Client(1001, "Del Rey", "Lana", "1234567890", Date(21,06, 2050)), PreconditionException);
}

/**
* \class ClientsEtComptesValides
* \brief classe Fixture pour des tests sur un Client et ses comptes
*/ 
class ClientsEtComptesValides : public ::testing::Test
{
public:
    ClientsEtComptesValides() : 
    f_clientTest1(1000, "Del Rey", "Lana", "1234567890", Date(21,6,1985)),
    chequeClient1(10001, 1.5, 500.0, "Cheque Lana", Date(), 0, 0.1),
    epargneClient1(30001, 2.0, 3000.0, "Epargne Lana", Date()),
    
    f_clientTest2(9999, "Swift", "Taylor", "9876543210", Date(13,12,1989)),
    chequeClient2(20002, 1.5, 1000.0, "Cheque Taylor", Date(), 0, 0.1),
    epargneClient2(30002, 2.0, 4000.0, "Epargne Taylor", Date())
    { };
    Client f_clientTest1;
    Client f_clientTest2;
    Cheque chequeClient1;
    Cheque chequeClient2;
    Epargne epargneClient1;
    Epargne epargneClient2;
};

/**
* \brief Test du constructeur de copie Client::Client (const Client)
*   cas valide : Un client copié parfaitement, de meme que tous ses comptes
*     	
*   cas invalide : aucun identifié
*/  
TEST_F(ClientsEtComptesValides, constructeurCopie_valide)
{
  f_clientTest1.ajouterCompte (chequeClient1);
  f_clientTest1.ajouterCompte (epargneClient1);
  Client copieClient(f_clientTest1);
  ASSERT_EQ(f_clientTest1.reqReleves (), copieClient.reqReleves ());
}

/**
* \brief Test du constructeur de copie Client& Client::operator= (const Client)
*   cas valide : Un client copié parfaitement, de meme que tous ses comptes
*     	
*   cas invalide : aucun identifié
*/  
TEST_F(ClientsEtComptesValides, operateurAffectation_valide)
{
  f_clientTest1.ajouterCompte (chequeClient1);
  f_clientTest1.ajouterCompte (epargneClient1);
  f_clientTest2 = f_clientTest1;
  ASSERT_EQ(f_clientTest1.reqReleves (), f_clientTest2.reqReleves ());
}

/**
* \brief Test de la méthode void ajouterCompte (const bancaire::Compte)
*   cas valide : ajouterCompteCheque Ajout d'un compte cheque
*                ajouterCompteEpargne Ajout d'un compte cheque
*     	
*   cas invalide : Aucun identifie
*/  
TEST_F(ClientsEtComptesValides, ajouterCompteCheque_valide)
{
  f_clientTest1.ajouterCompte(chequeClient1);
  ASSERT_EQ(f_clientTest1.nbComptes (), 1);
}

TEST_F(ClientsEtComptesValides, ajouterCompteEpargne_valide)
{
  f_clientTest1.ajouterCompte(epargneClient1);
  ASSERT_EQ(f_clientTest1.nbComptes (), 1);
}

/**
* \brief Test de la méthode int Client::reqNoFolio(void) const
*   cas valide : Création compte cheque valide connue et test le numero de folio
*     	
*   cas invalide : Aucun d'identifié
*/  
 TEST_F (ClientsEtComptesValides, reqNoFolio_numeroFolioValide)
 {
   ASSERT_EQ (f_clientTest1.reqNoFolio (), 1000);
 }

/**
* \brief Test de la méthode const std::string& Client::reqNom(void) const
*   cas valide : Création compte cheque valide connue et test le nom
*     	
*   cas invalide : Aucun d'identifié
*/  
 TEST_F (ClientsEtComptesValides, reqNom_nomFolioValide)
 {
   ASSERT_EQ (f_clientTest1.reqNom (), "Del Rey");
 }

/**
* \brief Test de la méthode const std::string& Client::reqPrenom(void) const
*   cas valide : Création compte cheque valide connue et test le prenom
*     	
*   cas invalide : Aucun d'identifié
*/

TEST_F (ClientsEtComptesValides, reqPrenom_prenomFolioValide)
 {
   ASSERT_EQ (f_clientTest1.reqPrenom (), "Lana");
 }

/**
* \brief Test de la méthode const std::string& Client::reqTelephone(void) const
*   cas valide : Création compte cheque valide connue et test le telephone
*     	
*   cas invalide : Aucun d'identifié
*/  
TEST_F (ClientsEtComptesValides, reqTelephone_telephoneValide)
{
  ASSERT_EQ (f_clientTest1.reqTelephone (), "1234567890");
}

/**
* \brief Test de la méthode const util::Date& Client::reqDateNaissance(void) const
*   cas valide : Création compte cheque valide connue et test la date de naissance
*     	
*   cas invalide : Aucun d'identifié
*/  
TEST_F (ClientsEtComptesValides, reqDateNaissance_dateNaissanceValide)
{
  ASSERT_EQ (f_clientTest1.reqDateNaissance (), Date(21,06,1985));
}  

/**
* \brief Test de la méthode std::string Client::reqReleves(void) const
*   cas valide : Création compte cheque valide connue et test le format du releve
*     	
*   cas invalide : Aucun d'identifié
*/
TEST_F (ClientsEtComptesValides, reqReleves_formatValide)
{
  f_clientTest1.ajouterCompte (chequeClient1);
  f_clientTest1.ajouterCompte (epargneClient1);
    string expected;
    stringstream ss;
    ss << "Client no de folio : 1000" << endl;
    ss << "Lana Del Rey" << endl;
    ss << "Date de naissance : 21/06/1985" << endl;
    ss << "1234567890" << endl;
    ss << endl;  // Ligne vide
    ss << "Comptes" << endl;
    ss << "Compte Cheque" << endl;
    ss << "Numero : 10001" << endl;
    ss << "Description : Cheque Lana" << endl;
    ss << "Date d'ouverture : " << Date() << endl;
    ss << "Taux d'interet : 1.5" << endl;
    ss << "Solde : 500$" << endl;
    ss << "Nombre de transactions : 0" << endl;
    ss << "Taux d'interet minimum : 0.1" << endl;
    ss << "Interet : 0$" << endl;
    ss << endl;  // Ligne vide
    ss << "Compte Epargne" << endl;
    ss << "Numero : 30001" << endl;
    ss << "Description : Epargne Lana" << endl;
    ss << "Date d'ouverture : " << Date() << endl;
    ss << "Taux d'interet : 2" << endl;
    ss << "Solde : 3000$" << endl;
    ss << "Interet : 60$" << endl;
    ss << endl;  // Ligne vide
    expected = ss.str();

    ASSERT_EQ(f_clientTest1.reqReleves (), expected);
}

/**
* \brief Test de la méthode int Client::nbComptes(void) const
*   cas valide : 
*     	
*   cas invalide : Aucun d'identifié
*/
TEST_F (ClientsEtComptesValides, nbComptes_calculValide)
{
  f_clientTest1.ajouterCompte (chequeClient1);
  f_clientTest1.ajouterCompte (epargneClient1);
  f_clientTest2.ajouterCompte (epargneClient2);
  ASSERT_EQ(f_clientTest1.nbComptes (), 2);
  ASSERT_EQ(f_clientTest2.nbComptes (), 1);
}


/**
* \brief Test de la méthode bool Client::operator< (Client& autreClient) const
*   cas valide : 
*     	
*   cas invalide : 
*/
TEST_F (ClientsEtComptesValides, operatorInferiorite_resultatValide)
{
  ASSERT_TRUE(f_clientTest1.operator < (f_clientTest2));

}

/**
* \brief Test de la méthode bool Client::operator< (Client& autreClient) const
*   cas valide : 
*     	
*   cas invalide : 
*/
TEST_F(ClientsEtComptesValides, ajouterCompte_compteDejaPresent_exceptionLancee)
{
  f_clientTest1.ajouterCompte(chequeClient1); // premier ajout valide
  ASSERT_THROW(f_clientTest1.ajouterCompte(chequeClient1), CompteDejaPresentException);
}

/**
* \brief Test de la méthode bool compteEstDejaPresent(int p_noCompte) const
*   cas valide : si un compte avec le meme noCompte existe
*     	
*   cas invalide : si aucun compte avec le meme noCompte existe
*/
TEST_F(ClientsEtComptesValides, compteEstDejaPresent_compteExiste_retourneTrue)
{
  f_clientTest1.ajouterCompte(epargneClient1);
  ASSERT_TRUE(f_clientTest1.compteEstDejaPresent(epargneClient1.reqNoCompte()));
}

TEST_F(ClientsEtComptesValides, compteEstDejaPresent_compteAbsent_retourneFalse)
{
  ASSERT_FALSE(f_clientTest1.compteEstDejaPresent(99999));
}

/**
* \brief Test de la méthode bool supprimerCompte(int p_noCompte)
*   cas valide : si le compte existe
*     	
*   cas invalide : si le compte n'existe pas
*/
TEST_F(ClientsEtComptesValides, supprimerCompte_compteAbsent_exceptionLancee)
{
  ASSERT_THROW(f_clientTest1.supprimerCompte(99999), CompteAbsentException);
}

TEST_F(ClientsEtComptesValides, supprimerCompte_comptePresent_supprimeAvecSucces)
{
  f_clientTest1.ajouterCompte(chequeClient1);
  ASSERT_EQ(f_clientTest1.nbComptes(), 1);

  ASSERT_NO_THROW(f_clientTest1.supprimerCompte(chequeClient1.reqNoCompte()));
  ASSERT_EQ(f_clientTest1.nbComptes(), 0);
}
