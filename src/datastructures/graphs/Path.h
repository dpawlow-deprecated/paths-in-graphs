#ifndef PATHS_IN_GRAPHS_PATH_H
#define PATHS_IN_GRAPHS_PATH_H

#include <vector>
#include "../../types/types.h"
#include "Edge.h"

using namespace std;

class Path {
public:
    vector<Edge> edges;

    Path();
    explicit Path(Edge const &edge);
    Path(Path const &path);

    void ExtendPath(Edge const &edge);

    long GetLength() const;
    Weight GetWeight() const;

private:
    Weight weight;
};


#endif //PATHS_IN_GRAPHS_PATH_H
