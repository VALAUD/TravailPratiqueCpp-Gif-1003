/**
 * \file    Cheque.cpp
 * \brief   Implementation de la classe Cheque
 * \author  Audrey Valade
 * \date    16 mars 2025, 16 h 37
 */

#include "Cheque.h"
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
  * \param[in] p_nombreTransactions Le nombre de transactions de l'objet
  * \param[in] p_tauxInteretMinimum Le taux d'intérêt minimum de l'objet
  * \return  Un objet cheque
  */
  Cheque::Cheque (int p_noCompte, double p_tauxInteret, double p_solde,
                  const std::string& p_description, const Date& p_dateOuverture, 
                  int p_nombreTransactions, double p_tauxInteretMinimum)
          : Compte(p_noCompte, p_tauxInteret, p_solde, p_description, p_dateOuverture),
          m_nombreTransactions(p_nombreTransactions),
          m_tauxInteretMinimum(p_tauxInteretMinimum)
  {
    PRECONDITION(p_tauxInteretMinimum > 0);
    PRECONDITION(p_tauxInteretMinimum < p_tauxInteret);
    PRECONDITION(p_nombreTransactions >= 0);
    PRECONDITION(p_nombreTransactions <= 40);
    INVARIANTS();
    POSTCONDITION(reqNombreTransactions() == p_nombreTransactions);
    POSTCONDITION(reqTauxInteretMinimum() == p_tauxInteretMinimum);
  };
  
  /**
  * \brief   Mutateur pour Taux d'intérêt
  * \param[in]  p_tauxInteret le Taux d'intérêt de l'objet
  */
  void Cheque::asgTauxInteret(double p_tauxInteret)
  {
    PRECONDITION(m_tauxInteretMinimum < p_tauxInteret);
    Compte::asgTauxInteret(p_tauxInteret);
    INVARIANTS();
  };

  /**
  * \brief   Mutateur pour Solde
  * \param[in]  p_solde le Solde de l'objet
  */
  void Cheque::asgSolde(double p_solde)
  {
    Compte::asgSolde(p_solde);
    INVARIANTS();
  };
  
  /**
  * \brief   Mutateur pour Nombre de transactions
  * \param[in]  p_nombreTransactions le  Nombre de transactions de l'objet
  */
    void Cheque::asgNombreTransaction(int p_nombreTransactions)
  {
    PRECONDITION(p_nombreTransactions >= 0);
    PRECONDITION(p_nombreTransactions <= 40) ;   
    m_nombreTransactions = p_nombreTransactions;      
    POSTCONDITION(reqNombreTransactions() == p_nombreTransactions);
    INVARIANTS();
  };
  
  /**
  * \brief Vérifie les invariants de la classe Cheque
  */
  void Cheque::verifieInvariant(void) const
  {
    INVARIANT(m_tauxInteretMinimum < reqTauxInteret());
    INVARIANT(m_nombreTransactions >= 0);
    INVARIANT(m_nombreTransactions <= 40);
  };
  
  /**
  * \brief   Acesseur pour Nombre de transactions
  * \return  m_nombreTransactions Le Nombre de transactions de l'objet
  */
  int Cheque::reqNombreTransactions(void) const {return m_nombreTransactions;};

  /**
  * \brief   Acesseur pour Taux d'intérêt minimum
  * \return  m_tauxInteretMinimum Le Taux d'intérêt minimum de l'objet
  */
  double Cheque::reqTauxInteretMinimum(void) const {return m_tauxInteretMinimum;};
   
  /**
  * \brief Retourne une chaîne formatée contenant les informations sur le compte
  * \return Une chaîne de caractères avec les informations du comptes
  */
  const std::string Cheque::reqCompteFormate(void) const
  {
    ostringstream os;
    os << "Compte Cheque" << endl;
    os << Compte::reqCompteFormate();
    os << "Nombre de transactions : " << m_nombreTransactions << endl;
    os << "Taux d'interet minimum : " << m_tauxInteretMinimum << endl;
    os << "Interet : " << calculerInteret() << "$" << endl;
    return os.str();
  };
  
  /**
  * \brief Calcule l'intérêt à appliquer au compte chèque
  *
  * Le calcul dépend du nombre de transactions et du solde actuel :
  * - Moins de 11 transactions : taux d'intérêt minimum
  * - Moins de 26 transactions : taux d'intérêt minimum * 1.4
  * - Moins de 36 transactions : taux d'intérêt minimum * 1.8
  * - Moins de 41 transactions : taux d'intérêt normal
  * Aucun intérêt n'est appliqué si le solde est positif.
  * 
  * \return Le montant d'intérêt appliqué (valeur négative si le solde est négatif)
  */
  double Cheque::calculerInteret(void) const
  {    
    if (reqNombreTransactions () < 11 && reqSolde() < 0) return (-(reqSolde() * reqTauxInteretMinimum ())/100);
    else if (reqNombreTransactions () < 26 && reqSolde() < 0) return (-(reqSolde()) * reqTauxInteretMinimum () * 1.4/100);
    else if (reqNombreTransactions () < 36 && reqSolde() < 0) return (-(reqSolde()) * reqTauxInteretMinimum () * 1.8/100);
    else if (reqNombreTransactions () < 41 && reqSolde() < 0) return (-(reqSolde()) * reqTauxInteret()/100);
    return 0;
  };
    
  /**
  * \brief Crée une copie polymorphique du compte chèque
  *
  * Cette méthode permet de dupliquer dynamiquement un objet `Cheque`
  * en respectant le polymorphisme. Elle retourne une copie de l'objet courant
  * sous forme de `std::unique_ptr<Compte>`.
  *
  * \return Une copie de l'objet courant encapsulée dans un unique_ptr
  */
  unique_ptr<Compte> Cheque::clone() const
  {
    return make_unique<Cheque>(*this);
  };
  
  /**
  * \brief Destructeur de la classe Cheque
  */
  Cheque::~Cheque () { }
} //namespace bancaire
