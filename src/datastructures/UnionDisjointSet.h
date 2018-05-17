#ifndef PATHS_IN_GRAPHS_UNIONDISJOINTSET_H
#define PATHS_IN_GRAPHS_UNIONDISJOINTSET_H


#include <vector>
#include "../types/types.h"

using namespace std;

class UnionDisjointSet {

private:
    vector<Node> parents;
    vector<Node> heights;

public:
    explicit UnionDisjointSet(int n_of_nodes);
    Node Find(Node n);
    void Union(Node a, Node b);
};


#endif //PATHS_IN_GRAPHS_UNIONDISJOINTSET_H
