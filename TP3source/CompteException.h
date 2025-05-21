/**
 * \file    CompteException.h
 * \brief   Prototype de la classe Client
 * \author  Audrey Valade
 * \date    18 mars 2025, 16 h 37
 */

#ifndef COMPTEEXCEPTION_H
#define COMPTEEXCEPTION_H
#include <string>
#include <stdexcept>

namespace bancaire
{
    class CompteException : public std::runtime_error
    {
    public:
      CompteException (const std::string& p_raison);
      virtual ~CompteException ();
    };

    class CompteDejaPresentException : public CompteException
    {
    public:
      CompteDejaPresentException (const std::string& p_raison);
      virtual ~CompteDejaPresentException ();  
    };

    class CompteAbsentException : public CompteException
    {
    public:
      CompteAbsentException (const std::string& p_raison);
      virtual ~CompteAbsentException ();
    };

} //namespace bancaire

#endif /* COMPTEEXCEPTION_H */

