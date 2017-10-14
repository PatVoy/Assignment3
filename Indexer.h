/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Indexer.h
 * Author: petioptrv
 *
 * Created on October 14, 2017, 1:31 PM
 */

#ifndef INDEXER_H
#define INDEXER_H

#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <utility>
#include <fstream>
#include <iostream>

#include <Document.h>
#include <Tokenizer.h>
#include <QueryResult.h>

typedef std::map<std::string, std::map<std::string, float> > TwoMap;
typedef std::map<std::string, 
                 std::map<std::string, 
                          std::map<std::string, float> > > ThreeMap;

class Indexer {
public:
    Indexer();
    void printMatrix();
    void printReducedMatrix();
    const size_t size();
    const float & weight(const int & freq,
                         const int & numDoc,
                         const int & appearances);
    void normalize();
    const double & similarityScore(TwoMap tokenMap, std::string docName);
    const std::vector<QueryResult> query(std::string & query);
    const std::vector<QueryResult> query(std::string & query, int & querySize);
    friend std::istream & operator>>(std::istream * is,
                                     Indexer & i);
    friend std::ostream & operator<<(std::ostream * os,
                                     const Indexer i);
    
    friend const Document & operator[](const int x);
private:
    // this is an attribute, so should be hidden
    ThreeMap wordMap;
    std::vector<std::string> docNames; // Same story with this one
    bool normalized;
};

#endif /* INDEXER_H */

