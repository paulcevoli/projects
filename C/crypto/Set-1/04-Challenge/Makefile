exercise=xorcipher
INCPATH=-I../../lib -I../../../ds
LIBPATH=-L../../lib -L../../../ds
LIBS=-lcryptobase -ldsbase
CPPOPTIONS=-Wall -g -std=c++11

all: $(exercise) 

clean:
	rm -f $(exercise)

$(exercise): $(exercise).cpp
	g++ $(CPPOPTIONS) $(INCPATH) $(LIBPATH) -o $@ $? $(LIBS)

