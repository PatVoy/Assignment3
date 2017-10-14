#include "tokenizer.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

    //default constructor
    tokenizer::tokenizer()
    {
    }
    // constructor with param input stream
    tokenizer::tokenizer(std::ifstream fin)
    {
       std::string word;
       while (fin >> word)
            {
            tokenV.push_back(word);
            }
        fin.close();
        for ( vector<string>::size_type i = 0; i != tokenV.size(); ++i )
            cout << tokenV[i] << endl;

    }
