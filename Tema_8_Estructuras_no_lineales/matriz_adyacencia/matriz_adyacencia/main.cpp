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
#include <iomanip>

#include "Ciudad.hpp"

#define INF 1000
#define TABS 3

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
    
    grafo[4][2] = 1;  // E <-> C
    
    grafo[5][2] = 1;  // F <-> C
    
    return grafo;

}

std::vector < std::vector<int> > genera_grafo_ponderado(int n)
{
    /* Crear el grafo */
    std::vector < std::vector<int> > grafo(n);
    
    for(int i = 0; i < n; ++i)
    {
        grafo[i] = std::vector<int>(n);
        std::fill(grafo[i].begin(), grafo[i].end(), INF);
        grafo[i][i] = 0;
    }
    
    /* Adicionar aristas al grafo */
    grafo[0][2] = 40; // 1 -> 3
    grafo[0][4] = 10; // 1 -> 5
    grafo[0][5] = 5;  // 1 -> 6

    grafo[1][3] = 5;  // 2 -> 4
    
    grafo[2][1] = 10; // 3 -> 2
    grafo[2][4] = 5;  // 3 -> 5
    
    grafo[3][2] = 5;  // 4 -> 3
    
    grafo[4][3] = 20;  // 5 -> 4
    
    grafo[5][1] = 20;  // 6 -> 2
    grafo[5][4] = 10;  // 6 -> 5
    
    return grafo;
}


void imprime_parcial(std::vector < std::vector<int> > A, int i, int j, int k)
{
    int real_i = i + 1;
    int real_j = j + 1;
    int real_k = k + 1;

    std::cout << "d" << real_i << real_j;
    std::cout << " = min(";
    std::cout << "d" << real_i << real_j;
    std::cout << ", ";
    std::cout << "d" << real_i << real_k;
    std::cout << " + ";
    std::cout << "d" << real_k << real_j;
    std::cout << ")";

    std::string Aij = (A[i][j] != INF) ? std::to_string(A[i][j]) : "inf";
    std::string Aik = (A[i][k] != INF) ? std::to_string(A[i][k]) : "inf";
    std::string Akj = (A[k][j] != INF) ? std::to_string(A[k][j]) : "inf";

    std::cout << " = min(";
    std::cout << std::setw(TABS) << Aij;
    std::cout << ", ";
    std::cout << std::setw(TABS) << Aik;
    std::cout << " + ";
    std::cout << std::setw(TABS) << Akj;
    std::cout << ")";

    int suma = A[i][k] + A[k][j];
    std::string suma_str = (A[i][k] != INF && A[k][j] != INF) ? std::to_string(suma) : "inf";

    std::cout << " = min(";
    std::cout << std::setw(TABS) << Aij;
    std::cout << ", ";
    std::cout << std::setw(TABS) << suma_str;
    std::cout << ")";

    int minimo = A[i][j] > suma ? suma : A[i][j];
    std::string minimo_str = (minimo != INF) ? std::to_string(minimo) : "inf";
    
    std::cout << " = ";
    std::cout << std::setw(TABS) << minimo_str;
    std::cout << std::endl;
}

void imprime(std::vector < std::vector<int> > M)
{
    int N = (int) M.size();
    
    /* Imprime los headers de las columnas */
    std::cout << std::setw(TABS) << " ";
    for (int i = 1; i <= N; i++)
    {
        std::cout << "|" << std::setw(TABS) << i;
    }
    std::cout << "|" << std::endl;

    /* Imprime la separación */
    int total_char = (TABS+1) * (N+1);
    for (int i = 0; i < total_char; i++)
    {
        std::cout << "_";
    }
    
    std::cout << std::endl;
    
    for(int i = 0; i < N; ++i)
    {
        std::cout << std::setw(TABS) << i+1;

        for(int j = 0; j < N; ++j)
        {
            std::string str = (M[i][j] == INF) ? "inf" : std::to_string(M[i][j]);

            std::cout << "|" << std::setw(TABS) << str;
        }

        std::cout << "|" << std::endl;
    }

    std::cout << std::endl << std::endl;
}

std::vector < std::vector<int> > duplicate(std::vector < std::vector<int> > C)
{
    int N = (int) C.size();
    std::vector < std::vector<int> > A(N);
    copy(C.begin(), C.end(), A.begin());
    
    return A;
    
}

std::vector < std::vector<int> > Floyd(std::vector < std::vector<int> > C)
 {
    /* Clonar la matriz original */

    std::vector < std::vector<int> > A = duplicate(C);
    
    int N = (int) C.size();
     
    for(int k = 0; k < N; ++k)
    {
        std::cout << "--- Iteración ";
        std::cout << k+1 << " ---";
        std::cout << std::endl << std::endl;

        for(int i = 0; i < N; ++i)
        {
            if (i == k) { continue; }

            for(int j = 0; j < N; ++j)
            {
                if (j == i || j == k) { continue; }

                /* Bloque para imprimir resultados parciales */
                imprime_parcial(A, i, j, k);

                int temp = A[i][k] + A[k][j];
                if ( temp < A[i][j] )
                    A[i][j] = temp;
            }
            std::cout << std::endl;
        }
        imprime(A);
    }
    
    return A;
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
    
    /* Obtener las aristas del grafo dirigido */
    for (int i = 0; i < numero_vertices; ++i) {
        for (int j = 0; j < numero_vertices; ++j) {
            if (dirigido[i][j] == 1) {
                std::cout << vertices[i] << " --> " << vertices[j] << std::endl;
            }
        }
    }
    
    
    /* Grafo dirigido ponderado */
    std::cout << std::endl;
    std::cout << "--- Grafo Dirigido Ponderado ---" << std::endl << std::endl;
    
    /* Generar el grafo dirigido */
    std::vector < std::vector<int> > ponderado = genera_grafo_ponderado(numero_vertices);
    
    /* Imprime matriz de costos */
    std::cout << "--- Matriz de costos ---" << std::endl << std::endl;
    imprime(ponderado);
    
    /* Calcular distancias mínimas con Floyd-Warshall */
    std::cout << "--- Calcular distancias mínimas con Floyd-Warshall ---" << std::endl << std::endl;
    std::vector < std::vector<int> > distancias = Floyd(ponderado);
    
    std::cout << "--- Matriz de distancias ---" << std::endl << std::endl;
    imprime(distancias);
    
    return 0;
}

