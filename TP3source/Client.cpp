/**
 * \file    Client.cpp
 * \brief   Implementation de la classe Client
 * \author  Audrey Valade
 * \date    16 mars 2025, 16 h 37
 */

#include "Client.h"
#include "ContratException.h"
#include "CompteException.h"
#include "validationFormat.h"

#include <sstream>

using namespace std;
using namespace util;
using namespace bancaire;

/**
* \brief   Constructeur avec paramètres
* \param[in] p_noFolio Le Numero de folio de l'objet
* \param[in] p_nom Le Nom de l'objet
* \param[in] p_prenom Le Prénom de l'objet
* \param[in] p_telephone Le Téléphone de l'objet
* \param[in] p_dateNaissance La Date de naissance de l'objet
* \return  Un objet client
*/
Client::Client (int p_noFolio, 
                const std::string& p_nom, 
                const std::string& p_prenom, 
                const std::string& p_telephone, 
                const Date& p_dateNaissance) : m_noFolio(p_noFolio),
        m_nom(p_nom), m_prenom(p_prenom), m_telephone(p_telephone), m_dateNaissance(p_dateNaissance)
{
  PRECONDITION(p_noFolio >= 1000 && p_noFolio < 10000);
  PRECONDITION(validerFormatNom(p_nom));
  PRECONDITION(validerFormatNom(p_prenom));
  PRECONDITION(!p_telephone.empty());
  PRECONDITION(p_dateNaissance < Date());
   
  POSTCONDITION(reqNoFolio() == p_noFolio);
  POSTCONDITION(reqNom() == p_nom);
  POSTCONDITION(reqPrenom() == p_prenom);
  POSTCONDITION(reqTelephone() == p_telephone);
  POSTCONDITION(reqDateNaissance() == p_dateNaissance);

  INVARIANTS();
};

/**
 * \brief Constructeur de copie
 * \param[in] p_client L'objet client à copier
 */
Client::Client(const Client& p_client)
: m_noFolio(p_client.m_noFolio), 
    m_nom(p_client.m_nom), 
    m_prenom(p_client.m_prenom), 
    m_telephone(p_client.m_telephone), 
    m_dateNaissance(p_client.m_dateNaissance)
{
  for (const auto &element : p_client.m_comptes)
    {  
      m_comptes.push_back(element->clone());
    }
};

/**
 * \brief Surcharge de l'opérateur d'assignation
 * \param[in] p_client L'objet client à copier
 * \return Une référence sur l'objet courant
 */
Client& Client::operator= (const Client& p_client)
{
  if (!(this == &p_client))
    {
      m_noFolio = p_client.m_noFolio;
      m_nom = p_client.m_nom;
      m_prenom = p_client.m_prenom;
      m_telephone = p_client.m_telephone;
      m_dateNaissance = p_client.m_dateNaissance;
      m_comptes.clear();
      for (const auto& element : p_client.m_comptes)
        {
          m_comptes.push_back(element->clone());
        }
    }
  return *this;
};

/**
 * \brief Vérifie les invariants de la classe Client
 */
void Client::verifieInvariant(void) const 
{
  INVARIANT(m_noFolio >= 1000 && m_noFolio < 10000);
  INVARIANT(validerFormatNom(m_nom));
  INVARIANT(validerFormatNom(m_prenom));
  INVARIANT(!m_telephone.empty());
};

/**
* \brief   Acesseur pour Numero de folio
* \return  m_noFolio Le Numero de folio de l'objet
*/
int Client::reqNoFolio(void) const {return m_noFolio;};

/**
* \brief   Acesseur pour Nom
* \return  m_nom Le Nom de l'objet
*/
const std::string& Client::reqNom(void) const {return m_nom;};

/**
* \brief   Acesseur pour Prénom
* \return  m_prenom Le Prénom de l'objet
*/
const std::string& Client::reqPrenom(void) const {return m_prenom;};

/**
* \brief   Acesseur pour Téléphone
* \return  m_telephone Le Téléphone de l'objet
*/
const std::string& Client::reqTelephone(void) const {return m_telephone;};

/**
* \brief   Acesseur pour Date de naissance
* \return  m_dateNaissance La Date de naissance de l'objet
*/
const util::Date& Client::reqDateNaissance(void) const{return m_dateNaissance;};

/**
 * \brief Retourne une chaîne formatée contenant les informations du client et ses comptes
 * \return Une chaîne de caractères avec les informations personnelles et les relevés de comptes
 */
std::string Client::reqReleves(void) const 
{
  ostringstream os;
  os << "Client no de folio : " << m_noFolio << endl;
  os << m_prenom << " " << m_nom << endl;
  os << "Date de naissance : " << m_dateNaissance << endl;
  os << m_telephone << endl << endl;
  os << "Comptes" << endl;

  for (const auto& compte : m_comptes)
    {
      os << compte->reqCompteFormate() << endl;
    };
  return os.str();
};

/**
 * \brief Ajoute un compte au client
 * \param[in] p_nouveauCompte Le compte à ajouter (copie en profondeur via clone)
 */
void Client::ajouterCompte (const Compte& p_nouveauCompte)
{  
  if (!compteEstDejaPresent(p_nouveauCompte.reqNoCompte())){
    m_comptes.push_back(p_nouveauCompte.clone());  
  } else {
      //Quand exception sera implementee, en attendant cout
      throw CompteDejaPresentException
              ("Impossible d'ajouter le compte car il est deja present.\n" + p_nouveauCompte.reqCompteFormate());
    }
};

/**
 * \brief Retourne le nombre de comptes associés au client
 * \return Le nombre de comptes
 */
int Client::nbComptes(void) const
{
  return m_comptes.size();
};

/**
 * \brief Compare deux clients selon leur numéro de folio
 * \param[in] c_1 Premier client à comparer
 * \param[in] c_2 Deuxième client à comparer
 * \return Le client ayant le plus petit numéro de folio
 */

bool Client::operator< (Client& autreClient) const
{
  return this->reqNoFolio() < autreClient.reqNoFolio ();
}


/**
 * \brief Destructeur de la classe Client
 */
Client::~Client () { }

/**
 * \brief Permet de verifier si le client a deja ce compte, si oui elle retourne
 * true sinon false
 * \param p_noCompte
 * \return bool 
 */
bool Client::compteEstDejaPresent(int p_noCompte) const{
  
  for (auto it = m_comptes.begin(); it != m_comptes.end(); ++it)
    {
      if ((*it)->reqNoCompte() == p_noCompte){return true;}
    }
  
  return false;
}

/**
 * \brief Methode permettant de supprimer un compte de la liste dont le numero
 * de compte est recu en paramettre
 * \param p_noCompte
 */
void Client::supprimerCompte(int p_noCompte){

  for (auto it = m_comptes.begin(); it != m_comptes.end(); ++it){
      if ((*it)->reqNoCompte() == p_noCompte){
          m_comptes.erase(it);
          return;
        }
    }
  throw CompteAbsentException("Le compte" + std::to_string(p_noCompte) + " est absent.");
}
