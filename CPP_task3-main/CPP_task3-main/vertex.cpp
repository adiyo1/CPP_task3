#include "vertex.hpp"
#include "player.hpp"

// Default constructor
vertex::vertex() : id_(0), resources_(), owner_(nullptr) {}

// Parameterized constructor
vertex::vertex(int id, std::vector<resourceTypes> resources, player *owner, std::vector<vertex*> neighboringVertices,std::vector<int>circlesNumbers)
    : id_(id), resources_(resources), owner_(owner),neighboringVertices_(neighboringVertices),circlesNumbers_(circlesNumbers) {}

int vertex::getVertexId() const
{
    return id_;
}

player* vertex::getVertexOwner() const
{
    return owner_;
}

// std::vector<resourceTypes> vertex::getVertexResources() const
// {
//     return resources_;
// }

const std::vector<resourceTypes>& vertex::getVertexResources() const {
    return resources_;
}

// int vertex::getVertexOwnerID() const{
//     return owner_->getPlayerId();
// }
void vertex::setVertexOwner(player *owner)
{
    if (owner_ != nullptr) {
        std::cout << "Vertex is already owned by another player." << std::endl;
        return;
    }
    // std::cout << "Player " << owner->getName() << " placed a settlement on vertex " << id_ << std::endl;
    this->avaliable_=1;
    owner_ = owner;
}
void vertex:: setAvaliable(int avaliable){
    avaliable_ = avaliable;
}
int vertex::getAvaliable(){
    return avaliable_;
}
std::vector<vertex*> vertex::getNeighboringVertices() const
{
    return neighboringVertices_;
}
std::vector<int> vertex::getCirclesNumbers() const{
    return circlesNumbers_;
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
