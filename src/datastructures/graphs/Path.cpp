#include "Path.h"

Path::Path() {
    this->weight = 0;
}

Path::Path(Edge const &edge) {
    ExtendPath(edge);
}

Path::Path(Path const &path) {
    this->edges = path.edges;
    this->weight = path.GetWeight();
}

void Path::ExtendPath(Edge const &edge) {
    this->edges.push_back(edge);
    this->weight += edge.GetWeight();
}

Weight Path::GetWeight() const {
    return this->weight;
}

long Path::GetLength() const {
    return this->edges.size();
}