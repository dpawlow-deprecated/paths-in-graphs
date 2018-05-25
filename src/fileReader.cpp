#include "fileReader.h"

AListGraph fileReader::HiperconectadosReaderToListGraph(string from, bool is_directed){

    ifstream inputFile;

    inputFile.open(from);
    int cantCiudades = 0;
    int cantPosiblesConexiones = 0;

    if (inputFile.is_open()) {

        inputFile >> cantCiudades;
        AListGraph graph = AListGraph(cantCiudades, is_directed);
        inputFile >> cantPosiblesConexiones;

        for (int j = 0; j < cantPosiblesConexiones; ++j) {
            graph.AddEdge(obtainNewEdge(inputFile));
        }

        inputFile.close();
        return graph;
    }

}

AMatrixGraph fileReader::HiperconectadosReaderToMatrixGraph(string from, bool is_directed) {

    ifstream inputFile;

    inputFile.open(from);
    int cantCiudades = 0;
    int cantPosiblesConexiones = 0;


    if (inputFile.is_open()) {

        inputFile >> cantCiudades;
        AMatrixGraph graph = AMatrixGraph(cantCiudades, is_directed);
        inputFile >> cantPosiblesConexiones;

        for (int j = 0; j < cantPosiblesConexiones; ++j) {
            graph.AddEdge(obtainNewEdge(inputFile));
        }

        inputFile.close();
        return graph;
    }


}

AListGraph fileReader::HiperauditadosReaderToListGraph(string from, vector<int> *oilCost, bool is_directed) {
    ifstream inputFile;

    inputFile.open(from);
    int cantCiudades = 0;
    int cantPosiblesConexiones = 0;

    vector<int>& oilCostValues = *oilCost;

    if (inputFile.is_open()) {

        inputFile >> cantCiudades;
        inputFile >> cantPosiblesConexiones;
        AListGraph graph = AListGraph(cantCiudades, is_directed);
        oilCostValues.assign(cantCiudades, 0);

        int cityOilCost;
        for (int i = 0; i < cantCiudades; ++i) {
            inputFile >> oilCostValues[i];
        }

        for (int j = 0; j < cantPosiblesConexiones; ++j) {
            graph.AddEdge(obtainNewEdge(inputFile));
        }

        inputFile.close();
        return graph;
    }

}

AMatrixGraph fileReader::HiperauditadosReaderToMatrixGraph(string from, vector<int> *oilCost, bool is_directed) {
    ifstream inputFile;

    inputFile.open(from);
    int cantCiudades = 0;
    int cantPosiblesConexiones = 0;

    vector<int>& oilCostValues = *oilCost;

    if (inputFile.is_open()) {

        inputFile >> cantCiudades;
        inputFile >> cantPosiblesConexiones;
        AMatrixGraph graph = AMatrixGraph(cantCiudades, is_directed);
        oilCostValues.assign(cantCiudades, 0);

        for (int i = 0; i < cantCiudades; ++i) {
            inputFile >> oilCostValues[i];
        }

        for (int j = 0; j < cantPosiblesConexiones; ++j) {
            graph.AddEdge(obtainNewEdge(inputFile));
        }

        inputFile.close();
        return graph;
    }

}

Edge fileReader::obtainNewEdge(ifstream& inputFile) {
    int edgeStart, edgeFinish, edgeWeight;
    inputFile >> edgeStart;
    inputFile >> edgeFinish;
    inputFile >> edgeWeight;
    return Edge(edgeStart, edgeFinish, edgeWeight);
}

