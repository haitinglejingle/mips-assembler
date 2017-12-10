/* 
 * MIPS_instruction.cpp
 */

#include <vector>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>

#include <iostream>

#include "MIPS_instruction.h"

MIPS_instruction:: MIPS_instruction()
{
    initialize_tables();
    return;
}

MIPS_instruction::~MIPS_instruction()
{
    return;
}

uint32_t MIPS_instruction::assemble (uint32_t pc, std::string op, 
                    std::string a, std::string b, std::string c)
{
    Mnemonic_func mapped_op;
    auto mapi = mnemonic_map.find(op);
    if (mapi == mnemonic_map.end()) {
        std::cerr << "could not find mnemonic [" << op << "]\n";
        exit(EXIT_FAILURE);
    }
    mapped_op = mapi->second;
    switch (mapped_op.type) {
        case Rtype : 
            return assemble_rtype(mapped_op.op,a,b,c,mapped_op.g);
        case Itype : 
            return assemble_itype(mapped_op.op,a,b,c,mapped_op.g,pc);
        case Jtype :
            return assemble_jtype(mapped_op.op,a,b,c,mapped_op.g);
    }
}

uint32_t MIPS_instruction::assemble_rtype(uint32_t op, std::string a,
             std::string b, std::string c, SyntaxGroup g)
{
    (void) op; (void) a; (void) b; (void) c; (void) g; 
    Rtype_instruction instruction; 
    instruction.op = 0;
    instruction.a  = 0;
    instruction.f  = op;
    switch (g) {
        case g1:
            instruction.Rs = regval(b);
            instruction.Rt = regval(c);
            instruction.Rd = regval(a);
            break;
        case g2:
            instruction.Rs = regval(a);
            instruction.Rt = regval(b);
            instruction.Rd = 0; 
            break;
        case g3:
            instruction.a  = stoi(c);
            instruction.Rs = 0;
            instruction.Rt = regval(b);
            instruction.Rd = regval(a);
            break;
        case g4:
            instruction.Rs = regval(c);
            instruction.Rt = regval(b);
            instruction.Rd = regval(a);
            break;
        case g5:
            instruction.Rs = regval(a);
            instruction.Rt = 0;
            instruction.Rd = 0;
            break;
        case g6:
            instruction.Rs = 0;
            instruction.Rt = 0;
            instruction.Rd = regval(a);
            break;
       default:
            std::cerr << "invalid code";
            break;
    }
    return *((uint32_t*)&instruction);
}

uint32_t MIPS_instruction::assemble_itype(uint32_t op, std::string a,
             std::string b, std::string c, SyntaxGroup g, uint32_t pc)
{
    (void) op; (void) a; (void) b; (void) c; (void) g; (void) pc;
    
    Itype_instruction instruction;
    instruction.op = op;
    switch (g) {
        case g1:
            instruction.Rt = regval(a);
            instruction.Rs = regval(b);
            instruction.i  = stoi(c);
            break;
        case g2:
            instruction.Rt = regval(b);
            instruction.Rs = regval(a);
            instruction.i  = stoi(c) - (pc+1); // rel addr
            break;
        case g3:
            instruction.Rt = 0;
            instruction.Rs = regval(a);
            instruction.i  = stoi(b) - (pc+1); // rel addr
            break;
        case g4:
            instruction.Rt = regval(c);
            instruction.Rs = regval(a);
            instruction.i  = stoi(b);
            break;
        case g5:
        case g6:
        default:
            std::cerr << "invalid code";
            break;
    }
    return *((uint32_t*)&instruction);
}

uint32_t MIPS_instruction::assemble_jtype(uint32_t op, std::string a,
             std::string b, std::string c, SyntaxGroup g)
{
    (void) op; (void) a; (void) b; (void) c; (void) g; 
    Jtype_instruction instruction; 
    switch (g) {
        case g1:
            instruction.op = op;
            instruction.i  = stoi(a);
            break;
        case g2:
        case g3:
        case g4:
        case g5:
        case g6:
        default:
            std::cerr << "invalid code";
            break;
    }
    return *((uint32_t*)&instruction);
}

uint32_t MIPS_instruction::regval(std::string reg)
{
    std::transform(reg.begin(), reg.end(), reg.begin(), ::tolower);
    auto mapi = register_map.find(reg);
    if (mapi == register_map.end()) {
        std::cerr << "could not find encoding"
            " for register [" << reg << "]\n";
        exit(EXIT_FAILURE);
    }
    return mapi->second;
}

void   MIPS_instruction::initialize_Mnemonic_map 
(const MIPS_instruction::Mnemonic_func_te *ops) 
{
    for (int i = 0; ops[i].key != "end"; ++i) {
        mnemonic_map.insert(
            std::pair<std::string, Mnemonic_func>
            (ops[i].key,ops[i].val));
    }
}

void   MIPS_instruction::initialize_Register_map 
(const MIPS_instruction::Register_te *reg) 
{
    for (int i = 0; reg[i].key != "end"; ++i) {

        register_map.insert(
            std::pair<std::string, uint32_t>
            (reg[i].key,reg[i].val));

    }
}

void MIPS_instruction::initialize_tables ()
{
    static const Register_te      reg[] = {
    {"$z",  0},  {"$zero",0},
    {"$at", 1},

    {"$v0", 2},  {"$v1", 3},
    
    {"$a0", 4},  {"$a1", 5},  {"$a2", 6},  {"$a3", 7},

    {"$t0",  8}, {"$t1",  9}, {"$t2", 10}, {"$t3", 11}, 
    {"$t4", 12}, {"$t5", 13}, {"$t6", 14}, {"$t7", 15},

    {"$s0", 16}, {"$s1", 17}, {"$s2", 18}, {"$s3", 19}, 
    {"$s4", 20}, {"$s5", 21}, {"$s6", 22}, {"$s7", 23}, 
   
    {"$t8", 24}, {"$t9", 25}, 
    
    {"$k0", 26}, {"$k1", 27}, 
    
    {"$gp", 28}, {"$sp", 29}, {"$fp", 30}, {"$ra", 31},

    {"end", 99}};
    
    static const Mnemonic_func_te ops[] = {
// R-type //
// Group 1: MNEUMONIC $d, $s, $t
    {"add" ,{ 0x20,Rtype,g1}},
    {"addu",{ 0x21,Rtype,g1}},
    {"and" ,{ 0x24,Rtype,g1}},
    {"nor" ,{ 0x27,Rtype,g1}},
    {"or"  ,{ 0x25,Rtype,g1}},
    {"slt" ,{ 0x2a,Rtype,g1}},
    {"sltu",{ 0x29,Rtype,g1}},
    {"sub" ,{ 0x22,Rtype,g1}},
    {"subu",{ 0x23,Rtype,g1}},
    {"xor" ,{ 0x26,Rtype,g1}},
// Group 2: MNEUMONIC $s, $t, 0
    {"div"  , {0x1a, Rtype, g2}}, 
    {"divu" , {0x1b, Rtype, g2}}, 
    {"mult" , {0x18, Rtype, g2}}, 
    {"multu", {0x19, Rtype, g2}}, 
// group 3: mneumonic $d, $t, c
    {"sll", {0x00, Rtype, g3}}, 
    {"sra", {0x03, Rtype, g3}}, 
    {"srl", {0x02, Rtype, g3}}, 
// group 4: mneumonic $d, $t, $s
    {"sllv", {0x04, Rtype, g4}},
    {"srav", {0x07, Rtype, g4}}, 
    {"srlv", {0x06, Rtype, g4}}, 
// group 5: mneumonic $s
    {"jr"  , {0x08, Rtype, g5}},
    {"mthi", {0x11, Rtype, g5}},
    {"mtlo", {0x13, Rtype, g5}},
// group 6: mneumonic $d
    {"mfhi", {0x10, Rtype, g6}},
    {"mflo", {0x12, Rtype, g6}},
// i-type //
// group 1: mneumonic $t, $s, i
    {"addi" , {0x08, Itype, g1}}, 
    {"addiu", {0x09, Itype, g1}}, 
    {"andi" , {0x0c, Itype, g1}}, 
    {"ori"  , {0x0d, Itype, g1}}, 
    {"slti" , {0x0a, Itype, g1}}, 
    {"sltiu", {0x0b, Itype, g1}}, 
    {"xori" , {0x07, Itype, g1}}, 
// group 2: mneumonic $s, $t, i
    {"beq", {0x04, Itype, g2}}, 
    {"bne", {0x05, Itype, g2}}, 
// group 3: mneumonic $s, i (0's in the $t field)
    {"bgez", {0x01, Itype, g3}}, 
    {"bgtz", {0x07, Itype, g3}}, 
    {"blez", {0x06, Itype, g3}}, 
    {"bltz", {0x01, Itype, g3}}, 
// group 4: mneumonic $t, i($s)
    {"lb" , {0x20, Itype, g4}}, 
    {"lbu", {0x24, Itype, g4}}, 
    {"lh" , {0x21, Itype, g4}}, 
    {"lhu", {0x25, Itype, g4}}, 
    {"lui", {0x0f, Itype, g4}}, 
    {"lw" , {0x23, Itype, g4}}, 
    {"sb" , {0x28, Itype, g4}}, 
    {"sh" , {0x29, Itype, g4}}, 
    {"sw" , {0x2b, Itype, g4}}, 
// j-type //
// group 1: mneumonic i
    {"j"  , {0x02, Jtype, g1}},
    {"jal", {0x03, Jtype, g1}},
    
    {"end" ,{ 111, Rtype, g1}}};
    initialize_Register_map(reg);
    initialize_Mnemonic_map(ops);
}






