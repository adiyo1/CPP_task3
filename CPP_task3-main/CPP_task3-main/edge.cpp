#include "edge.hpp"

// Default constructor
edge::edge() : id_(0), owner_(nullptr), vertexesOfTheEdge_() {}

// Parameterized constructor
edge::edge(int id, player* owner, std::vector<vertex*> vertexesOfTheEdge)
    : id_(id), owner_(owner), vertexesOfTheEdge_(vertexesOfTheEdge) {}

// Implementation of getRoadIsAvailable
player* edge::getRoadIsAvailable() const {
    // Example implementation, adjust as needed
    return owner_;
}

// Implementation of getVertexesOfTheEdge
std::vector<vertex*> edge::getVertexesOfTheEdge() const {
    return vertexesOfTheEdge_;
}

player* edge:: getEdgeOwner() const
{
    return owner_;
}
void edge::setEdgeOwner(player* owner)
{
    owner_ = owner;
}

bool edge::isConnectedToEdge(const edge& otherEdge) const {
    for (vertex* v1 : vertexesOfTheEdge_) {
        for (vertex* v2 : otherEdge.getVertexesOfTheEdge()) {
            if (v1 == v2) {
                return true;
            }
        }
    }
    return false;
}

