#ifndef PATHS_IN_GRAPHS_AMATRIXGRAPH_H
#define PATHS_IN_GRAPHS_AMATRIXGRAPH_H

#include <iostream>
#include "Graph.h"

class AMatrixGraph: public Graph {

private:
    struct MatrixEdge {
        bool not_null;
        Weight weight;

        MatrixEdge(){
            not_null = true;
            weight = 0;
        }

        explicit MatrixEdge(Weight w) {
            not_null = true;
            weight = w;
        }
    };

    using AdjacencyRow = vector<MatrixEdge>;
    using AdjacencyMatrix = vector<AdjacencyRow >;

    AdjacencyMatrix adjacency_matrix;
    bool is_directed;

public:
    AMatrixGraph(unsigned long n_of_nodes, bool is_directed);
    AMatrixGraph(vector<Edge> &edge, bool is_directed);
    explicit AMatrixGraph(Graph &graph);

    void AddEdge(Edge const &edge) override;
    bool EdgeExists(Node start, Node finish) override;
    bool EdgeInRange(Node start, Node finish) override;
    Weight GetEdgeWeight(Node start, Node finish) override;
    void SetEdgeWeight(Node start, Node finish, Weight weight);

    bool IsDirected() const override;
    unsigned long GetNumberOfNodes() const override;

    vector<Edge>::iterator BeginEdgesIterator(Node node) override;
    void NextEdgesIterator(Node node, vector<Edge>::iterator &it) override ;
    bool HasNextEdgesIterator(Node node, vector<Edge>::iterator it) override ;

    Path MinimumPath(Node start, Node finish) override;
    unique_ptr<Graph> MinimumSpanningTree() override;

    void PrintGraph();

};


#endif //PATHS_IN_GRAPHS_AMATRIXGRAPH_H
