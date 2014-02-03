EXENAME = mp3test

COMPILER = g++
WARNINGS = -Wchar-subscripts -Wimplicit -Wparentheses -Wreturn-type -Wmissing-braces -Wundef -Wshadow
COMPILER_OPTS = -c -g -O0 -Wfatal-errors -Werror $(WARNINGS)
LINKER = g++

MAIN_OBJS = main.o EasyBMP.o BlockBMP.o
MAIN_DEPS = list.h list.cpp list_given.h list_given.cpp EasyBMP.o BlockBMP.o main.cpp

EBMP_DEPS = EasyBMP.h EasyBMP.cpp
BBMP_DEPS = EasyBMP.o BlockBMP.h BlockBMP.cpp

CODE_CLN = *.o $(EXENAME)

IMAG_CLN = interleaved*.bmp unshuffled*.bmp mixSplit*.bmp

all: $(EXENAME)

$(EXENAME) : main.o
	$(LINKER) $(MAIN_OBJS) -o $(EXENAME)

main.o : $(MAIN_DEPS)
	$(COMPILER) $(COMPILER_OPTS) main.cpp

EasyBMP.o : $(EBMP_DEPS)
	$(COMPILER) $(COMPILER_OPTS) EasyBMP.cpp

BlockBMP.o : $(BBMP_DEPS)
	$(COMPILER) $(COMPILER_OPTS) BlockBMP.cpp

clean:
	-rm -f $(CODE_CLN) $(IMAG_CLN)
