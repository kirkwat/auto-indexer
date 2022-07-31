#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Indexer.h"

int main(int argc, char** argv) {
    //run catch test if there are no arguments
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