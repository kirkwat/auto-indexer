#define CATCH_CONFIG_RUNNER
#include <fstream>
#include <iostream>
#include "catch.hpp"
#include "Indexer.h"

int main(int argc, char** argv) {
    if(argc==1){
        return Catch::Session().run();
    }
    /*
    std::ofstream outputstream(argv[2]);
    outputstream << "Hello, World!" << std::endl;
    outputstream.close();
    std::cout << "Hello and wrote sample output file." << std::endl;*/
    Indexer index= Indexer();

    index.parse(argv[1]);

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