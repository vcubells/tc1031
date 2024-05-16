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
    
    /* Mostrar incidentes de entrada */
    graph->getIncidentePorVertex();
    
    /* Eliminar un edge */
    graph->removeEdge(a, c, 3);
    
    /* Adicionar un vértice nuevo */
    Vertex<char, int> * d = new Vertex<char, int>('D');
    Vertex<char, int> * e = new Vertex<char, int>('E');
    
    /* Adicionar vértices al grafo */
    graph->addVertex(d);
    graph->addVertex(e);
    
    /* Adicionar aristas al grafo */
    graph->addEdge(a, d, 10);
    graph->addEdge(b, e, 20);
    graph->addEdge(c, e, 30);
    
    /* Visualizando el grafo */
    std::cout << *graph << std::endl;
    
    /* Buscar un nodo */
    char value = 'E';
    
    auto found = graph->search(value);
    
    if (found) {
        std::cout << "(S) El nodo " << found->getInfo() << " existe" << std::endl;
    }
    else {
        std::cout << "(S) El nodo " << value << " no existe" << std::endl;
    }
    
    /* Mostrar incidentes de entrada */
    graph->getIncidentePorVertex();
    
    /* Eliminar el grafo */
    delete graph;

    return 0;
}
