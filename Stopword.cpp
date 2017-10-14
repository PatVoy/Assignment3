#include "stopword.h"
#include <iostream>
#include <fstream>
#include <list>

using namespace std;
    //std::list<std::string> lStopwords;

    //default constructor creates anobject with an empty stopword list
    stopword::stopword()
    {
    }
    //reads the stopword list from this file
    stopword::stopword(string fileName)
    {
        ifstream fin(fileName.c_str());
       string word;
       while (fin >> word)
        {
        listStopwords.push_back(word);
        }
        fin.close();

    }
