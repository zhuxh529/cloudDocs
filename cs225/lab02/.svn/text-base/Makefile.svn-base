# CS 225 Lab 02
# Written by Jack Toole Fall 2010

EXE = sketchify

OBJS = main.o EasyBMP.o

COMPILER = g++
COMPILER_OPTS = -c -g -O0 -w
LINKER = g++
LINKER_OPTS = -o

all : $(EXE)

$(EXE) : $(OBJS)
	$(LINKER) $(LINKER_OPTS) $(EXE) $(OBJS)

main.o : main.cpp EasyBMP.h
	$(COMPILER) $(COMPILER_OPTS) main.cpp
	
EasyBMP.o : EasyBMP.cpp EasyBMP.h
	$(COMPILER) $(COMPILER_OPTS) EasyBMP.cpp

clean : 
	-rm -f *.o $(EXE)

