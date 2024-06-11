#pragma once
#include <vector>
#include "vertex.hpp"
#include "player.hpp"

class edge {
private:
    int id_;
    player* owner_;
    std::vector<vertex> vertexesOfTheEdge_;

public:
    edge(); // Default constructor

    edge(int id, player* owner, std::vector<vertex> vertexesOfTheEdge); // Parameterized constructor

    std::vector<vertex> getVertexesOfTheEdge() const;
    player* getRoadIsAvailable() const;
    
};
