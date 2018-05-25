#include <queue>
#include "DijkstraPQ.h"


struct SmallerWeightedNode {
    bool operator()(const pair<Node, Weight>& left, const pair<Node, Weight>& right) {
        return left.second > right.second;
    }
};

Weight* DijkstraPQ(Graph &graph) {
    std::vector<pair<Node, Weight>> nodeSet;
    priority_queue<pair<Node, Weight >, vector<pair<Node, Weight >>, SmallerWeightedNode > unvisitedNodeSet;

    Weight costToNode [graph.GetNumberOfNodes()];

    unvisitedNodeSet.push(make_pair(Node(0), Weight(0)));
    costToNode[0] = 0;

    for(Node n = 1; n < graph.GetNumberOfNodes(); n++) {
        if (graph.EdgeExists(0, n)) {
            unvisitedNodeSet.push(make_pair(n, graph.GetEdgeWeight(0, n)));
            costToNode[n] = graph.GetEdgeWeight(0, n);
        }
        else {
            unvisitedNodeSet.push(make_pair(n, LONG_MAX));
            costToNode[n] = LONG_MAX;
        }
    }

    while(unvisitedNodeSet.size() != 0) {

        //find node with smallest cost
        pair<Node, Weight > smallestNode = unvisitedNodeSet.top();
        unvisitedNodeSet.pop();

        if (costToNode[smallestNode.first] < smallestNode.second) continue;

        //find unvisited nodes adjacent to the smallest one
        auto adjacentIt = graph.BeginEdgesIterator(smallestNode.first);
        while(graph.HasNextEdgesIterator(smallestNode.first, adjacentIt)) {
            Weight costToUnvisitedNode = costToNode[adjacentIt->GetFinishingNode()];
            Weight costFromSmallestNode = costToNode[smallestNode.first] + adjacentIt->GetWeight();
            if (costToUnvisitedNode > costFromSmallestNode) {
                costToNode[adjacentIt->GetFinishingNode()] = costFromSmallestNode;

                unvisitedNodeSet.push(make_pair(adjacentIt->GetFinishingNode(), adjacentIt->GetWeight()));
            }
        }
    }

    Weight* result = costToNode;
    return result;
}