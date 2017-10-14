/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Indexer.cpp
 * Author: petioptrv
 * 
 * Created on October 14, 2017, 1:31 PM
 */

#include "Indexer.h"

Indexer::Indexer() {
    normalized = false;
}

const size_t Indexer::size() {
    return docNames.size();
}

void Indexer::printMatrix() {

}

void Indexer::printReducedMatrix() {

}

void Indexer::normalize() {
    
    
    normalized = true;  // We can flag the object as normalized in here
}

// I thought about it and I don't think we can overload >> operator 
// because it would have to return an istream (you can only overload if 
// the return type and arguments are the same)
// which does not fit with the functionality of this method, so
// an add function might serve us better here.
void Indexer::add(const Document & doc) {
    // We've added a document, so the object is no longer normalized
    normalized = false;
    // The reason the value is saved to a local variable is because this 
    // prevents us from having to make a method call (i.e. doc.name()) 
    // every time we need the name of the document, which is needed on each 
    // iteration while adding words to the database below – method calls are
    // costly, so this is just a faster way to do it
    std::string docName = doc.name();
    docNames.push_back(docName);
    
    // Extract words from doc content
    Tokenizer tokenizer();  // Create tokenizer object
    // Feed the content of the doc to the tokenizer overloaded braket operator
    // to get a vector of words in return
    std::vector<std::string> tokens = tokenizer(doc.content());
    
    // Travers the vector of tokens and add it to the data structure
    for (std::vector<std::string>::const_iterator token = tokens.begin();
         token != tokens.end();
         ++token) {
        wordMap[*token][docName]["frequency"]++;
    }
}

const std::vector<QueryResult> query(std::string & query) {
    
}

const std::vector<QueryResult> query(std::string & query, int & querySize) {
    
}

std::ostream & operator<<(std::ostream * os, const Indexer i) {
    // Print the normalized boolean
    os << "Normalized: " << i.normalized << "\n";
    
    // Iterate through every word
    for (std::map<std::string, std::map<std::string, 
            std::map<std::string, float> > >::const_iterator 
            word = i.wordMap.begin();                           // THIS LOOKS HORRIBLE!!!!
         word != i.wordMap.end();
         ++word) {
        
        os << word->first << "\n";  // Print out the word
        // Iterate over every document
        for (std::vector<std::string>::const_iterator 
                docName = i.docNames.begin();
             docName != i.docNames.end();
             ++docName) {
            
            os << "    " << *docName << "\n";  // Print out the doc name
            // Iterate over the different metrics for that word within that document
            for (std::map<word, float>::const_iterator 
                    metric = word->second[docName].begin();
                 metric != word->second[docName].end();
                 ++metric) {
                
                // Print out the metric string and the value associated with it
                os << "        ";  // Indent output
                os << metric->first << ": " << metric->second << "\n";
            }
        }
    }
    
    return os;
}

