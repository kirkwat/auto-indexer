//
// Created by watso on 10/1/2020.
//

#ifndef INC_20F_AUTO_IDX_INDEXER_H
#define INC_20F_AUTO_IDX_INDEXER_H


#include "DSList.h"
#include "DSString.h"
#include "Keyword.h"

using namespace std;

class Indexer {
private:
    DSList<Keyword> index;

public:
    Indexer();
    void parse(char*);
    void create(char*);
    int getPage(DSString);
    void addKeyword(DSString,int);
    int addKeyIndex(DSString,int);
    void assignSubWord(int,int);

    void printList();

};


#endif //INC_20F_AUTO_IDX_INDEXER_H
