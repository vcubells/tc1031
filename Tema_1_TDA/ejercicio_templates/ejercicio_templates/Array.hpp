//
//  Array.hpp
//  ejercicio_templates
//
//  Created by Vicente Cubells on 12/08/21.
//

#ifndef Array_hpp
#define Array_hpp

#include <iostream>

#define MAX 5

/* Declaración de la clase template */

template <class T>
class Array
{
private:
    T datos[MAX];     // Espacio de almacenamiento
    int longitud = 0;   // Cantidad de elementos
    
public:
    T obtener(int index);
    int getLongitud();
    bool estaLleno();
    T eliminar();
    void insertar(T item);
    void imprimir();
};

/* Implemenación de la clase template */

template <class T>
T Array<T>::obtener(int index)
{
    T item;
    
    if (index >= 0 && index < longitud)
    {
        item = datos[index];
    }
    else {
        std::cout << "Índice fuera de rango, no se puede obtener el elemento" << std::endl;
    }
    
    return item;
}

template <class T>
int Array<T>::getLongitud()
{
    return longitud;
}

template <class T>
bool Array<T>::estaLleno()
{
    return longitud == MAX;
}

template <class T>
T Array<T>::eliminar()
{
    T item;
    if (longitud > 0) {
        item = datos[longitud-1];
        --longitud;
    }
    else {
        std::cout << "El arreglo está vacío, no se puede borrar un elemento" << std::endl;
    }
        
    return item;
}

template <class T>
void Array<T>::insertar(T item)
{
    if (!estaLleno()) {
        datos[longitud] = item;
        ++longitud;
    }
    else {
        std::cout << "El arreglo está lleno, no se puede insertar el elemento" << std::endl;
    }
}

template <class T>
void Array<T>::imprimir()
{
    for (int i = 0; i < longitud; ++i) {
        std::cout << datos[i] << std::endl;
        //operator<<(std::cout, datos[i]);
    }
}



#endif /* Array_hpp */
