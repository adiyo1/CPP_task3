#include "hexagon.hpp"
#include "edge.hpp"
#include "vertex.hpp"

// Default constructor
hexagon::hexagon()
    : id_(0), circleNumber_(0), resource_(resourceTypes::desert), vertexes_(), edges_() {}

// Parameterized constructor
hexagon::hexagon(int id, int circleNumber, resourceTypes resource, std::vector<vertex> vertexes, std::vector<edge> edges)
    : id_(id), circleNumber_(circleNumber), resource_(resource), vertexes_(vertexes), edges_(edges) {}

int hexagon::getHexagonId() {
    return id_;
}

int hexagon::getHexagonCircleNumber() {
    return circleNumber_;
}

std::vector<vertex> hexagon::getHexagonVertexes() const {
    return vertexes_;
}

std::vector<edge> hexagon::getHexagonEdges() const {
    return edges_;
}

resourceTypes hexagon::getHexagonResource() const {
    return resource_;
}
