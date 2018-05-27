#ifndef PATHS_IN_GRAPHS_HIPERCONECTADOS_H
#define PATHS_IN_GRAPHS_HIPERCONECTADOS_H

#include <set>
#include "datastructures/graphs/Edge.h"
#include "datastructures/graphs/Graph.h"

struct SolutionEj1 {
    set<Edge> always_present;
    set<Edge> sometimes_present;

    void AddAlwaysPresent(Edge const &e) {
        always_present.emplace(e);
    }

    void AddSometimesPresent(Edge const &e) {
        sometimes_present.emplace(e);
    }
};

SolutionEj1* Hiperconectados(Graph &graph);

#endif //PATHS_IN_GRAPHS_HIPERCONECTADOS_H
