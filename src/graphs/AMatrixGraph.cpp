//
// Created by dante on 16.05.18.
//

#include "AMatrixGraph.h"

Path AMatrixGraph::MinimumPath(Node start, Node finish){
    Path path = Path();
    return path;
};

bool AMatrixGraph::ExistsEdge(Node start, Node finish) {
    return this->adjacency_matrix[start][finish].is_connected;
}

bool AMatrixGraph::IsDirected() {
    return this->is_directed;
}

bool AMatrixGraph::IsWeighted() {
    return this->is_weighted;
}

Weight AMatrixGraph::GetEdgeWeight(Node start, Node finish) {
    if (adjacency_matrix[start][finish].is_connected) {
        return adjacency_matrix[start][finish].weight;
    } else {
        __throw_logic_error("Edge doesn't exist");
    }
}