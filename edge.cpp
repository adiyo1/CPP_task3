#include "edge.hpp"

// Default constructor
edge::edge() : id_(0), owner_(nullptr), vertexesOfTheEdge_() {}

// Parameterized constructor
edge::edge(int id, player* owner, std::vector<vertex> vertexesOfTheEdge)
    : id_(id), owner_(owner), vertexesOfTheEdge_(vertexesOfTheEdge) {}

// Implementation of getRoadIsAvailable
player* edge::getRoadIsAvailable() const {
    // Example implementation, adjust as needed
    return owner_;
}

// Implementation of getVertexesOfTheEdge
std::vector<vertex> edge::getVertexesOfTheEdge() const {
    return vertexesOfTheEdge_;
}
