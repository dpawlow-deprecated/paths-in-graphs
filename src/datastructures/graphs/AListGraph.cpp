#include "AListGraph.h"

using namespace std;

void AListGraph::AddEdge(Edge const &edge) {
    adjacency_list[edge.GetStartingNode()].emplace_front(Edge(edge));
    adjacency_list[edge.GetStartingNode()].unique();
    if (!IsDirected()) {
        adjacency_list[edge.GetFinishingNode()].emplace_front(Edge(edge));
        adjacency_list[edge.GetFinishingNode()].unique();
    }
}

bool AListGraph::EdgeExists(Node start, Node finish) {
    for (auto it = adjacency_list[start].begin(); it != adjacency_list[start].end(); ++it ) {
        if (it->GetFinishingNode() == finish) {
            return true;
        }
    }
    return false;
}

Weight AListGraph::GetEdgeWeight(Node start, Node finish) {
    for (auto it = adjacency_list[start].begin(); it != adjacency_list[start].end(); ++it ) {
        if (it->GetFinishingNode() == finish) {
            return it->GetWeight();
        }
    }
    throw logic_error("Edge doesn't exist.");
}

bool AListGraph::IsDirected() {

}
bool AListGraph::IsWeighted() {

}

Path AListGraph::MinimumPath(Node start, Node finish) {

}

unique_ptr<Graph> AListGraph::MinimumSpanningTree() {

}