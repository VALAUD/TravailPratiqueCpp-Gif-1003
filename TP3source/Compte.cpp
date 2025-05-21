/**
 * \file    Compte.cpp
 * \brief   Implementation de la classe Compte
 * \author  Audrey Valade
 * \date    16 mars 2025, 16 h 37
 */

#include "Compte.h"
#include "ContratException.h"
#include <sstream>

using namespace std;
using namespace util;

/**
* \namespace <name>
*/
namespace bancaire
{
    /**
    * \brief   Constructeur avec paramètres
    * \param[in] p_noCompte Le numero de compte de l'objet
    * \param[in] p_tauxInteret Le taux d'intérêt de l'objet
    * \param[in] p_solde Le solde de l'objet
    * \param[in] p_description La description de l'objet
    * \param[in] p_dateOuverture La date d'ouverture de l'objet
    * \return  Un objet compte
    */
    Compte::Compte (int p_noCompte, double p_tauxInteret, double p_solde, const std::string& p_description, const Date& p_dateOuverture):
    m_noCompte(p_noCompte), m_tauxInteret(p_tauxInteret), m_solde(p_solde), m_description(p_description), m_dateOuverture(p_dateOuverture)
    {
      PRECONDITION(p_noCompte > 0);
      PRECONDITION(p_tauxInteret > 0);
      PRECONDITION(!p_description.empty());

      POSTCONDITION(reqNoCompte() == p_noCompte);
      POSTCONDITION(reqTauxInteret() == p_tauxInteret);
      POSTCONDITION(reqSolde() == p_solde);
      POSTCONDITION(reqDescription() == p_description);
      POSTCONDITION(reqDateOuverture() == p_dateOuverture);

      INVARIANTS();
    };

    /**
    * \brief   Mutateur pour Taux d'intérêt
    * \param[in]  p_tauxInteret Le Taux d'intérêt de l'objet
    */
    void Compte::asgTauxInteret(double p_tauxInteret) 
    {        
      PRECONDITION(p_tauxInteret >= 0);
      m_tauxInteret = p_tauxInteret;
      POSTCONDITION(reqTauxInteret() == p_tauxInteret);
      INVARIANTS();
    };

    /**
    * \brief   Mutateur pour Solde
    * \param[in]  p_solde Le Solde de l'objet
    */
    void Compte::asgSolde(double p_solde)
    {
      m_solde = p_solde;
      POSTCONDITION(reqSolde() == p_solde);
      INVARIANTS();
    };

    /**
    * \brief   Mutateur pour Description
    * \param[in]  p_description La Description de l'objet
    */
    void Compte::asgDescription(const std::string& p_description)
    {
      PRECONDITION(!p_description.empty())
      m_description = p_description;
      POSTCONDITION (reqDescription() == p_description);
      INVARIANTS();
    };

    /**
    * \brief Vérifie les invariants de la classe Compte
    */
    void Compte::verifieInvariant(void) const
    {
      INVARIANT(m_noCompte > 0);
      INVARIANT(m_tauxInteret >= 0);
      INVARIANT(!m_description.empty());
    };
    
    /**
    * \brief   Acesseur pour Numero de compte
    * \return  m_noCompte Le Numero de compte de l'objet
    */
    int Compte::reqNoCompte(void) const {return m_noCompte;};

    /**
    * \brief   Acesseur pour Taux d'intérêt
    * \return  m_tauxInteret Le Taux d'intérêt de l'objet
    */
    double Compte::reqTauxInteret(void) const {return m_tauxInteret;};
    
    /**
    * \brief   Acesseur pour Solde
    * \return  m_solde Le Solde de l'objet
    */
    double Compte::reqSolde(void) const {return m_solde;};

    /**
    * \brief   Acesseur pour Description
    * \return  m_description La Description de l'objet
    */
    const std::string& Compte::reqDescription(void) const {return m_description;};  
    
    /**
    * \brief   Acesseur pour Date d'ouverture
    * \return  m_dateOuverture La Date d'ouverture de l'objet
    */
    const util::Date& Compte::reqDateOuverture(void) const {return m_dateOuverture;};

    /**
    * \brief Retourne une chaîne formatée contenant les informations sur le compte
    * \return Une chaîne de caractères avec les informations du comptes
    */
    const std::string Compte::reqCompteFormate(void) const
    {
      ostringstream os;
      os << "Numero : " << m_noCompte << endl;
      os << "Description : " << m_description << endl;
      os << "Date d'ouverture : " << m_dateOuverture << endl;
      os << "Taux d'interet : " << m_tauxInteret << endl;
      os << "Solde : " << m_solde << "$" << endl;
      return os.str();
    };
    
    /**
     * \brief Calcule les intérêts pour le compte
     *
     * Méthode virtuelle permettant un traitement polymorphe.
     * Retourne 0 par défaut si la classe dérivée ne redéfinit pas cette méthode.
     *
     * \return Le montant d’intérêt (0 par défaut)
     */
    double Compte::calculerInteret() const {return 0;};

    /**
    * \brief Destructeur de la classe Compte
    */
    Compte::~Compte(){};    
} //namespace bancaire
