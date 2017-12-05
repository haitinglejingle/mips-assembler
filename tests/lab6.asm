#
# lab6.asm
# 
#   Test Code from EE126 lab 6
#
        beq $s0, $s1, L1
        add $t0, $t0, $t0
        beq $s2, $s3, L2
        add $t1, $t1, $t1
L1:     add $t2, $t2, $t2
L2:     add $t3, $t3, $t3
        j exit
        add $s0, $s0, $s0
exit:   add $s1, $s1, $s1
        nop // add -> ID
        nop // add -> EX
        nop // add -> MEM
        nop // add -> WB
