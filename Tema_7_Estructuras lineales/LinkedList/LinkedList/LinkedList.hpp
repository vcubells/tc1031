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
     * Nota: No liberan la memoria ocupada por el nodo eliminado
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
    
    /* Obtener el nodo que se encuentra en una posición */
    Node<T> * at(int) const;
    
    /* Obtener la posición de un nodo */
    int index(Node<T> *) const;
    
    /* Obtener la posición de un valor */
    int index(const T &) const;

    /* Mostrar el contenido de la lista */
    template <typename Tn>
    friend std::ostream & operator <<(std::ostream &, const LinkedList<Tn> &);
};

template <class T>
LinkedList<T>::~LinkedList()
{
    this->clear();
}


/* Obtener el tamaño de la lista */
template <class T>
int LinkedList<T>::size() const
{
    return this->_size;
}

/* Obtener el primer elemento */
template <class T>
Node<T> * LinkedList<T>::first() const
{
    return this->_first;
}

/* Determinar si la lista está vacía */
template <class T>
bool LinkedList<T>::empty() const
{
    return this->_first == nullptr;
}

/* Insertar un elemento en una posición dada */
template <class T>
void LinkedList<T>::insert(const T & value, int position)
{
    /* Crear el nuevo nodo a insertar */
    Node<T> * newnode = new Node<T>(value);
    
    this->insert(newnode, position);
}
/* Insertar un nodo en una posición dada
 * Si position < 0 se inserta al inicio
 * Si position > _size se inserta al final
 * en cualquier otro caso, se inserta en la posición dada
 */
template <class T>
void LinkedList<T>::insert(Node<T> * node, int position)
{
    /* Cuando la lista está vacía o position < 0 se inserta al inicio */
    if (this->empty() || position <= 0) {
        node->setNext(this->_first);
        this->_first = node;
    }
    /* Cuando se inserta en cualquier posición diferente del inicio */
    else {
        
        /* Si position > size se inserta al final */
        if (position > this->_size) { position = this->_size; }
        
        /* Obtener el nodo que está en la posición anterior */
        Node<T> * previous = this->at(position-1);
        
        /* Actualizar apuntadores */
        node->setNext(previous->getNext());
        previous->setNext(node);
    }
    
    /* Incrementar el tamaño de la lista */
    ++this->_size;
}

/* Insertar un elemento al inicio */
template <class T>
void LinkedList<T>::insert_front(const T & value)
{
    this->insert(value, 0);
}

template <class T>
void LinkedList<T>::insert_front(Node<T> * node)
{
    this->insert(node, 0);
}

/* Insertar un elemento al final */
template <class T>
void LinkedList<T>::insert_back(const T & value)
{
    this->insert(value, this->_size);
}

template <class T>
void LinkedList<T>::insert_back(Node<T> * node)
{
    this->insert(node, this->_size);
}

/* Eliminar el elemento en la posición dada */
template <class T>
Node<T> * LinkedList<T>::remove(int position)
{
    /* Cuando la lista está vacía o position es inválida */
    if (this->empty() || (position < 0 || position >= this->_size )) {
        return nullptr;
    }

    /* Declarar variable temporal para guardar el nodo a eliminar */
    Node<T> * removenode;
    
    /* Eliminar el primer nodo de la lista */
    if (position == 0) {
        /* Se guarda el apuntador a first */
        removenode = this->_first;
        
        /* Se actualiza first al siguiente nodo */
        this->_first = this->_first->getNext();
        
    }
    /* Eliminar cualquier otro nodo */
    else {
        /* Se obtiene el apuntador al anterior */
        Node<T> * previous = this->at(position-1);
        
        /* Se guarda el apuntador al nodo a eliminar */
        removenode = previous->getNext();
        
        /* Se actualiza el anterior para que apunte al siguiente nodo */
        previous->setNext(removenode->getNext());
    }

    /* Establecer el siguiente en nullptr */
    removenode->setNext(nullptr);
    
    /* Decrementar el tamaño de la lista */
    --this->_size;
    
    return removenode;
}

/* Eliminar el primer elemento */
template <class T>
Node<T> * LinkedList<T>::remove_front()
{
    return this->remove(0);
}

/* Eliminar el último elemento */
template <class T>
Node<T> * LinkedList<T>::remove_back()
{
    return this->remove(this->_size - 1);
}

/* Eliminar un elemento dado */
template <class T>
Node<T> * LinkedList<T>::remove(Node<T> * node)
{
    return this->remove( this->index(node) );
}

/* Eliminar todos los elementos de la lista y liberar la memoria ocupada */
template <class T>
void LinkedList<T>::clear()
{
    /* Cuando la lista está vacía */
    if ( this->empty() ) { return; }
    
    /* Obtener una referencia al primer nodo */
    Node<T> * tmp = this->_first;
    
    /* Desplazarse por la lista e ir eliminando los nodos */
    while (tmp != nullptr) {
        /* Mover first al siguiente elemento */
        this->_first = tmp->getNext();
        
        /* Liberar la memoria del nodo */
        delete tmp;
        
        /* Apuntar al primero */
        tmp = this->_first;
    }
    
    /* Establecer el size en 0 */
    this->_size = 0;
    
    /* Establecer first en nullptr */
    this->_first = nullptr;
}

/* Obtener el nodo que se encuentra en una posición */
template  <class T>
Node<T> *  LinkedList<T>::at(int position) const
{
    /* Cuando la lista está vacía o position es inválida */
    if (this->empty() || (position < 0 || position >= this->_size )) {
        return nullptr;
    }
    
    /*  Buscar el nodo que se encuentra en position */
    int pos = 0;
    
    /* Obtener una referencia al primer nodo */
    Node<T> * tmp = this->_first;
    
    /* Desplazarse por la lista hasta encontrar el nodo */
    while (tmp != nullptr && pos++ < position)
    {
        tmp = tmp->getNext();
    }
    
    return tmp;
}

/* Obtener la posición de un nodo */
template  <class T>
int LinkedList<T>::index(Node<T> * node) const
{
    /* Cuando la lista está vacía o node es nullptr */
    if (this->empty() || node == nullptr) {
        return -1;
    }
    
    /* Buscar el valor del nodo y regresar su posición */
    return this->index( node->getInfo() );
}

/* Obtener la posición de un valor */
template  <class T>
int LinkedList<T>::index(const T & value) const
{
    /* Cuando la lista está vacía */
    if ( this->empty() ) {
        return -1;
    }
    
    /* Buscar value y regresar su posición */
    int pos = 0;
    
    /* Obtener una referencia al primer nodo */
    Node<T> * tmp = this->_first;
    
    /* Desplazarse por la lista hasta encontrar el value */
    while (tmp != nullptr && tmp->getInfo() != value)
    {
        tmp = tmp->getNext();
        ++pos;
    }
    
    /* Si el value no se encuentra en la lista */
    if (pos == this->_size) { return -1; }
    
    return pos;
}

/* Mostrar el contenido de la lista */
template <class T>
std::ostream & operator <<(std::ostream & os, const LinkedList<T> & list)
{
    /* Obtener el primer elemento de la lista */
    Node<T> * tmp = list._first;
    
    /* Desplazarse mientras tmp != nullptr */
    while (tmp != nullptr) {
        os << *tmp << std::endl;
        
        /* Desplazar el apuntador al siguiente elemento */
        tmp = tmp->getNext();
    }
    
    return os;
}


#endif /* LinkedList_hpp */
