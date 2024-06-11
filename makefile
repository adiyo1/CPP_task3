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