#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <string>
#include <vector>
#include <map>

class document
{
    public:
        document();
        document(std::string fileName);
        std::string name();
        int size();
        std::string content();
        friend std::ostream &operator<< (std::ostream & os,const document & doc);

    private:
        std::string nameOfFile;
        std::string contentOfFile;
        int sizeOfFile;

};

#endif // DOCUMENT_H

