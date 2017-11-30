CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=-g -lm -std=c++11

MAIN=./src/DistanceVector.cpp

SOURCES=$(wildcard ./src/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
MAIN_OBJECTS=$(filter-out $(MAIN:.cpp=.o), $(OBJECTS))

EXECUTABLE=./DistanceVector

.PHONY: all bin clean

all: bin

bin: $(EXECUTABLE)

$(EXECUTABLE): $(MAIN_OBJECTS)
	$(CC) $(LDFLAGS) $(MAIN_OBJECTS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm $(OBJECTS)
	-rm $(EXECUTABLE)
