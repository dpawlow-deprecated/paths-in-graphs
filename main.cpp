#include "src/fileReader.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <zconf.h>
#include "src/datastructures/graphs/AListGraph.h"
#include "src/algorithms/Floyd.h"

string getActualDir(){
    char wd[256];
    getcwd( wd, 256 );
    string cwd2 = wd;
    return cwd2.substr(0,cwd2.size()-18) + "/src";
}

int main(int argc, char *argv[]) {

    int selector;
    bool is_directed;
    string file;

    if (argc >= 1 and argc <= 4) {
        selector = atoi(argv[1]);
        is_directed = argv[2];
        file = argv[3];
    } else {
        cout << "Faltan parametros" << endl;
        return 0;
    }

    AMatrixGraph aMatrixGraph = AMatrixGraph(0,true);
    AListGraph listGraph = AListGraph(0,true);

    string strFile = getActualDir() + file;


    if (selector == 1) {
        listGraph = fileReader::HiperconectadosReaderToListGraph(
                strFile,
                is_directed);
    }

    if (selector == 2) {
        aMatrixGraph = fileReader::HiperconectadosReaderToMatrixGraph(
                strFile,
                is_directed);
        aMatrixGraph.PrintGraph();
    }

    vector<int> *oil_cost = new vector<int>;
    if (selector == 3) {
        listGraph = fileReader::HiperauditadosReaderToListGraph(
                strFile, oil_cost,
                is_directed);
    }

    if (selector == 4) {
        aMatrixGraph = fileReader::HiperauditadosReaderToMatrixGraph(
                strFile, oil_cost,
                is_directed);
        aMatrixGraph.PrintGraph();
    }
}