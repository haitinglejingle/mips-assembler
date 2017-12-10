
#include <bitset>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "MIPS_instruction.h"
#define DBG std::cout <<  __func__ \
                      << "[" << __LINE__ << "]\n"
using namespace std;
void test0 ();
void test1 ();
void test2 ();
void test3 ();
void test4 (int a1, int a2);

int main (int b, char ** a) 
{
    int    arg1, arg2;
    for (int i = 0; i < b; ++i) {
        if (strcmp(a[i],"-t0")==0) {
            test0();
        } else if (strcmp(a[i],"-t1")==0) {
            test1();
        } else if (strcmp(a[i],"-t2")==0) {
            test2();
        } else if (strcmp(a[i],"-t3")==0) {
            test3();
        } else if (strcmp(a[i],"-t4")==0) {
            sscanf(a[++i],"%d",&arg1);
            sscanf(a[++i],"%d",&arg2);
            test4(arg1, arg2);
        }
    }
}

void test0 ()
{DBG;
    MIPS_instruction mi;
    cout << std::bitset<32>(mi.assemble(0,"jal","10","0","")) << endl; 
    return;
}

void test1 ()
{DBG;
    MIPS_instruction mi;
    string a, b[5];
    int i  = 0;
    int pc = 0;

    while (true) { 
        cin >> a;
        if (a == "-p") {
            cin >> a;
            pc = stoi(a);
        } else if (a == "-r") {
            cout << std::bitset<32>
                (mi.assemble(pc,b[0],b[1],b[2],b[3])) << endl;
            i = 0;
        } else {
            b[i++] = a;
        } 
    }

    return;
}

void test2 ()
{DBG;
    return;
}

void test3 ()
{DBG;
    return;
}

void test4 (int a1, int a2)
{DBG; 
    (void) a1; (void) a2;
       
    return;
}

