/**
 * \file CompteException.cpp
 * \brief Implantation de la classe CompteException et de ses héritiers
 * \author 
 * \date v3.0 révisée balises Doxygen C++ normes
 */
#include "CompteException.h"
#include <sstream>

using namespace std;
using namespace bancaire;


/**
 * \brief Constructeur de la classe de base CompteException
 * \param p_raison chaîne de caractères représentant l'erreur
 */
CompteException::CompteException(const std::string& p_raison) :
runtime_error (p_raison) {}

CompteException::~CompteException () { }

/**
 * \brief Constructeur de la classe de base CompteDejaPresentException
 * \param p_raison chaîne de caractères représentant l'erreur
 */
CompteDejaPresentException::CompteDejaPresentException(const std::string& p_raison) :
CompteException (p_raison) { }

CompteDejaPresentException::~CompteDejaPresentException () {}

/**
 * \brief Constructeur de la classe de base CompteAbsentException
 * \param p_raison chaîne de caractères représentant l'erreur
 */
CompteAbsentException::CompteAbsentException(const std::string& p_raison) :
CompteException (p_raison) {}

CompteAbsentException::~CompteAbsentException () {}