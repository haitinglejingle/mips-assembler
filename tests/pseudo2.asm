# similar to lab6, pseudoinstructions are included in the middle
        bgt $s0, $s1, L1
        bgt $s0, $s1, 0x8
        add $t0, $t0, $t0
        beq $s2, $s3, L2
        add $t1, $t1, $t1
L1:     add $t2, $t2, $t2
L2:     add $t3, $t3, $t3
        j exit
        add $s0, $s0, $s0
        move $t0, $t1
exit:   add $s1, $s1, $s1
        nop // add -> ID
        nop // add -> EX
        nop // add -> MEM
        nop // add -> WB
