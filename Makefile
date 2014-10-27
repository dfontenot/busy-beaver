CC=g++
CFLAGS=-Iinclude -std=c++11
TEST_CFLAGS=-isystem include -Llib
TEST_CLIBS=-lpthread -lgtest
SOURCES=$(wildcard src/*.cpp)
TESTS=$(wildcard test/*.cpp)

.PHONY: clean all

all: busy_beaver

busy_beaver: $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@

tests: $(TESTS)
	$(CC) $(CFLAGS) $(TEST_CFLAGS) $(filter-out src/busybeaver.cpp,$(SOURCES)) $^ -o $@ $(TEST_CLIBS)

clean:
	rm busy_beaver* tests*
