#include <set>
#include "Prim.h"


AListGraph& Prim(Graph &graph) {
    AListGraph result = AListGraph(graph.GetNumberOfNodes(), graph.IsDirected());
    std::set<Node > visitedNodeSet;
    visitedNodeSet.insert(0);

    while(0 < graph.GetNumberOfNodes()) {
        vector<Edge>::iterator smallestEdge;
        Weight smallestWeight = LONG_MAX;

        //for each already visited node
        for(auto visitedNodeIt = visitedNodeSet.begin(); visitedNodeIt != visitedNodeSet.end(); ++visitedNodeIt) {
            vector<Edge>::iterator edgeIt = graph.BeginEdgesIterator(*visitedNodeIt);

            //for all its edges
            while(graph.HasNextEdgesIterator(*visitedNodeIt, edgeIt)) {

                //if its finishing node wasn't visited already, see if it is the smallest one
                if(visitedNodeSet.find(edgeIt->GetFinishingNode()) == visitedNodeSet.end()) {
                    if(smallestWeight > edgeIt->GetWeight()) {
                        smallestEdge = edgeIt;
                        smallestWeight = edgeIt->GetWeight();
                    }
                }
                graph.NextEdgesIterator(*visitedNodeIt, edgeIt);
            }
            visitedNodeSet.insert(smallestEdge->GetFinishingNode());
            result.AddEdge(*smallestEdge);
        }
    }

    return result;
}
