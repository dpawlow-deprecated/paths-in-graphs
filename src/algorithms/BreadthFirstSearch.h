#ifndef PATHS_IN_GRAPHS_BREADTHFIRSTSEARCH_H
#define PATHS_IN_GRAPHS_BREADTHFIRSTSEARCH_H

#include "../types/types.h"

enum Color { White, Gray, Black };

struct BFSNode {
    Color color;
    bool parent_null;
    Node parent;
    bool distance_infinite;
    unsigned long distance;

    BFSNode() {
        color = White;
        parent_null = true;
        distance_infinite = true;
    }

    void SetColor(Color c) {
        color = c;
    }

    void SetDistance(unsigned long d) {
        distance = d;
        distance_infinite = false;
    }

    void SetParent(Node p) {
        parent = p;
        parent_null = false;
    }

    void SetAttributes(Color c, Node p, unsigned long d) {
        SetColor(c);
        SetDistance(d);
        SetParent(p);
    }
};




#endif //PATHS_IN_GRAPHS_BREADTHFIRSTSEARCH_H
