# Makefile
#
# Purpose: Compile assembler program
# By: Ashton Stephens
# Date : 12/5/17
#

IDIRS	  = ./

# # # # # # # # # # # # # # # # 
# This is where you keep your .h files

CC      = clang++
IFLAGS  = $(patsubst %,-I%,$(IDIRS))
CFLAGS  = -std=c++11 -Wall -Wextra -Werror -Wfatal-errors -pedantic $(IFLAGS)
LDFLAGS = 
DBFLAGS = -g -DDEBUG
LDLIBS  = -lpthread
RM_OBJS = && rm *.o

%.o: %.cpp 
	$(CC) $(CFLAGS) -c -o $@ $<

%.o.test: %.cpp
	$(CC) $(DBFLAGS) $(CFLAGS) -c -o $*.o $<

# # # # # # # # # # # # # # # # 
# stuff you might have to change 
# 	|	|	|
# 	V	V	V

EXECUTABLES = mipsasm

MIPS_ASSEMBLER_INCLUDES  = mipsasm.o main.o map/MIPS_instruction.o

mipsasm: $(MIPS_ASSEMBLER_INCLUDES)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS) $(RM_OBJS) 
mips_assembler_test: $(patsubst %,%.test,$(MIPS_ASSEMBLER_INCLUDES))
	$(CC) $(LDFLAGS) -o $@ $(MIPS_ASSEMBLER_INCLUDES) $(LDLIBS) $(RM_OBJS)

clean: 
	rm *~ *.swp map/*.o *.o $(EXECUTABLES) 2> /dev/null; true




