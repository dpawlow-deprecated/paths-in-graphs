#include "treeGenerator.h"

vector<Edge> vector_graph;

vector<Edge> TreeGenerator(int number_of_nodes, int minWeight, int maxWeight){
    srand(time(NULL));

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

bool exists(vector<pair<bool,bool >> &nodes_without_edges, Node end, Node start){
    for (int i = 0; i < vector_graph.size(); ++i) {
        if((vector_graph[i].GetStartingNode() == start && vector_graph[i].GetFinishingNode() == end) ||
                (vector_graph[i].GetStartingNode() == end && vector_graph[i].GetFinishingNode() == start)){
            return true;
        }
    }
    return false;
}

Node getNodeWithoutEdges( vector<pair<bool,bool >> &nodes_without_edges, Node start){
    Node randNode;
    do{
        randNode = rand() % (nodes_without_edges.size());
    }while(nodes_without_edges[randNode].second || exists(nodes_without_edges,randNode,start) || randNode == start);

    nodes_without_edges[randNode].second = true;
    return randNode;
}

Node getStartNode(vector<pair<bool,bool >> &nodes_without_edges){
    Node randNode = (Node) (rand() % (nodes_without_edges.size()));

    if (!(!nodes_without_edges[randNode].first && !nodes_without_edges[randNode].second)){
        for (Node i = 0; i < nodes_without_edges.size(); ++i) {
            if (!nodes_without_edges[i].first && !nodes_without_edges[i].second) {
                randNode = i;
            }
        }
    }
    nodes_without_edges[randNode].first = true;
    return randNode;
}

void checkValues( vector<pair<bool,bool >> &nodes_without_edges) {
    for (int k = 0; k < nodes_without_edges.size(); k++) {
        if (!nodes_without_edges[k].first && !nodes_without_edges[k].second) {
            throw logic_error("LA CAGAMOS");
        }
    }
}