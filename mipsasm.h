// mipsasm.h
#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "mipsasm.h"
#include "map/MIPS_instruction.h"

class MipsAssembler
{
    public:
        MipsAssembler();
        ~MipsAssembler();
        void FirstPass();
        void FirstPass(std::string filename);
        void SecondPass();

    private:
        MIPS_instruction mi;
        std::vector<std::string> prog;
        int CheckFirstWord(std::string filename, int addr);

        std::map<std::string, uint32_t> labelmap;
        std::map<std::string, int> pseudomap;

        void GetWords(uint32_t wAddr, std::string& opcode, 
                std::string& one, std::string& two, std::string& three);
        void HandlePseudo(uint32_t wAddr, std::string& opcode, std::string& one,
                std::string& two, std::string& three);
        void InitializePseudoMap();

        bool IsAsmLine(std::istringstream& line);
};
