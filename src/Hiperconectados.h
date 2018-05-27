#ifndef PATHS_IN_GRAPHS_HIPERCONECTADOS_H
#define PATHS_IN_GRAPHS_HIPERCONECTADOS_H

#include "datastructures/graphs/Edge.h"
#include "datastructures/graphs/Graph.h"

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

SolutionEj1* Hiperconectados(Graph &graph);

#endif //PATHS_IN_GRAPHS_HIPERCONECTADOS_H
