/**
 * \file    Epargne.h
 * \brief   Prototype de la classe Epargne
 * \author  Audrey Valade
 * \date    16 mars 2025, 16 h 37
 */

#ifndef EPARGNE_H
#define EPARGNE_H
#include "Compte.h"
#include <memory>

/**
* \namespace <name>
*/
namespace bancaire
{
   /**
   * \class   Epargne
   * \brief   Classe permettant de modeliser un objet epargne.
   */
  class Epargne : public Compte
  {
  public:
    Epargne (int p_noCompte, 
             double p_tauxInteret, 
             double p_solde = 0, 
             const std::string& p_description = "Epargne", 
             const util::Date& p_dateOuverture = util::Date());
    
    void asgTauxInteret(double p_tauxInteret);
    void asgSolde(double p_solde);

    virtual const std::string reqCompteFormate(void) const;
        
    virtual std::unique_ptr<Compte> clone() const override;
    virtual double calculerInteret() const;
    virtual ~Epargne ();
  
  private:
    void verifieInvariant(void) const;
  };
} //namespace bancaire

#endif /* EPARGNE_H */

