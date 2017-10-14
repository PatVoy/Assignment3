#include "document.h"
#include <iostream>
#include <fstream>

using namespace std;

    // default constructor
    document::document()
    {
    }
    // constructor accepts a file name and reads content into document object
    document::document(string fileName)
    {
        ifstream fin(fileName.c_str());
        nameOfFile = fileName;
        string line;

        while (fin >> line) {
            contentOfFile += line;
            contentOfFile += " ";
        }
        fin.close();
    }
    // returns the file name of the document
    string document::name()
    {
        return nameOfFile;
    }
    //size in characters
    int document::size()
    {
            ifstream fin(nameOfFile.c_str());
            string line;
            sizeOfFile=0;

            if (fin.is_open())
            {
                 while(getline (fin, line)){
                        sizeOfFile += line.length();
                }
            }
                fin.close();

                return sizeOfFile;
    }
    // returns the text of the document
   string document::content()
    {
        return contentOfFile;
    }
    // overload operator<< returns name, size, and content of doc
    ostream &operator<< (std::ostream & os,const document & doc)
        {
          return os << "Name: " << doc.nameOfFile << endl <<
          "Size: " << doc.sizeOfFile << endl << "Content: " << doc.contentOfFile << endl;
        }


