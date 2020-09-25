//
//  main.cpp
//  LinkedList
//
//  Created by Vicente Cubells on 25/09/20.
//

#include <iostream>
#include "Node.hpp"

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
    
    
    return 0;
}
