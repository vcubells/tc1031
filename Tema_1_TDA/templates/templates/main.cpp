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
    return (a < b ? a : b);

//     if (a < b)
//        return a;
//     else
//        return b;
}

/* función Template */
template <class T>
T mayor(T a, T b)
{
    return (a > b ? a : b);
}

/* función Template */
template <class T>
bool igual(T a, T b)
{
    return (a == b);
}



template <class T, class E>
T menor(T a, E b)
{
    return (a < b ? a : b);
}

int main(int argc, const char * argv[]) {
    
    /* Definir dos números enteros */
    int int1 = 5;
    int int2 = 10;
    
    /* Comparar dos números enteros */
    std::cout << "El entero menor es: " << menor(int1, int2) << std::endl;
    std::cout << "El entero mayor es: " << mayor(int1, int2) << std::endl;
    
    /* Definir dos números flotantes */
    float float1 = 1.4;
    float float2 = 2.3;
    
    /* Comparar dos números flotantes */
    std::cout << "El flotante menor es: " << menor(float1, float2) << std::endl;
    std::cout << "El flotante mayor es: " << mayor(float1, float2) << std::endl;
    
    /* Crear dos objetos de tipo Libro */
    Libro l1(5);
    Libro l2(2);
    
    /* Comparar dos libros */
    Libro r = menor(l1, l2);
    
    /* Imprimir el Id del libro menor */
    std::cout << "El Libro menor es: " << r.getId() << std::endl;
    
    Libro m = mayor(l1, l2);
    std::cout << "El Libro mayor es: " << m.getId() << std::endl;
    
    
    /* Imprimir todo el libro con un método */
    std::cout << "Los datos del libro son: " << std::endl;
    r.print();
    operator<<(std::cout, r);
    std::cout << r;
    
    /* Comparar dos libros con la sobrecarga del operador */
    std::cout << "¿Libro 1 es menor que Libro 2? = " << l1.operator<(l2) << std::endl;
        
    return 0;
}
