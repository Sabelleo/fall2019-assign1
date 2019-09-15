#include <iostream>

using namespace std;

class dna
{
  public:
    //definitions for functions, etc.
    dna();
    ~dna();
    double findVar(double mean, int thisLine);
    int stringGen(double mean, double stdDevi);
    char randomChar(double pA, double pC, double pG);
    string randomString(double pA, double pC, double pG, double mean, double stdDev);
};
