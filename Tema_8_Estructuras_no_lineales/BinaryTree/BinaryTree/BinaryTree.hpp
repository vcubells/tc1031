//
//  BinaryTree.hpp
//  BinaryTree
//
//  Created by Vicente Cubells on 13/10/20.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <iostream>
#include "TreeNode.hpp"

template <class T>
class BinaryTree {
    TreeNode<T> * root = nullptr;
    
public:
    BinaryTree() {}
    virtual ~BinaryTree();
    
    /* Insertar un nodo en el árbol */
    void insert(T &);
    void insert(TreeNode<T> *, TreeNode<T> *);
    
    /* Eliminar un nodo del árbol */
    TreeNode<T> * remove(T &);
    
    /* Eliminar todos los nodos del árbol */
    void clear();
    void clear(TreeNode<T> * );
    
    /* Recorridos de un árbol */
    void preOrden() const;
    void preOrden(TreeNode<T> *) const;
    
    void inOrden() const;
    void inOrden(TreeNode<T> *) const;
    
    void postOrden() const;
    void postOrden(TreeNode<T> *) const;
    
    /* Mostrar el contenido del árbol */
    template <typename Tn>
    friend std::ostream & operator <<(std::ostream &, const BinaryTree<Tn> &);
};

template <class T>
BinaryTree<T>::~BinaryTree()
{
    this->clear();
}

/* Insertar un nodo en el árbol */
template <class T>
void BinaryTree<T>::insert(T & value)
{
    this->insert( new TreeNode<T>(value), this->root );
}

template <class T>
void BinaryTree<T>::insert(TreeNode<T> * node, TreeNode<T> * current)
{
    /* Verificar si el árbol está vacío */
    if (this->root == nullptr) {
        /* Establecer el nodo como raíz */
        this->root = node;
    }
    else {
        if (current->getLeft() == nullptr) {
            current->setLeft(node);
        }
        else if (current->getRight() == nullptr) {
                current->setRight(node);
            }
        else {
            insert(node, current->getLeft() );
            insert(node, current->getRight() );
        }
    }
}

/* Eliminar un nodo del árbol */
template <class T>
TreeNode<T> * BinaryTree<T>::remove(T &)
{
    
}

/* Eliminar todos los nodos del árbol */
template <class T>
void BinaryTree<T>::clear()
{
    this->clear(this->root);
}

template <class T>
void BinaryTree<T>::clear(TreeNode<T> * node)
{
    if (node != nullptr) {
        clear( node->getLeft() );
        clear( node->getRight() );
        delete node;
    }
}

/* Recorridos de un árbol */
template <class T>
void BinaryTree<T>::preOrden() const
{
    this->preOrden( this->root );
}

template <class T>
void BinaryTree<T>::preOrden(TreeNode<T> * node) const
{
    if (node != nullptr) {
        /* Procesar el nodo */
        std::cout << *node << " ";
        
        /* Desplazarse a la izquierda */
        preOrden( node->getLeft() );
        
        /* Desplazarse a la derecha */
        preOrden( node->getRight() );
    }
}

template <class T>
void BinaryTree<T>::inOrden() const
{
    this->inOrden( this->root );
}

template <class T>
void BinaryTree<T>::inOrden(TreeNode<T> * node) const
{
    if (node != nullptr) {
        /* Desplazarse a la izquierda */
        inOrden( node->getLeft() );
        
        /* Procesar el nodo */
        std::cout << *node << " ";
        
        /* Desplazarse a la derecha */
        inOrden( node->getRight() );
    }
}

template <class T>
void BinaryTree<T>::postOrden() const
{
    this->postOrden( this->root );
}

template <class T>
void BinaryTree<T>::postOrden(TreeNode<T> * node) const
{
    if (node != nullptr) {
        /* Desplazarse a la izquierda */
        postOrden( node->getLeft() );
        
        /* Desplazarse a la derecha */
        postOrden( node->getRight() );
        
        /* Procesar el nodo */
        std::cout << *node << " ";
    }
}

/* Mostrar el contenido del árbol */
template <class T>
std::ostream & operator <<(std::ostream &, const BinaryTree<T> &)
{
    
}

#endif /* BinaryTree_hpp */
