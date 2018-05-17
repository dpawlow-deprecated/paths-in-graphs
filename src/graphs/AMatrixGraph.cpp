#include "AMatrixGraph.h"

void AMatrixGraph::AddEdge(Edge const &edge) {
    if (EdgeExists(edge.GetStartingNode(), edge.GetFinishingNode())) {
        throw logic_error("Edge already exists.");
    }
    adjacency_matrix[edge.GetStartingNode()][edge.GetFinishingNode()] = MatrixEdge(edge.GetWeight());
    if (!IsDirected()) {
        adjacency_matrix[edge.GetFinishingNode()][edge.GetStartingNode()] = MatrixEdge(edge.GetWeight());
    }

}

Path AMatrixGraph::MinimumPath(Node start, Node finish){
    Path path = Path();
    return path;
};

bool AMatrixGraph::EdgeExists(Node start, Node finish) {
    return adjacency_matrix[start][finish].is_connected;
}

bool AMatrixGraph::IsDirected() {
    return is_directed;
}

bool AMatrixGraph::IsWeighted() {
    return is_weighted;
}

Weight AMatrixGraph::GetEdgeWeight(Node start, Node finish) {
    if (EdgeExists(start, finish)) {
        return adjacency_matrix[start][finish].weight;
    } else {
        throw logic_error("Edge doesn't exist.");
    }
}