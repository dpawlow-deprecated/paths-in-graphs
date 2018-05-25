#include "Floyd.h"

AMatrixGraph FloydAlgorithm(AMatrixGraph &matrixG) {
    AMatrixGraph matrixGraph = matrixG;
    unsigned long size = matrixGraph.GetNumberOfNodes();
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i != j && k != j && matrixGraph.EdgeExists(i,k) && matrixGraph.EdgeExists(k,j)) {
                    Weight peso = matrixGraph.GetEdgeWeight(i,k);
                    Weight peso2 = matrixGraph.GetEdgeWeight(k,j);
                    if(matrixGraph.EdgeExists(i,j)){
                        Weight peso3 = matrixGraph.GetEdgeWeight(i,j);
                        matrixGraph.SetEdgeWeight(i,j, minimum(matrixGraph.GetEdgeWeight(i,j), matrixGraph.GetEdgeWeight(i,k) +  matrixGraph.GetEdgeWeight(k,j)));
                    } else {
                        matrixGraph.AddEdge(Edge(i,j, matrixGraph.GetEdgeWeight(i,k) +  matrixGraph.GetEdgeWeight(k,j)));
                    }
                }
            }
        }
    }

    matrixGraph.PrintGraph();
    return matrixGraph;
}

Weight minimum(Weight first, Weight second){
    return min(first,second);
}