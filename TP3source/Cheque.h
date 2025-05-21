/**
 * \file    Cheque.h
 * \brief   Prototype de la classe Cheque
 * \author  Audrey Valade
 * \date    16 mars 2025, 16 h 37
 */

#ifndef CHEQUE_H
#define CHEQUE_H
#include "Compte.h"
#include <memory>

namespace bancaire
{
   /**
   * \class   Cheque
   * \brief   Classe permettant de modeliser un objet cheque.
   */
  class Cheque : public Compte
  {
  public:
    Cheque (int p_noCompte,
            double p_tauxInteret,
            double p_solde = 0,
            const std::string& p_description = "Cheque",
            const util::Date& p_dateOuverture = util::Date(), 
            int p_nombreTransactions = 0, 
            double p_tauxInteretMinimum = 0.1);
    
    void asgTauxInteret(double p_tauxInteret);
    void asgSolde(double p_solde);
    void asgNombreTransaction(int p_nombreTransactions);
      
    int reqNombreTransactions(void) const;
    double reqTauxInteretMinimum(void) const;
    virtual const std::string reqCompteFormate(void) const;
 
    virtual std::unique_ptr<Compte> clone() const override;
    virtual double calculerInteret(void) const;
    virtual ~Cheque ();
      
  private:
    void verifieInvariant(void) const;

    int m_nombreTransactions;
    double m_tauxInteretMinimum;
  };   
} //namespace bancaire

#endif /* CHEQUE_H */
