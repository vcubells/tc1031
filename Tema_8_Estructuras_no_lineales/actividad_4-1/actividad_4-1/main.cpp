//
//  main.cpp
//  actividad_4-1
//
//  Created by Vicente Cubells on 13/11/20.
//

#include <iostream>
#include "/Users/vcubells/Developer/GitHub/tc1031/Tema_8_Estructuras_no_lineales/Graph/Graph/Graph.hpp"

void loadGraph2(int v, int e, Graph<int, int> & graph)
{
    /* Implementar */
}

void loadGraph(int v, int e, std::vector < std::vector<int> > & graph)
{
    /* Implementar */
}

void DFS(std::vector < std::vector<int> > & graph, int u)
{
    /* Implementar */
}

void BFS(Graph<int, int> & graph, int u)
{
    /* Implementar */
}

int main(int argc, const char * argv[]) {
    
    /* Definir número de vértices y aristas */
    const int vertices = 10;
    const int aristas = 15;
    
    /* Declaración del grafo como matriz de adyacencia */
    std::vector < std::vector<int> > matriz_adyacencia;

    /* Generar el grafo como matriz de adyacencia */
    loadGraph(vertices, aristas, matriz_adyacencia);
    
    /* Recorrido con DFS */
    std::cout << "------ Matriz de adyacencia con DFS ------" << std::endl;
    int nodo_u = 1;
    DFS(matriz_adyacencia, u);
    
    /* Declaración del grafo como multilista */
    Graph<int, int> multilista = new Graph<int, int>();

    /* Generar el grafo como multilista */
    loadGraph2(vertices, aristas, multilista);
    
    /* Recorrido con BFS */
    std::cout << "------ Multilista con BFS ------" << std::endl;
    int nodo_u = 1;
    BFS(multilista, u);
    
    delete multilista;
    
    return 0;
}
