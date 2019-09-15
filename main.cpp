#include "dna.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
  //constructor
  dna dna1;

  try {
      //check for initial file added as a command line argument
      if (argc > 0)
      {
        //assign old file name, create new file sabelleoconnell.txt
        //set up for loop of adding successive files to sabelleoconnell.txt
        string fileName = argv[1];
        bool again = true;
        bool valid = true;
        char decide;
        ofstream newfile;
        newfile.open ("sabelleoconnell.txt");
        cout << "File ./sabelleoconnell.txt has been opened." << endl;

        //add data to sabelleoconnell.txt while bool again == true;
        while (again)
        {
          //access file with DNA strings
          ifstream file;
          //variables tracking statistics for data
          int numLines = 0;
          int totChar = 0;
          int totBigram = 0;
          int lineChar = 0;
          double mean = 0;
          double addVar = 0;
          double var = 0;
          double stdDev = 0;
          string line;
          file.open(fileName);
          bool readmeAdded = false;

          //create int values for the number of each dna type and bigram type
          int charA = 0;
          int charC = 0;
          int charT = 0;
          int charG = 0;

          int charAA = 0;
          int charAC = 0;
          int charAG = 0;
          int charAT = 0;

          int charCA = 0;
          int charCC = 0;
          int charCG = 0;
          int charCT = 0;

          int charGA = 0;
          int charGC = 0;
          int charGG = 0;
          int charGT = 0;

          int charTA = 0;
          int charTC = 0;
          int charTG = 0;
          int charTT = 0;

          //check whether file is open
          if (file.is_open())
          {
              cout << "File ./" << fileName << " has been opened." << endl;
              //iterate through all lines of file to accept strings of dna
              while (getline(file, line, '\n') && valid)
              {
                  //gather needed data, including number of lines and characters
                  transform(line.begin(), line.end(), line.begin(), ::tolower());
                  numLines += 1;
                  lineChar = line.length();
                  totChar += lineChar;

                  //sort characters to find number of each dna type for probability
                  char b;
                  char c;
                  char d;
                  int i = 0;
                  for (i = 0; i < line.size(); i++)
                  {
                      b = line[i];
                      switch (b)
                      {
                        case 'a':
                          charA += 1;
                          break;
                        case 'c':
                          charC += 1;
                          break;
                        case 'g':
                          charG += 1;
                          break;
                        case 't':
                          charT += 1;
                          break;
                        default:
                          //check for invalid syntax in file
                          cout << "Your file contains values other than A, C, G, and T." << endl;
                          cout << "Not a viable file format." << endl;
                          valid = false;
                      }
                  }
                  //if file isn't valid, don't run code to check the file
                  //ask for another file instead
                  while (valid)
                  {
                    //sort pairs of char to find number of each bigram type for probability
                    int j = 0;
                    int k = 0;
                    //j += 2 as we are checking pairs, not individuals
                    for (j = 0; j < line.size(); j += 2)
                    {
                        c = line[j];
                        k = j + 1;
                        d = line[k];
                        switch (c)
                        {
                          case 'a':
                            //if the first char is 'a', check the next char for which bigram type
                            switch (d)
                            {
                              case 'a':
                                charAA += 1;
                                break;
                              case 'c':
                                charAC += 1;
                                break;
                              case 'g':
                                charAG += 1;
                                break;
                              case 't':
                                charAT += 1;
                                break;
                            }
                            break;
                          case 'c':
                            switch (d)
                            {
                              case 'a':
                                charCA += 1;
                                break;
                              case 'c':
                                charCC += 1;
                                break;
                              case 'g':
                                charCG += 1;
                                break;
                              case 't':
                                charCT += 1;
                                break;
                            }
                            break;
                          case 'g':
                            switch (d)
                            {
                              case 'a':
                                charGA += 1;
                                break;
                              case 'c':
                                charGC += 1;
                                break;
                              case 'g':
                                charGG += 1;
                                break;
                              case 't':
                                charGT += 1;
                                break;
                            }
                            break;
                          case 't':
                            switch (d)
                            {
                              case 'a':
                                charTA += 1;
                                break;
                              case 'c':
                                charTC += 1;
                                break;
                              case 'g':
                                charTG += 1;
                                break;
                              case 't':
                                charTT += 1;
                                break;
                            }
                            break;
                        }
                        // add to total bigram count
                        totBigram += 1;
                    }
                // calculate mean and probabilities
                double mean = (double)totChar / (double)numLines;

                double perA = (double)charA / (double)totChar;
                double perC = (double)charC / (double)totChar;
                double perG = (double)charG / (double)totChar;
                double perT = (double)charT / (double)totChar;

                double perAA = (double)charAA / (double)totBigram;
                double perAC = (double)charAC / (double)totBigram;
                double perAG = (double)charAG / (double)totBigram;
                double perAT = (double)charAT / (double)totBigram;

                double perCA = (double)charCA / (double)totBigram;
                double perCC = (double)charCC / (double)totBigram;
                double perCG = (double)charCG / (double)totBigram;
                double perCT = (double)charCT / (double)totBigram;

                double perGA = (double)charGA / (double)totBigram;
                double perGC = (double)charGC / (double)totBigram;
                double perGG = (double)charGG / (double)totBigram;
                double perGT = (double)charGT / (double)totBigram;

                double perTA = (double)charTA / (double)totBigram;
                double perTC = (double)charTC / (double)totBigram;
                double perTG = (double)charTG / (double)totBigram;
                double perTT = (double)charTT / (double)totBigram;

                //close file, and open again to find Variance
                //unable to do this in one file opening without data structures
                file.close();
                file.open(fileName);

                if (file.is_open())
                {
                  while (getline(file, line, '\n'))
                  {
                    //find the components needed for variance, append to total
                    lineChar = line.length();
                    addVar += dna1.findVar(mean, lineChar);
                  }

                  //calculate variance and standard deviation
                  var = addVar / (double)numLines;
                  stdDev = sqrt(var);

                  //add readme to file, if file doesn't already have one
                  if (!readmeAdded)
                  {
                    newfile << "Sabelle O'Connell" << endl;
                    newfile << "2275242" << endl;
                    newfile << "CPSC 350 - 02: Data Structures Fall 2019" << endl;
                    newfile << "Programming Assignment 1: C++ Review" << endl;
                    newfile << endl;
                    readmeAdded = true;
                  }

                  //adds data to file
                  newfile << "Results from File ./" << fileName << ":" << endl;
                  newfile << "Sum of nucleotides in all DNA strings: " << totChar << endl;
                  newfile << "Mean length of DNA strings: " << mean << endl;
                  newfile << "Variance of String Length: " << var << endl;
                  newfile << "Standard Deviation of String Length: " << stdDev << endl;
                  newfile << endl;

                  newfile << "Total relative probabilities of nucleotides:" << endl;
                  newfile << "A: " << perA << endl;
                  newfile << "C: " << perC << endl;
                  newfile << "G: " << perG << endl;
                  newfile << "T: " << perT << endl;
                  newfile << endl;

                  newfile << "Total relative probabilities of nucleotide bigrams:" << endl;
                  newfile << "AA: " << perAA << endl;
                  newfile << "AC: " << perAC << endl;
                  newfile << "AG: " << perAG << endl;
                  newfile << "AT: " << perAT << endl;
                  newfile << "CA: " << perCA << endl;
                  newfile << "CC: " << perCC << endl;
                  newfile << "CG: " << perCG << endl;
                  newfile << "CT: " << perCT << endl;
                  newfile << "GA: " << perGA << endl;
                  newfile << "GC: " << perGC << endl;
                  newfile << "GG: " << perGG << endl;
                  newfile << "GT: " << perGT << endl;
                  newfile << "TA: " << perTA << endl;
                  newfile << "TC: " << perTC << endl;
                  newfile << "TG: " << perTG << endl;
                  newfile << "TT: " << perTT << endl;
                  newfile << endl;

                  //add 1000 gaussian strings of DNA constructed using probabilities
                  for (int i = 0; i < 1000; i++)
                  {
                    newfile << dna1.randomString(perA, perC, perG, mean, stdDev) << endl;
                  }
                  newfile << endl;
                  cout << "File ./sabelleoconnell.txt has been appended." << endl;
                }
                else
                {
                    cout << "Error opening " << fileName << " the second time." << endl;
                }
                //close file
                file.close();
                cout << "File ./" << fileName << " has been closed." << endl;
                //escape while loop
                valid = false;
              }
            }
          }
          else
          {
              cout << "Error opening " << fileName << "." << endl;
          }

          //ask user if they want another file appended
          cout << "Do you want to process andother list of DNA? (y/n)" << endl;
          cin >> decide;

          //check for valid inputs
          while (decide != 'y' && decide != 'n')
          {
            cout << "Do you want to process andother list of DNA? (y/n), Case sensitive." << endl;
            cin >> decide;
          }
          if (decide == 'y')
          {
            //enter while loop for valid again, accept new file
            valid = true;
            cout << "Enter name of file, full file path or file name (if in same directory) (nameHere.txt): " << endl;
            cin >> fileName;
          }
          else
          {
            //user does not want to add another file, close file
            newfile.close();
            cout << "File ./sabelleoconnell.txt has been closed." << endl;
            again = false;
          }
      }

    }
    else
    {
      cout << "You didn't add a file. Please restart this program." << endl;
    }
  }
  //catch exception
  catch (exception e)
  {
    cout << "Something went wrong. Follow the MAKEFILE instructions when running this program again." << endl;
  }
}
