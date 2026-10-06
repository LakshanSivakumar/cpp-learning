CXX      ?= g++
CXXFLAGS ?= -std=c++20 -Wall -Wextra -Wpedantic -Wshadow -fsanitize=address,undefined -g

.PHONY: test basics clean

test: bin/arrays
	./bin/arrays

bin/arrays: pointer-array-utils/arrays.cpp | bin
	$(CXX) $(CXXFLAGS) $< -o $@

basics: | bin
	$(CXX) $(CXXFLAGS) basics/functions-multi-file/functions.cpp basics/functions-multi-file/add.cpp -o bin/functions
	$(CXX) $(CXXFLAGS) basics/classes-intro/classes.cpp -o bin/classes
	$(CXX) $(CXXFLAGS) calculator-pointer-result/calculator.cpp -o bin/calculator

bin:
	mkdir -p bin

clean:
	rm -f bin/arrays bin/functions bin/classes bin/calculator
