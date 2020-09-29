//
//  main.cpp
//  LinkedList
//
//  Created by Vicente Cubells on 25/09/20.
//

#include <iostream>
#include "Node.hpp"
#include "LinkedList.hpp"

int main(int argc, const char * argv[]) {
    
    /* Uso de constructor predeterminado Node<T>() */
    Node<int> n1;
    std::cout << n1 << std::endl;
    
    /* Uso de constructor con parámetros Node<T>(T) */
    Node<float> n2(3.14);
    std::cout << n2 << std::endl;
    
    /* Uso de constructor copia Node<T>(Node<T> &) */
    Node<int> n3 = n1;
    std::cout << n3 << std::endl;
    
    /* Crear un nodo con memoria dinámica */
    Node<int> * nodeptr = new Node<int>(10);
    std::cout << *nodeptr << std::endl;
    
    /* Liberar la memoria ocupada por el nodo */
    delete nodeptr;
    
    
    /* Crear una lista */
    LinkedList<int> * list = new LinkedList<int>();
    
    /* Determinar si la lista está vacía */
    std::cout << (list->empty() ? "La lista está vacía" : "La lista tiene elementos") << std::endl;
    
    /* Insertar elementos en la lista */
    list->insert_front(1);
    list->insert_front(2);
    
    /* Mostrar el contenido de la lista */
    std::cout << *list << std::endl;
    
    /* Obtener tamaño de la lista */
    std::cout << "Tamaño de la lista: " << list->size() << " elementos" << std::endl;
    
    /* Eliminar un elemento */
    Node<int> * node = list->remove_front();
    
    std::cout << "El nodo eliminado es: " << *node << std::endl;
    
    /* Liberar la memoria del nodo eliminado */
    delete node;
    
    
    /* Eliminar un elemento */
    node = list->remove_front();
    
    std::cout << "El nodo eliminado es: " << *node << std::endl;
    
    /* Liberar la memoria del nodo eliminado */
    delete node;
    
    /* Determinar si la lista está vacía */
    std::cout << (list->empty() ? "La lista está vacía" : "La lista tiene elementos") << std::endl;
    
    /* Liberar la memoria de la lista */
    delete list;
    
    
    return 0;
}
