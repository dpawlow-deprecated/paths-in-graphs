#include "Path.h"

Path::Path() {
    this->weight = 0;
}

Path::Path(Edge edge) {
    ExtendPath(edge);
}

Path::Path(Path path) {
    this->edges = path.edges;
    this->weight = path.GetWeight();
}

void Path::ExtendPath(Edge edge) {
    this->edges.push_back(edge);
    this->weight += edge.GetWeight();
}

Weight Path::GetWeight() {
    return this->weight;
}

long Path::GetLength() {
    return this->edges.size();
}