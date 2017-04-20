TARGET = sharedinterests

INCLUDES =  list.h  \
            tree.h  \
            stack.h \
            hash.h  \

CPPOPTIONS = -Wall -std=c++11 -g -I../include

all: $(TARGET) 

clean:
	rm -rf $(TARGET) 

$(TARGET): $(TARGET).cpp
	g++ $(CPPOPTIONS) -o $(TARGET) $? 

