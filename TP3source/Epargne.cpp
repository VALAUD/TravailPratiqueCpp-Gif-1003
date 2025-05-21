/**
 * \file    Epargne.cpp
 * \brief   Implementation de la classe Epargne
 * \author  Audrey Valade
 * \date    16 mars 2025, 16 h 37
 */

#include "Epargne.h"
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
  * \return  Un objet epargne
  */
  Epargne::Epargne (int p_noCompte, double p_tauxInteret, double p_solde, const std::string& p_description, const Date& p_dateOuverture) : 
  Compte(p_noCompte, p_tauxInteret, p_solde, p_description, p_dateOuverture) 
  {
    PRECONDITION(p_tauxInteret >= 0.1 && p_tauxInteret <= 3.5);
    PRECONDITION(p_solde >= 0);
    INVARIANTS();
  };
  
  /**
  * \brief   Mutateur pour Taux d'intérêt
  * \param[in]  p_tauxInteret Le Taux d'intérêt de l'objet
  */
    void Epargne::asgTauxInteret(double p_tauxInteret)
  {
    PRECONDITION(p_tauxInteret >= 0.1);
    PRECONDITION(p_tauxInteret <= 3.5);
    Compte::asgTauxInteret(p_tauxInteret);      
    INVARIANTS();
  };
  
  /**
  * \brief   Mutateur pour Solde
  * \param[in]  p_solde Le Solde de l'objet
  */
  void Epargne::asgSolde(double p_solde)
  {
    PRECONDITION(p_solde >= 0);
    Compte::asgSolde(p_solde);
    INVARIANTS();
  };
  
  /**
  * \brief Vérifie les invariants de la classe Epargne
  */
  void Epargne::verifieInvariant(void) const
  {    
    INVARIANT(reqTauxInteret() >= 0.1);
    INVARIANT(reqTauxInteret() <= 3.5);
    INVARIANT(reqSolde() >= 0);
  };
  
  /**
  * \brief Retourne une chaîne formatée contenant les informations sur le compte
  * \return Une chaîne de caractères avec les informations du comptes
  */
  const std::string Epargne::reqCompteFormate(void) const
  {
    ostringstream os;
    os << "Compte Epargne" << endl;
    os << Compte::reqCompteFormate();
    os << "Interet : " << calculerInteret() << "$"<< endl;
    return os.str();
  };
  
  /**
  * \brief Calcule l'intérêt à appliquer au compte epargne
  *
  * Le calcul dépend du solde et du taux d'intérêt.
  * 
  * \return Le montant d'intérêt appliqué (valeur négative si le solde est négatif)
  */
  double Epargne::calculerInteret() const
  {
    return reqSolde() * (reqTauxInteret()/100);
  };  
  
  /**
  * \brief Crée une copie polymorphique du compte Epargne
  *
  * Cette méthode permet de dupliquer dynamiquement un objet `Epargne`
  * en respectant le polymorphisme. Elle retourne une copie de l'objet courant
  * sous forme de `std::unique_ptr<Compte>`.
  *
  * \return Une copie de l'objet courant encapsulée dans un unique_ptr
  */
  unique_ptr<Compte> Epargne::clone() const
  {
    return make_unique<Epargne>(*this);
  };

  /**
  * \brief Destructeur de la classe Epargne
  */
  Epargne::~Epargne(){};
} //namespace bancaire