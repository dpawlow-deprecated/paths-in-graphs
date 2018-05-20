#include "AListGraph.h"

using namespace std;

AListGraph::AListGraph(unsigned long n_of_nodes, bool is_directed) {

}

AListGraph::AListGraph(Graph const &graph) {}

void AListGraph::AddEdge(Edge const &edge) {
    if (!EdgeExists(edge.GetStartingNode(), edge.GetFinishingNode())) {
        throw logic_error("Edge already exists");
    }
    adjacency_list[edge.GetStartingNode()].emplace_back(Edge(edge));
    if (!IsDirected()) {
        adjacency_list[edge.GetFinishingNode()].emplace_back(Edge(edge));
    }
}

bool AListGraph::EdgeInRange(Node start, Node finish) {
    return start < adjacency_list.size() && finish < adjacency_list.size();
};

bool AListGraph::EdgeExists(Node start, Node finish) {
    if (!EdgeInRange(start, finish)) {
        throw logic_error("Edge out of range.");
    }
    for (Edge &e : adjacency_list[start]) {
        if (e.GetFinishingNode() == finish) {
            return true;
        }
    }
    return false;
}

Weight AListGraph::GetEdgeWeight(Node start, Node finish) {
    if (!EdgeInRange(start, finish)) {
        throw logic_error("Edge out of range.");
    }
    for (Edge &e : adjacency_list[start]) {
        if (e.GetFinishingNode() == finish) {
            return e.GetWeight();
        }
    }
    throw logic_error("Edge doesn't exist.");
}

bool AListGraph::IsDirected() const {
    return is_directed;
}

unsigned long AListGraph::GetNumberOfNodes() const {
    return adjacency_list.size();
}

vector<Edge>::iterator AListGraph::GetEdgesBeginIterator(Node node) {
    return adjacency_list[node].begin();
}

vector<Edge>::iterator AListGraph::GetEdgesEndIterator(Node node) {
    return adjacency_list[node].end();
}


Path AListGraph::MinimumPath(Node start, Node finish) {

}

unique_ptr<Graph> AListGraph::MinimumSpanningTree() {

}