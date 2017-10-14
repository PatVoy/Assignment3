#ifndef STOPWORD_H
#define STOPWORD_H
#include <string>
#include <vector>
#include <list>

class stopword
{
    public:
        stopword();
        stopword(std::string fileName);
        //bool operator();
        //overload operator() to return true if the token is in the object’s list, otherwise false

    private:
        std::string fileName;
        std::vector<std::string> contentStopwords;
        std::list<std::string> listStopwords;

};

#endif // STOPWORD_H
