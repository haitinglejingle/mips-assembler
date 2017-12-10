#
# lab5.asm
# 
#   Test Code from EE126 lab 5
#
    lw $t0, 0x0($zero)
    add $t0, $t0, $t0
    add $t1, $t0, $t0
    sub $t2, $t1, $t0
    sw $t2, 0x4($zero)
    sw $t2, 0x6($zero)
    nop # sw -> ID
    nop # sw -> EX
    nop # sw -> MEM
    nop # sw -> WB
