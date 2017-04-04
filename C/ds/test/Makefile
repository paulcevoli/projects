exercise = tests
INCPATH = -I..
LIBPATH = -L..
LIBS=-l dsbase 

all: $(exercise) 

clean:
	rm -f $(exercise)

$(exercise): $(exercise).cpp 
	g++ -g -std=c++11 $(INCPATH) $(LIBPATH) -o $@ $? $(LIBS)

