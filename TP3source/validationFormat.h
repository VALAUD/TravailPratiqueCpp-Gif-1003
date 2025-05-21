/**
 * \file    validationFormat.h
 * \breif   
 * \author  Audrey Valade
 * \date    16 mars 2025, 16 h 37
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H
#include<iostream>
#include <cstring>
#include <string>
#include <array>
#include <fstream>


bool validerFormatNom(const std::string& p_nom); 
bool validerFormatFichier(std::istream& p_is);
bool validerFormatDate(const std::string& p_jour, const std::string& p_mois, const std::string& p_annee);


#endif /* VALIDATIONFORMAT_H */

