/* two pass assembler
 *
 * 
 */ 
#include <iostream>
#include <string>
#include <vector>
#include "mipsasm.h"

using namespace std;

int main (int argc, char*argv[]) 
{
    MipsAssembler MAss;
    if (argc == 1) { // read from stdin
        MAss.FirstPass();
    } else if (argc == 2) {
        MAss.FirstPass(string(argv[1]));
    }
    MAss.SecondPass();

    return EXIT_SUCCESS;
}

