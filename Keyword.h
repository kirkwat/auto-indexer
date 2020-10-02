//
// Created by watso on 10/1/2020.
//

#ifndef INC_20F_AUTO_IDX_KEYWORD_H
#define INC_20F_AUTO_IDX_KEYWORD_H


#include "DSVector.h"
#include "DSString.h"

class Keyword {
private:
    DSVector<int> pageNumbers;
    DSVector<DSString> subwords;
    DSString word;
    int isSorted;

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
    void sortPages();
    void sortPages(int, int);

    DSString getWord()const;
    int getSubSize();
    DSString getSubAt(int);

};

#endif //INC_20F_AUTO_IDX_KEYWORD_H
