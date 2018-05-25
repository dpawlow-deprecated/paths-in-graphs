#include "fileReader.h"

AListGraph* fileReader::HiperconectadosReaderToListGraph(string from, bool is_directed){

    ifstream inputFile;

    inputFile.open(from);
    int cant_ciudades = 0;
    int cant_posibles_conexiones = 0;

    if (inputFile.is_open()) {

        inputFile >> cant_ciudades;
        AListGraph* graph = new AListGraph(cant_ciudades, is_directed);
        inputFile >> cant_posibles_conexiones;

        for (int j = 0; j < cant_posibles_conexiones; ++j) {
            graph->AddEdge(obtainNewEdge(inputFile));
        }

        inputFile.close();
        return graph;
    }

}

AMatrixGraph* fileReader::HiperconectadosReaderToMatrixGraph(string from, bool is_directed) {

    ifstream inputFile;

    inputFile.open(from);
    int cant_ciudades = 0;
    int cant_posibles_conexiones = 0;


    if (inputFile.is_open()) {

        inputFile >> cant_ciudades;
        AMatrixGraph* graph = new AMatrixGraph(cant_ciudades, is_directed);
        inputFile >> cant_posibles_conexiones;

        for (int j = 0; j < cant_posibles_conexiones; ++j) {
            graph->AddEdge(obtainNewEdge(inputFile));
        }

        inputFile.close();
        return graph;
    }


}

AListGraph* fileReader::HiperauditadosReaderToListGraph(string from, vector<int> *oil_cost, bool is_directed) {
    ifstream inputFile;

    inputFile.open(from);
    int cant_ciudades = 0;
    int cant_posibles_conexiones = 0;

    vector<int>& oil_costValues = *oil_cost;

    if (inputFile.is_open()) {

        inputFile >> cant_ciudades;
        inputFile >> cant_posibles_conexiones;
        AListGraph* graph = new AListGraph(cant_ciudades, is_directed);
        oil_costValues.assign(cant_ciudades, 0);

        int city_oil_cost;
        for (int i = 0; i < cant_ciudades; ++i) {
            inputFile >> oil_costValues[i];
        }

        for (int j = 0; j < cant_posibles_conexiones; ++j) {
            graph->AddEdge(obtainNewEdge(inputFile));
        }

        inputFile.close();
        return graph;
    }

}

AMatrixGraph* fileReader::HiperauditadosReaderToMatrixGraph(string from, vector<int> *oil_cost, bool is_directed) {
    ifstream inputFile;

    inputFile.open(from);
    int cant_ciudades = 0;
    int cant_posibles_conexiones = 0;

    vector<int>& oil_costValues = *oil_cost;

    if (inputFile.is_open()) {

        inputFile >> cant_ciudades;
        inputFile >> cant_posibles_conexiones;
        AMatrixGraph* graph = new AMatrixGraph(cant_ciudades, is_directed);
        oil_costValues.assign(cant_ciudades, 0);

        for (int i = 0; i < cant_ciudades; ++i) {
            inputFile >> oil_costValues[i];
        }

        for (int j = 0; j < cant_posibles_conexiones; ++j) {
            graph->AddEdge(obtainNewEdge(inputFile));
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

