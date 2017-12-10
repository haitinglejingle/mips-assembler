#
# lab4.asm
# 
#   Test Code from EE126 lab 4
#
    add $t2, $t0, $t1
    sw $t2, 0x0($zero) # Incorrect value stored due to data hazard
    sub $t3, $t0, $t1
    sw $t2, 0x0($zero) # Correct value stored
    sw $t3, 0x4($t3) # Incorrect address used due to data hazard
    sw $t3, 0x4($t3) # Correct address used
    or $s2, $s0, $s1
    nop
    nop
    sw $s2, 0xC($zero) #Correct value stored; data hazard overcome by 2 nops
    nop # sw -> ID
    nop # sw -> EX
    nop # sw -> MEM
    nop # sw -> WB (write to dmem complete)
