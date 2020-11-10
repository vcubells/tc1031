//
//  main.cpp
//  Graph
//
//  Created by Vicente Cubells on 10/11/20.
//

#include <iostream>
#include "Graph.hpp"

int main(int argc, const char * argv[]) {
    
    /* Crear un grafo */
    Graph<char,int> * graph = new Graph<char,int>();
    
    /* Crear vértices */
    Vertex<char, int> * a = new Vertex<char, int>('A');
    Vertex<char, int> * b = new Vertex<char, int>('B');
    Vertex<char, int> * c = new Vertex<char, int>('C');
    
    /* Adicionar vértices al grafo */
    graph->addVertex(a);
    graph->addVertex(b);
    graph->addVertex(c);
    
    /* Adicionar aristas al grafo */
    graph->addEdge(a, b, 1);
    graph->addEdge(a, c, 2);
    graph->addEdge(a, c, 3);
    graph->addEdge(b, c, 3);
    
    /* Visualizando el grafo */
    std::cout << *graph << std::endl;
    
    /* Eliminar un edge */
    graph->removeEdge(a, c, 3);
    
    /* Visualizando el grafo */
    std::cout << *graph << std::endl;
    
    /* Eliminar el grafo */
    delete graph;

    return 0;
}
