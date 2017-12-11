#pragma once
#include <vector>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <map>

class MIPS_instruction
{
public:
    
    MIPS_instruction();
    ~MIPS_instruction();
    
    void     add_label (std::string label, uint32_t iAddr);
    uint32_t assemble (uint32_t pc, std::string op, 
      std::string a, std::string b, std::string c);
    
private:

    enum   MnemType    {Rtype, Itype, Jtype};
    enum   SyntaxGroup {g1, g2, g3, g4, g5, g6};
    struct Mnemonic_func;
    struct Mnemonic_func_te;
    struct Register_te;
    struct Pseudo_te;
    struct PseudoInst;

    void initialize_tables (); 
    
    uint32_t assemble_rtype(uint32_t op, std::string a,
                 std::string b, std::string c, SyntaxGroup g);
    uint32_t assemble_itype(uint32_t op, std::string a,
                 std::string b, std::string c, SyntaxGroup g, uint32_t pc);
    uint32_t assemble_jtype(uint32_t op, std::string a,
                 std::string b, std::string c, SyntaxGroup g);

    void   initialize_Mnemonic_map (const Mnemonic_func_te *ops);
    void   initialize_Register_map (const Register_te *reg);
    void   initalize_Pseudo_map(const Pseudo_te *psi);

    std::map <std::string, Mnemonic_func> mnemonic_map;
    std::map <std::string, uint32_t> register_map;
    std::map <std::string, uint32_t> label_map;
    std::map <std::string, PseudoInst> pseudo_map;
    
    uint32_t regval(std::string reg);
    uint32_t getval(std::string reg);
    

    uint32_t pseudo(PseudoInst pi_type, std::string a_, std::string b_, 
            std::string c_, uint32_t pc);

    std::string getPseudoOperand(std::string x, std::string a, std::string b, 
            std::string c); 

    uint32_t assemble_iformat(Mnemonic_func mop, std::string a, std::string b, 
            std::string c, uint32_t pc);

    std::vector<std::string> getStringVect(std::string strArr[], int len);

    void printMachineCode(uint32_t bin); // 
    void printMachineCode(uint32_t bin, uint32_t pc); // for testing 

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *  Internal Data                                        * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 

    struct Mnemonic_func {
        uint32_t    op;
        MnemType    type;
        SyntaxGroup g;
    };

    struct Mnemonic_func_te {
        std::string   key;
        Mnemonic_func val;
    };
    
    struct Register_te {
        std::string   key;
        uint32_t      val;
    };

    struct PseudoInst {
        std::vector<std::string> op;
        std::vector<std::string> a;
        std::vector<std::string> b;
        std::vector<std::string> c;
    };

    struct Pseudo_te {
        std::string   key;
        PseudoInst    val;
    };

    struct Rtype_instruction 
    {
        unsigned f  : 6;
        unsigned a  : 5;
        unsigned Rd : 5;
        unsigned Rt : 5;
        unsigned Rs : 5;
        unsigned op : 6;
    };

    struct Itype_instruction 
    {
        unsigned i  :16;
        unsigned Rt : 5;
        unsigned Rs : 5;
        unsigned op : 6;
    };

    struct Jtype_instruction 
    {
        unsigned i  :26;
        unsigned op : 6;
    };

};

