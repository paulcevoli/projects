OBJECTS = crypto.o  \

INCLUDES = crypto.h \

CPPOPTIONS = -Wall -g -I../../lib
LIBOPTIONS = -L../../lib 
LIBS = -l dsbase

all: libcryptobase.a

clean:
	rm -rf *.o libcryptobase.a 

crypto.o: $(INCLUDES) crypto.cpp
	g++ $(LIBOPTIONS) $(CPPOPTIONS) -c crypto.cpp $(LIBS)

libcryptobase.a: $(OBJECTS)
	ar cr $@ $?
	ranlib $@
