// mipsasm.h
#pragma once
#include <string>
#include <vector>
#include <map>
#include "mipsasm.h"

class MipsAssembler
{
    public:
        MipsAssembler();
        ~MipsAssembler();
        void FirstPass();
        void FirstPass(std::string filename);
        void SecondPass();
    private:
        static const int INIT_PROGSZE = 10;
        std::vector<std::string> prog;
        void CheckLabel(std::string filename, int addr);
        std::map<std::string, int> labelmap;

        void GetWords(int wordAddress, std::string& opcode, std::string& one, 
                std::string& two, std::string& three, std::string& offset);
        void EnsureLowercase(std::string& opcode, std::string& one, 
                std::string& two, std::string& three, std::string& offset);
};
