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
    DSVector<int> subwords;
    DSString word;

public:
    Keyword();
    Keyword(char[]);
    Keyword(DSString);

    bool operator== (const Keyword&)const;
    bool operator> (const Keyword&)const;
    bool operator< (const Keyword&)const;

    void addPage(int);
    void addSub(int);
    bool printPages();
    void sortSub();
    void sortSub(int, int);
    void sortPages();
    void sortPages(int, int);

    DSString getWord()const;
    int getSubSize();
    int getSubAt(int);

};

#endif //INC_20F_AUTO_IDX_KEYWORD_H
