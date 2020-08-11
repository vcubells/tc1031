//
//  main.cpp
//  tda_array
//
//  Created by Vicente Cubells Nonell on 11/08/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "Array.hpp"

int main(int argc, const char * argv[]) {
    
    /* Crear una instancia de un Array */
    Array arreglo;
    
    /* Tamaño inicial del arreglo */
    std::cout << "El arreglo tiene " << arreglo.getLongitud() << " elementos" << std::endl;
    
    /* Eliminar un elemento cuando el arreglo está vacío */
    arreglo.eliminar();
    
    /* Adicionar elementos al arreglo */
    arreglo.insertar(1);
    arreglo.insertar(2);
    arreglo.insertar(3);
    arreglo.insertar(4);
    arreglo.insertar(5);
    
    /* Insertar un elemento cuando el arreglo está lleno */
    arreglo.insertar(6);
    
    /* Tamaño del arreglo después de insertar elementos */
    std::cout << "El arreglo tiene " << arreglo.getLongitud() << " elementos" << std::endl;
    
    /* Eliminar un elemento cuando el arreglo está lleno */
    arreglo.eliminar();
    
    /* Imprimir los elementos del arreglo */
    arreglo.imprimir();
    
    /* Tamaño final del arreglo */
    std::cout << "El arreglo tiene " << arreglo.getLongitud() << " elementos" << std::endl;
    
    return 0;
}
