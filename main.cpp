#include "src/fileReader.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "src/datastructures/graphs/AListGraph.h"

int main(int argc, char *argv[]) {

    int selector;
    bool is_directed;
    if (argc >= 1) {
        selector = atoi(argv[1]);
        is_directed = (bool) atoi(argv[2]);
    } else {
        cout << "Faltan parametros" << endl;
        return 0;
    }

    // Leer el archivo del tercer argumento
    AMatrixGraph aMatrixGraph = AMatrixGraph(0, true);
    AListGraph listGraph = AListGraph(0, true);

    if (selector == 1) {
        fileReader::HiperconectadosReader(
                "/home/guido/Escritorio/Algo3/paths-in-graphs/src/testFIles/hiperconectados.txt", listGraph,
                is_directed);
    }

    if (selector == 2) {
        fileReader::HiperconectadosReader(
                "/home/guido/Escritorio/Algo3/paths-in-graphs/src/testFIles/hiperconectados.txt", aMatrixGraph,
                is_directed);
    }

    if (selector == 3) {
        fileReader::HiperauditadosReader(
                "/home/guido/Escritorio/Algo3/paths-in-graphs/src/testFIles/hiperauditados.txt", listGraph,
                is_directed);
    }

    if (selector == 4) {
        fileReader::HiperauditadosReader(
                "/home/guido/Escritorio/Algo3/paths-in-graphs/src/testFIles/hiperauditados.txt", aMatrixGraph,
                is_directed);
    }


}