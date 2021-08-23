//
//  main.cpp
//  compara_fibonacci
//
//  Created by Vicente Cubells on 23/08/21.
//

#include <iostream>
#include <vector>

int fibonacciI(int);
int fibonacciT(int);
int fibonacciR(int);

int main(int argc, const char * argv[]) {
    
    if (argc < 3) {
        std::cout << "Use: a.out numero_serie método" << std::endl;
        exit(0);
    }
    
    int numero = atoi(argv[1]);
    char opcion = *(argv[2]);
    int fib = 0;
    
    switch (opcion) {
        case 'R':
            fib = fibonacciR(numero);
            break;
        case 'I':
            fib = fibonacciI(numero);
            break;
        case 'T':
            fib = fibonacciT(numero);
            break;
            
        default:
            std::cout << "Use: a.out numero_serie método" << std::endl;
            break;
    }
    
    std::cout << "Fib(" << numero << ") = " << fib << std::endl;
    
    return 0;
}

/* Función Fibonacci con variables temporales */
int fibonacciI(int n)
{
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        /* Definir variables temporales */
        int n_2 = 0;
        int n_1 = 1;
        
        for (int i = 2; i <= n; ++i) {
            int temp = n_1;
            n_1 = temp + n_2;
            n_2 = temp;
        }
        
        return n_1;
    }
    
    return 0;
}

/* Función Fibonacci con una tabla temporal */
int fibonacciT(int n)
{
    /* Definir una tabla temporal */
    std::vector<int> tabla(n);
    
    tabla[0] = 0;
    tabla[1] = 1;
    
    for (int i = 2; i <= n; ++i) {
        tabla[i] = tabla[i-1] + tabla[i-2];
    }
    
    return tabla[n];
}

/* Función Fibonacci recursivo */
int fibonacciR(int n)
{
    /* Condición de parada */
    if (n < 2) {
        return n;
    }
    /* Paso recursivo */
    else {
        return fibonacciR(n-1) + fibonacciR(n-2);
    }
}
