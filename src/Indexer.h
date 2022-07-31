#ifndef INC_20F_AUTO_IDX_INDEXER_H
#define INC_20F_AUTO_IDX_INDEXER_H


#include "DSList.h"
#include "DSString.h"
#include "Keyword.h"

using namespace std;

//This class parses the input file and generates the keyword index.
class Indexer {
private:
    DSList<Keyword> index;  //list of words as part of the index

public:
    Indexer();
    void parse(char*);
    void create(char*);
    int getPage(DSString);
    void addKeyword(DSString,int);
    int addKeyIndex(DSString,int);
    void assignSubWord(int,DSString);
    void sortIndex();
    void sortIndex(int,int);
    DSString removeTrailPunct(DSString word);

    void printList();

};


#endif //INC_20F_AUTO_IDX_INDEXER_H
