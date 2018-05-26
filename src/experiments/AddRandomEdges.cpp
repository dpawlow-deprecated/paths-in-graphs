#include "AddRandomEdges.h"

void AddRandomEdges(Graph &graph, int cantEdges, int minWeight, int maxWeight) {
    srand(time(NULL));

    Node randStartEdge;
    Node randEndEdge;

    for (int i = 0; i < cantEdges; ++i) {
        if(!isComplete(graph)){
            do {
                randStartEdge = rand() % graph.GetNumberOfNodes();
                randEndEdge = rand() % graph.GetNumberOfNodes();
            } while (graph.EdgeExists(randStartEdge, randEndEdge));

            graph.AddEdge(Edge(randStartEdge, randEndEdge, rand() % (maxWeight - minWeight + 1) + minWeight));
        } else {
            throw logic_error("Estas agregando mas ejes de los posibles");
        }
    }
}

bool isComplete(Graph &graph){
    for (Node i = 0; i < graph.GetNumberOfNodes(); ++i) {
        for (Node j = 0; j < graph.GetNumberOfNodes(); ++j) {
            if(!graph.EdgeExists(i,j)){
                return false;
            }
        }
    }
    return true;
}
