exercise = part

all: $(exercise) 

clean:
	rm -f $(exercise)

$(exercise): $(exercise).cpp
	g++ -g -std=c++11 -o $@ $?

