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


void AMatrixGraph::PrintGraph(){
    cout << "     " ;
    for (int i = 0; i < adjacency_matrix.size(); ++i) {
        cout << i << "  | ";
    }
    cout << endl;
    for (int i = 0; i < adjacency_matrix.size(); ++i) {
        cout << i << "  | ";
        for (int j = 0; j < adjacency_matrix.size(); ++j) {
            if(adjacency_matrix[i][j].weight < 10 && adjacency_matrix[i][j].weight >= 0) cout << 0;
            cout << adjacency_matrix[i][j].weight;

                cout << " | ";

        }
        cout << endl;
    }
}

unsigned long AMatrixGraph::GetNumberOfNodes() const {
    return adjacency_matrix.size();
}

AdjacencyMatrix AMatrixGraph::GetAdjacencyMatrix() {
    return adjacency_matrix;
}

vector<Edge>::iterator AMatrixGraph::BeginEdgesIterator(Node node){

}
vector<Edge>::iterator AMatrixGraph::NextEdgesIterator(Node node, vector<Edge>::iterator it){

}

bool AMatrixGraph::HasNextEdgesIterator(Node node, vector<Edge>::iterator it){

}

unique_ptr<Graph> AMatrixGraph::MinimumSpanningTree(){

}


