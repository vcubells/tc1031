//
//  BinaryTree.hpp
//  BinaryTree
//
//  Created by Vicente Cubells on 13/10/20.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <iostream>
#include <queue>
#include "TreeNode.hpp"

template <class T>
class BinaryTree {
protected:
    TreeNode<T> * root = nullptr;
    
    void clear(TreeNode<T> * );
    
public:
    BinaryTree() {}
    virtual ~BinaryTree();
    
    /* Insertar un nodo en el árbol */
    bool insert(T &, TreeNode<T> *);
    bool insert(TreeNode<T> *, TreeNode<T> *);
    
    bool empty() const;
    
    /* Eliminar un nodo del árbol */
    virtual TreeNode<T> * remove(T &);
    
    /* Eliminar todos los nodos del árbol */
    void clear();
    
    
    /* Recorridos de un árbol */
    void preOrden() const;
    void preOrden(TreeNode<T> *) const;

    void inOrden() const;
    void inOrden(TreeNode<T> *) const;
    
    void postOrden() const;
    void postOrden(TreeNode<T> *) const;
    
    int topN() const;
    int topN(TreeNode<T> *, int, int) const;
    
    void printLeaf() const;
    void printLeaf(TreeNode<T> *) const;
    
    void bfs();
    void bfs(TreeNode<T> *);
     
    TreeNode<T> * search(T value) const;
    TreeNode<T> * search(T value, TreeNode<T> *) const;
};

template <class T>
BinaryTree<T>::~BinaryTree()
{
    this->clear();
}

template <class T>
bool BinaryTree<T>::empty() const
{
    return this->root == nullptr;
}

/* Insertar un nodo en el árbol */
template <class T>
bool BinaryTree<T>::insert(T & value, TreeNode<T> * parent)
{
    return this->insert( new TreeNode<T>(value), parent );
}

template <class T>
bool BinaryTree<T>::insert(TreeNode<T> * node, TreeNode<T> * parent)
{
    /* Declarar variable para saber si se insertó el nodo */
    bool inserted = false;
    
    /* Verificar si el árbol está vacío */
    if (this->root == nullptr) {
        /* Establecer el nodo como raíz */
        this->root = node;
    }
    else if (parent == nullptr)
    {
        /* Insertar un nuevo nodo raiz */
        node->setLeft(root);
        root = node;
    }
    else {
        if (parent->getLeft() == nullptr) {
            parent->setLeft(node);
            inserted = true;
        }
        else if (parent->getRight() == nullptr) {
            parent->setRight(node);
            inserted = true;
            }
        else {
            inserted = insert(node, parent->getLeft() );
            if (!inserted) {
                insert(node, parent->getRight() );
            }
        }
    }
    
    return inserted;
}

/* Eliminar un nodo del árbol */
template <class T>
TreeNode<T> * BinaryTree<T>::remove(T &)
{
    return nullptr;
}

/* Eliminar todos los nodos del árbol */
template <class T>
void BinaryTree<T>::clear()
{
    this->clear(this->root);
    this->root = nullptr;
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


template <class T>
int BinaryTree<T>::topN() const
{
    return this->topN( this->root, 4, 0 );
}

template <class T>
int BinaryTree<T>::topN(TreeNode<T> * node, int n, int cont) const
{
    if (node != nullptr && cont < n) {
        
        /* Desplazarse a la izquierda */
        cont = topN( node->getRight(), n, cont );
         
        if (cont < n ) {
            std::cout << *node << " (" << ++cont << ") ";
        }
        else return cont;
        
        /* Desplazarse a la derecha */
        cont = topN( node->getLeft(), n, cont );
    }
    
    return cont;
}

/* Imprimir los nodos hojas de un árbol */
template <class T>
void BinaryTree<T>::printLeaf() const
{
    this->printLeaf( this->root );
}

template <class T>
void BinaryTree<T>::printLeaf(TreeNode<T> * node) const
{
    if (node != nullptr) {
        TreeNode<T> * left = node->getLeft();
        TreeNode<T> * right = node->getRight();
        
        if (left == nullptr && right == nullptr ) {
            /* Procesar el nodo */
            std::cout << *node << " ";
        }
        else {
            /* Desplazarse a la izquierda */
            printLeaf( left );
            
            /* Desplazarse a la derecha */
            printLeaf( right );
        }
    }
}

/* Reccorido de un árbol por niveles */
template <class T>
void BinaryTree<T>::bfs()
{
    /* Establecer el nivel de la raíz en 1 */
    if (!empty()) {
        this->root->setLevel(1);
        this->bfs( this->root );
    }
}

template <class T>
void BinaryTree<T>::bfs(TreeNode<T> * node)
{
    std::queue< TreeNode<T> * > q;
    
    q.push(node);
    
    TreeNode<T> * aux;
    
    int current_level = 1;
    
    std::cout << std::endl << "Level " << current_level << ": ";
    
    int level = 0;
    
    while (!q.empty()) {
        
        /* Sacar el primer elemento de la cola */
        aux = q.front();
        q.pop();
        
        level = aux->getLevel();
        
        /* Insertar en la cola el hijo izquierdo */
        TreeNode<T> * left = aux->getLeft();
        
        if (left != nullptr) {
            left->setLevel( level + 1);
            q.push(left);
        }
        
        /* Insertar en la cola el hijo derecho */
        TreeNode<T> * right = aux->getRight();
        
        if (right != nullptr) {
            right->setLevel(level + 1);
            q.push(right);
        }
        
        /* Si cambiamos de nivel, insertar un salto de linea */
        if (current_level != level ) {
            current_level += 1;
            std::cout << std::endl << "Level " << current_level << ": ";
        }
        
        /* Imprimiendo el nodo */
        std::cout << *aux << "  ";
    }
}


/* Búsqueda en un árbol */
template <class T>
TreeNode<T> * BinaryTree<T>::search(T value) const
{
    return search(value, this->root);
}

template <class T>
TreeNode<T> *  BinaryTree<T>::search(T value, TreeNode<T> * node) const
{
    TreeNode<T> * found = nullptr;
    
    if (node != nullptr) {
        /* Procesar el nodo */
        if (node->getInfo() == value) {
            return node;
        }
        else {
            /* Desplazarse a la izquierda */
            found = search(value, node->getLeft() );
            
            /* Desplazarse a la derecha */
            if (!found) {
                found = search(value, node->getRight() );
            }
        }
    }
    
    return found;
}
#endif /* BinaryTree_hpp */
