#pragma once
#include <vector>
#include "vertex.hpp"
#include "player.hpp"

class edge {
private:
    int id_;
    player* owner_;
    std::vector<vertex*> vertexesOfTheEdge_;//need to a a pointer

public:
    edge(); // Default constructor

    edge(int id, player* owner, std::vector<vertex*> vertexesOfTheEdge); // Parameterized constructor

    std::vector<vertex*> getVertexesOfTheEdge() const;
    player* getRoadIsAvailable() const;
    player* getEdgeOwner() const;
    void setEdgeOwner(player* owner);
    bool isConnectedToEdge(const edge& otherEdge) const; 
    
};
