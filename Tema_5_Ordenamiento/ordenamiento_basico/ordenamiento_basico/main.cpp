//
//  main.cpp
//  ordenamiento_basico
//
//  Created by Vicente Cubells on 28/08/23.
//

#include <iostream>
#include <time.h>
#include "Libro.hpp"
#include <iterator>

template < class T>
bool asc(T a, T b)
{
    return a < b;
}

template < class T>
bool desc(T a, T b)
{
    return a > b;
}

template <class T>
void burbuja(T v[], int n, bool compara(T,T) )
{
    T temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            //if (v[j-1] > v[j])
            if (compara(v[j], v[j-1]))
            {
                /*temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;*/
                std::swap(v[j], v[j-1]);
            }
        }
    }
}

template <class T>
void insercion(T numbers[], int n, bool compara(T,T))
{
    int i, j;
    T index;
    for (i=1; i < n; i++)
    {
        index = numbers[i];
        j = i-1;
        while (j >= 0 && compara(index, numbers[j]))
        {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j+1] = index;
    }
}

template <class T>
void seleccion(T x[], int n, bool compara(T,T))
{
    int minimo = 0;
    T temp;
    
    for(int i = 0; i < n-1; i++)
    {
        minimo = i;
        for(int j = i + 1; j < n; j++)
        {
            if (  compara(x[j], x[minimo]) )
                minimo = j;
        }
       /* temp = x[minimo];
        x[minimo] = x[i];
        x[i] = temp;*/
        std::swap(x[minimo], x[i]);
    }
}

int main(int argc, const char * argv[]) {
    if (argc < 2) {
        std::cout << "Use: a.out algoritmo" << std::endl;
        exit(0);
    }
    
    char algoritmo = *(argv[1]);
    
    srand((unsigned int) time(NULL));
    
    const int N = 10;
    
    //float vector[N];
    Libro vector[N];
    
    /* Inicializar el vector con números aleatorios */
    for (int i = 0; i < N; ++i) {
        vector[i] = Libro(rand() % 1000);
        
    }
    
    /* Imprimir el vector original */
    std::cout << "----- Inicia Vector original -----" << std::endl;
    std::copy(vector, vector+N, std::ostream_iterator<Libro>(std::cout, " "));
    std::cout << "----- Fin Vector original -----" << std::endl;
    
    switch (algoritmo) {
        case 'B':
            burbuja(vector, N, desc);
            break;
        case 'I':
            insercion(vector, N, desc);
            break;
        case 'S':
            seleccion(vector, N, asc);
            break;
        default:
            std::cout << "Use: a.out algoritmo" << std::endl;
            break;
    }
    
    /* Imprimir el vector ordenado */
    std::cout << "----- Inicia Vector ordenado -----" << std::endl;
    std::copy(vector, vector+N, std::ostream_iterator<Libro>(std::cout, " "));
    std::cout << "----- Fin Vector ordenado -----" << std::endl;
    
    return 0;
}
