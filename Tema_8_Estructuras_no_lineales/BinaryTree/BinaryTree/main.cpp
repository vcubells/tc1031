//
//  main.cpp
//  BinaryTree
//
//  Created by Vicente Cubells on 13/10/20.
//

#include <iostream>
#include "TreeNode.hpp"
#include "BinaryTree.hpp"
#include "BST.hpp"

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
    
    
    /* Creación de un BinaryTree vacío */
    std::cout << std::endl;
    std::cout << "--- Demostración del uso de un Binary Tree ---" << std::endl;
    std::cout << std::endl;
    
    /* Crear un árbol */
    std::cout << "(C) Se crea un árbol vacío" << std::endl;
    BinaryTree<int> * tree = new BinaryTree<int>();
    
    /* Insertar nodos en el árbol */
    
    std::cout << "(I) Se insertó la raiz" << std::endl;
    TreeNode<int> * root = new TreeNode<int>(1);
    
    tree->insert(root, nullptr);
    
    std::cout << "(I) Se insertaron algunos nodos" << std::endl;
    
    TreeNode<int> * a = new TreeNode<int>(2);
    TreeNode<int> * b = new TreeNode<int>(3);
    TreeNode<int> * c = new TreeNode<int>(4);
    TreeNode<int> * d = new TreeNode<int>(5);
    TreeNode<int> * e = new TreeNode<int>(6);
    TreeNode<int> * f = new TreeNode<int>(7);
    
    tree->insert(a, root);
    tree->insert(b, root);
    tree->insert(c, root);
    tree->insert(d, root);
    
    tree->insert(e, b);
    tree->insert(f, b);
    
    std::cout << "(V) Se imprime el árbol en PreOrden" << std::endl;
    tree->preOrden();
    std::cout << std::endl;
    
    std::cout << "(V) Se imprime el árbol en InOrden" << std::endl;
    tree->inOrden();
    std::cout << std::endl;
    
    std::cout << "(V) Se imprime el árbol en PostOrden" << std::endl;
    tree->postOrden();
    std::cout << std::endl;
    
    std::cout << "(C) Se eliminan todos los nodos del árbol" << std::endl;
    tree->clear();
    
    /* Determinar si el árbol está vacío */
    std::cout << (tree->empty() ? "(E) El árbol está vacío" : "(E) El árbol tiene elementos") << std::endl;
    
    /* Eliminar la memoria ocupada por el árbol */
    delete tree;
    std::cout << "(D) Se liberó la memoria del árbol" << std::endl;
    
    
    /* Creación de un BST vacío */
    std::cout << std::endl;
    std::cout << "--- Demostración del uso de un Binary Search Tree ---" << std::endl;
    std::cout << std::endl;
    
    /* Crear un árbol */
    std::cout << "(C) Se crea un BST vacío" << std::endl;
    BST<int> * bst = new BST<int>();
    
    /* Insertar nodos en el árbol */
    
    std::cout << "(I) Se insertaron algunos nodos" << std::endl;
    
    TreeNode<int> * na = new TreeNode<int>(10);
    TreeNode<int> * nb = new TreeNode<int>(8);
    TreeNode<int> * nc = new TreeNode<int>(4);
    TreeNode<int> * nd = new TreeNode<int>(12);
    TreeNode<int> * ne = new TreeNode<int>(6);
    TreeNode<int> * nf = new TreeNode<int>(9);
    
    bst->insert(na);
    bst->insert(nb);
    bst->insert(nc);
    bst->insert(nd);
    bst->insert(ne);
    bst->insert(nf);
    
    /* Insertar un nodo repetido */
    TreeNode<int> * repetido = new TreeNode<int>(9);
    bool inserted = bst->insert(repetido);
    
    std::cout << (inserted ? "(I) El valor 9 se insertó" : "(I) El valor 9 ya existe existe") << std::endl;
    
    std::cout << "(V) Se imprime el BST en PreOrden" << std::endl;
    bst->preOrden();
    std::cout << std::endl;
    
    std::cout << "(V) Se imprime el BST en InOrden" << std::endl;
    bst->inOrden();
    std::cout << std::endl;
    
    std::cout << "(V) Se imprime el BST en PostOrden" << std::endl;
    bst->postOrden();
    std::cout << std::endl;
    
    std::cout << "(V) Se imprimen los primeros n elementos en InOrden" << std::endl;
    int nodos = bst->topN();
    std::cout << std::endl;
    std::cout << "El BTS tiene " << nodos <<" nodos" << std::endl;
    std::cout << std::endl;
    
    TreeNode<int> * exist = bst->search(6);
    /* Buscar si el nodo existe */
    if (exist != nullptr) {
        std::cout << "(S) El valor 6 se encontró y su padre es ";
        std::cout << exist->getParent()->getInfo() << std::endl;
    }
    else {
        std::cout << "(S) El valor 6 no existe" << std::endl;
    }
    
    exist = bst->search(20);
    /* Buscar si el nodo existe */
    std::cout << (exist ? "(S) El valor 20 se encontró" : "(S) El valor 20 no existe") << std::endl;
    
    std::cout << "(C) Se eliminan todos los nodos del árbol" << std::endl;
    bst->clear();
    
    /* Determinar si el BST está vacío */
    std::cout << (bst->empty() ? "(E) El BST está vacío" : "(E) El BST tiene elementos") << std::endl;
    
    /* Eliminar la memoria ocupada por el BST */
    delete bst;
    std::cout << "(D) Se liberó la memoria del BST" << std::endl;
    
    
    return 0;
}
