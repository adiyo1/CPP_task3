#pragma once
#include "vertex.hpp"
#include "edge.hpp"
#include "hexagon.hpp"
#include "vector"
#include <iostream>

class board
{
private:
    std::vector<hexagon> hexagons_;
    std::vector<edge> edges_;
    std::vector<vertex> vertexes_;
    std::vector<vertex*> vertexes2_;
public:
void make ();
    board();
    // Method to get a vertex by its ID
    vertex& getVertex(int vertexId);
    vertex* getVertex2(int vertexId);
    std::vector<hexagon> getHexagons() const;
    std::vector<edge> getEdges() const;
    std::vector<vertex> getVertexes() const;
    std::vector<vertex*> getVertexes2() ;
    const std::vector<int>& getNeighboringVertices(int id) const;
    const vertex& getVertex(int id) const;
    // vertex& getVertex(int id);
        // std::cout<<vertex0.getVertexResources()[0]<<endl;
    edge& getEdge(int edgeId);
    
};