#include "AddRandomEdges.h"

void AddRandomEdges(Graph &graph, int cantNodes, int minWeight, int maxWeight) {
    srand(time(NULL));

    Node randStartEdge;
    Node randEndEdge;

    for (int i = 0; i < cantNodes; ++i) {
        if(!isComplete(graph)){
            do {
                randStartEdge = rand() % graph.GetNumberOfNodes();
                randEndEdge = rand() % graph.GetNumberOfNodes();
            } while (graph.EdgeExists(randStartEdge, randEndEdge));

            graph.AddEdge(Edge(randStartEdge, randEndEdge, rand() % (maxWeight - minWeight + 1) + minWeight));
        } else {
            break;
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
