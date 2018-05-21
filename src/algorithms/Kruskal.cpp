#include <algorithm>
#include "Kruskal.h"
#include "../datastructures/UnionDisjointSet.h"

bool EdgeIsLighter(Edge const &e1, Edge const &e2) {
    return e1.GetWeight() < e2.GetWeight();
};

vector<Edge>* GetEdges(Graph &graph) {
    auto * edges_ptr = new vector<Edge>;
    for (unsigned long i = 0; i < graph.GetNumberOfNodes(); i++) {
        auto it = graph.BeginEdgesIterator(i);
        while (graph.HasNextEdgesIterator(i, it)) {
            edges_ptr->emplace_back(Edge(*it));
            it = graph.NextEdgesIterator(i, it);
        }
    }
    sort(edges_ptr->begin(), edges_ptr->end(), EdgeIsLighter);
    return edges_ptr;
}

AListGraph* KruskalPathCompression(Graph &graph) {
    auto * agm_ptr = new AListGraph(graph.GetNumberOfNodes(), false);
    UnionDisjointSet uds = UnionDisjointSet(graph.GetNumberOfNodes());

    auto * edges_ptr = GetEdges(graph);
    for (Edge &e : *edges_ptr) {
        if (uds.Find(e.GetStartingNode()) != uds.Find(e.GetFinishingNode())) {
            agm_ptr->AddEdge(e);
            uds.Union(e.GetStartingNode(), e.GetFinishingNode());
        }
    }
    delete edges_ptr;
    return agm_ptr;
}

AListGraph* KruskalWithLists(Graph &graph) {
    auto * agm_ptr = new AListGraph(graph.GetNumberOfNodes(), false);

}
