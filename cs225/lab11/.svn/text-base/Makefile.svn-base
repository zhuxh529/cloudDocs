EXENAME = testheap
CXX = g++
CXX_FLAGS = -g -O0 -Wall -Wfatal-errors
OBJS = testheap.o

IS_LIBRT:=$(shell locate -l 1 -c librt.so)
ifeq ($(IS_LIBRT),0)
LIBRT=
else
LIBRT=-lrt
endif

$(EXENAME) : $(OBJS)
	$(CXX) $(LIBRT) -o $@ $^

testheap.o: testheap.cpp minheap.h minheap.cpp
	$(CXX) -c $(CXX_FLAGS) testheap.cpp

clean:
	-rm -f *.o $(EXENAME)

