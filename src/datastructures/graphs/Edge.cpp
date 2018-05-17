#include "Edge.h"

Edge::Edge(Edge const &edge) {
    this->start = edge.GetStartingNode();
    this->finish = edge.GetFinishingNode();
    this->weight = edge.GetWeight();
}

Edge::Edge(Node start, Node finish) {
    this->start = start;
    this->finish = finish;
}

Edge::Edge(Node start, Node finish, Weight weight) {
    this->start = start;
    this->finish = finish;
    this->weight = weight;
}

Weight Edge::GetWeight() const {
    return this->weight;
}

Node Edge::GetStartingNode() const {
    return this->start;
}

Node Edge::GetFinishingNode() const {
    return this->finish;
}