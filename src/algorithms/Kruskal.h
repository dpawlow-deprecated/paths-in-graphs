#ifndef PATHS_IN_GRAPHS_KRUSKAL_H
#define PATHS_IN_GRAPHS_KRUSKAL_H

#include <algorithm>
#include "../datastructures/graphs/AListGraph.h"
#include "../datastructures/UnionDisjointSet.h"

bool EdgeIsLighter(Edge const &e1, Edge const &e2) {
    return e1.GetWeight() < e2.GetWeight();
};

AListGraph KruskalPathCompression(Graph &graph) {
    AListGraph agm = AListGraph(graph.GetNumberOfNodes(), false);
    UnionDisjointSet uds = UnionDisjointSet(graph.GetNumberOfNodes());

    vector<Edge> edges;
    for (unsigned long i = 0; i < graph.GetNumberOfNodes(); i++) {
        auto it = graph.BeginEdgesIterator(i);
        while (graph.HasNextEdgesIterator(i, it)) {
            edges.emplace_back(Edge(*it));
            it = graph.NextEdgesIterator(i, it);
        }
    }

    sort(edges.begin(), edges.end(), EdgeIsLighter);

    for (Edge &e : edges) {
        if (uds.Find(e.GetStartingNode()) != uds.Find(e.GetFinishingNode())) {
            agm.AddEdge(e);
            uds.Union(e.GetStartingNode(), e.GetFinishingNode());
        }
    }
}


#endif //PATHS_IN_GRAPHS_KRUSKAL_H
