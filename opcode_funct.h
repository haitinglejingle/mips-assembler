/* 
 * Constants for mapping mneumonics to their opcode or funct field
 * R-type instructions all have opcode 0x0 with a different funct field
 */

// R-type //
// Group 1: MNEUMONIC $d, $s, $t
#define ADD  0x20
#define ADDU 0x21
#define AND  0x24
#define NOR  0x27
#define OR   0x25
#define SLT  0x2A
#define SLTU 0x29
#define SUB  0x22
#define SUBU 0x23
#define XOR  0x26

// Group 2: MNEUMONIC $s, $t, 0
#define DIV   0x1A
#define DIVU  0x1B
#define MULT  0x18
#define MULTU 0x19

// Group 3: MNEUMONIC $d, $t, c
#define SLL 0x00
#define SRA 0x03
#define SRL 0x02

// Group 4: MNEUMONIC $d, $t, $s
#define SLLV 0x04
#define SRAV 0x07
#define SRLV 0x06

// Group 5: MNEUMONIC $s
#define JR   0x08
#define MTHI 0x11
#define MTLO 0x13

// Group 6: MNEUMONIC $d
#define MFHI 0x10
#define MFLO 0x12

// I-type //
// Group 1: MNEUMONIC $t, $s, i
#define ADDI  0x08
#define ADDIU 0x09
#define ANDI  0x0C
#define ORI   0x0D
#define SLTI  0x0A
#define SLTIU 0x0B
#define XORI  0x07

// Group 2: MNEUMONIC $s, $t, i
#define BEQ 0x04
#define BNE 0x05

// Group 3: MNEUMONIC $s, i (0's in the $t field)
#define BGEZ 0x01
#define BGTZ 0x07
#define BLEZ 0x06
#define BLTZ 0x01

// Group 4: MNEUMONIC $t, i($s)
#define LB  0x20
#define LBU 0x24
#define LH  0x21
#define LHU 0x25
#define LUI 0x0F
#define LW  0x23
#define SB  0x28
#define SH  0x29
#define SW  0x2B

// J-type //
// Group 1: MNEUMONIC i
#define J   0x02
#define JAL 0x03
