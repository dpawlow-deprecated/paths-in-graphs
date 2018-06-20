#include "Hiperconectados.h"

long GetEdgeWeightSum(Graph &graph) {
    long weight_sum = 0;
    for (unsigned long i = 0; i < graph.GetNumberOfNodes(); i++) {
        for(auto it = graph.BeginEdgesIterator(i); it != graph.BeginEdgesIterator(i); ++it) {
            if (it->GetFinishingNode() > i) {
                weight_sum += it->GetWeight();
            }
        }
    }
    return weight_sum;
}

bool EdgeAlwaysPresent(Graph &graph, Edge const &e, long unaltered_mst_weight, AListGraph* GetMST(Graph)) {
    Graph graph_without_e = AListGraph(graph);
    graph_without_e.RemoveEdge(e);

    Graph* mst_without_e = GetMST(graph_without_e);
    long mst_without_e_weight = GetEdgeWeightSum(*mst_without_e);

    return unaltered_mst_weight < mst_without_e_weight;
}

SolutionEj1* Hiperconectados(Graph &graph, AListGraph* GetMST(Graph)) {
    SolutionEj1 solution = SolutionEj1();

    Graph* unaltered_mst = GetMST(graph);
    long unaltered_mst_weight = GetEdgeWeightSum(*unaltered_mst);

    for (unsigned long i = 0; i < graph.GetNumberOfNodes(); i++) {
        for(auto it = graph.BeginEdgesIterator(i); it != graph.BeginEdgesIterator(i); ++it) {
            if (it->GetFinishingNode() > i) {
                if (EdgeAlwaysPresent(graph, *it, unaltered_mst_weight, GetMST)) {
                    solution.AddAlwaysPresent(*it);
                } else if (EdgeSometimesPresent()) {

                }

            }
        }
    }
}

