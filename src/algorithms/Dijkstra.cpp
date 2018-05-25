#include <set>
#include "Dijkstra.h"

Weight* Dijkstra(Graph &graph) {
    AListGraph result = AListGraph(graph.GetNumberOfNodes(), graph.IsDirected());
    std::set<Node > unvisitedNodeSet;

    for(int i = 1; i < graph.GetNumberOfNodes(); i++) {
        unvisitedNodeSet.insert(Node(i));
    }

    Weight costToNode [graph.GetNumberOfNodes()];
    costToNode[0] = 0;

    for(int i = 1; i < graph.GetNumberOfNodes(); i++) {
        if (graph.EdgeExists(0, i)) {
            costToNode[i] = graph.GetEdgeWeight(0, i);
        }
        else {
            costToNode[i] = LONG_MAX;
        }
    }

    while(unvisitedNodeSet.size() != 0) {

        //find node with smallest cost
        Weight smallestWeight = LONG_MAX;
        Node smallestNode = graph.GetNumberOfNodes() + 1;
        for (auto unvisitedNodeIt = unvisitedNodeSet.begin(); unvisitedNodeIt != unvisitedNodeSet.end(); ++unvisitedNodeIt) {
            if(smallestWeight > costToNode[*unvisitedNodeIt]) {
                smallestNode = *unvisitedNodeIt;
                smallestWeight = costToNode[*unvisitedNodeIt];
            }
        }
        unvisitedNodeSet.erase(smallestNode);

        //find unvisited nodes adjacent to the smallest one
        for (auto unvisitedNodeIt = unvisitedNodeSet.begin(); unvisitedNodeIt != unvisitedNodeSet.end(); ++unvisitedNodeIt) {
            if(graph.EdgeExists(smallestNode, *unvisitedNodeIt)) {
                Weight costToUnvisitedNode = costToNode[*unvisitedNodeIt];
                Weight costFromSmallestNode = costToNode[smallestNode] + graph.GetEdgeWeight(smallestNode, *unvisitedNodeIt);
                if (costToUnvisitedNode > costFromSmallestNode) {
                    costToNode[*unvisitedNodeIt] = costFromSmallestNode;
                }
            }
        }
    }
    
    return costToNode;
}