#ifndef PATHS_IN_GRAPHS_PATH_H
#define PATHS_IN_GRAPHS_PATH_H

#include <vector>
#include "../types/types.h"
#include "Edge.h"

using namespace std;

class Path {
public:
    vector<Edge> edges;

    Path();
    explicit Path(Edge edge);
    explicit Path(Path path);

    void ExtendPath(Edge edge);

    long GetLength();
    Weight GetWeight();
private:
    Weight weight;

};


#endif //PATHS_IN_GRAPHS_PATH_H
