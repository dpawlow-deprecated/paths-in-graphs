#include "AMatrixGraph.h"


AMatrixGraph::AMatrixGraph(unsigned long n_of_nodes, bool is_directed) {
    AdjacencyRow row = vector<MatrixEdge>(n_of_nodes, MatrixEdge());
    this->adjacency_matrix = vector<AdjacencyRow>(n_of_nodes, row);
    this->is_directed = is_directed;
}

AMatrixGraph::AMatrixGraph(Graph &graph) {
    this->is_directed = graph.IsDirected();

    AMatrixGraph new_graph = AMatrixGraph(graph.GetNumberOfNodes(), graph.IsDirected());
    for (unsigned long i = 0; i < graph.GetNumberOfNodes(); i++) {
        for(auto it = graph.BeginEdgesIterator(i); it != graph.BeginEdgesIterator(i); ++it) {
            AddEdge(*it);
        }
    }
}

void AMatrixGraph::AddEdge(Edge const &edge) {
    if (!EdgeExists(edge.GetStartingNode(), edge.GetFinishingNode())) {
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
    if (EdgeInRange(start, finish)) {
        return adjacency_matrix[start][finish].not_null;
    } else {
        throw logic_error("Edge out of range");
    }
}

bool AMatrixGraph::EdgeInRange(Node start, Node finish) {
    return start < GetNumberOfNodes() && finish < GetNumberOfNodes();
}

bool AMatrixGraph::IsDirected() const {
    return is_directed;
}

Weight AMatrixGraph::GetEdgeWeight(Node start, Node finish) {
    if (EdgeExists(start, finish)) {
        return adjacency_matrix[start][finish].weight;
    } else {
        throw logic_error("Edge doesn't exist.");
    }
}

unsigned long AMatrixGraph::GetNumberOfNodes() const {
    return adjacency_matrix.size();
}