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
    static AListGraph HiperauditadosReaderToListGraph(string from, vector<int> *oil_cost, bool is_directed);
    static AMatrixGraph HiperauditadosReaderToMatrixGraph(string from, vector<int> *oil_cost, bool is_directed);
    static Edge ObtainNewEdge(ifstream& input_file);
};

#endif //PATHS_IN_GRAPHS_FILEREADER_H
