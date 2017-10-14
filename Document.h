#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <string>
#include <vector>
#include <map>

class Document
{
    public:
        document();
        document(std::string fileName);
        std::string name();
        int size();
        void content();

    private:
        std::string fileName;
        std::vector<std::string> contentV;
        std::map< std::string, std::map<std::string,int> > wordMap;
        std::map<std::string,int> fullWordTotals;
        size_t maxWordLen;

};

#endif // DOCUMENT_H
