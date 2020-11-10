//
//  main.cpp
//  matriz_adyacencia
//
//  Created by Vicente Cubells on 06/11/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Ciudad.hpp"

std::vector < std::vector<int> > genera_grafo_no_dirigido(int n)
{
    /* Crear el grafo */
    std::vector < std::vector<int> > grafo(n);
    
    /* Generar la triangular inferior */
    for(int i = 1; i < n; ++i)
    {
        grafo[i] = std::vector<int>(i);
        std::fill(grafo[i].begin(), grafo[i].end(), 0);
    }
    
    /* Adicionar aristas al grafo */
    grafo[1][0] = 1;  // B <-> A
    
    grafo[2][0] = 1;  // C <-> A

    grafo[2][1] = 1;  // C <-> B
    
    grafo[3][0] = 1;  // D <-> A
    
    grafo[4][2] = 1;  // D <-> C
    
    grafo[5][2] = 1;  // F <-> C
    
    return grafo;

}

std::vector < std::vector<int> > genera_grafo_dirigido(int n)
{
    /* Crear el grafo */
    std::vector < std::vector<int> > grafo(n);
    
    for(int i = 0; i < n; ++i)
    {
        grafo[i] = std::vector<int>(n);
        std::fill(grafo[i].begin(), grafo[i].end(), 0);
    }
    
    /* Adicionar aristas al grafo */
    grafo[0][1] = 1;  // A -> B
    grafo[0][3] = 1;  // A -> D

    grafo[1][0] = 1;  // B -> A
    grafo[1][2] = 1;  // B -> C
    grafo[1][4] = 1;  // B -> E
    grafo[1][5] = 1;  // B -> F
    
    grafo[2][0] = 1;  // C -> A
    grafo[2][5] = 1;  // C -> F
    
    grafo[3][4] = 1;  // D -> E
    
    grafo[4][0] = 1;  // E -> A
    
    return grafo;
}

template <typename T>
void visualizar( std::vector < std::vector<int> > grafo, std::vector<T> vertices )
{
    /* Imprimir los nodos */
    std::cout << "\t";
    for (auto vertice : vertices) {
        std::cout << vertice << "\t";
    }
    
    std::cout << std::endl;
    
    /* Imprimir las filas de la matriz */
    int i = 0;
    for (auto fila : grafo) {
        std::cout << vertices[i++] << "\t";
        std::copy(fila.begin(), fila.end(), std::ostream_iterator<int>(std::cout, "\t") );
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    
    const int  numero_vertices = 6;
    
    /* Vector de vértices */
    std::vector<char> vertices(numero_vertices);
    
    /* Generar los vértices */
    for (int i = 0; i < numero_vertices; ++i) {
        //std::string nombre = "Ciudad " + std::to_string(i + 1);
        //vertices[i] = Ciudad(nombre, rand() % 10000000);
        vertices[i] = 65 + i;
    }
    
    /* Grafo no dirigido */
    std::cout << "--- Grafo No Dirigido ---" << std::endl << std::endl;
    
    /* Generar el grafo no dirigido */
    std::vector < std::vector<int> > no_dirigido = genera_grafo_no_dirigido(numero_vertices);
    
    /* Visualizar el grafo no dirigido */
    visualizar(no_dirigido, vertices);
    
    /* Obtener las aristas del grafo no dirigido */
    for (int i = 0; i < numero_vertices; ++i) {
        for (int j = 0; j < i; ++j) {
            if (no_dirigido[i][j] == 1) {
                std::cout << vertices[i] << " --> " << vertices[j] << ", ";
                std::cout << vertices[j] << " --> " << vertices[i] << std::endl;
            }
        }
    }
    
    /* Grafo dirigido */
    std::cout << std::endl;
    std::cout << "--- Grafo Dirigido ---" << std::endl << std::endl;
    
    /* Generar el grafo dirigido */
    std::vector < std::vector<int> > dirigido = genera_grafo_dirigido(numero_vertices);
    
    /* Visualizar el grafo dirigido */
    visualizar(dirigido, vertices);
    
    /* Obtener las aristas del grafo no dirigido */
    for (int i = 0; i < numero_vertices; ++i) {
        for (int j = 0; j < numero_vertices; ++j) {
            if (dirigido[i][j] == 1) {
                std::cout << vertices[i] << " --> " << vertices[j] << std::endl;
            }
        }
    }
    
    return 0;
}

