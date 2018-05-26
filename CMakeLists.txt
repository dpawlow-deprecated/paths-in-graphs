cmake_minimum_required(VERSION 3.9)
project(paths_in_graphs)

set(CMAKE_CXX_STANDARD 11)

add_executable(paths_in_graphs
        README.md src/datastructures/graphs/Graph.h src/types/types.h src/datastructures/graphs/Edge.cpp src/datastructures/graphs/Edge.h src/datastructures/graphs/Path.cpp src/datastructures/graphs/Path.h src/datastructures/graphs/AMatrixGraph.cpp src/datastructures/graphs/AMatrixGraph.h src/algorithms/Dijkstra.cpp src/algorithms/Dijkstra.h src/algorithms/Prim.cpp src/algorithms/Prim.h src/datastructures/graphs/AListGraph.cpp src/datastructures/graphs/AListGraph.h src/algorithms/Kruskal.cpp src/algorithms/Kruskal.h src/datastructures/UnionDisjointSet.cpp src/datastructures/UnionDisjointSet.h src/algorithms/BreadthFirstSearch.cpp src/algorithms/BreadthFirstSearch.h)
