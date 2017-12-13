
# MIPS Assembler

by: Michelle Chan & Ashton Stephens

## Files
### Provided Files
#### C++
- main.cpp 
- mipsasm.h
- mipsasm.cpp
- MIPS\_instruction.h
- MIPS\_instruction.cpp
#### Example Assembly    
- lab6.asm
- pseudo1.asm 
#### Others
- toVHD.py 
- report.pdf
- Makefile 
- run.sh   

### Compiling

To compile the project, type `make` into terminal and the executable file
`mipsasm` will be created. In order to compile a MIPS assembly file run
`mipsasm < lab6.asm > ascii\_machine\_instructions.mi`

To get the corresponding output that can be placed into an imem.vhd unit,
run toVHD.py by typing `./toVHD.py ascii\_machine\_instructions.mi 
imem\_input.vhd`

After this procedure is done, imem\_input.vhd will hold the corresponding 
vhdl code that can be coppied and pasted into an imem.vhd file as used in
the course lab reports.

### Fast Example

In order to make grading easier, a bash script has been provided that
will compile the program and run in it in terminal. The desired output
is lab6.vhd and pseudo1.vhd, which should hold code that can be pasted 
into an imem.vhd unit in the initialization statement. Just enter the
folder and type the following:
    
`bash run.sh`

This will create a directory called _outputs_ that will hold four files.
These will be `lab6.mi lab6.vhd pseudo.mi pseudo.vhd`. As well, this script will
call make and will compile `mipsasm` in the project directory.

`outputs/file.mi`
    - holds the ascii machine instructions with one instruction per line

`outputs/file.vhd` 
    - holds the machine instructions in a way that makes copying and pasting
      into a vhdl file easy



