#include "document.h"
#include <iostream>
#include <fstream>

using namespace std;

    const string delimiters = " ,?.\\\'\"1234567890::<>/|}{][()*&^%$#@!~\n";
    string nameOfFile;
    size_t maxWordLen = 0;

    // default constructor
    document::document()
    {
    }
    // constructor accepts a file name and reads content into document object
    document::document(string fileName)
    {
       ifstream fin(fileName.c_str());
       nameOfFile = fileName;
       // if we had a vector
       /*string word;
       while (fin >> word)
        {
        contentV.push_back(word);
        }
        fin.close();*/
        string line;
        while (getline(fin, line)) {
            size_t currPos = 0;
           // size_t newPos; // not used
            string nextWord = "";
            // Extract each word character by character
            for (string::iterator character = line.begin();
                    character != line.end();
                    ++character) {
                if (delimiters.find_first_of(*character, currPos) ==
                        string::npos) {
                    nextWord += tolower(*character);
                } else {
                    if (nextWord != "") {
                        ++wordMap[nextWord][fileName];
                        maxWordLen = maxWordLen > nextWord.size() ?
                            maxWordLen: nextWord.size();
                        nextWord = "";
                    }
                }

            }
            if (nextWord != "") {
                    ++wordMap[nextWord][fileName];
                    maxWordLen = maxWordLen > nextWord.size() ?
                        maxWordLen: nextWord.size();
                    nextWord = "";
            }

        }
    }
    // returns the file name of the document
    string document::name()
    {
        cout << "Trying name function:" << endl;
        return "Name of file is: " + nameOfFile;
    }
    //size in characters
    int document::size()
    {
        cout << "Trying size function:" << endl;
            ifstream fin(nameOfFile.c_str());
            string line;
            int c=0;

            if (fin.is_open())
            {
                 while(getline (fin, line)){
                        c += line.length();
                }
            }
                fin.close();
                cout << "Size of file in characters is: ";
                return c;
    }
    //returns the text of the document
    void document::content()
    {
        cout << "Trying content function:" << endl;
        // if we had a vector
        /*for ( vector<string>::size_type i = 0; i != contentV.size(); ++i )
            cout << contentV[i] << endl;
            //cout << endl;*/
        for (map< string, map<string,int> >::iterator word = wordMap.begin();
         word != wordMap.end();
         ++word)
        cout  << left << word->first<<endl;
    }
