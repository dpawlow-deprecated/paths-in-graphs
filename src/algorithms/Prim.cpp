#include <set>
#include "Prim.h"


AListGraph& Prim(Graph &graph) {
    AListGraph result = AListGraph(graph.GetNumberOfNodes(), graph.IsDirected());
    std::set<Node > unvisitedNodeSet;

    for(Node n = 1; n < graph.GetNumberOfNodes(); n++) {
        unvisitedNodeSet.insert(n);
    }

    Weight costToNode [graph.GetNumberOfNodes()];
    costToNode[0] = 0;

    Edge bestEdges [graph.GetNumberOfNodes()];

    for(Node n = 1; n < graph.GetNumberOfNodes(); n++) {
        if (graph.EdgeExists(0, n)) {
            Weight weight = graph.GetEdgeWeight(0, n);
            costToNode[n] = weight;
            bestEdges[n] = Edge(0, n, weight);
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

        //add that node and the edge which connects to it
        unvisitedNodeSet.erase(smallestNode);
        result.AddEdge(bestEdges[smallestNode]);

        //find unvisited nodes adjacent to the smallest one
        for (auto unvisitedNodeIt = unvisitedNodeSet.begin(); unvisitedNodeIt != unvisitedNodeSet.end(); ++unvisitedNodeIt) {
            if(graph.EdgeExists(smallestNode, *unvisitedNodeIt)) {
                Weight costToUnvisitedNode = costToNode[*unvisitedNodeIt];
                Weight costFromSmallestNode = costToNode[smallestNode] + graph.GetEdgeWeight(smallestNode, *unvisitedNodeIt);
                if (costToUnvisitedNode > costFromSmallestNode) {
                    costToNode[*unvisitedNodeIt] = costFromSmallestNode;
                    bestEdges[*unvisitedNodeIt] = Edge(smallestNode, *unvisitedNodeIt);
                }
            }
        }
    }

    return result;
}
