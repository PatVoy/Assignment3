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

class Indexer {
public:
    Indexer();
    void printMatrix();
    void printReducedMatrix();
    void add(const Document & doc);
    const size_t size();
    void normalize();
    const std::vector<QueryResult> query(std::string & query);
    const std::vector<QueryResult> query(std::string & query, int & querySize);
    friend std::ostream & operator<<(std::ostream * os,
                                     const Indexer i);
private:
    // this is an attribute, so should be hidden
    std::map<std::string, std::map<Document, std::map<std::string, float> > > wordMap;
    std::vector<std::string> docNames; // Same story with this one
    bool normalized;
};

#endif /* INDEXER_H */

