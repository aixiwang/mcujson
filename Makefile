CC=gcc

CFLAGS=-Wall
LDFLAGS=-std=c99

SOURCES=main.c mcujson.c
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=mcujson_test

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -r $(EXECUTABLE)
