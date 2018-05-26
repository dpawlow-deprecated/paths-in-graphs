#ifndef PATHS_IN_GRAPHS_TYPES_H
#define PATHS_IN_GRAPHS_TYPES_H
#include <vector>
#include "../datastructures/graphs/Edge.h"

using namespace std;
using Node = unsigned long;
using Weight = long;

struct SolutionEj1 {
    vector<Edge> always_present;
    vector<Edge> sometimes_present;

    void AddAlwaysPresent(Edge const &e) {
        always_present.emplace_back(e);
    }

    void AddSometimesPresent(Edge const &e) {
        sometimes_present.emplace_back(e);
    }
};

#endif //PATHS_IN_GRAPHS_TYPES_H
