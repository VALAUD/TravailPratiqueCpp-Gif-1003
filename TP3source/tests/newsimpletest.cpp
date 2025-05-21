/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/testFiles/simpletest.cpp to edit this template
 */

/* 
 * File:   newsimpletest.cpp
 * Author: etudiant
 *
 * Created on 7 avril 2025, 17 h 37
 */

#include <stdlib.h>
#include <iostream>
#include "Cheque.h"

/*
 * Simple C++ Test Suite
 */

void
testAsgTauxInteret ()
{
  double p_tauxInteret;
  bancaire::Cheque cheque;
  cheque.asgTauxInteret (p_tauxInteret);
  if (true /*check result*/)
    {
      std::cout << "%TEST_FAILED% time=0 testname=testAsgTauxInteret (newsimpletest) message=error message sample" << std::endl;
    }
}

void
testAsgSolde ()
{
  double p_solde;
  bancaire::Cheque cheque;
  cheque.asgSolde (p_solde);
  if (true /*check result*/)
    {
      std::cout << "%TEST_FAILED% time=0 testname=testAsgSolde (newsimpletest) message=error message sample" << std::endl;
    }
}

void
testAsgNombreTransaction ()
{
  int p_nombreTransactions;
  bancaire::Cheque cheque;
  cheque.asgNombreTransaction (p_nombreTransactions);
  if (true /*check result*/)
    {
      std::cout << "%TEST_FAILED% time=0 testname=testAsgNombreTransaction (newsimpletest) message=error message sample" << std::endl;
    }
}

void
testReqNombreTransactions ()
{
  bancaire::Cheque cheque;
  int result = cheque.reqNombreTransactions ();
  if (true /*check result*/)
    {
      std::cout << "%TEST_FAILED% time=0 testname=testReqNombreTransactions (newsimpletest) message=error message sample" << std::endl;
    }
}

void
testReqTauxInteretMinimum ()
{
  bancaire::Cheque cheque;
  double result = cheque.reqTauxInteretMinimum ();
  if (true /*check result*/)
    {
      std::cout << "%TEST_FAILED% time=0 testname=testReqTauxInteretMinimum (newsimpletest) message=error message sample" << std::endl;
    }
}

void
testReqCompteFormate ()
{
  bancaire::Cheque cheque;
  const std::string result = cheque.reqCompteFormate ();
  if (true /*check result*/)
    {
      std::cout << "%TEST_FAILED% time=0 testname=testReqCompteFormate (newsimpletest) message=error message sample" << std::endl;
    }
}

void
testClone ()
{
  bancaire::Cheque cheque;
  std::unique_ptr<Compte> result = cheque.clone ();
  if (true /*check result*/)
    {
      std::cout << "%TEST_FAILED% time=0 testname=testClone (newsimpletest) message=error message sample" << std::endl;
    }
}

int
main (int argc, char** argv)
{
  std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
  std::cout << "%SUITE_STARTED%" << std::endl;

  std::cout << "%TEST_STARTED% testAsgTauxInteret (newsimpletest)" << std::endl;
  testAsgTauxInteret ();
  std::cout << "%TEST_FINISHED% time=0 testAsgTauxInteret (newsimpletest)" << std::endl;

  std::cout << "%TEST_STARTED% testAsgSolde (newsimpletest)" << std::endl;
  testAsgSolde ();
  std::cout << "%TEST_FINISHED% time=0 testAsgSolde (newsimpletest)" << std::endl;

  std::cout << "%TEST_STARTED% testAsgNombreTransaction (newsimpletest)" << std::endl;
  testAsgNombreTransaction ();
  std::cout << "%TEST_FINISHED% time=0 testAsgNombreTransaction (newsimpletest)" << std::endl;

  std::cout << "%TEST_STARTED% testReqNombreTransactions (newsimpletest)" << std::endl;
  testReqNombreTransactions ();
  std::cout << "%TEST_FINISHED% time=0 testReqNombreTransactions (newsimpletest)" << std::endl;

  std::cout << "%TEST_STARTED% testReqTauxInteretMinimum (newsimpletest)" << std::endl;
  testReqTauxInteretMinimum ();
  std::cout << "%TEST_FINISHED% time=0 testReqTauxInteretMinimum (newsimpletest)" << std::endl;

  std::cout << "%TEST_STARTED% testReqCompteFormate (newsimpletest)" << std::endl;
  testReqCompteFormate ();
  std::cout << "%TEST_FINISHED% time=0 testReqCompteFormate (newsimpletest)" << std::endl;

  std::cout << "%TEST_STARTED% testClone (newsimpletest)" << std::endl;
  testClone ();
  std::cout << "%TEST_FINISHED% time=0 testClone (newsimpletest)" << std::endl;

  std::cout << "%SUITE_FINISHED% time=0" << std::endl;

  return (EXIT_SUCCESS);
}

