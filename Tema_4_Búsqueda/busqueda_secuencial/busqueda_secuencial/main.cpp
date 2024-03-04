//
//  main.cpp
//  busqueda_secuencial
//
//  Created by Vicente Cubells Nonell on 28/08/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include <vector>
#include "../../../Tema_5_Ordenamiento/ordenamiento_generico/ordenamiento_generico/Ordenamiento.hpp"
#include "Busqueda.hpp"
#include "Persona.hpp"

int genera_int()
{
    return rand() % 100;
}

float genera_float()
{
    return rand() % 100 * 0.5;
}

/* TODO */
Persona genera_persona()
 {
    /* Generar un número aleatorio entre 1 y 100 */
    int age = rand() % 100 + 1;
    
    std::string name = "Persona " + std::to_string(age);
    std::string lastname = "Apellido " + std::to_string(age);
    
    return Persona(name, lastname, age);
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
    
    return elementos;
}

template <typename T>
void buscar(
            T(* genera)(),
            int (* algoritmo)(std::vector<T>, T),
            bool ordena = false
            )
{
    /* Genera un vector */
    std::vector<T> elementos = crea_vector(genera);
    
    /* Ordenar vector para búsqueda binaria */
    if (ordena)
    {
        /* Ordenar el vector de números */
        elementos = Ordenamiento<T>::mergesort(elementos, Ordenamiento<T>::asc);
    }
    
    /* Imprimir el vector  */
    std::copy(elementos.begin(), elementos.end(), std::ostream_iterator<T>(std::cout, " "));
    
//    for (auto i = elementos.begin(); i < elementos.end(); ++i)
//    {
//        std::cout << i << " ";
//    }
        
    std::cout << std::endl;
    T valor;
    int age;
    std::cout << "Entra la edad de la persona que quieres buscar?: ";
    std::cin >> age;
    valor = Persona("", "", age);
    
    /* Obtener elemento a buscar */
    /*if (strcmp(typeid(T).name(),"Persona") == 0)
    {
        int age;
        std::cout << "Entra la edad de la persona que quieres buscar?: ";
        valor = Persona("", "", age);
    }
    else {
        std::cout << "¿Qué elemento quieres buscar?: ";
        std::cin >> valor;
    }*/
    
    int resultado = algoritmo(elementos, valor);
    
    if (resultado == -1) {
        std::cout << "El valor buscado no se encuentra en el vector" << std::endl;
    }
    else {
        std::cout << "El valor buscado se encuentra en la posición " << resultado + 1 << std::endl;
    
    }
    
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    
    /* Definir semilla del generador random */
    srand((int) time(nullptr));
    
    /* Búsqueda secuencial de números enteros */
    //buscar<int>(genera_int, Busqueda<int>::busquedaSecuencial);
    
    /* Búsqueda binaria de números punto flotante */
    //buscar<float>(genera_float, Busqueda<float>::busquedaBinaria, true);
    
    /* Búsqueda binaria sobre un objeto definido */
    /* TODO */
    //buscar<Persona>(genera_persona, Busqueda<Persona>::busquedaBinaria, true);
    buscar<Persona>(genera_persona, Busqueda<Persona>::busquedaSecuencial);
    
    return 0;
}
