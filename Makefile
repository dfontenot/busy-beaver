CC=g++
CFLAGS=-Iinclude
SOURCES=$(wildcard src/*.cpp)

all: busy_beaver

busy_beaver: $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@
