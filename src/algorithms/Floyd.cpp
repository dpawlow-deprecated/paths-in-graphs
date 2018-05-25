#include "Floyd.h"

AdjacencyMatrix FloydAlgorithm(AMatrixGraph matrixGraph) {
    AdjacencyMatrix matrix = matrixGraph.GetAdjacencyMatrix();
    unsigned long size = matrix.size();
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i != j && matrix[i][k].not_null && matrix[k][j].not_null) {
                    matrix[i][j].weight = minimum(matrix[i][j].weight, matrix[i][k].weight + matrix[k][j].weight);
                }
            }
        }
    }


    cout << "     " ;
    for (int i = 0; i < matrix.size(); ++i) {
        cout << i << "  | ";
    }
    cout << endl;
    for (int i = 0; i < matrix.size(); ++i) {
        cout << i << "  | ";
        for (int j = 0; j < matrix.size(); ++j) {
            if(matrix[i][j].weight < 10 && matrix[i][j].weight >=0) cout << 0;
            cout << matrix[i][j].weight;

            cout << " | ";

        }
        cout << endl;
    }

    return matrix;
}

Weight minimum(Weight first, Weight second){
    return min(first,second);
}