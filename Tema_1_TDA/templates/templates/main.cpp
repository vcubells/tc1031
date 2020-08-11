//
//  main.cpp
//  templates
//
//  Created by Vicente Cubells Nonell on 11/08/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "Libro.hpp"

/* función Template */
template <class T>
T menor(T a, T b)
{
    //return (a < b ? a : b);

     if (a < b)
        return a;
     else
        return b;
}

int main(int argc, const char * argv[]) {
    
    /* Definir dos números enteros */
    int int1 = 5;
    int int2 = 10;
    
    /* COmparra dos nñumeros enteros */
    std::cout << "El entero menor es: " << menor(int1, int2) << std::endl;
    
    /* Definir dos números flotantes */
    float float1 = 1.4;
    float float2 = 2.3;
    
    /* Comparar dos números flotantes */
    std::cout << "El flotante menor es: " << menor(float1, float2) << std::endl;
    
    /* Crear dos objetos de tipo Libro */
    Libro l1(5);
    Libro l2(2);
    
    /* Comparar dos libros */
    std::cout << "El Libro menor es: " << menor(l1, l2) << std::endl;
    
    return 0;
}
