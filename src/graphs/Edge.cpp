#include "Edge.h"

Edge::Edge(Node start, Node finish) {
    this->start = start;
    this->finish = finish;
}

Edge::Edge(Node start, Node finish, Weight weight) {
    this->start = start;
    this->finish = finish;
    this->weight = weight;
}

Weight Edge::GetWeight() {
    return this->weight;
}

Node Edge::GetStartingNode() {
    return this->start;
}

Node Edge::GetFinishingNode() {
    return this->finish;
}