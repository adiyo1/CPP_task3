


# CXX = g++
# CXXFLAGS = -std=c++11 -Wsign-conversion -g
# CATANOBJ = catan.o player.o  hexagon.o vertex.o Demo.o edge.o  board.o
# TESTOBJ = Test.o TestCounter.o $(filter-out Demo.o, $(CATANOBJ))
# VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

# all: Catan test

# test: $(TESTOBJ) 
# 	$(CXX) $(CXXFLAGS) $(TESTOBJ) -o test
# 	./test

# Catan: $(CATANOBJ)
# 	$(CXX) $(CXXFLAGS) $(CATANOBJ) -o catan

# catan.o : catan.cpp catan.hpp
# 	$(CXX) $(CXXFLAGS) -c catan.cpp

# player.o : player.cpp player.hpp
# 	$(CXX) $(CXXFLAGS) -c player.cpp

# Demo.o: Demo.cpp
# 	$(CXX) $(CXXFLAGS) -c Demo.cpp

# valgrind: Catan
# 	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./Catan 2>&1 | { egrep "lost| at " || true; }
# 	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

# TestCounter.o: TestCounter.cpp 
# 	$(CXX) $(CXXFLAGS) -c TestCounter.cpp

# Test.o: Test.cpp
# 	$(CXX) $(CXXFLAGS) -c Test.cpp

# # Cards.o : Cards.cpp Cards.hpp
# #  $(CXX) $(CXXFLAGS) -c Cards.cpp

# clean:
# 	rm -f *.o Catan test

# .PHONY: all clean


CXX =g++
CXXFLAGS =-std=c++11 -Wall -Wextra -Werror -pedantic -I include
SRC_FILES =Demo.cpp board.cpp edge.cpp hexagon.cpp player.cpp vertex.cpp development_card.cpp  catan.cpp
SS = Demo.cpp
OBJ_FILES =$(SRC_FILES:.cpp=.o)
EXECUTABLE = catan

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE)