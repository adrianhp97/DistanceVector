CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=-g -lm -std=c++11

MAIN=./src/DistanceVector.cpp

SOURCES=$(wildcard ./src/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=./DistanceVector

.PHONY: all bin clean

all: bin

bin: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm $(OBJECTS)
	-rm $(EXECUTABLE)

run:
	./DistanceVector
