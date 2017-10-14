//Assignment 2 Comp 345 Try
#include "document.h"
#include "stopword.h"
#include "tokenizer.h"
#include "indexer.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){

    document d; // trying default document obj
    cout<<"With default constructor:"<<endl;
    //d.name();
    //d.size();
    //cout<<endl;
    //d.content();

    document d1("try.txt"); //trying document obj with filename
    cout << endl;
    cout<<"With constructor:"<<endl;
    d1.content();
    cout << d1.size() << endl;
    cout << d1.name() << endl;

    cout << endl;
    indexer indx("index.txt");

    stopword s("stopwordstry.txt"); // trying stopword list with filename
    //std::ifstream fin("try.txt");
    //tokenizer t(fin);

    return 0;
}
