#ifndef INDEXER_H
#define INDEXER_H
#include <string>
#include <vector>
#include <map>
#include "document.h"
#include "tokenizer.h"
#include <utility>

class Indexer
{
    friend Indexer & operator>>(document&, Indexer&);
    public:
        Indexer();
        int size();
        void addDoc();
        void printMatrix();
        void normalize();
        void setNormalized(bool ans);
        std::vector<std::string> doc_names;
        std::map < std::string, std::map < document, std::pair < int, double > > > wordMap;
    private:                   // begin private section
        int numDoc;
        bool normalized;
};

#endif // INDEXER_H
