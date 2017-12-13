#!bin/bash

mkdir outputs &&

make && ./mipsasm < lab6.asm > outputs/lab6.mi && \
    python toVHD.py outputs/lab6.mi outputs/lab6.vhd

make && ./mipsasm < pseudo1.asm > outputs/pseudo1.mi && \
    python toVHD.py outputs/pseudo1.mi outputs/pseudo1.vhd
