#include "dna.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <ctime>

using namespace std;

dna::dna()
{
  //constructor
}
dna::~dna()
{
  //destructor
  cout << "Thank you, program exited." << endl;
}

//function returns variance using mean and current line length
double dna::findVar(double mean, int thisLine)
{
  double var = pow(((double)mean - (double)thisLine), 2);
  return var;
}

//function returns line length using the gaussian distribution formula
int dna::stringGen(double mean, double stdDevi)
{
  //random called, normalized with stdDev
  double a = ((double)rand() / (RAND_MAX));
  double b = ((double)rand() / (RAND_MAX));
  double c = sqrt((-2.0)*log(a))*(cos(2.0*M_PI*b));
  double d = (stdDevi*c) + mean;
  //line length rounded down to be an int
  int newD = (int)d;
  return newD;
}

//function returns a nucleotide value based on the percentage odds
char dna::randomChar(double pA, double pC, double pG)
{
  char randChar;
  //calculates random number in [0, 1)
  double num = ((double)rand() / (RAND_MAX));
  //number has pA% chance of being less than pA
  if (num <= pA)
      randChar = 'a';
  //if bigger than pA, number has pC% chance of being less than (pA+pC). etc. for pG
  else if (num <= (pA+pC))
      randChar = 'c';
  else if (num <= (pA+pC+pG))
      randChar = 'g';
  else
      //whatever percent isn't in remaining three percentages is the pT value
      randChar = 't';

  return randChar;
}

//function returns a gaussian distribution string using randomChar and stringGen
string dna::randomString(double pA, double pC, double pG, double mean, double stdDev)
{
  int strLen = stringGen(mean, stdDev);
  string randStr = "";
  for (int i = 0; i < strLen; i++)
  {
    char randChar = randomChar(pA, pC, pG);
    randStr += randChar;
  }
  return randStr;
}
