CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=BinaryTreeDemo.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=BinaryTreeDemo.exe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
