#include "Floyd.h"

AdjacencyMatrix floydAlgorithm(AMatrixGraph matrixGraph) {
    AdjacencyMatrix matrix = matrixGraph.GetAdjacencyMatrix();
    unsigned long size = matrix.size();
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i != j && matrix[i][k].weight != 0 && matrix[k][j].weight != 0) {
                    matrix[i][j].weight = minimum(matrix[i][j].weight, matrix[i][k].weight + matrix[k][j].weight);
                }
            }
        }
    }
    return matrix;
}

Weight minimum(Weight first, Weight second){
    if(first == 0){
        return second;
    }

    if(second == 0){
        return first;
    }
    return min(first,second);
}