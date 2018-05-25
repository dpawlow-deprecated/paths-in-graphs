#include "Dantzig.h"


AMatrixGraph DantzigAlgorithm(AMatrixGraph &matrixG) {
    AMatrixGraph matrixGraph = matrixG;

    for (int k = 0; k < n - 1; ++k) {

        for (int i = 0; i < k; ++i) {

            if (matrixGraph.EdgeExists(i, j)) {
                matrixGraph.SetEdgeWeight(i, k + 1) = getMinOf(i, k, i, k + 1);
            } else {
                matrixGraph.AddEdge(Edge(i, k + 1, getMinOf(i, k, i, k + 1)));
            }

            if (matrixGraph.EdgeExists(i, j)) {
                matrixGraph.SetEdgeWeight(k + 1, i) = getMinOf(i, k, k + 1, i);
            } else {
                matrixGraph.AddEdge(Edge(k + 1, i, getMinOf(i, k, k + 1, i)));
            }
        }

        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (matrixGraph.EdgeExists(i, j)) {
                    matrixGraph.SetEdgeWeight(i, j) = min(matrixGraph.GetEdgeWeight(i, j),
                                                          matrixGraph.GetEdgeWeight(i, k + 1) +
                                                          matrixGraph.GetEdgeWeight(k + 1, j));
                } else {
                    matrixGraph.AddEdge(
                            Edge(i, j, matrixGraph.GetEdgeWeight(i, k + 1) + matrixGraph.GetEdgeWeight(k + 1, j)));
                }
            }
        }
    }
    matrixGraph.PrintGraph();
}
