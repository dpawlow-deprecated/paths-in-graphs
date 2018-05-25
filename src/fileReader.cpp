//La entrada consistir´a de una primera l´ınea con dos enteros n y m, correspondientes a la cantidad de ciudades y a la capacidad de posibles
// conexiones, respectivamente. Luego le suceder´an m l´ıneas con tres enteros, ai , bi y ci
//ai y bi indicar´an las ciudades a conectar,
//mientras que ci indicar´a el costo asociado. Asumiremos que todos los valores en la entrada ser´an enteros positivos.
#include "fileReader.h"
#include "datastructures/graphs/AMatrixGraph.h"

void fileReader::HiperconectadosReader(string from, AListGraph graph, bool is_directed) {

    ifstream inputFile;

    inputFile.open(from);
    int cantCiudades = 0;
    int cantPosiblesConexiones = 0;

    if (inputFile.is_open()) {

        inputFile >> cantCiudades;
        cout << "Cantidad de ciudades: " << cantCiudades << '\n';
        graph = AListGraph(cantCiudades, is_directed);
        inputFile >> cantPosiblesConexiones;
        cout << "Capacidad de posibles conexiones: " << cantPosiblesConexiones << '\n';

        for (int j = 0; j < cantPosiblesConexiones; ++j) {
            graph.AddEdge(obtainNewEdge(inputFile));
        }

        inputFile.close();
    }

}

void fileReader::HiperconectadosReader(string from, AMatrixGraph graph, bool is_directed) {

    ifstream inputFile;

    inputFile.open(from);
    int cantCiudades = 0;
    int cantPosiblesConexiones = 0;

    if (inputFile.is_open()) {

        inputFile >> cantCiudades;
        cout << "Cantidad de ciudades: " << cantCiudades << '\n';
        graph = AMatrixGraph(cantCiudades, is_directed);
        inputFile >> cantPosiblesConexiones;
        cout << "Capacidad de posibles conexiones: " << cantPosiblesConexiones << '\n';

        for (int j = 0; j < cantPosiblesConexiones; ++j) {
            graph.AddEdge(obtainNewEdge(inputFile));
        }

        graph.PrintGraph();
    }
    inputFile.close();

}

vector<int> fileReader::HiperauditadosReader(string from, AListGraph graph, bool is_directed) {
    ifstream inputFile;

    inputFile.open(from);
    int cantCiudades = 0;
    int cantPosiblesConexiones = 0;

    //Modificar esto
    vector<int> oilCost;

    if (inputFile.is_open()) {

        inputFile >> cantCiudades;
        cout << "Cantidad de ciudades: " << cantCiudades << '\n';
        inputFile >> cantPosiblesConexiones;
        cout << "Capacidad de posibles conexiones: " << cantPosiblesConexiones << '\n';
        graph = AListGraph(cantCiudades, is_directed);
        oilCost.assign(cantCiudades, 0);

        for (int i = 0; i < cantCiudades; ++i) {
            inputFile >> oilCost[i];
        }

        for (int j = 0; j < cantPosiblesConexiones; ++j) {
            graph.AddEdge(obtainNewEdge(inputFile));
        }
    }
    inputFile.close();

    return oilCost;
}

vector<int> fileReader::HiperauditadosReader(string from, AMatrixGraph graph, bool is_directed) {
    ifstream inputFile;

    inputFile.open(from);
    int cantCiudades = 0;
    int cantPosiblesConexiones = 0;

    //Modificar esto
    vector<int> oilCost;

    if (inputFile.is_open()) {

        inputFile >> cantCiudades;
        cout << "Cantidad de ciudades: " << cantCiudades << '\n';
        inputFile >> cantPosiblesConexiones;
        cout << "Capacidad de posibles conexiones: " << cantPosiblesConexiones << '\n';
        graph = AMatrixGraph(cantCiudades, is_directed);
        oilCost.assign(cantCiudades, 0);

        for (int i = 0; i < cantCiudades; ++i) {
            inputFile >> oilCost[i];
        }

        for (int j = 0; j < cantPosiblesConexiones; ++j) {
            graph.AddEdge(obtainNewEdge(inputFile));
        }

        graph.PrintGraph();
    }
    inputFile.close();

    return oilCost;
}


Edge fileReader::obtainNewEdge(ifstream& inputFile) {
    int edgeStart, edgeFinish, edgeWeight;
    inputFile >> edgeStart;
    inputFile >> edgeFinish;
    inputFile >> edgeWeight;
    return Edge(edgeStart, edgeFinish, edgeWeight);
}

