#
# LAB5.ASM
# 
#   TEST CODE FROM EE126 LAB 5
#
    LW $T0, 0X0($ZERO)
    ADD $T0, $T0, $T0
    ADD $T1, $T0, $T0
    SUB $T2, $T1, $T0
    SW $T2, 0X4($ZERO)
    SW $T2, 0X6($ZERO)
    NOP # SW -> ID
    NOP # SW -> EX
    NOP # SW -> MEM
    NOP # SW -> WB
