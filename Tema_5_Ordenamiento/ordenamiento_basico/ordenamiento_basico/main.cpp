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

/*
 O(n^2)
 M(n^2)
 */
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

/*
 O(n^2)
 M(n)
 */
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

template <class T>
void quicksort (T a[], int primero, int ultimo)
{
    int izquierdo = primero;
    int derecho = ultimo;
    
    //Se selecciona pivote
    T pivote = a[primero];
    
    if ( primero < ultimo) // Paso base
    {
        // partición
        while ( izquierdo < derecho)
        {
            while ( (izquierdo < derecho) && (a[izquierdo] <= pivote )) izquierdo++;
            while ( a[derecho] > pivote ) derecho--;
            if ( izquierdo < derecho) // se intercambian los contenidos
            {
                std::swap(a[izquierdo], a[derecho]);
            }
        }
        // Se intercambia el pivote con el elemento de la posición derecha
        std::swap(a[primero], a[derecho]);
        
        // Paso recursivo
        quicksort ( a, primero, derecho-1);
        quicksort ( a, izquierdo, ultimo);
    }
}

template <class T>
void mergesort (T v[], int l, int n)
{
    int m = (n+l)/2;
    if (n > l)
    {
        mergesort (v, l, m);
        mergesort (v, m+1, n);
        merge (v, l, m, n);
    }
}

template <class T>
void merge (T v[], int l, int m, int n)
{
    int i, j, k;
    T aux[n];
    
    for (i=m+1; i>l; i--)         // Vector auxiliar O(n)
        aux[i-1] = v[i-1];
    for (j=m; j<n; j++)
        aux[n+m-j] = v[j+1];
    for (k=l; k<=n; k++)         // Mezcla O(n)
        if (aux[i]<aux[j])
            v[k] = aux[i++];
        else
            v[k] = aux[j--];
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
            insercion(vector, N, asc);
            break;
        case 'S':
            seleccion(vector, N, asc);
            break;
        case 'Q':
            quicksort(vector, 0, N);
            break;
        case 'M':
            mergesort(vector, 0, N);
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
