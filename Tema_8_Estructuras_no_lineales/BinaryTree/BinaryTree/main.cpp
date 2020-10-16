//
//  main.cpp
//  BinaryTree
//
//  Created by Vicente Cubells on 13/10/20.
//

#include <iostream>
#include "TreeNode.hpp"

int main(int argc, const char * argv[]) {
    
    /* Creación de nodos */
    std::cout << "--- Creación y eliminación de nodos ---" << std::endl;
    std::cout << std::endl;
    
    /* Uso de constructor predeterminado TreeNode<T>() */
    TreeNode<int> n1;
    std::cout << "-> Nodo creado con constructor predeterminado: " << n1 << std::endl;
    
    /* Uso de constructor con parámetros TreeNode<T>(T) */
    TreeNode<float> n2(3.14);
    std::cout << "-> Nodo creado con constructor con parámetros: " << n2 << std::endl;
    
    /* Uso de constructor copia TreeNode<T>(TreeNode<T> &) */
    TreeNode<int> n3 = n1;
    std::cout << "-> Nodo creado con constructor copia: " << n3 << std::endl;
    
    /* Crear un nodo con memoria dinámica */
    TreeNode<int> * nodeptr = new TreeNode<int>(10);
    std::cout << "-> Nodo creado con memoria dinámica: " << *nodeptr << std::endl;
    
    /* Liberar la memoria ocupada por el nodo */
    std::cout << "<- Nodo eliminado con delete: " << *nodeptr << std::endl;
    delete nodeptr;
    
    
    return 0;
}
