//
//  main.cpp
//  LinkedList
//
//  Created by Vicente Cubells on 25/09/20.
//

#include <iostream>
#include "Node.hpp"
#include "LinkedList.hpp"
#include "SortedLinkedList.hpp"

int main(int argc, const char * argv[]) {
    
    /* Creación de nodos */
    std::cout << "--- Creación y eliminación de nodos ---" << std::endl;
    std::cout << std::endl;
    
    /* Uso de constructor predeterminado Node<T>() */
    Node<int> n1;
    std::cout << "-> Nodo creado con constructor predeterminado: " << n1 << std::endl;
    
    /* Uso de constructor con parámetros Node<T>(T) */
    Node<float> n2(3.14);
    std::cout << "-> Nodo creado con constructor con parámetros: " << n2 << std::endl;
    
    /* Uso de constructor copia Node<T>(Node<T> &) */
    Node<int> n3 = n1;
    std::cout << "-> Nodo creado con constructor copia: " << n3 << std::endl;
    
    /* Crear un nodo con memoria dinámica */
    Node<int> * nodeptr = new Node<int>(10);
    std::cout << "-> Nodo creado con memoria dinámica: " << *nodeptr << std::endl;
    
    /* Liberar la memoria ocupada por el nodo */
    std::cout << "<- Nodo eliminado con delete: " << *nodeptr << std::endl;
    delete nodeptr;
    
    /* Trabajo con una LinkedList */
    std::cout << std::endl;
    std::cout << "--- Demostración de uso de la LinkedList ---" << std::endl;
    std::cout << std::endl;
    
    /* Crear una lista */
    std::cout << "(C) Se crea una lista vacía" << std::endl;
    LinkedList<int> * list = new LinkedList<int>();
    
    /* Determinar si la lista está vacía */
    std::cout << (list->empty() ? "(E) La lista está vacía" : "(E) La lista tiene elementos") << std::endl;
    
    /* Insertar un elemento al inicio de la lista */
    std::cout << "(I) Se inserta el 1 al inicio" << std::endl;
    list->insert_front(1);

    /* Insertar un elemento al final de la lista */
    std::cout << "(I) Se inserta el 2 al final" << std::endl;
    list->insert_back(2);
    
    /* Insertar un elemento en una posición intermedia de la lista */
    std::cout << "(I) Se inserta el 5 en la posición 1" << std::endl;
    list->insert(5,1);
    
    /* Insertar un elemento en una posición intermedia de la lista */
    std::cout << "(I) Se inserta el 8 en la posición 1" << std::endl;
    list->insert(8,1);
    
    /* Mostrar el contenido de la lista */
    std::cout << "(L) La lista tiene los siguientes elementos: " << std::endl;
    std::cout << *list << std::endl;
    
    /* Obtener tamaño de la lista */
    std::cout << "(S) Tamaño de la lista: " << list->size() << " elementos" << std::endl;
    
    /* Obtener el nodo que está en una posición  */
    Node<int> * at = list->at(2);
    
    if (at != nullptr) {
        std::cout << "(P) El nodo que se encuentra en la posición 2 es el: " << *at << std::endl;
    }
    
    /* Obtener el nodo que está en una posición [] */
    at = list->operator[](3);
        
    if (at != nullptr) {
        std::cout << "(P) El nodo que se encuentra en la posición 3 es el: " << *at << std::endl;
    }
    
    /* Obtener el nodo que está en una posición  */
    std::cout << "(P) El 8 se encuentra en la posición: " << list->index(8) << std::endl;
    
    /* Obtener tamaño de la lista */
    std::cout << "(N) El 8 se repite: " << list->count(8) << " veces" << std::endl;
    
    /* Invertir la lista */
    std::cout << "(U) Se invierte la lista" << std::endl;
    list->reverse();
    
    /* Mostrar el contenido de la lista */
    std::cout << "(L) La lista tiene los siguientes elementos: " << std::endl;
    std::cout << *list << std::endl;
    
    /* Eliminar un elemento del inicio de la lista */
    Node<int> * node = list->remove_front();
    
    std::cout << "(R) Se eliminó el nodo del inicio: " << *node << std::endl;
    
    /* Liberar la memoria del nodo eliminado */
    delete node;
    std::cout << "(D) Se liberó la memoria del nodo eliminado" << std::endl;
    
    /* Eliminar un elemento del final de la lista */
    node = list->remove_back();
    
    std::cout << "(R) Se eliminó el nodo del final: " << *node << std::endl;
    
    /* Liberar la memoria del nodo eliminado */
    delete node;
    std::cout << "(D) Se liberó la memoria del nodo eliminado" << std::endl;
    
    /* Insertar un elemento en una posición intermedia de la lista */
    std::cout << "(I) Se inserta el 10 en la posición 10" << std::endl;
    list->insert(10,10);
    
    /* Mostrar el contenido de la lista */
    std::cout << "(L) La lista tiene los siguientes elementos: " << std::endl;
    std::cout << *list << std::endl;
    
    /* Eliminar un elemento */
    node = list->remove(1);
    std::cout << "(R) Se eliminó el nodo de la posición 1: " << *node << std::endl;
    
    /* Liberar la memoria del nodo eliminado */
    delete node;
    std::cout << "(D) Se liberó la memoria del nodo eliminado" << std::endl;
    
    /* Obtener tamaño de la lista */
    std::cout << "(S) Tamaño de la lista: " << list->size() << " elementos" << std::endl;
    
    /* Vaciar la lista */
    list->clear();
    std::cout << "(V) Se vació la lista"<< std::endl;
    
    /* Determinar si la lista está vacía */
    std::cout << (list->empty() ? "(E) La lista está vacía" : "(E) La lista tiene elementos") << std::endl;
    
    /* Liberar la memoria de la lista */
    delete list;
    std::cout << "(D) Se liberó la memoria de la lista" << std::endl;
    
    
    /* Trabajo con una SortedLinkedList */
    std::cout << std::endl;
    std::cout << "--- Demostración de uso de la SortedLinkedList ---" << std::endl;
    std::cout << std::endl;
    
    /* Crear una lista */
    std::cout << "(C) Se crea una lista ordenada vacía" << std::endl;
    SortedLinkedList<int> * sortedlist = new SortedLinkedList<int>();
    
    /* Determinar si la lista está vacía */
    std::cout << (sortedlist->empty() ? "(E) La lista ordenada está vacía" : "(E) La lista ordenada tiene elementos") << std::endl;
    
    /* Insertar un elemento al inicio de la lista */
    std::cout << "(I) Se inserta el 1" << std::endl;
    sortedlist->insert(1);

    /* Insertar un elemento al final de la lista */
    std::cout << "(I) Se inserta el 2" << std::endl;
    sortedlist->insert(2);
    
    /* Insertar un elemento en una posición intermedia de la lista */
    std::cout << "(I) Se inserta el 5" << std::endl;
    sortedlist->insert(5);
    
    /* Insertar un elemento en una posición intermedia de la lista */
    std::cout << "(I) Se inserta el 8" << std::endl;
    sortedlist->insert(8);
    
    /* Insertar un elemento en una posición intermedia de la lista */
    std::cout << "(I) Se inserta el 4" << std::endl;
    sortedlist->insert(4);
    
    /* Mostrar el contenido de la lista */
    std::cout << "(L) La lista ordenada tiene los siguientes elementos: " << std::endl;
    std::cout << *sortedlist << std::endl;
    
    /* Obtener tamaño de la lista */
    std::cout << "(S) Tamaño de la lista ordenada: " << sortedlist->size() << " elementos" << std::endl;
    
    /* Obtener el nodo que está en una posición  */
    at = sortedlist->at(2);
    
    if (at != nullptr) {
        std::cout << "(P) El nodo que se encuentra en la posición 2 es el: " << *at << std::endl;
    }

    /* Obtener el nodo que está en una posición  */
    std::cout << "(P) El 8 se encuentra en la posición: " << sortedlist->index(8) << std::endl;
    
    /* Obtener tamaño de la lista */
    std::cout << "(N) El 8 se repite: " << sortedlist->count(8) << " veces" << std::endl;
    
    /* Invertir la lista */
    std::cout << "(U) Se invierte la lista ordenada" << std::endl;
    sortedlist->reverse();
    
    /* Mostrar el contenido de la lista */
    std::cout << "(L) La lista ordenada tiene los siguientes elementos: " << std::endl;
    std::cout << *sortedlist << std::endl;
    
    /* Eliminar un elemento del inicio de la lista */
    node = sortedlist->remove_front();
    
    std::cout << "(R) Se eliminó el nodo del inicio: " << *node << std::endl;
    
    /* Liberar la memoria del nodo eliminado */
    delete node;
    std::cout << "(D) Se liberó la memoria del nodo eliminado" << std::endl;
    
    /* Eliminar un elemento del final de la lista */
    node = sortedlist->remove_back();
    
    std::cout << "(R) Se eliminó el nodo del final: " << *node << std::endl;
    
    /* Liberar la memoria del nodo eliminado */
    delete node;
    std::cout << "(D) Se liberó la memoria del nodo eliminado" << std::endl;
    
    /* Mostrar el contenido de la lista */
    std::cout << "(L) La lista ordenada tiene los siguientes elementos: " << std::endl;
    std::cout << *sortedlist << std::endl;
    
    /* Eliminar un elemento */
    node = sortedlist->remove(1);
    std::cout << "(R) Se eliminó el nodo de la posición 1: " << *node << std::endl;
    
    /* Liberar la memoria del nodo eliminado */
    delete node;
    std::cout << "(D) Se liberó la memoria del nodo eliminado" << std::endl;
    
    /* Obtener tamaño de la lista */
    std::cout << "(S) Tamaño de la lista ordenada: " << sortedlist->size() << " elementos" << std::endl;
    
    /* Vaciar la lista */
    sortedlist->clear();
    std::cout << "(V) Se vació la lista ordenada"<< std::endl;
    
    /* Determinar si la lista está vacía */
    std::cout << (sortedlist->empty() ? "(E) La lista ordenada está vacía" : "(E) La lista ordenada tiene elementos") << std::endl;
    
    /* Liberar la memoria de la lista */
    delete sortedlist;
    std::cout << "(D) Se liberó la memoria de la lista ordenada" << std::endl;
    
    
    return 0;
}
