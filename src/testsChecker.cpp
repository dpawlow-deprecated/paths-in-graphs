#include "testsChecker.h"
#include "datastructures/graphs/AListGraph.h"
#include "algorithms/BellmanFord.h"

bool checkMatrixAlgorithms(AMatrixGraph &matrixGraph){
    AMatrixGraph floyd = FloydAlgorithm(matrixGraph);
    AMatrixGraph dantzig = DantzigAlgorithm(matrixGraph);

    dantzig.PrintGraph();
    floyd.PrintGraph();

    for (int i = 0; i < matrixGraph.GetNumberOfNodes(); i++) {
        for (int j = 0; j < matrixGraph.GetNumberOfNodes(); j++) {
            if(dantzig.EdgeExists(i,j) != floyd.EdgeExists(i,j)){
                return false;
            }

            if(dantzig.EdgeExists(i,j)){
                int test = dantzig.GetEdgeWeight(i,j);
                int test2 = floyd.GetEdgeWeight(i,j);
                if(dantzig.GetEdgeWeight(i,j) != floyd.GetEdgeWeight(i,j)){
                    return false;
                }
            }
        }
    }
    return true;
}

bool checkListAlgorithms(AListGraph &listGraph){
    //Continuar...
   /* AMatrixGraph dijkstra = Dijkstra(listGraph);
    AMatrixGraph bellmanford = BellmanFordAlgorithm(bellmanford);*/
}