//
//  main.cpp
//  busqueda_secuencial
//
//  Created by Vicente Cubells Nonell on 28/08/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include <vector>

template <typename T>
int busqueda(std::vector<T> elementos, T valor)
{
    int i = 0;
    int encontrado = -1;
    
    long int size = elementos.size();
    
    while (encontrado == -1 && i < size) {
        if (elementos[i] == valor) {
            encontrado = i;
        }
        ++i;
    }
    
    return encontrado;
}

int genera_int()
{
    return rand() % 100;
}

float genera_float()
{
    return rand() % 100 * 0.5;
}

template <typename T>
void buscar(T(* genera)())
{
    /* Vector de elementos */
    std::vector<T> elementos;
    
    /* Definir tamaño del vector */
    const int N = 10;
    
    /* Generar números aleatorios */
    for (int i = 0; i < N; ++i) {
        elementos.push_back(genera());
        std::cout << elementos.back() << ", ";
    }
    
    std::cout << std::endl;
    
    /* Obtener elemento a buscar */
    T valor;
    std::cout << "¿Qué elemento quieres buscar?: ";
    std::cin >> valor;
    
    int result = busqueda(elementos, valor);
    
    if (result == -1) {
        std::cout << "El valor buscado no se encuentra en el vector" << std::endl;
    }
    else {
        std::cout << "El valor buscado se encuentra en la posición " << result + 1 << std::endl;
    
    }
}

int main(int argc, const char * argv[]) {
    
    /* Definir semilla del generador random */
    srand((int) time(nullptr));
    
    /* Búsqueda de números enteros */
    buscar<int>(genera_int);
    
    /* Búsqueda de números punto flotante */
    buscar<float>(genera_float);
    
    return 0;
}
