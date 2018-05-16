//
// Created by dante on 16.05.18.
//

#include "AMatrixGraph.h"


Path AMatrixGraph::MinimumPath(Node start, Node finish){
    Path path = Path();
    return path;
};

bool AMatrixGraph::ExistsEdge(Node start, Node finish) {
    return this->adjacency_matrix[start][finish] != ;
}