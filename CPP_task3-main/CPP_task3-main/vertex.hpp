#ifndef VERTEX_HPP
#define VERTEX_HPP

#pragma once
#include <vector>
#include <iostream>
#include "enums.hpp"
// Forward declaration of the player class
class player;

//enum class resourceTypes { wood, stone, clay, sheep, wheat, desert, sea };

class vertex {
private:
    int id_;
    std::vector<resourceTypes> resources_; // vector of resources
    player* owner_;
    std::vector<vertex*> neighboringVertices_;
    std::vector<int>circlesNumbers_;
    int avaliable_;

public:
    vertex(); // Default constructor
    vertex(int id, std::vector<resourceTypes> resources, player* owner,std::vector<vertex*>neighboringVertices,std::vector<int>circlesNumbers); // Parameterized constructor

    int getVertexId() const;
    player* getVertexOwner() const;
    int getVertexOwnerID() const;
    void setVertexOwner(player* owner); // Corrected return type to void
    // std::vector<resourceTypes> getVertexResources() const;
    const std::vector<resourceTypes>& getVertexResources() const;
    std::vector<vertex*> getNeighboringVertices() const;
    std::vector<int> getCirclesNumbers() const;
    void  setAvaliable(int avaliable);
    int getAvaliable();
    

};
#endif // VERTEX_HPP