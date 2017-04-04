OBJECTS  =  list.o  \
            tree.o  \
            hash.o  \

INCLUDES =  list.h  \
            tree.h  \
            hash.h  \

CPPOPTIONS = -Wall -std=c++11 -g -I../include

all: libdsbase.a

clean:
	rm -rf *.o libdsbase.a 

list.o: $(INCLUDES) list.cpp
	g++ $(CPPOPTIONS) -c list.cpp

tree.o: $(INCLUDES) tree.cpp
	g++ $(CPPOPTIONS) -c tree.cpp

hash.o: $(INCLUDES) hash.cpp
	g++ $(CPPOPTIONS) -c hash.cpp

libdsbase.a: $(OBJECTS)
	ar cr $@ $?
	ranlib $@
