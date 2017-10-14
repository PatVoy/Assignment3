#ifndef STOPWORDS_H
#define STOPWORDS_H
#include <string>
#include <vector>
#include <list>

class stopwords
{
    public:
        stopwords();
        stopwords(std::string fileName);
        friend std::ostream &operator<< (std::ostream & os,const stopword & st);
        bool operator() (const std::string & token) // returns if a token is found in stopword list
        {
         for (std::list<std::string>:: const_iterator i = listStopwords.begin(); i != listStopwords.end(); ++i)
         if (token == *i) return true;
         return false;
        }

    private:
        std::string fileName;
        std::string token;
        std::list<std::string> listStopwords;

};

#endif // STOPWORD_H

