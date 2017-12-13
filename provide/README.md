
# MIPS Assembler

## Files
### Provided Files
- main.cpp
- mipsasm.h
- mipsasm.cpp
- MIPS\_instruction.h
- MIPS\_instruction.cpp
- toVHD.py
- report.pdf
- Makefile 
- run.sh

### Compiling

To compile the project, type "make" into terminal and the executable file
"mipsasm" will be created. In order to compile a MIPS assembly file run
"mipsasm < lab5.asm > ascii\_machine\_instructions.mi"

To get the corresponding output that can be placed into an imem.vhd unit,
run toVHD.py by typing "./toVHD.py ascii\_machine\_instructions.mi 
imem\_input.vhd"

After this procedure is done, imem\_input.vhd will hold the corresponding 
vhdl code that can be coppied and pasted into an imem.vhd file as used in
the course lab reports.

    


