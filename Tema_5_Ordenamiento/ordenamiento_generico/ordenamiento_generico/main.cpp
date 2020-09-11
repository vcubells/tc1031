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
#include "Persona.hpp"

int genera_int()
{
    return rand() % 100;
}

float genera_float()
{
    return rand() % 100 * 0.5;
}

Persona genera_persona()
{
    int edad = rand() % 20;
    std::string nombre = "Persona " + std::to_string(edad);
    return Persona(nombre, edad);
}

template <typename T>
std::vector<T> crea_vector(T(* genera)())
{
    /* Definir cantidad de elementos */
    const int n = 10;
    
    /* Vector de elementos */
    std::vector<T> elementos(n);
    
    /* Generar un vector de elementos aleatorios */
    std::generate(elementos.begin(), elementos.end(), genera);
    
    /* Imprimir el vector original */
    std::copy(elementos.begin(), elementos.end(), std::ostream_iterator<T>(std::cout, " "));
    
    std::cout << std::endl;
    
    return elementos;
}

template <typename T>
void ordena(
            T(* genera)(),
            std::vector<T>(* algoritmo)(std::vector<T>, bool(*)(T,T)),
            bool(* criterio)(T,T)
            )
{
    /* Genera un vector */
    std::vector<T> elementos = crea_vector(genera);
    
    /* Ordenar el vector de números */
    elementos = algoritmo(elementos, criterio);
    
    /* Imprimir el vector ordenado */
    std::copy(elementos.begin(), elementos.end(), std::ostream_iterator<T>(std::cout, " "));
    
    std::cout << std::endl << std::endl;
}

int main(int argc, const char * argv[]) {
    
    /* Establecer la semilla del generador */
    srand((unsigned int) time(nullptr));
    
    /* Ordenar números enteros */
    std::cout << "- Ordenamiento de números enteros -" << std::endl;
  
    ordena<int>(genera_int, Ordenamiento<int>::burbuja, Ordenamiento<int>::asc);
    
    /* Ordenar números en punto flotante */
    std::cout << "- Ordenamiento de números flotantes -" << std::endl;
    
    ordena<float>(genera_float, Ordenamiento<float>::insercion, Ordenamiento<float>::desc);
    
    /* Ordenar personas por el nombre */
    std::cout << "- Ordenamiento de personas por el nombre -" << std::endl;
    
    ordena<Persona>(genera_persona, Ordenamiento<Persona>::seleccion, Persona::edad_desc);
    
    /* Ordenar números enteros con QuickSort */
      std::cout << "- Ordenamiento de números enteros con QuickSort -" << std::endl;
    
    ordena<int>(genera_int, Ordenamiento<int>::quicksort, Ordenamiento<int>::asc);
    
    /* Ordenar números en punto flotante con MergeSort */
    std::cout << "- Ordenamiento de números flotantes con MergeSort -" << std::endl;
    
    ordena<float>(genera_float, Ordenamiento<float>::mergesort, Ordenamiento<float>::desc);
    
    return 0;
}
