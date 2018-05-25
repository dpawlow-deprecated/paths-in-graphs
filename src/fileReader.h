//
// Created by guido on 22/05/18.
//

#ifndef PATHS_IN_GRAPHS_FILEREADER_H
#define PATHS_IN_GRAPHS_FILEREADER_H

#include "datastructures/graphs/AListGraph.h"
#include "datastructures/graphs/AMatrixGraph.h"
#include <iostream>
#include <fstream>

class fileReader {
public:
    static void HiperconectadosReader(string from, AListGraph graph, bool is_directed);
    static void HiperconectadosReader(string from, AMatrixGraph graph, bool is_directed);
    static vector<int> HiperauditadosReader(string from, AListGraph graph, bool is_directed);
    static vector<int> HiperauditadosReader(string from, AMatrixGraph graph, bool is_directed);
    static Edge obtainNewEdge(ifstream& inputFile);
};

#endif //PATHS_IN_GRAPHS_FILEREADER_H
