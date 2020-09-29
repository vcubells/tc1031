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
    
    /* Obtener el elemento que se encuentra en una posición */
    Node<T> * at(int) const;
    
    /* Obtener la posición de un nodo */
    int at(Node<T> *) const;

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
void LinkedList<T>::insert(const T &, int)
{
    /* Por implementar */
}

template <class T>
void LinkedList<T>::insert(Node<T> * node, int)
{
    /* Por implementar */
}

/* Insertar un elemento al inicio */
template <class T>
void LinkedList<T>::insert_front(const T & value)
{
    /* Crear un nuevo nodo */
    Node<T> * node = new Node<T>(value);
    this->insert_front(node);
}

template <class T>
void LinkedList<T>::insert_front(Node<T> * node)
{
    /* Insertar el primer elemento */
    if (this->empty()) {
        this->_first = node;
    }
    /* Insertar cualquier elemento */
    else {
        node->setNext(this->_first);
        this->_first = node;
    }
    
    /* Incrementar el tamaño de la lista */
    ++this->_size;
}

/* Insertar un elemento al final */
template <class T>
void LinkedList<T>::insert_back(const T &)
{
    /* Por implementar */
}

template <class T>
void LinkedList<T>::insert_back(Node<T> *)
{
    /* Por implementar */
}

/* Eliminar el elemento en la posición dada */
template <class T>
Node<T> * LinkedList<T>::remove(int)
{
    /* Por implementar */
}

/* Eliminar el primer elemento */
template <class T>
Node<T> * LinkedList<T>::remove_front()
{
    /* Declarar una variable temporal */
    Node<T> * node = nullptr;
    
    /* Verificar si la lista no está vacía */
    if (!this->empty()) {
        
        /* Guardar una referencia al primer elemento */
        node = this->_first;
        
        /* Actualizamos first al siguiente elemento */
        this->_first = node->getNext();
        
        /* Estableciendo next en nullptr */
        node->setNext(nullptr);
        
        /* Decrementar el tamaño de la lista */
        --this->_size;
    }
    
    return node;
}

/* Eliminar el último elemento */
template <class T>
Node<T> * LinkedList<T>::remove_back()
{
    /* Por implementar */
}

/* Eliminar un elemento dado */
template <class T>
Node<T> * LinkedList<T>::remove(Node<T> *)
{
    /* Por implementar */
}

/* Eliminar todos los elementos de la lista y liberar la memoria ocupada */
template <class T>
void LinkedList<T>::clear()
{
    /* Por implementar */
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
