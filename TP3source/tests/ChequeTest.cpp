/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/testFiles/simpletest.cpp to edit this template
 */

/* 
 * File:   ChequeTest.cpp
 * Author: etudiant
 *
 * Created on 7 avril 2025, 12 h 30
 */

#include <stdlib.h>
#include <iostream>
#include "Cheque.h"

/*
 * Simple C++ Test Suite
 */

void
testCheque ()
{
  int p_noCompte;
  double p_tauxInteret;
  double p_solde;
  const std::string& p_description;
  const util::Date& p_dateOuverture;
  int p_nombreTransactions;
  double p_tauxInteretMinimum;
  bancaire::Cheque cheque (p_noCompte, p_tauxInteret, p_solde, p_description, p_dateOuverture, p_nombreTransactions, p_tauxInteretMinimum);
  if (true /*check result*/)
    {
      std::cout << "%TEST_FAILED% time=0 testname=testCheque (ChequeTest) message=error message sample" << std::endl;
    }
}

void
testAsgTauxInteret ()
{
  double p_tauxInteret;
  bancaire::Cheque cheque;
  cheque.asgTauxInteret (p_tauxInteret);
  if (true /*check result*/)
    {
      std::cout << "%TEST_FAILED% time=0 testname=testAsgTauxInteret (ChequeTest) message=error message sample" << std::endl;
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
      std::cout << "%TEST_FAILED% time=0 testname=testAsgSolde (ChequeTest) message=error message sample" << std::endl;
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
      std::cout << "%TEST_FAILED% time=0 testname=testAsgNombreTransaction (ChequeTest) message=error message sample" << std::endl;
    }
}

void
testReqNombreTransactions ()
{
  bancaire::Cheque cheque;
  int result = cheque.reqNombreTransactions ();
  if (true /*check result*/)
    {
      std::cout << "%TEST_FAILED% time=0 testname=testReqNombreTransactions (ChequeTest) message=error message sample" << std::endl;
    }
}

void
testReqTauxInteretMinimum ()
{
  bancaire::Cheque cheque;
  double result = cheque.reqTauxInteretMinimum ();
  if (true /*check result*/)
    {
      std::cout << "%TEST_FAILED% time=0 testname=testReqTauxInteretMinimum (ChequeTest) message=error message sample" << std::endl;
    }
}

void
testReqCompteFormate ()
{
  bancaire::Cheque cheque;
  const std::string result = cheque.reqCompteFormate ();
  if (true /*check result*/)
    {
      std::cout << "%TEST_FAILED% time=0 testname=testReqCompteFormate (ChequeTest) message=error message sample" << std::endl;
    }
}

void
testClone ()
{
  bancaire::Cheque cheque;
  std::unique_ptr<Compte> result = cheque.clone ();
  if (true /*check result*/)
    {
      std::cout << "%TEST_FAILED% time=0 testname=testClone (ChequeTest) message=error message sample" << std::endl;
    }
}

int
main (int argc, char** argv)
{
  std::cout << "%SUITE_STARTING% ChequeTest" << std::endl;
  std::cout << "%SUITE_STARTED%" << std::endl;

  std::cout << "%TEST_STARTED% testCheque (ChequeTest)" << std::endl;
  testCheque ();
  std::cout << "%TEST_FINISHED% time=0 testCheque (ChequeTest)" << std::endl;

  std::cout << "%TEST_STARTED% testAsgTauxInteret (ChequeTest)" << std::endl;
  testAsgTauxInteret ();
  std::cout << "%TEST_FINISHED% time=0 testAsgTauxInteret (ChequeTest)" << std::endl;

  std::cout << "%TEST_STARTED% testAsgSolde (ChequeTest)" << std::endl;
  testAsgSolde ();
  std::cout << "%TEST_FINISHED% time=0 testAsgSolde (ChequeTest)" << std::endl;

  std::cout << "%TEST_STARTED% testAsgNombreTransaction (ChequeTest)" << std::endl;
  testAsgNombreTransaction ();
  std::cout << "%TEST_FINISHED% time=0 testAsgNombreTransaction (ChequeTest)" << std::endl;

  std::cout << "%TEST_STARTED% testReqNombreTransactions (ChequeTest)" << std::endl;
  testReqNombreTransactions ();
  std::cout << "%TEST_FINISHED% time=0 testReqNombreTransactions (ChequeTest)" << std::endl;

  std::cout << "%TEST_STARTED% testReqTauxInteretMinimum (ChequeTest)" << std::endl;
  testReqTauxInteretMinimum ();
  std::cout << "%TEST_FINISHED% time=0 testReqTauxInteretMinimum (ChequeTest)" << std::endl;

  std::cout << "%TEST_STARTED% testReqCompteFormate (ChequeTest)" << std::endl;
  testReqCompteFormate ();
  std::cout << "%TEST_FINISHED% time=0 testReqCompteFormate (ChequeTest)" << std::endl;

  std::cout << "%TEST_STARTED% testClone (ChequeTest)" << std::endl;
  testClone ();
  std::cout << "%TEST_FINISHED% time=0 testClone (ChequeTest)" << std::endl;

  std::cout << "%SUITE_FINISHED% time=0" << std::endl;

  return (EXIT_SUCCESS);
}

