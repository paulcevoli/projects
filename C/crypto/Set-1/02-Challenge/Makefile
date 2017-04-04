exercise=fixedxor
INCPATH=-I../../lib
LIBPATH=-L../../lib -L../../../lib
LIBS=-lcryptobase -ldsbase

all: $(exercise) 

clean:
	rm -f $(exercise)

$(exercise): $(exercise).cpp
	g++ -g -std=c++11 $(INCPATH) $(LIBPATH) -o $@ $? $(LIBS)

