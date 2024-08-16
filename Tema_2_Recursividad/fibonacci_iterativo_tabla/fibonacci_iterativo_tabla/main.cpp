//
//  main.cpp
//  fibonacci_iterativo_tabla
//
//  Created by Vicente Cubells Nonell on 21/08/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include <vector>

/*
 
 T(n) = O(n)
 S(n) = O(n)
 
*/

/* Función Fibonacci con una tabla temporal */
int fibonacci(int n)
{
    /* Definir una tabla temporal */
    std::vector<int> tabla(n);                // 1        | 1(1)
    
    tabla[0] = 0;                             // 2         | 2(1)
    tabla[1] = 1;                             // 2         | 2(1)
    
    for (int i = 2; i <= n; ++i) {            // 1 + 1 + 1  | 1(1) + 1 (n+1) + 1 (n)
        tabla[i] = tabla[i-1] + tabla[i-2];   // 7          | 7(n)
    }
    
    return tabla[n];                           // 2         | 2(1)
}                                              //       T(n) = 1 + 2 + 2 + 1 + n + 1 + n + 7n + 2
                                                //      T(n) = 9n + 9
                                                //      O(n)

int main(int argc, const char * argv[]) {
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

