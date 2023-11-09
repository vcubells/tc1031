//
//  main.cpp
//  actividad_4-1
//
//  Created by Vicente Cubells on 13/11/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include "/Users/vcubells/Developer/GitHub/tc1031/Tema_8_Estructuras_no_lineales/Graph/Graph/Graph.hpp"

#define INF 1000
#define TABS 3


/* Definir número de vértices y aristas */
const int vertices = 10;
const int aristas = 15;

/* Variables auxiliares para DFS */
std::vector < std::vector <int> > recorrido(vertices);
std::vector<int> visitado(vertices);


void loadGraph2(int v, int e, Graph<int, int> * graph)
{
    /* Implementar */
    
    /* Adicionar los vértices del grafo */
    for(int i = 0; i < v; ++i)
    {
        graph->addVertex(i);
    }
    
    /* Definir variables para los vértices origen y destino */
    int origen;
    int destino;
    
    /* Adicionar las aristas del grafo */
    int i = 0;
    while (i < e)
    {
        origen = rand() % v;
        destino = rand() % v;
        
        Vertex<int, int> * v_origen = graph->search(origen);
        Vertex<int, int> * v_destino = graph->search(destino);
        
        /* Definir la lambda de comparación */
        auto f_existe = [v_destino]( Edge<int,int> * edge ) { return edge->getTarget() == v_destino; };
        
        /* Buscar si existe una conexión entre origen y destino */
        std::vector< Edge<int,int> * > * edges = v_origen->getEdges();
        auto pos = std::find_if(edges->begin(), edges->end(), f_existe);
        if (pos == edges->end()) {
            if (origen != destino) {
                graph->addEdge(v_origen, v_destino, 1);
                ++i;
            }
        }
    }
    
}

void loadGraph(int v, int e, std::vector < std::vector<int> > & graph)
{
    /* Implementar */
    
    /* Inicializar la matriz con ceros */
    for(int i = 0; i < v; ++i)
    {
        graph[i] = std::vector<int>(v);
        std::fill(graph[i].begin(), graph[i].end(), 0);
    }
    
    /* Definir variables para los vértices origen y destino */
    int origen;
    int destino;
    
    /* Generar las aristas de manera aleatoria */
    int i = 0;
    while (i < e)
    {
        origen = rand() % v;
        destino = rand() % v;
        
        if (graph[origen][destino] == 0) {
            if (origen != destino) {
                graph[origen][destino] = 1;
                ++i;
            }
        }
    }
}

void DFS(std::vector < std::vector<int> > & graph, int u)
{
    /* Implementar */
    
    /* Recorrer los incidentes en u */
    std::cout << u+1 << " --> ";
    for (int e = 0; e < vertices; ++e) {
        if (graph[u][e] == 0 )
        {
            continue;
        }
        else {
            if (recorrido[u][e] == 0) {
                int w = e;
                recorrido [u][e] = 1;
                if (visitado[e] == 0) {
                    visitado[e] = 1;
                    DFS(graph, w);
                }
            }
        }
    }
    std::cout << std::endl;
    
}

void BFS(Graph<int, int> * graph, int u)
{
    /* Implementar */
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
int main(int argc, const char * argv[]) {
    
    /* Declaración del grafo como matriz de adyacencia */
    std::vector < std::vector<int> > matriz_adyacencia(vertices);

    /* Generar el grafo como matriz de adyacencia */
    loadGraph(vertices, aristas, matriz_adyacencia);
    
    /* Imprimir la matriz de adyacencia */
    imprime(matriz_adyacencia);
    
    /* Inicializar la matriz de recorrido con ceros */
    for(int i = 0; i < vertices; ++i)
    {
        recorrido[i] = std::vector<int>(vertices);
        std::fill(recorrido[i].begin(), recorrido[i].end(), 0);
    }
    
    /* Inicializar el vector de visitados con ceros */
    std::fill(visitado.begin(), visitado.end(), 0);
    
    /* Recorrido con DFS */
    std::cout << "------ Matriz de adyacencia con DFS ------" << std::endl;
    int u = 0;
    DFS(matriz_adyacencia, u);
    
    /* Declaración del grafo como multilista */
    Graph<int, int> * multilista = new Graph<int, int>();

    /* Generar el grafo como multilista */
    loadGraph2(vertices, aristas, multilista);
    
    /* Visualizando el grafo */
    std::cout << *multilista << std::endl;
    
    /* Recorrido con BFS */
    std::cout << "------ Multilista con BFS ------" << std::endl;
    u = 1;
    BFS(multilista, u);
    
    delete multilista;
    
    return 0;
}
