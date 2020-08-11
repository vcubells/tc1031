//
//  Array.cpp
//  tc1031
//
//  Created by Vicente Cubells Nonell on 11/08/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "Array.hpp"


int Array::obtener(int index)
{
    int item = -1;
    
    if (index >= 0 && index < longitud)
    {
        item = datos[index];
    }
    else {
        std::cout << "Índice fuera de rango, no se puede obtener el elemento" << std::endl;
    }
    
    return item;
}

int Array::getLongitud()
{
    return longitud;
}

bool Array::estaLleno()
{
    return longitud == MAX;
}

int Array::eliminar()
{
    int item = -1;
    if (longitud > 0) {
        item = datos[longitud-1];
        --longitud;
    }
    else {
        std::cout << "El arreglo está vacío, no se puede borrar un elemento" << std::endl;
    }
        
    return item;
}

void Array::insertar(int item)
{
    if (!estaLleno()) {
        datos[longitud] = item;
        ++longitud;
    }
    else {
        std::cout << "El arreglo está lleno, no se puede insertar el elemento" << std::endl;
    }
}

void Array::imprimir()
{
    for (int i = 0; i < longitud; ++i) {
        std::cout << datos[i] << std::endl;
    }
}
