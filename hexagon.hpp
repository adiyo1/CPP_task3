#pragma once
#include <vector>
#include "edge.hpp"
#include "vertex.hpp"

class hexagon {
private:
    int id_;
    int circleNumber_;
    resourceTypes resource_;
    std::vector<vertex> vertexes_;
    std::vector<edge> edges_;

public:
    hexagon(); // Default constructor
    hexagon(int id, int circleNumber, resourceTypes resource, std::vector<vertex> vertexes, std::vector<edge> edges); // Parameterized constructor

    int getHexagonId();
    int getHexagonCircleNumber();
    std::vector<vertex> getHexagonVertexes() const;
    std::vector<edge> getHexagonEdges() const;
    resourceTypes getHexagonResource() const;
};
