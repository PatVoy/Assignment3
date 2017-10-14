#include "Indexer.h"  // This should be the only import in here

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

void Indexer::printMatrix() {}

void Indexer::printMatrixReduced() {}

void Indexer::normalize()
{
    normalized = ans;  // Flag matrix as normalized
}

void Indexer::setNormalized(bool ans)
{
}
//adding a document into the index
void add(document::)
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
    
    numDoc++;  // Increment doc counter
}
