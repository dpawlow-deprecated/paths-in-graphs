#ifndef PATHS_IN_GRAPHS_TREEGENERATOR_H
#define PATHS_IN_GRAPHS_TREEGENERATOR_H

#include <vector>
#include <ctime>
#include <random>
#include <iostream>
#include "../datastructures/graphs/Edge.h"
using namespace std;

vector<Edge> TreeGenerator(int number_of_nodes, int minWeight, int maxWeight);
Node getNodeWithoutEdges( vector<pair<bool,bool >> &nodes_without_edges, Node start);
void checkValues( vector<pair<bool,bool >> &nodes_without_edges);
Node getStartNode(vector<pair<bool,bool >> &nodes_without_edges);
bool exists(vector<pair<bool,bool >> &nodes_without_edges, Node end, Node start);

#endif //PATHS_IN_GRAPHS_TREEGENERATOR_H
