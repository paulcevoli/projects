exercise=hex2base64

INCPATH=-I../../lib

LIBPATH=-L../../lib -L../../../lib

LIBS=-l cryptobase -l dsbase

all: $(exercise) 

clean:
	rm -f $(exercise)

$(exercise): $(exercise).cpp
	g++ -g -std=c++11 $(INCPATH) $(LIBPATH) -o $@ $? $(LIBS)

