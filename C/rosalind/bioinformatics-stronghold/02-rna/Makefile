PROGRAM=rna

INCPATH=-I../../lib

LIBPATH=-L../../lib -L../../../lib

LIBS=

all: $(PROGRAM) 

clean:
	rm -f $(PROGRAM)

$(PROGRAM): $(PROGRAM).cpp
	g++ -g -std=c++11 $(INCPATH) $(LIBPATH) -o $@ $? $(LIBS)

