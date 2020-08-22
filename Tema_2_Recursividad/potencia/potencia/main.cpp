//
//  main.cpp
//  potencia
//
//  Created by Vicente Cubells Nonell on 14/08/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>

/*
 
 Ejemplo de como se resuelve la ecuación de recurrencia para obtener la complejidad

 c1             si n == 0   donde c1 es el tiempo de evaluar la condición n == 0
 T(n-1) + c2    si n > 0    donde c2 es el tiempo de evaluar la condición n > 0  y la multiplicación x * f(n-1)
 
 T(0) = 1
 T(1) = T(n-1) + c2
 T(2) = (T(n-2) + c2) + c2 = T(n-2) + 2 * c2
 T(3) = ( (T(n-3) + c2) + c2 ) + c2 = T(n-3) + 3 * c2
 T(4) = ( ( (T(n-4) + c2) + c2 ) + c2 ) + c2 = T(n-4) + 4 * c2
 
 ...
 
 T(n) = T(n-k) + k * c2
 
 Asumiendo k = n, tenemos
 
 T(n) = T(0) + n * c2 = 1 + c2*n donde c2 y 1 son valores constantes
 
 Entonces el grado mayor del polinomio es n, siendo la complejidad O(n)
 
 Espacial O(n)

*/


long int potencia(int x, int n)
{
    /* Condición de parada */
    if (n == 0) {
        std::cout << "Llegué a la condición de parada" << std::endl;
        return 1;
    }
    /* Paso recursivo */
    else {
        std::cout << "Calculando " << x <<"^" << n << std::endl;
        long int pot = potencia(x, n-1);
        long int res = x * pot;
        std::cout << "Resultado " << x <<"^" << n << " = " << res << std::endl;
        return res;
    }
}

int main(int argc, const char * argv[]) {
    int n = -1;
    int x = -1;
    
    /* Entrar el número x a evelar a la potencia n */
    do {
        std::cout << "Entre el número: ";
        std::cin >> x;
    }
    while (x <= 0);
    
    /* Entrar la potencia n */
    do {
        std::cout << "Entre la potencia: ";
        std::cin >> n;
    }
    while (n < 0);
    
    /* Calcular la potencia de x a la n */
    long int resultado = potencia(x, n);
    
    /* Mostrar el resultado */
    std::cout << x << "^" << n << " = " << resultado << std::endl;
    
    return 0;
}
