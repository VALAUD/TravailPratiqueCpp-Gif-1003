/**
 * \file    validationFormat.cpp
 * \brief   
 * \author  Audrey Valade
 * \date    16 mars 2025, 16 h 37
 */

#include "validationFormat.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

bool validerFormatNom(const string& p_nom)
{
  if (p_nom.empty())
    {
      return false;
    }
  const char* nom = p_nom.c_str();
  int longeurNom = strlen(nom);  
  char lettreDebut = nom[0];
  char lettreFin = nom[longeurNom-1];

  string symboles = " -éèêëàâäçèéêëîïôöùûüÿçÉÈÊËÀÂÄÇÎÏÔÖÙÛÜÇabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const char* symbolesAnalyse = symboles.c_str();
  int longeurListeSymbole = strlen(symbolesAnalyse);  
  char16_t codeEspace = symbolesAnalyse[0];
  char16_t codeTiret = symbolesAnalyse[1];

  bool symboleValide = false;

  for (int i = 0; i < longeurNom ; i++)
    {
      char lettre = nom[i];
      char16_t codeLettre = lettre;
      char lettreSuivante = nom[i+1];

      if ((lettre == lettreDebut || lettre == lettreFin) && (codeLettre == codeEspace || codeLettre == codeTiret))
        {
            return false;
        }
      else if ((lettre == lettreSuivante) && (codeLettre == codeEspace || codeLettre == codeTiret))
        {
          return false;
        }
      else if (symboles.find(lettre) == string::npos)
        {
          return false;
        }
    }
  return true;
}

bool validerFormatDate(const string& p_jour, const string& p_mois, const string& p_annee)
{

  if (p_jour == "00" || p_mois == "00" || p_annee == "0000" || p_jour.length() != 2 || p_mois.length() != 2 || p_annee.length() != 4)
    {
      return false;
    }

  else 
    {
      return true;
    }
}


bool validerFormatFichier(istream& p_is)
{
  if (!p_is)
    {
      cerr << "ouverture impossible" << endl;
      return 1;
    }

  string prenom;
  string nom;
  getline(p_is, prenom);
  getline(p_is, nom);
  if (!validerFormatNom(prenom) || !validerFormatNom(nom))
    return false;


//  string dateNaissance;
//  getline(p_is, dateNaissance);
  string jour;
  string mois;
  string annee;
  p_is >> jour >> mois >> annee;
  p_is.ignore();
  if(!validerFormatDate(jour, mois, annee))
    return false;

  string telephone;
  string folio;
  getline(p_is, telephone);
  getline(p_is, folio);
  if (telephone.empty() || folio.empty())
    return false;

  string line;
  int i = 6;
  while (getline(p_is, line))
    {      
      if (line.empty()) 
        {
          return false;
        }
      else if (line == "cheque" || line == "epargne")
        {
          if (line == "cheque")
            i = 7;
          else
            i = 6;

          for (int j = 1 ; j < i ; j++) 
            {
              if (line.empty())
                {
                  return false;
                }
              getline(p_is, line);
            }
        }

      else
        {
          return false;
        }
    }
  return true;
}