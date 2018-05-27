#include "UnionDisjointSet.h"

UnionDisjointSet::UnionDisjointSet(unsigned long n_of_nodes) {
    vector<Node> heights(n_of_nodes, 1);
    this->heights = heights;

    vector<Node> parents(n_of_nodes, 0);
    this->parents = parents;
    for (unsigned long i = 0; i < this->parents.size(); i++) {
        this->parents[i] = i;
    }
}

Node UnionDisjointSet::Find(Node n) {
    if (parents[n] != n) {
        parents[n] = Find(parents[n]);
    }
    return parents[n];
}

void UnionDisjointSet::Union(Node a, Node b) {
    a = Find(a);
    b = Find(b);
    if (heights[a] < heights[b]) {
        parents[a] = b;
    } else {
        parents[b] = a;
    }
    if (heights[a] == heights[b]) {
        heights[a]++;
    }
}