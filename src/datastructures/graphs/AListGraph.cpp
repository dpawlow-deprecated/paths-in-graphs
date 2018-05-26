#include "AListGraph.h"

using namespace std;

AListGraph::AListGraph(unsigned long n_of_nodes, bool is_directed) {
    vector<Edge> empty;
    adjacency_list.assign(n_of_nodes,empty);
    this->is_directed = is_directed;
}

AListGraph::AListGraph(const vector<Edge> &edges, unsigned long n_of_nodes, bool is_directed) {
    vector<Edge> empty;
    adjacency_list.assign(n_of_nodes,empty);
    for (Edge const &edge : edges) {
        AddEdge(edge);
    }
    this->is_directed = is_directed;
}

AListGraph::AListGraph(Graph const &graph) {}

void AListGraph::AddEdge(Edge const &edge) {
    if (EdgeExists(edge.GetStartingNode(), edge.GetFinishingNode())) {
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

vector<Edge>::iterator AListGraph::BeginEdgesIterator(Node node) {
    return adjacency_list[node].begin();
}

void AListGraph::NextEdgesIterator(Node node, vector<Edge>::iterator &it) {
    if (!HasNextEdgesIterator(node, it)) {
        throw logic_error("Doesn't have next iterator");
    }
    advance(it, 1);
}

bool AListGraph::HasNextEdgesIterator(Node node, vector<Edge>::iterator it) {
    return it != adjacency_list[node].end();
}

Path AListGraph::MinimumPath(Node start, Node finish) {

}

unique_ptr<Graph> AListGraph::MinimumSpanningTree() {

}

void AListGraph::PrintGraph() {
    cout << "     " ;
    for (Node i = 0; i < this->GetNumberOfNodes(); ++i) {
        cout << "\n" << i << "->";
        auto it = this->BeginEdgesIterator(i);
        while(this->HasNextEdgesIterator(i, it)) {
            cout << it->GetFinishingNode();
            this->NextEdgesIterator(i, it);
            if (this->HasNextEdgesIterator(i, it)) {
                cout << ",";
            }
        }
    }
    cout << endl;

}