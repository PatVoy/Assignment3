#ifndef INDEXER_H
#define INDEXER_H

#include <string>
#include <vector>
#include <map>
#include <utility>
#include "Document.h"
#include "tokenizer.h"

class Indexer
{
public:
    Indexer();
    int size();
    void printMatrix();
    void printRedicedMatrix();
    void normalize();
    void add(document::document & doc);
private:                   // begin private section
    std::map < std::string, std::map < document, std::map <std::string, double > > > wordMap;  // This is an attribute, so should be hidden
    std::vector<std::string> doc_names;  // Same story with this one
    bool normalized;
};

#endif // INDEXER_H
