#!/usr/bin/env python

import sys
import re

def main ():
    if (len(sys.argv) < 2):
        print("expecting format:\n\t" + sys.argv[0] + " [infile] [outfile]")
    else :
        instructions = getInstructions(sys.argv[1]);
        imem_output(instructions,sys.argv[2])

def getInstructions(filename):
    instructions =  [];
    file = open(filename,"r")
    instructions = file.readlines();
    file.close()
    return [line[:-1] for line in instructions]
    
def imem_output(instr,filename):
    instr_chunks = [] 
    file = open(filename,"w")
    
    for i in instr:
        while i:
            instr_chunks.append(i[:8])
            i = i[8:]

    for i in range(0,len(instr_chunks)):
        file.write("imemBytes("+str(i)+") <= \""+instr_chunks[i]+"\";\n")

    file.close()


main()

