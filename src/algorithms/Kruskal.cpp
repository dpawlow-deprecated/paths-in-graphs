#include <algorithm>
#include "Kruskal.h"
#include "../datastructures/UnionDisjointSet.h"

bool EdgeIsLighter(Edge const &e1, Edge const &e2) {
    return e1.GetWeight() < e2.GetWeight();
};

AListGraph* KruskalPathCompression(Graph &graph) {
    auto * agm_ptr = new AListGraph(graph.GetNumberOfNodes(), false);
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
            agm_ptr->AddEdge(e);
            uds.Union(e.GetStartingNode(), e.GetFinishingNode());
        }
    }

    return agm_ptr;
}
