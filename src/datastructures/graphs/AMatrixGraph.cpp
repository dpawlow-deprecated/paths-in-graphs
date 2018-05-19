#include "AMatrixGraph.h"


AMatrixGraph::AMatrixGraph(unsigned long n_of_nodes, bool is_directed) {
    AdjacencyRow row = vector(n_of_nodes, MatrixEdge());
    this->adjacency_matrix = vector(n_of_nodes, row);
    this->is_directed = is_directed;
}

AMatrixGraph::AMatrixGraph(Graph graph) {
    this->is_directed = graph.IsDirected();

    AMatrixGraph new_graph = AMatrixGraph(graph.GetNumberOfNodes(), graph.IsDirected());
    auto edges_iterator = graph.GetEdgesBeginIterator(0);

    while (edges_iter.)

    for (Edge &edge: graph. {
        this->AddEdge(edge);
    }
}


void AMatrixGraph::AddEdge(Edge const &edge) {
    if (EdgeExists(edge.GetStartingNode(), edge.GetFinishingNode())) {
        throw logic_error("Edge already exists.");
    }

    if (edge.GetStartingNode() >= ) {

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
    if (EdgeInRange(start, finish)) {
        return adjacency_matrix[start][finish].not_null;
    } else {
        throw logic_error("Edge out of range");
    }
}

bool AMatrixGraph::EdgeInRange(Node start, Node finish) {
    return start < GetNumberOfNodes() && finish < GetNumberOfNodes();
}

bool AMatrixGraph::IsDirected() {
    return is_directed;
}

Weight AMatrixGraph::GetEdgeWeight(Node start, Node finish) {
    if (EdgeExists(start, finish)) {
        return adjacency_matrix[start][finish].weight;
    } else {
        throw logic_error("Edge doesn't exist.");
    }
}

unsigned long AMatrixGraph::GetNumberOfNodes() {
    return adjacency_matrix.size();
};