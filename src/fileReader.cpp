#include "fileReader.h"

AListGraph* fileReader::HiperconectadosReaderToListGraph(string from, bool is_directed){

    ifstream input_file;

    input_file.open(from);
    int cant_ciudades = 0;
    int cant_posibles_conexiones = 0;

    if (input_file.is_open()) {

        input_file >> cant_ciudades;
        AListGraph* graph = new AListGraph(cant_ciudades, is_directed);
        input_file >> cant_posibles_conexiones;

        for (int j = 0; j < cant_posibles_conexiones; ++j) {
            graph->AddEdge(ObtainNewEdge(input_file));
        }

        input_file.close();
        return graph;
    }

}

AMatrixGraph* fileReader::HiperconectadosReaderToMatrixGraph(string from, bool is_directed) {

    ifstream input_file;

    input_file.open(from);
    int cant_ciudades = 0;
    int cant_posibles_conexiones = 0;


    if (input_file.is_open()) {

        input_file >> cant_ciudades;
        AMatrixGraph* graph = new AMatrixGraph(cant_ciudades, is_directed);
        input_file >> cant_posibles_conexiones;

        for (int j = 0; j < cant_posibles_conexiones; ++j) {
            graph->AddEdge(ObtainNewEdge(input_file));
        }

        input_file.close();
        return graph;
    }


}

AListGraph* fileReader::HiperauditadosReaderToListGraph(string from, vector<int> *oil_cost, bool is_directed) {
    ifstream input_file;

    input_file.open(from);
    int cant_ciudades = 0;
    int cant_posibles_conexiones = 0;

    vector<int>& oil_costValues = *oil_cost;

    if (input_file.is_open()) {

        input_file >> cant_ciudades;
        input_file >> cant_posibles_conexiones;
        AListGraph* graph = new AListGraph(cant_ciudades, is_directed);
        oil_costValues.assign(cant_ciudades, 0);

        int city_oil_cost;
        for (int i = 0; i < cant_ciudades; ++i) {
            input_file >> oil_costValues[i];
        }

        for (int j = 0; j < cant_posibles_conexiones; ++j) {
            graph->AddEdge(ObtainNewEdge(input_file));
        }

        input_file.close();
        return graph;
    }

}

AMatrixGraph* fileReader::HiperauditadosReaderToMatrixGraph(string from, vector<int> *oil_cost, bool is_directed) {
    ifstream input_file;

    input_file.open(from);
    int cant_ciudades = 0;
    int cant_posibles_conexiones = 0;

    vector<int>& oil_costValues = *oil_cost;

    if (input_file.is_open()) {

        input_file >> cant_ciudades;
        input_file >> cant_posibles_conexiones;
        AMatrixGraph* graph = new AMatrixGraph(cant_ciudades, is_directed);
        oil_costValues.assign(cant_ciudades, 0);

        for (int i = 0; i < cant_ciudades; ++i) {
            input_file >> oil_costValues[i];
        }

        for (int j = 0; j < cant_posibles_conexiones; ++j) {
            graph->AddEdge(ObtainNewEdge(input_file));
        }

        input_file.close();
        return graph;
    }

}

Edge fileReader::ObtainNewEdge(ifstream& input_file) {
    int edge_start, edge_finish, edge_weight;
    input_file >> edge_start;
    input_file >> edge_finish;
    input_file >> edge_weight;
    return Edge(edge_start, edge_finish, edge_weight);
}

