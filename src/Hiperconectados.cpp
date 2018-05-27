#include "Hiperconectados.h"

#include "datastructures/graphs/AListGraph.h"
#include "algorithms/Kruskal.h"
#include "datastructures/UnionDisjointSet.h"

//Adaptation of Kruskal's algorithm.
//Finds if a given edge is present in every MST or if it can be present in some MSTs.
SolutionEj1* Hiperconectados(Graph &graph) {
    auto * solution = new SolutionEj1;

    UnionDisjointSet uds = UnionDisjointSet(graph.GetNumberOfNodes());
    auto * edges_ptr = GetEdges(graph);
    for (unsigned long i = 0; i < edges_ptr->size(); i++) {
        Node parent_start = uds.Find(edges_ptr->at(i).GetStartingNode());
        Node parent_finish = uds.Find(edges_ptr->at(i).GetFinishingNode());

        //Check if it creates a cycle
        if (parent_start != parent_finish) {
            bool is_unique = true;
            unsigned long j = i + 1;
            //Check every edge of the same weight that would form the same cycle
            while (j < edges_ptr->size() && edges_ptr->at(j).GetWeight() == edges_ptr->at(i).GetWeight()) {
                bool closes_same_loop = parent_start == uds.Find(edges_ptr->at(j).GetStartingNode());
                closes_same_loop &= parent_finish == uds.Find(edges_ptr->at(j).GetFinishingNode());
                if (closes_same_loop) {
                    solution->AddSometimesPresent(Edge(edges_ptr->at(j)));
                    is_unique = false;
                }
                j++;
            }

            if (is_unique) {
                solution->AddAlwaysPresent(Edge(edges_ptr->at(i))); //There can be only one
            } else {
                solution->AddSometimesPresent(Edge(edges_ptr->at(i)));
            }
            uds.Union(edges_ptr->at(i).GetStartingNode(), edges_ptr->at(i).GetFinishingNode());
        }
    }
    delete edges_ptr;
    return solution;
}