#define CATCH_CONFIG_RUNNER
#include <fstream>
#include <iostream>
#include "catch.hpp"

int main(int argc, char** argv) {
   // if(argc==1){
        return Catch::Session().run();
   // }
    std::ofstream outputstream(argv[2]);
    outputstream << "Hello, World!" << std::endl;
    outputstream.close();
    std::cout << "Hello and wrote sample output file." << std::endl;
    return 0;
}
