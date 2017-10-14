//
//  QueryResult.cpp
//  
//
//  Created by Petio Petrov on 2017-10-13.
//

#include "QueryResult.h"

QueryResult::QueryResult(document d, int s) : doc(d), score(s) {}

std::ostream & operator<< (std::ostream & os, const QueryResult & queryResult) {
    std::ostringstream buffer;
    buffer << doc.name() << "\n" << score;
}
