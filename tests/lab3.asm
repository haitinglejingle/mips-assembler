#
# lab3.asm
# 


#   Test Code EE126 lab 3
#
    lw $t2, 0($z)
L1: beq $t0, $t2, L2
    sub $s0, $s0, $s1

    add $t0, $t0, $t1
    j L1
L2: or $s2, $s0, $t3
    and $s2, $s2, $s3
    sw $s2, 4($t3)
    nop
