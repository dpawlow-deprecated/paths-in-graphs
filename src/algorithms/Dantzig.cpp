#include <climits>
#include "Dantzig.h"

AMatrixGraph DantzigAlgorithm(AMatrixGraph &matrixG) {
    AMatrixGraph matrixGraph = matrixG;
    for (Node k = 0; k < matrixGraph.GetNumberOfNodes()-1; k++) {
        for (Node i = 0; i <= k; i++) {
            if (i != k + 1) {
                if (matrixGraph.EdgeExists(i, k + 1)) {
                    matrixGraph.SetEdgeWeight(i, k + 1, getMinOf(matrixGraph, k, i, k + 1));
                } else {
                    matrixGraph.AddEdge(Edge(i, k + 1, getMinOf(matrixGraph, k, i, k + 1)));
                }

                if (matrixGraph.EdgeExists(k + 1, i)) {
                    matrixGraph.SetEdgeWeight(k + 1, i, getMinOf(matrixGraph, k, k + 1, i));
                } else {
                    matrixGraph.AddEdge(Edge(k + 1, i, getMinOf(matrixGraph, k, k + 1, i)));
                }
            }
        }

        for (Node i = 0; i < k; i++) {
            for (Node j = 0; j < k; j++) {
                if (i != j) {
                    if (matrixGraph.EdgeExists(i, j) && matrixGraph.EdgeExists(i, k + 1) && matrixGraph.EdgeExists(k + 1, j)) {
                        matrixGraph.SetEdgeWeight(i, j, min(matrixGraph.GetEdgeWeight(i, j), matrixGraph.GetEdgeWeight(i, k + 1) + matrixGraph.GetEdgeWeight(k + 1, j)));
                    } else {
                        matrixGraph.AddEdge(
                                Edge(i, j, matrixGraph.GetEdgeWeight(i, k + 1) + matrixGraph.GetEdgeWeight(k + 1, j)));
                    }
                }
            }
        }
    }

    return matrixGraph;
}

Weight getMinOf(AMatrixGraph &matrixGraph, int limit, Node rowValue, Node columnValue) {
    Weight result;

    if(matrixGraph.EdgeExists(rowValue,columnValue)) {
        result = matrixGraph.GetEdgeWeight(rowValue, columnValue);
    } else {
        result = LONG_MAX;
    }

    for (Node j = 0; j <= limit; j++) {
        if (matrixGraph.EdgeExists(rowValue, j) && matrixGraph.EdgeExists(j, columnValue)) {
            result = min(result, matrixGraph.GetEdgeWeight(rowValue, j) + matrixGraph.GetEdgeWeight(j, columnValue));
        }
    }
    return result;
}