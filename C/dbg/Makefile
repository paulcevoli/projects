OBJECTS  =  debug.o 
INCLUDES =  debug.h 
CPPOPTIONS = -Wall -g -std=c++11
LIBRARY = libdbgbase.a

all: $(LIBRARY)

clean:
	rm -rf *.o $(LIBRARY) 

debug.o: $(INCLUDES) debug.cpp
	g++ $(CPPOPTIONS) -c debug.cpp

$(LIBRARY): $(OBJECTS)
	ar cr $@ $?
	ranlib $@
