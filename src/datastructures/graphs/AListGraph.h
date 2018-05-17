#ifndef PATHS_IN_GRAPHS_ALISTGRAPH_H
#define PATHS_IN_GRAPHS_ALISTGRAPH_H

#include <bits/forward_list.h>
#include "Graph.h"

using namespace std;

class AListGraph: public Graph {
private:
    struct ListNode {
        Node node;
        Weight edge_weight;

        ListNode(Node n, Weight w){
            node = n;
            edge_weight = w;
        }
    };

    vector<std::forward_list<ListNode>> adjacency_list;

public:
    void AddEdge(Edge const &edge) override;
    bool EdgeExists(Node start, Node finish) override;
    Weight GetEdgeWeight(Node start, Node finish) override;

    bool IsDirected() override;
    bool IsWeighted() override;

    Path MinimumPath(Node start, Node finish) override;
    unique_ptr<Graph> MinimumSpanningTree() override;
};


#endif //PATHS_IN_GRAPHS_ALISTGRAPH_H
