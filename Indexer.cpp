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

typedef std::map<std::string, float> OneMap;
typedef std::map<std::string, std::map<std::string, float> > TwoMap;
typedef std::map<std::string, 
                 std::map<std::string, 
                          std::map<std::string, float> > > ThreeMap;

Indexer::Indexer() {
    normalized = false;
}

const size_t Indexer::size() {
    return docNames.size();
}

void Indexer::printMatrix() {
  int maxWordLen=0;
    int maxFileNameLen=0;

    for (ThreeMap::iterator
            word = this.wordMap.begin();                           // THIS LOOKS HORRIBLE!!!!
         word != this.wordMap.end();
         ++word)
    {
            if(word->first.length() > maxWordLen)
                maxWordLen = word->first.length();
    }

    for (int i = 0; i < docNames.size(); i++)
    {
        if(docNames[i].name().length() > maxFileNameLen)
            maxFileNameLen = docNames[i].name().length();
    }



    // Keeps track of the totals for the full matrix
    map<string,int> fullWordTotals;

    int indexColumnLength = 1 + 1 + maxWordLen + 1;
    int dataColumnLength = 1 + 1 + maxFileNameLen + 1;
    int separationLineLength = indexColumnLength +
                               (dataColumnLength * docNames.size()) + 1;
    string separationLine(separationLineLength, '-');
    string leftBorder = "| ";
    string rightBorder = " |";
    string midBorder = " | ";

    // MATRIX HEADER

    cout << "FULL MATRIX" << endl;
    cout << separationLine << endl;
    cout << leftBorder << setw(maxWordLen) << left << "Dictionary";
    // Print out the file names
    for (vector<Document>::iterator fileName = docNames.begin();
            fileName != docNames.end();
            ++fileName) {
        cout << setw(3) << midBorder
                << setw(maxFileNameLen) << left << *fileName.name();
    }
    cout << rightBorder << "\n" << separationLine << endl;

    // MATRIX BODY

    // Print each row
    for (ThreeMap::iterator word = wordMap.begin();
         word != wordMap.end();
         ++word) {
        cout << leftBorder << setw(maxWordLen) << left << word->first;

        // Print each column for that row
        for (vector<Document>::iterator fileName = docNames.begin();
                fileName != docNames.end();
                ++fileName) {
            cout << setw(3) << midBorder
                    << setw(maxFileNameLen) << right
                    << word->second->second["frequency"] << " | " << word->second->second["weight"];
            fullWordTotals[*fileName.name()] += word->second->second->["frequency"];
        }
        cout << setw(2) << rightBorder << endl;  // Close last column
    }
    cout << separationLine << "\n" << setw(2) << leftBorder
            << setw(maxWordLen) << left << "Total";
    for (map<string,int>::iterator fileName = fullWordTotals.begin();
            fileName != fullWordTotals.end();
            ++fileName) {
        cout << setw(3) << midBorder << setw(maxFileNameLen) << right
                << fileName->second;
    }
    cout << setw(2) << rightBorder << "\n" << separationLine << "\n\n" << endl;
}

void Indexer::printReducedMatrix() {

}

float weight(int freq, int numDoc, int appearances)
{
    return roundf((1 + log(freq))*log(numDoc/appearances)* 100) / 100;
}

void Indexer::normalize() {
    int numDoc = this.size();
    int freq = 0;
    int appearances = 0;
    //traverses the map to get all the numbers needed for the weight calculation
    for (ThreeMap::const_iterator word = this.wordMap.begin();
         word != this.wordMap.end();
         ++word)
    {
        appearances = word->second.size();
        //traverses inner map to get the frequency of each word/document
        for(TwoMap::const_iterator iter = word->second.begin(); iter != word->second.end(); ++iter){
                freq = this.wordMap[word][iter]["frequency"];

                float weight = weight(freq, numDoc, appearances);
                this.wordMap[word][iter]["weight"] = weight;
            }

    }
    normalized = true;
}

const double & Indexer::similarityScore(TwoMap tokenMap,
                              std::string docName) {
    // Make sure the passed map is of same length as the word map
    assert (tokenMap.size() == wordMap.size() && 
            "The two maps are not of equal size");
    
    // Calculate the score
    double num = 0;
    double denomLeft = 0;
    double denomRight = 0;
    for (TwoMap::const_iterator token = tokenMap.begin();
            token != tokenMap.end();
            ++token) {
        float tokenWeight = token->second["weight"];
        float wordWeight = wordMap[token->first][docName]["weight"];
        num += tokenWeight * wordWeight;
        denomLeft += pow(tokenWeight, 2);
        denomRight += pow(wordWeight, 2);
    }
    
    return num/(sqrt(denomLeft) * sqrt(denomRight));
}

const std::vector<QueryResult> query(std::string & query) {

}

const std::vector<QueryResult> query(std::string & query, int & querySize) {

}

std::istream & operator>>(std::istream * is, Indexer i) {
    std::string docName;
    is >> docName;
    
    Document doc(docName);
    i.docVector.push_back(doc);
    
    // Extract words from doc content
    Tokenizer tokenizer();  // Create tokenizer object
    // Feed the content of the doc to the tokenizer overloaded bracket operator
    // to get a vector of words in return
    std::vector<std::string> tokens = tokenizer(doc.content());
    
    // Traverse the vector of tokens and add it to the data structure
    for (std::vector<std::string>::const_iterator token = tokens.begin();
         token != tokens.end();
         ++token) {
        i.wordMap[*token][docName]["frequency"]++;
    }
}

std::ostream & operator<<(std::ostream * os, const Indexer i) {
    // Print the normalized boolean
    os << "Normalized: " << i.normalized << "\n";

    // Iterate through every word
    for (std::map<std::string, std::map<Document,
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
