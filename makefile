DEP := shared.hpp
BIN := v1 v2
FLAGS := -O3 -ffast-math -Wall -Wpedantic 

all: $(BIN)

v1: %: %.cpp $(DEP)
	g++ $(FLAGS) $< -o $@ && ./$@

v2: %: %.cpp $(DEP)
	g++ $(FLAGS) $< -o $@ && ./$@

clean:
	rm -I $(BIN)
