#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <fstream>
#include <istream>
#include <vector>


class tokenizer
{
    public:
        tokenizer();
        tokenizer(std::ifstream fin);


    private:
        std::vector<std::string> tokenV;

};

#endif // TOKENIZER_H
