//
//  main.cpp
//  fibonacci
//
//  Created by Vicente Cubells Nonell on 21/08/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>

/*
 
 Ejemplo de operaciones que se realizan al obtener el 5to número de la serie
 
                                    T(5)
                        T(4)          +             T(3)
               T(3)      +     T(2)           T(2)    +    T(1)
          T(2)  +  T(1)    T(1) + T(0)    T(1) + T(0)
      T(1) + T(0)
 
*/

/*

 Ejemplo de como se resuelve la ecuación de recurrencia para obtener la complejidad

T(0) = 0
F(1) = 1
T(n) = T(n-1) + T(n-2)

T(0) = 0
T(1) = 1
T(2) = T(n-1) + T(n-2) = T(1) + T(0) = 1
T(3) = T(n-1) + T(n-2) = T(2) + T(1) = 2
T(4) = T(n-1) + T(n-2) = T(3) + T(2) = 3
T(5) = T(n-1) + T(n-2) = T(4) + T(3) = 5

 c1                     si n <= 1   donde c1 es el tiempo de evaluar la condición n <= 1
 T(n-1) + T(n-2) + c   si n > 1    donde c2 es el tiempo de evaluar la condición n > 1  y la suma f(n-1) + f(n-2)
 
 T(0) = 0
 T(1) = 1
 T(2) = T(n-1) + T(n-2) + c
 
 Asumiendo que T(n-2) es aproximadamente igual a T(n-1)
 
 T(2) = 2 * T(n-1) + c
 T(3) = 2 * ( 2 * T(n-2) + c ) + c = 4 * T(n-2) + 3*c
 T(4) = 2 * ( 4 * T(n-3) + 3*c ) + c = 8 * T(n-3) + 7*c
 T(5) = 2 * ( 8 * T(n-4) + 7*c ) + c = 16 * T(n-4) + 15c
 
 ...
 
 T(n) = 2^k * T(n-k) +  (2^k - 1 ) * c
 
 Obteniendo el valor para el cual n - k = 0 tenemos n = k
 
 T(n) = 2^(n) * T(0) + (2^n - 1) * c
 
 T(n) = (2^n - 1) * c   donde c y 1 son valores constantes
 
 Entonces el grado mayor del polinomio es 2^n, siendo la complejidad O(2^n)
 
 Espacial O(n)

*/

/* Función Fibonacci recursivo */
int fibonacci(int n)
{
    /* Condición de parada */
    if (n < 2) {
        return n;
    }
    /* Paso recursivo */
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

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
