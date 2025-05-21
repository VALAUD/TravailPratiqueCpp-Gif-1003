/**
 * \file    Cheque.cpp
 * \brief   Programme de test pour les classes clients, comptes et ses heritiers (classes cheque et epargne)
 * \author  Audrey Valade
 * \date    16 mars 2025, 16 h 37
 */

#include <cstdlib>
#include <iostream>
#include <sstream>

#include "Date.h"
#include "Compte.h"
#include "Cheque.h"
#include "Epargne.h"
#include "Client.h"

using namespace std;
using namespace util;
using namespace bancaire;

/**
 * \fn int main()
 */
int main ()
{
    cout << "Saisir les informations sur le nouveau Client" << endl;
    int no_folio;
    string nom;
    string prenom;
    int jour;
    int mois;
    int annee;
    string telephone;

    cout << "Folio : "; cin >> no_folio; cin.ignore();
    cout << "Nom : "; 
    getline(cin,nom);
    cout << "Prénom : "; 
    getline(cin, prenom);

    cout << "Date de naissance" << endl;
    cout << "Jour : "; cin >> jour;
    cout << "Mois : "; cin >> mois;
    cout << "Année : "; cin >> annee;
    Date date_naissance(jour, mois, annee);

    cout << "Téléphone : "; cin >> telephone;

    Client nouveauClient(no_folio, nom, prenom, telephone, date_naissance);

    // nouveau compte cheque
    int no_compteCheque;
    string descriptionCheque;
    double tauxInteretCheque;
    double soldeCheque;
    int nb_transaction;
    double taux_interet_min;
    string taux_interet_min_str;

    cout << endl << "Saisir les informations sur le nouveau compte Cheque" << endl;
    cout << "numéro de compte : " ; cin >> no_compteCheque; cin.ignore();
    cout << "Description : " ; getline(cin,descriptionCheque);
    if (descriptionCheque.empty()) {descriptionCheque = "Cheque";};
    cout << "Taux d'interet : " ; cin >> tauxInteretCheque;
    cout << "Solde : " ; cin >> soldeCheque;
    cout << "Nombre de transaction : " ; cin >> nb_transaction; cin.ignore();
    
    cout << "Taux d'intérêt minimum : " ; getline(cin, taux_interet_min_str);
    if (taux_interet_min_str.empty()) {taux_interet_min = 0.1;} 
    else 
      {
        stringstream ss(taux_interet_min_str);
        ss >> taux_interet_min;
      }
    
    Cheque nouveauCompteCheque(no_compteCheque, tauxInteretCheque, soldeCheque, descriptionCheque, Date(), nb_transaction, taux_interet_min);
    nouveauClient.ajouterCompte(nouveauCompteCheque);  

    int no_compteEpargne;
    string descriptionEpargne;
    double tauxInteretEpargne;
    double soldeEpargne;

    cout << endl << "Saisir les informations sur le nouveau compte Epargne" << endl;
    cout << "numéro de compte : " ; cin >> no_compteEpargne; cin.ignore();
    cout << "Description : " ; getline(cin, descriptionEpargne);
    if (descriptionEpargne.empty()) {descriptionEpargne="Epargne";};
    cout << "Taux d'Interet : " ; cin >> tauxInteretEpargne;
    cout << "Solde : " ; cin >> soldeEpargne;

    Epargne nouveauCompteEpargne(no_compteEpargne, tauxInteretEpargne, soldeEpargne, descriptionEpargne, Date());
    nouveauClient.ajouterCompte(nouveauCompteEpargne);

    cout << endl << "tout va bien ici"<< endl;
    cout << endl << "reqCompte" << endl << nouveauCompteCheque.reqCompteFormate () << endl; 
    cout << endl << nouveauCompteEpargne.reqCompteFormate () << endl;

    cout << endl << "reqCompte" << endl << nouveauClient.reqReleves ();

    return 0;
}