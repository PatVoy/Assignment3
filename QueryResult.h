//
//  QueryResult.hpp
//  
//
//  Created by Petio Petrov on 2017-10-13.
//

#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <document.h>

class QueryResult
{
public:
    QueryResult(document & d, int & s);
    friend std::ostream & operator<< (std:ostream & os,
                                      const QueryResult & queryResult);

private:
    document doc;
    int score;
}

#endif /* QueryResult_hpp */
