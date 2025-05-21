/**
 * \file    Compte.h
 * \brief   Prototype de la classe Compte
 * \author  Audrey Valade
 * \date    16 mars 2025, 16 h 37
 */

#ifndef COMPTE_H
#define COMPTE_H
#include "Date.h"
#include <memory>

/**
* \namespace <name>
*/
namespace bancaire
{
   /**
   * \class   Compte
   * \brief   Classe permettant de modeliser un objet compte.
   */
    class Compte
    {
    public:
      Compte (int p_noCompte, 
              double p_tauxInteret, 
              double p_solde = 0, 
              const std::string& p_description = "Compte Courant", 
              const util::Date& p_dateOuverture = util::Date());
      
      void asgTauxInteret(double p_tauxInteret);
      void asgSolde(double p_solde);
      void asgDescription(const std::string& p_description);
      
      int reqNoCompte(void) const;
      double reqTauxInteret(void) const;
      double reqSolde(void) const;
      const std::string& reqDescription(void) const;
      const util::Date& reqDateOuverture(void) const;
      virtual const std::string reqCompteFormate(void) const;      
      
      virtual std::unique_ptr<Compte> clone() const =0;
      virtual double calculerInteret() const;
      virtual ~Compte ();
      
      
    private:
      void verifieInvariant(void) const;

      int m_noCompte;
      double m_tauxInteret;
      double m_solde;
      std::string m_description;
      util::Date m_dateOuverture;
    };   
} //namespace bancaire

#endif /* COMPTE_H */
