CC=g++
CFLAGS=-Iinclude -std=gnu++11 -g
TEST_CFLAGS=-isystem include
TEST_CLIBS=-lpthread lib/.libs/libgtest.a
SOURCES=$(wildcard src/*.cpp)
TESTS=$(wildcard test/*.cpp)

.PHONY: clean all

all: busy_beaver

busy_beaver: $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@

tests: $(TESTS)
	$(CC) $(CFLAGS) $(TEST_CFLAGS) $(filter-out src/main.cpp,$(SOURCES)) $^ -o $@ $(TEST_CLIBS)

clean:
	rm busy_beaver* tests*
