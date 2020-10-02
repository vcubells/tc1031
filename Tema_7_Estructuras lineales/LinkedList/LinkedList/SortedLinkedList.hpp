//
//  SortedLinkedList.hpp
//  LinkedList
//
//  Created by Vicente Cubells on 02/10/20.
//

#ifndef SortedLinkedList_hpp
#define SortedLinkedList_hpp

#include <iostream>
#include "LinkedList.hpp"

template <class T>
class SortedLinkedList : public LinkedList<T>
{
public:
    /* Constructor */
    SortedLinkedList() { };
    
    /* Destructor */
    virtual ~SortedLinkedList() { };
    
    /* Insertar de manera ordenada */
    void insert(const T &);
    void insert(Node<T> *);
    
    /* Obtener la posición de un valor */
    int index(const T &) const override;
    
    /* Obtener la cantidad de ocurrencias de un elemento en una lista ordenada */
    int count(const T &) const override;
    
    /* Eliminar los elementos duplicados en una lista ordenada */
    void remove_duplicates();
private:
    /* Ocultar algunos métodos heredados */
    using LinkedList<T>::insert_back;
    using LinkedList<T>::insert_front;
    using LinkedList<T>::insert;
};


/* Insertar un nodo en la posición que le corresponde
 * Complejidad: O(1) si es al inicio, O(n) cualquier otro caso
 */
template <class T>
void SortedLinkedList<T>::insert(const T & value)
{
    /* Crear el nuevo nodo a insertar */
    Node<T> * newnode = new Node<T>(value);
    
    this->insert(newnode);
}

template <class T>
void SortedLinkedList<T>::insert(Node<T> * node)
{
    /* Obtener una referencia al primer elemento */
    Node<T> * tmp = this->_first;
    
    /* Usar una referencia al nodo anterior */
    Node<T> * previous = nullptr;
    
    /* Obtener la info del nodo a insertar */
    T info = node->getInfo();
    
    /* Obtener la posición que le corresponde */
    while (tmp != nullptr && tmp->getInfo() < info ) {
        
        /* Mover previous a la posición de tmp */
        previous = tmp;
        
        /* Desplazarse al siguiente elemento */
        tmp = tmp->getNext();
    }
    
    /* Determinar si va al inicio */
    if (tmp == this->_first)
    {
        /* Poner first a apuntar a node */
        this->_first = node;
    }
    else {
        /* Poner el anterior a apuntar a node */
        previous->setNext(node);
    }
    
    /* Poner node a apuntar al que le sigue */
    node->setNext(tmp);
    
    /* Incrementar el tamaño de la lista */
    ++this->_size;
}

/* Obtener la cantidad de ocurrencias de un elemento en una lista ordenada
 * Complejidad: O(n)
 */
template  <class T>
int SortedLinkedList<T>::count(const T & value) const
{
    /* Obtener una referencia al primer elemento */
    Node<T> * tmp = this->_first;
    
    /* Contador de ocurrencias */
    int ocurr = 0;
    
    /* Recorrer la lista */
    while (tmp != nullptr) {

        /* Obtener la información del nodo actual */
        T info = tmp->getInfo();
        
        /* Si encontramos un elemento igual, incremento el contador */
        if (info == value) {
            ++ocurr;
        }
        /* Si encontramos un elemento mayor, termina */
        else if (info > value ) {
            break;
        }
        
        /* Desplazarse al siguiente elemento */
        tmp = tmp->getNext();
    }
    
    return ocurr;
}

/* Eliminar los elementos duplicados en una lista ordenada
 * Complejidad: O(n)
 */
template  <class T>
void SortedLinkedList<T>::remove_duplicates()
{
    /* Obtener una referencia al primer elemento */
    Node<T> * tmp = this->_first;
    
    /* Recorrer la lista */
    while (tmp->getNext() != nullptr) {
        
        /* Obtener la información del nodo actual */
        T info = tmp->getInfo() ;
        
        Node<T> * next = tmp->getNext();
        
        /* Determinar si el siguiente elemento es igual */
        if (next->getInfo() == info) {
            tmp->setNext( next->getNext() );
            
            /* Liberar la memoria del nodo eliminado */
            delete next;
            
            /* Decrementar el tamaño de la lista */
            --this->_size;
        }
        /* Desplazarse al siguiente elemento */
        else {
            tmp = tmp->getNext();
        }
    }
}

/* Obtener la posición de un valor
 * Complejidad: O(n)
 */
template  <class T>
int SortedLinkedList<T>::index(const T & value) const
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
    while (tmp != nullptr && tmp->getInfo() < value)
    {
        tmp = tmp->getNext();
        ++pos;
    }
    
    /* Si el value no se encuentra en la lista */
    if (tmp == nullptr || tmp->getInfo() != value) { return -1; }
    
    return pos;
}

#endif /* SortedLinkedList_hpp */
