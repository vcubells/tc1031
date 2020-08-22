//
//  main.cpp
//  factorial
//
//  Created by Vicente Cubells Nonell on 13/08/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>

/*
 
 Ejemplo paso a paso de como se resuleve el factorial de 5
 
n = 5   factorial(5)   5 * factorial(5-1) =     // Paso recursivo
n = 4   factorial(4)   4 * factorial(4-1) =     // Paso recursivo
n = 3   factorial(3)   3 * factorial(3-1) =     // Paso recursivo
n = 2   factorial(2)   2 * factorial(2-1) =     // Paso recursivo
n = 1   factorial(1)   1 * factorial(1-1) =     // Paso recursivo
n = 0   factorial(0)                      = 1   // Condición de parada
 
n = 1   factorial(1)   1 * 1 = 1
n = 2   factorial(2)   2 * 1 = 2
n = 3   factorial(3)   3 * 2 = 6
n = 4   factorial(4)   4 * 6 = 24
n = 5   factorial(5)   5 * 24 = 120
 
 = factorial(5)
 = factorial( 5 * factorial(4) )
 = factorial( 5 * factorial( 4 * factorial(3) ) )
 = factorial( 5 * factorial( 4 * factorial( 3 * factorial(2) ) ) )
 = factorial( 5 * factorial( 4 * factorial( 3 * factorial( 2 * factorial(1) ) ) ) )
 = factorial( 5 * factorial( 4 * factorial( 3 * factorial( 2 * factorial( 1 * factorial(0) ) ) ) ) )
 
 = factorial( 5 * factorial( 4 * factorial( 3 * factorial( 2 * factorial( 1 * 1 ) ) ) ) )
 = factorial( 5 * factorial( 4 * factorial( 3 * factorial( 2 * 1 ) ) ) )
 = factorial( 5 * factorial( 4 * factorial( 3 * 2 ) ) )
 = factorial( 5 * factorial( 4 * 6 ) )
 = factorial( 5 * 24 )
 = 120
 
*/

/*
 
 Ejemplo de como se resuelve la ecuación de recurrencia para obtener la complejidad
 
 c1             si n <= 1   donde c1 es el tiempo de evaluar la condición n <= 1
 T(n-1) + c2    si n > 1    donde c2 es el tiempo de evaluar la condición n > 1  y la multiplicación n * f(n-1)
 
 T(0) = 1
 T(1) = 1
 T(2) = T(n-1) + c2
 T(3) = (T(n-2) + c2) + c2 = T(n-2) + 2 * c2
 T(4) = ( (T(n-3) + c2) + c2 ) + c2 = T(n-3) + 3 * c2
 T(5) = ( ( (T(n-4) + c2) + c2 ) + c2 ) + c2 = T(n-4) + 4 * c2
 
 ...
 
 T(n) = T(n-k) + k * c2
 
 Asumiendo k = n-1, tenemos
 
 T(n) = T(1) + (n - 1) * c2 = 1 + c2*n - c2  donde c2 y 1 son valores constantes
 
 Entonces el grado mayor del polinomio es n, siendo la complejidad O(n)
 
 Espacial O(n)
 
*/

long int factorial(int n)
{
    /* Condición de parada */
    if (n <= 1) {
        return 1;
    }
    /* Paso recursivo */
    else {
        return n * factorial(n-1);
    }
}

int main(int argc, const char * argv[]) {
    
    int n = -1;
    
    /* Entrar el número a calcular el factorial */
    do {
        std::cout << "Entre el número: ";
        std::cin >> n;
    }
    while (n < 0);
    
    /* Calcular el factorial de n */
    long int resultado = factorial(n);
    
    /* Mostrar el resultado */
    std::cout << "El factorial de " << n << " = " << resultado << std::endl;
    
    return 0;
}
