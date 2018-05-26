#include "treeGenerator.h"


vector<Edge> TreeGenerator(int number_of_nodes, int minWeight, int maxWeight){
    srand(time(NULL));
    vector<Edge> vector_graph;
    vector< pair<bool,bool> > nodes_without_edges;

    int number_of_edges = number_of_nodes - 1;

    for (Node j = 0; j < number_of_nodes; ++j) {
        nodes_without_edges.emplace_back(false,false);
    }

    for (Node i = 0; i < number_of_edges; i++) {
        Node random_node = getStartNode(nodes_without_edges);
        Node random_node_without_edge =  getNodeWithoutEdges(nodes_without_edges, random_node);
        vector_graph.emplace_back(Edge(random_node, random_node_without_edge, rand()%(maxWeight-minWeight + 1) + minWeight));
        nodes_without_edges[random_node_without_edge];
    }

    checkValues(nodes_without_edges);
    return vector_graph;
}

void checkValues( vector<pair<bool,bool >> &nodes_without_edges) {
    for (int k = 0; k < nodes_without_edges.size(); k++) {
        if (nodes_without_edges[k].first == false && nodes_without_edges[k].second == false) {
            throw "LA CAGAMOS";
        }
    }
}


Node getNodeWithoutEdges( vector<pair<bool,bool >> &nodes_without_edges, Node start){
    Node randNode;
    do{
        randNode = rand() % (nodes_without_edges.size());
    }while(nodes_without_edges[randNode].second || randNode == start);

    nodes_without_edges[randNode].second = true;
    return randNode;
}

Node getStartNode(vector<pair<bool,bool >> &nodes_without_edges){
    Node randNode = (Node) (rand() % (nodes_without_edges.size()));

    for (Node i = 0; i < nodes_without_edges.size(); ++i) {
        if (!nodes_without_edges[i].first && !nodes_without_edges[i].second) {
            randNode = i;
        }
    }
    nodes_without_edges[randNode].first = true;
    return randNode;
}