//
//  main.cpp
//  fibonacci_iterativo_variables
//
//  Created by Vicente Cubells Nonell on 21/08/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>

/*
 
 T(n) = O(n)
 S(n) = O(1)
 
*/

/* Función Fibonacci con variables temporales */
int fibonacci(int n)
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

int main(int argc, const char * argv[])
{
    int n = 0;
    
    /* Entrar el número n de la serie */
    do {
        std::cout << "Entre el número: ";
        std::cin >> n;
    }
    while (n < 0);

    /* Calcular el valor de la serie */
    int resultado = fibonacci(n);
    
    /* Mostrar el resultado */
    std::cout << "Fib("<< n << ") = " << resultado << std::endl;
    
    return 0;
}

