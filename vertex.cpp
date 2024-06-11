#include "vertex.hpp"

// Default constructor
vertex::vertex() : id_(0), resources_(), owner_(nullptr) {}

// vertex::vertex() : id_(0), resources_(), owner_(nullptr) {}

// Parameterized constructor
vertex::vertex(int id, std::vector<resourceTypes> resources, player *owner, std::vector<vertex*> neighboringVertices)
    : id_(id), resources_(resources), owner_(owner),neighboringVertices_(neighboringVertices) {}

int vertex::getVertexId() const
{
    return id_;
}

player *vertex::getVertexOwner() const
{
    return owner_;
}

std::vector<resourceTypes> vertex::getVertexResources() const
{
    return resources_;
}

void vertex::setVertexOwner(player *owner)
{

    owner_ = owner;
}
std::vector<vertex*> vertex::getNeighboringVertices() const
{
    return neighboringVertices_;
}

// #include "vertex.hpp"

// // Default constructor
// vertex::vertex() : id_(0), resources_(), owner_(nullptr) {}

// // Parameterized constructor
// vertex::vertex(int id, std::vector<resourceTypes> resources, int owner)
//     : id_(id), resources_(resources), owner_(owner) {}

// int vertex::getVertexId() const {
//     return id_;
// }

// player* vertex::getVertexOwner() const {
//     return owner_;
// }

// std::vector<resourceTypes> vertex::getVertexResources() const {
//     return resources_;
// }
// player* setVertexOwner(player* owner){
//     owner_ = owner;
//     return owner_;
// }
