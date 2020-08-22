//
//  main.cpp
//  factorial_iterativo
//
//  Created by Vicente Cubells Nonell on 21/08/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>

/*
 
 Temporal O(n)
 Espacial O(n)

*/

long int factorial(int n)
{
    long int resultado = 1;
    
    for (int i = 2; i <= n; ++i) {
        resultado *= i;
    }

    return resultado;
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
