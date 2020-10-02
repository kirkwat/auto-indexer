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

//for reading files
//TODO: ignore trailing punctuation
//TODO: ignore case

//for creating index
//TODO: sort page numbers
//TODO: sort keywords alphabetically, use ascii
//TODO: print to file, 50 char per line