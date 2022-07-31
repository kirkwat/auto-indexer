#ifndef INC_20F_AUTO_IDX_KEYWORD_H
#define INC_20F_AUTO_IDX_KEYWORD_H


#include "DSVector.h"
#include "DSString.h"

//This class contains characteristics of a keyword in the index.
class Keyword {
private:
    DSVector<int> pageNumbers;      //pages containing the keyword
    DSVector<DSString> subwords;    //words that are under a master keyword category
    DSString word;                  //string of keyword
    int isSorted;                   //tracks if words are sorted

public:
    Keyword();
    Keyword(char[]);
    Keyword(DSString);

    bool operator== (const Keyword&)const;
    bool operator> (const Keyword&)const;
    bool operator< (const Keyword&)const;

    void addPage(int);
    void addSub(DSString);
    bool printKeyword(ofstream &fout);
    void sort();
    void sortPages(int, int);
    void sortSub(int, int);

    DSString getWord()const;
    int getSubSize();
    DSString getSubAt(int);

};

#endif //INC_20F_AUTO_IDX_KEYWORD_H
