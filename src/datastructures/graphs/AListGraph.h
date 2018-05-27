#ifndef PATHS_IN_GRAPHS_ALISTGRAPH_H
#define PATHS_IN_GRAPHS_ALISTGRAPH_H

#include <bits/forward_list.h>
#include "Graph.h"
#include <iostream>

using namespace std;

class AListGraph: public Graph {
private:
    vector<vector<Edge>> adjacency_list;
    bool is_directed;

public:
    AListGraph(unsigned long n_of_nodes, bool is_directed);
    AListGraph(const vector<Edge> &edges, unsigned long n_of_nodes, bool is_directed);
    AListGraph(Graph const &graph);

    void AddEdge(Edge const &edge) override;
    bool EdgeExists(Node start, Node finish) override;
    bool EdgeInRange(Node start, Node finish) override;
    Weight GetEdgeWeight(Node start, Node finish) override;

    bool IsDirected() const override;

    unsigned long GetNumberOfNodes() const override;
    vector<Edge>::iterator BeginEdgesIterator(Node node) override;
    void NextEdgesIterator(Node node, vector<Edge>::iterator &it) override;
    bool HasNextEdgesIterator(Node node, vector<Edge>::iterator it) override;


    Path MinimumPath(Node start, Node finish) override;
    unique_ptr<Graph> MinimumSpanningTree() override;

    void PrintGraph();
};


#endif //PATHS_IN_GRAPHS_ALISTGRAPH_H
