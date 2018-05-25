#include <set>
#include "Dijkstra.h"

Weight* Dijkstra(Graph &graph) {
    std::set<Node > unvisitedNodeSet;

    for(Node n = 0; n < graph.GetNumberOfNodes(); n++) {
        unvisitedNodeSet.insert(n);
    }

    Weight costToNode [graph.GetNumberOfNodes()];
    costToNode[0] = 0;

    for(Node n = 1; n < graph.GetNumberOfNodes(); n++) {
        if (graph.EdgeExists(0, n)) {
            costToNode[n] = graph.GetEdgeWeight(0, n);
        }
        else {
            costToNode[n] = LONG_MAX;
        }
    }

    while(!unvisitedNodeSet.empty()) {

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

    Weight* result = costToNode;
    return result;
}