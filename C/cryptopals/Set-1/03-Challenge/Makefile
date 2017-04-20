exercise=singlexor
INCPATH=-I../../lib -I../../../lib
LIBPATH=-L../../lib -L../../../lib
LIBS=-lcryptobase -ldsbase
CCOPTS=-Wall -g -std=c++11

all: $(exercise) 

clean:
	rm -f $(exercise)

$(exercise): $(exercise).cpp
	g++ $(CCOPTS) $(INCPATH) $(LIBPATH) -o $@ $? $(LIBS)

