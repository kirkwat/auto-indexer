#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Indexer.h"

int main(int argc, char** argv) {
    if(argc==1){
        return Catch::Session().run();
    }
    //create index object
    Indexer index= Indexer();
    //read file
    index.parse(argv[1]);
    //create index
    index.create(argv[2]);

    return 0;
}
//for creating index
//TODO: print to file, 50 char per line
//TODO: make code look nice and comment
//TODO: email fontenot about project 1 and 2