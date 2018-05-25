#include "BellmanFord.h"

void BellmanFordAlgorithm(AListGraph listGraph){

    Weight costToNode [listGraph.GetNumberOfNodes()];
    costToNode[0] = 0;
    for(int i = 1; i < listGraph.GetNumberOfNodes(); i++) {
        costToNode[i] = LONG_MAX;
    }

    bool shouldContinue;
    for (int j = 0; j < listGraph.GetNumberOfNodes(); ++j) {
        auto it = listGraph.BeginEdgesIterator(j);
        shouldContinue = true;
        while(shouldContinue){
            costToNode[it->GetFinishingNode()] = min(costToNode[it->GetFinishingNode()],costToNode[j] + listGraph.GetEdgeWeight(j, it->GetFinishingNode()));
            if(listGraph.HasNextEdgesIterator(j, it)){
                listGraph.NextEdgesIterator(j, it);
            } else {
                shouldContinue = false;
            }
        }
    }
}