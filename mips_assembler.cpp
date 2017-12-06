/* 
 *  mips_assembler.cpp
 * 
 *  Purpose: Assembler for MIPS Assembly code
 *  By: Michelle Chan & Ashton Stephens
 *  Date: 12/5/17
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "instructions.h"

void R_type_test();

int main (int argc, char*argv[]) 
{
    (void) argc; 
    (void) argv; 
    R_type_test();
}


void R_type_test()
{
    struct R_Type test;
    *((int*)&test)=0;
    test.Op     = 0b000010;
    for(int i = 0; i < 4; fputc(((char*)&test)[i++],stdout));

}


