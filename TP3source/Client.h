/**
 * \file    Client.h
 * \brief   Prototype de la classe Client
 * \author  Audrey Valade
 * \date    16 mars 2025, 16 h 37
 */

#ifndef CLIENT_H
#define CLIENT_H
#include "Date.h"
#include "Compte.h"
#include <vector>

/**
 * \class   Client
 * \brief   Classe permettant de modeliser un objet client.
 */
namespace bancaire
{
    class Client
    {
    public:
      Client (int p_noFolio, 
              const std::string& p_nom, 
              const std::string& p_prenom, 
              const std::string& p_telephone, 
              const util::Date& p_dateNaissance);

      Client (const Client& p_client);

      Client& operator= (const Client& p_client);

      void ajouterCompte (const bancaire::Compte& p_nouveauCompte);

      int reqNoFolio(void) const;
      const std::string& reqNom(void) const;
      const std::string& reqPrenom(void) const;
      const std::string& reqTelephone(void) const;
      const util::Date& reqDateNaissance(void) const;
      std::string reqReleves(void) const;


      int nbComptes(void) const;

      bool operator< (Client& autreClient) const;

      virtual ~Client ();

      bool compteEstDejaPresent(int p_noCompte) const;
      void supprimerCompte(int p_noCompte);

    private:
      int m_noFolio;
      std::string m_nom;
      std::string m_prenom;
      std::string m_telephone;
      util::Date m_dateNaissance;

      std::vector< std::unique_ptr<bancaire::Compte> > m_comptes;

      void verifieInvariant(void) const;
    };
} //namespace bancaire

#endif /* CLIENT_H */

