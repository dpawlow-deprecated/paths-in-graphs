#ifndef PATHS_IN_GRAPHS_TYPES_H
#define PATHS_IN_GRAPHS_TYPES_H
#include <vector>

using namespace std;
using Node = unsigned long;
using Weight = long;

struct MatrixEdge {
    bool not_null;
    Weight weight;

    MatrixEdge(){
        not_null = true;
        weight = 0;
    }

    explicit MatrixEdge(Weight w) {
        not_null = true;
        weight = w;
    }
};

using AdjacencyRow = vector<MatrixEdge>;
using AdjacencyMatrix = vector<AdjacencyRow>;

#endif //PATHS_IN_GRAPHS_TYPES_H
