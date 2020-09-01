//
//  main.cpp
//  ordenamiento_generico
//
//  Created by Vicente Cubells Nonell on 01/09/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "Ordenamiento.hpp"

int main(int argc, const char * argv[]) {
    
    /* Establecer la semilla del generador */
    srand((unsigned int) time(nullptr));
    
    /* Definir cantidad de elementos */
    const int n = 10;
    
    /*
    * Ordenar números enteros
    */
    
    std::cout << "- Ordenamiento de números enteros -" << std::endl;
    
    /* Definir un vector de enteros */
    std::vector<int> numeros(n);
    
    /* Generar un vector de números enteros utilizando una función Lambda */
    std::generate(numeros.begin(), numeros.end(), [](){return rand() % 100;});
    
    /* Imprimir el vector original */
    std::copy(numeros.begin(), numeros.end(), std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << std::endl;
    
    /* Ordenar el vector de números */
    numeros = Ordenamiento<int>::burbuja(numeros, Ordenamiento<int>::asc);
    
    /* Imprimir el vector ordenado */
    std::copy(numeros.begin(), numeros.end(), std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << std::endl << std::endl;
    
    /*
     * Ordenar números en punto flotante
     */
    
    std::cout << "- Ordenamiento de números flotantes -" << std::endl;
    
    /* Definir un vector de flotantes */
    std::vector<float> numeros_f(n);
    
    /* Generar un vector de números enteros utilizando una función Lambda */
    std::generate(numeros_f.begin(), numeros_f.end(), [](){return rand() % 100 * 0.5;});
    
    /* Imprimir el vector original */
    std::copy(numeros_f.begin(), numeros_f.end(), std::ostream_iterator<float>(std::cout, " "));
    
    std::cout << std::endl;
    
    /* Ordenar el vector de números */
    numeros_f = Ordenamiento<float>::burbuja(numeros_f, Ordenamiento<float>::desc);
    
    /* Imprimir el vector ordenado */
    std::copy(numeros_f.begin(), numeros_f.end(), std::ostream_iterator<float>(std::cout, " "));
    
    std::cout << std::endl << std::endl;
     
    return 0;
}

