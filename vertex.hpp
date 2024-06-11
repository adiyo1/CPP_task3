#pragma once
#include <vector>
#include <iostream>

// Forward declaration of the player class
class player;

enum class resourceTypes { wood, stone, clay, sheep, wheat, desert, sea };

class vertex {
private:
    int id_;
    std::vector<resourceTypes> resources_; // vector of resources
    player* owner_;
    std::vector<vertex*> neighboringVertices_;
    

public:
    vertex(); // Default constructor
    vertex(int id, std::vector<resourceTypes> resources, player* owner,std::vector<vertex*>neighboringVertices); // Parameterized constructor

    int getVertexId() const;
    player* getVertexOwner() const;
    void setVertexOwner(player* owner); // Corrected return type to void
    std::vector<resourceTypes> getVertexResources() const;
    std::vector<vertex*> getNeighboringVertices() const;

};
