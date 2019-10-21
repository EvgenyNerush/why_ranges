CXX := g++ -O3 -ffast-math -std=c++2a -Wall -Wpedantic -I range-v3/include
#CXX := clang++ -Ofast -std=c++2a -Wall -Wpedantic -I range-v3/include
DEP := shared.hpp
BIN := v1 v2 v3 v4
FLAGS := 

all: $(BIN)

v1: %: %.cpp $(DEP)
	$(CXX) $< -o $@ && ./$@

v2: %: %.cpp $(DEP)
	$(CXX) $< -o $@ && ./$@

v3: %: %.cpp $(DEP)
	$(CXX) $< -o $@ && ./$@

v4: %: %.cpp $(DEP)
	$(CXX) $< -o $@ && ./$@

clean:
	rm -I $(BIN)
