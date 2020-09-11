//
//  Busqueda.hpp
//  busqueda_secuencial
//
//  Created by Vicente Cubells Nonell on 10/09/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#ifndef Busqueda_hpp
#define Busqueda_hpp

#include <iostream>

template <class T>
class Busqueda {
public:
    static int busquedaSecuencial(std::vector<T>, T);
    
    static int busquedaBinaria(std::vector<T>, T);
    static int busquedaBinaria(std::vector<T>, T, int, int);
};

template <class T>
int Busqueda<T>::busquedaSecuencial(std::vector<T> e, T valor)
{
    int i = 0;
    int encontrado = -1;
    
    long int size = e.size();
    
    while (encontrado == -1 && i < size) {
        if (e[i] == valor) {
            encontrado = i;
        }
        ++i;
    }
    
    return encontrado;
}

template <class T>
int Busqueda<T>::busquedaBinaria(std::vector<T> e, T valor)
{
   int size = (int) e.size() - 1;
    
    return busquedaBinaria(e, valor, 0, size);
}


template <class T>
int Busqueda<T>::busquedaBinaria(std::vector<T> e, T valor, int inferior, int superior)
{
    if (inferior >= superior)
    {
        return -1;
    }
    else  {
        int mitad = (inferior + superior) / 2;
        
        if (e[mitad] == valor) {
            return mitad;
        }
        else if (valor < e[mitad])
            return busquedaBinaria(e, valor, inferior, mitad);
        else
            return busquedaBinaria(e, valor, mitad + 1, superior);
    }
}

#endif /* Busqueda_hpp */
