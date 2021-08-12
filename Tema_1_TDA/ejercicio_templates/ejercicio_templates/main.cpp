//
//  main.cpp
//  ejercicio_templates
//
//  Created by Vicente Cubells on 09/08/21.
//

#include <iostream>
#include "Array.hpp"
#include "Libro.hpp"

template <class V>
void comun(Array<V>);

Array<int> insertar(Array<int>);
Array<char> insertar(Array<char>);
Array<float> insertar(Array<float>);
Array<Libro> insertar(Array<Libro>);

int main(int argc, const char * argv[]) {
    
    /* TODO #1. Crear un TDA Array que sea un template */
   
    /* Ver implementación en archivo Array.hpp */
    
    /* TODO #2. Ejemplificar el uso del TDA Array con diferentes tipos como int y float */
    
    std::cout << "--- Trabajando con enteros ---" << std::endl;
    Array<int> enteros;
    comun<int>(enteros);
    
    std::cout << "--- Trabajando con caracteres ---" << std::endl;
    Array<char> caracteres;
    comun<char>(caracteres);
    
    std::cout << "--- Trabajando con flotantes ---" << std::endl;
    Array<float> flotantes;
    comun<float>(flotantes);
    
    std::cout << "--- Trabajando con objetos de tipo Libros ---" << std::endl;
    Array<Libro> libros;
    comun<Libro>(libros);
    
    
    return 0;
}

Array<Libro> insertar(Array<Libro> arreglo)
{
    /* Adicionar elementos al arreglo */
    arreglo.insertar(Libro("Libro 1"));
    arreglo.insertar(Libro("Libro 2"));
    arreglo.insertar(Libro("Libro 3"));
    arreglo.insertar(Libro("Libro 4"));
    arreglo.insertar(Libro("Libro 5"));
    
    /* Insertar un elemento cuando el arreglo está lleno */
    arreglo.insertar(Libro("Libro 6"));
    
    return arreglo;
}

Array<float> insertar(Array<float> arreglo)
{
    /* Adicionar elementos al arreglo */
    arreglo.insertar(1.3);
    arreglo.insertar(3.4);
    arreglo.insertar(10.2);
    arreglo.insertar(3.0);
    arreglo.insertar(8.5);
    
    /* Insertar un elemento cuando el arreglo está lleno */
    arreglo.insertar(20.55);
    
    return arreglo;
}

Array<char> insertar(Array<char> arreglo)
{
    /* Adicionar elementos al arreglo */
    arreglo.insertar('a');
    arreglo.insertar('b');
    arreglo.insertar('c');
    arreglo.insertar('d');
    arreglo.insertar('f');
    
    /* Insertar un elemento cuando el arreglo está lleno */
    arreglo.insertar('g');
    
    return arreglo;
}

Array<int> insertar(Array<int> arreglo)
{
    /* Adicionar elementos al arreglo */
    arreglo.insertar(1);
    arreglo.insertar(2);
    arreglo.insertar(3);
    arreglo.insertar(4);
    arreglo.insertar(5);
    
    /* Insertar un elemento cuando el arreglo está lleno */
    arreglo.insertar(6);
    
    return arreglo;
}

template <class V>
void comun(Array<V> arreglo)
{
    /* Tamaño inicial del arreglo */
    std::cout << "El arreglo tiene " << arreglo.getLongitud() << " elementos" << std::endl;
    
    /* Eliminar un elemento cuando el arreglo está vacío */
    arreglo.eliminar();
    
    /* Insertar */
    arreglo = insertar(arreglo);
    
    /* Tamaño del arreglo después de insertar elementos */
    std::cout << "El arreglo tiene " << arreglo.getLongitud() << " elementos" << std::endl;
    
    /* Eliminar un elemento cuando el arreglo está lleno */
    arreglo.eliminar();
    
    /* Imprimir los elementos del arreglo */
    arreglo.imprimir();
    
    /* Tamaño final del arreglo */
    std::cout << "El arreglo tiene " << arreglo.getLongitud() << " elementos" << std::endl;
}
