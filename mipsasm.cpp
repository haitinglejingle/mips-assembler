// mipsasm.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "mipsasm.h"

using namespace std;

MipsAssembler::MipsAssembler()
{
}

MipsAssembler::~MipsAssembler()
{
}

void MipsAssembler::FirstPass()
{
    int wordAddress = 0; 
    string line;
    while (getline(cin, line)) {
        CheckLabel(line, wordAddress); 
        wordAddress++;
    }
}

void MipsAssembler::FirstPass(string filename)
{
    int wordAddress = 0;
    string line;
    ifstream file(filename);
    if (file) {
        while (getline(file, line)) {
            CheckLabel(line, wordAddress); 
            wordAddress++;
        }
    }
}

void MipsAssembler::CheckLabel(string line, int addr)
{
    string label;
    istringstream iss(line);
    prog.push_back(line);
    iss >> label;
    if (label.back() == ':') {
        label.pop_back();
        labelmap[label] = addr;
    }
}

void MipsAssembler::SecondPass()
{
    int len = prog.size();
    string opcode, one, two, three, offset;
    for (int i = 0; i < len; ++i) { // i is the word address
        opcode = ""; one = ""; two = ""; three = ""; offset = "";
        GetWords(i, opcode, one, two, three, offset);
//      you can print the strings here to see them
//        cout << "opcode: " << opcode << endl
//             << "one: " << one << endl
//             << "two: " << two << endl
//             << "three: " << three << endl
//             << "offset: " << offset << endl;
    }
}

// pass EMPTY strings to this - this function does not always clear old values
void MipsAssembler::GetWords(int wordAddress, string& opcode, 
        string& one, string& two, string& three, string& offset)
{
    string word, line;
    line = prog[wordAddress];
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
    //cout << "one is this " << one << endl;
    if (!iss.eof()) iss >> two;
    else two = "";
    if (!iss.eof()) iss >> three;
    else three = "";

    EnsureLowercase(opcode, one, two, three, offset);
    // clean up
    if (two != "") {
        one.pop_back();  // get rid of comma
        if (three == "" && two.back() == ')') { // handle loads/stores
            string junk;
            size_t found = two.find_first_of("xX"); 
            istringstream iss2(two);
            if (found != string::npos) {
                two[found] = 'x';
                getline(iss2, junk, 'x');
            }
                getline(iss2, offset, '(');
                getline(iss2, two, ')');
        }
    }
    if (three != "") two.pop_back();  // get rid of comma
}

void MipsAssembler::EnsureLowercase(string& opcode, string& one, string& two, 
        string& three, string& offset)
{
    transform(opcode.begin(), opcode.end(), opcode.begin(), ::tolower);
    transform(one.begin(), one.end(), one.begin(), ::tolower);
    transform(two.begin(), two.end(), two.begin(), ::tolower);
    transform(three.begin(), three.end(), three.begin(), ::tolower);
}
