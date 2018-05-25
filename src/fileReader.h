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
    static AListGraph HiperconectadosReaderToListGraph(string from, bool is_directed);
    static AMatrixGraph HiperconectadosReaderToMatrixGraph(string from, bool is_directed);
    static AListGraph HiperauditadosReaderToListGraph(string from, vector<int> *oilCost, bool is_directed);
    static AMatrixGraph HiperauditadosReaderToMatrixGraph(string from, vector<int> *oilCost, bool is_directed);
    static Edge obtainNewEdge(ifstream& inputFile);
};

#endif //PATHS_IN_GRAPHS_FILEREADER_H
