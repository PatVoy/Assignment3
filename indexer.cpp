#include "indexer.h"
#include "document.h"
#include "tokenizer.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <map>
#include <utility>

 // constructor
Indexer::Indexer()
{
  Indexer::numDoc = 0;
  Indexer::normalized = false;
}

int Indexer::size()
{
   return numDoc;
}

 void Indexer::addDoc()
{
   numDoc++;
}

void Indexer::setNormalized(bool ans)
{
    normalized = ans;
}
//adding a document into the index
Indexer & operator>>(document& doc, Indexer& indx)
{
    indx.setNormalized(false);
    indx.doc_names.push_back(doc.name());
    std::map < std::string, std::map < document, std::pair < int, double > > > :: iterator wordCheck;
    std::string words[] = {"a", "b", "c", "a", "b", "d"};
    for(int i = 0; i < 6; i++){
        if(indx.wordMap.empty())
            indx.wordMap[words[i]].insert({doc, {1, 0}});
        else
        {
            if(indx.wordMap.count(words[i]) == 0)
                indx.wordMap[words[i]].insert({doc, {1, 0}});
            else
                indx.wordMap[words[i]][doc].first += 1;
        }
    }

}

void Indexer::normalize(){}
void Indexer::printMatrix(){}
// just playing around
int main()
{

    Indexer indx = Indexer();
    std::cout << indx.size() << std::endl;
    indx.addDoc();
    std::cout << indx.size() << std::endl;
    document doc = document();

    return 0;
}
