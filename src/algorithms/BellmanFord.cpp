#include "BellmanFord.h"

Weight* BellmanFordAlgorithm(AListGraph listGraph){

    Weight costToNode [listGraph.GetNumberOfNodes()];
    costToNode[0] = 0;
    for(int i = 1; i < listGraph.GetNumberOfNodes(); i++) {
        costToNode[i] = LONG_MAX;
    }

    for (int j = 0; j < listGraph.GetNumberOfNodes(); ++j) {
        auto it = listGraph.BeginEdgesIterator(j);
        while(listGraph.HasNextEdgesIterator(j, it)){
            costToNode[it->GetFinishingNode()] = min(costToNode[it->GetFinishingNode()],costToNode[j] + listGraph.GetEdgeWeight(j, it->GetFinishingNode()));
            listGraph.NextEdgesIterator(j, it);
        }
    }
    return costToNode;
}