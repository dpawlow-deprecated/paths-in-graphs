#include "Floyd.h"

AMatrixGraph FloydAlgorithm(AMatrixGraph &matrixG) {
    AMatrixGraph matrixGraph = matrixG;
    Node size = matrixGraph.GetNumberOfNodes();
    for (Node k = 0; k < size; k++) {
        for (Node i = 0; i < size; i++) {
            for (Node j = 0; j < size; j++) {
                if (i != j && k != j && matrixGraph.EdgeExists(i,k) && matrixGraph.EdgeExists(k,j)) {
                    if(matrixGraph.EdgeExists(i,j)){
                        matrixGraph.SetEdgeWeight(i,j, min(matrixGraph.GetEdgeWeight(i,j), matrixGraph.GetEdgeWeight(i,k) +  matrixGraph.GetEdgeWeight(k,j)));
                    } else {
                        matrixGraph.AddEdge(Edge(i,j, matrixGraph.GetEdgeWeight(i,k) +  matrixGraph.GetEdgeWeight(k,j)));
                    }
                }
            }
        }
    }
    return matrixGraph;
}