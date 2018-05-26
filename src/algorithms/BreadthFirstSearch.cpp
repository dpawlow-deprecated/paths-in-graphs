#include <queue>
#include "BreadthFirstSearch.h"
#include "../datastructures/graphs/Graph.h"



void BFS(Graph &graph, Node source) {
    vector<BFSNode> node_info = vector<BFSNode>(graph.GetNumberOfNodes(), BFSNode());
    node_info[source].SetColor(Gray);
    node_info[source].SetDistance(0);

    priority_queue queue = priority_queue();
    queue.push(source);
    while (!queue.empty()) {
        Node u = queue.top();
        queue.pop();

        auto edges_it = graph.BeginEdgesIterator(u);
        while (graph.HasNextEdgesIterator(u, edges_it)) {
            if (node_info[edges_it->GetFinishingNode()].color == White) {
                node_info[edges_it->GetFinishingNode()].SetColor(Gray);
                node_info[edges_it->GetFinishingNode()].SetDistance(node_info[u].distance + 1);
                node_info[edges_it->GetFinishingNode()].SetParent(u);
                queue.push(edges_it->GetFinishingNode());
            }
            graph.NextEdgesIterator(u, edges_it);
        }
        node_info[u].SetColor(Black);
    }
}