/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QuerryResult.cpp
 * Author: petioptrv
 * 
 * Created on October 14, 2017, 1:06 PM
 */

#include "QueryResult.h"

QueryResult::QueryResult(const Document & d, const int & s) : doc(d), score(s) {
}

std::ostream & operator<<(std::ostream & os, const QueryResult & queryResult) {
    os << "DOC SCORE: " << queryResult.score << "\n\n";
    os << "DOC PRINTOUT\n" <<  queryResult.doc;
    
    return os;
}

