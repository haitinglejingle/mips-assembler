// mipsasm.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "mipsasm.h"
#include "map/MIPS_instruction.h"

using namespace std;

MipsAssembler::MipsAssembler()
{
}

MipsAssembler::~MipsAssembler()
{
}

/*--------*\
 * PUBLIC *
\*--------*/

void MipsAssembler::FirstPass()
{
    uint32_t wAddr = 0;
    string line;
    uint32_t instCount;
    while (getline(cin, line)) {
        instCount = CheckFirstWord(line, wAddr); 
        for (uint32_t i = 0; i < instCount; ++i) wAddr++;
    }
}

void MipsAssembler::FirstPass(string filename)
{
    uint32_t wAddr = 0;
    string line;
    uint32_t instCount;
    ifstream file(filename);
    if (file) {
        while (getline(file, line)) {
            instCount = CheckFirstWord(line, wAddr); 
            for (uint32_t i = 0; i < instCount; ++i) wAddr++;
        }
    }
    file.close();
}

void MipsAssembler::SecondPass()
{
    uint32_t len = prog.size();
    uint32_t wAddr = 0;
    string opcode, one, two, three;
    for (uint32_t i = 0; i < len; ++i) { // i is the word address
        opcode = ""; one = ""; two = ""; three = "";
        GetWords(i, opcode, one, two, three);
//      you can print the strings here to see them
//        cout << "opcode: " << opcode << " "
//             << "one: " << one << endl 
//             << "two: " << two  << endl 
//             << "three: " << three << endl;

        wAddr+=mi.assemble(wAddr, opcode, one, two, three);
    }
}

/*---------*\
 * PRIVATE *
\*---------*/

// handle labels, check for pseudocode
// returns the number of word addresses to increment
int MipsAssembler::CheckFirstWord(string line, int addr)
{
    int instCount = 0;
    string label;
    istringstream iss(line);
    if (IsAsmLine(iss)) {  // return if line does not contain asm
        instCount++;
        prog.push_back(line); 
        iss >> label;
        if (label.back() == ':') {
            label.pop_back();
            mi.add_label(label, addr);
        }
    }
    return instCount;
}

// returns that the line is neither EMPTY nor begins with a comment
bool MipsAssembler::IsAsmLine(istringstream &line) {
    line >> ws; // eat up leading white space
    return !(line.eof() || line.peek() == '#');
}

// pass EMPTY strings to this - this function does not always clear old values
void MipsAssembler::GetWords(uint32_t wAddr, string& opcode, 
        string& one, string& two, string& three)
{
    string word, line;
    line = prog[wAddr];
    istringstream iss(line);
    getline(iss, line, '#');
    iss.str(line);
    iss.clear();
    iss >> opcode; // get first word
    if (opcode.back() == ':') { // skip labels
        iss >> opcode;
    }
    // get the strings
    if (!iss.eof()) iss >> one;
    else one = "";
    if (!iss.eof()) iss >> two;
    else two = "";
    if (!iss.eof()) iss >> three;
    else three = "";

    // clean up
    if (two != "") {
        one.pop_back();  // get rid of comma
        if (three == "" && two.back() == ')') { // handle loads/stores
            string temp;
            istringstream iss2(two);
            getline(iss2, temp, '(');
            two = temp;
            getline(iss2, three, ')');
        } else if (three != "") {
            two.pop_back();
        }
    } 
}
