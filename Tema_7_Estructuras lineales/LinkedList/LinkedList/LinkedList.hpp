//
//  LinkedList.hpp
//  LinkedList
//
//  Created by Vicente Cubells on 25/09/20.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>
#include "Node.hpp"

template <class T>
class LinkedList {
private:
    Node<T> * _first = nullptr;
    int _size = 0;
    
public:
    /* Constructor */
    LinkedList() { };
    
    /* Destructor */
    virtual ~LinkedList();
    
    /* Obtener el tamaño de la lista */
    int size() const;
    
    /* Obtener el primer elemento */
    Node<T> * first() const;
    
    /* Determinar si la lista está vacía */
    bool empty() const;
    
    /* Insertar un elemento en una posición dada */
    void insert(const T &, int);
    void insert(Node<T> *, int);
    
    /* Insertar un elemento al inicio */
    void insert_front(const T &);
    void insert_front(Node<T> *);

    /* Insertar un elemento al final */
    void insert_back(const T &);
    void insert_back(Node<T> *);
    
    /* Eliminar un elemento y regresar un apuntador al mismo.
     * Nota: No liberan la memmoria ocupada por el nodo eliminado
     */
    /* Eliminar el elemento en la posición dada */
    Node<T> * remove(int);
    
    /* Eliminar el primer elemento */
    Node<T> * remove_front();
    
    /* Eliminar el último elemento */
    Node<T> * remove_back();
    
    /* Eliminar un elemento dado */
    Node<T> * remove(Node<T> *);
    
    /* Eliminar todos los elementos de la lista y liberar la memoria ocupada */
    virtual void clear();
    
    /* Obtener el elemento que se encuentra en una posición */
    Node<T> * at(int) const;
    
    /* Obtener la posición de un nodo */
    int at(Node<T> *) const;

    /* Mostrar el contenido de la lista */
    template <typename Tn>
    friend std::ostream & operator <<(std::ostream &, const LinkedList<Tn> &);
};

#endif /* LinkedList_hpp */
