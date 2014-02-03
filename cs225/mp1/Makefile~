#declare our compiler and compiler options variables.
COMPILER = g++
COMPILER_FLAGS = -c -g -O0 -Wall -Werror
LINKER = g++

# we tell make how to link mp1
mp1 : main.o EasyBMP.o
	$(LINKER)	main.o	EasyBMP.o -o mp1


# main.cpp is compiled to get main.o
main.o : main.cpp EasyBMP.h
		$(COMPILER)	$(COMPILER_FLAGS)	main.cpp
# EasyBMP.cpp is compiled to get EasyBMP.o
EasyBMP.o : EasyBMP.cpp EasyBMP.h
		$(COMPILER)	$(COMPILER_FLAGS)	EasyBMP.cpp



# clean target in the mp1
.PHONY: clean
clean:
	-rm -f *.o mp1


