
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
    
    uint32_t assemble (uint32_t pc, std::string op, 
      std::string a, std::string b, std::string c);
    
private:

    enum   MnemType    {Rtype, Itype, Jtype};
    enum   SyntaxGroup {g1, g2, g3, g4, g5, g6};
    struct Mnemonic_func;
    struct Mnemonic_func_te;
    struct Register_te;

    void initialize_tables (); 
    
    uint32_t assemble_rtype(uint32_t op, std::string a,
                 std::string b, std::string c, SyntaxGroup g);
    uint32_t assemble_itype(uint32_t op, std::string a,
                 std::string b, std::string c, SyntaxGroup g, uint32_t pc);
    uint32_t assemble_jtype(uint32_t op, std::string a,
                 std::string b, std::string c, SyntaxGroup g);

    void   initialize_Mnemonic_map (const Mnemonic_func_te *ops);
    void   initialize_Register_map (const Register_te *reg);

    std::map <std::string, Mnemonic_func> mnemonic_map;
    std::map <std::string, uint32_t> register_map;

    uint32_t regval(std::string reg);
    
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

