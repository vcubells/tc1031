//
//  Node.hpp
//  LinkedList
//
//  Created by Vicente Cubells on 25/09/20.
//

#ifndef Node_hpp
#define Node_hpp

#include <iostream>

template <class T>
class Node {
private:
    T info;
    Node<T> * next = nullptr;
    
public:
    /* Constructores */
    Node() { };
    Node(const T & _info) : info(_info) {}
    Node(const Node<T> & );
    
    /* Destructor */
    virtual ~Node();
    
    /* Getter y Setter */
    T getInfo() const { return info; }
    void setInfo(T & value) { info = value; }
    
    Node<T> * getNext() const { return next; }
    void setNext(Node<T> * value) { next = value; }
    
    /* Sobrecarga operador == */
    bool operator ==(Node<T> &);
    
    /* Sobrecarga operador << */
    template <typename Tn>
    friend std::ostream & operator << (std::ostream & os, const Node<Tn> & node);
};

template <class T>
Node<T>::Node(const Node<T> & other)
{
    info = other.info;
    next = other.next;
}

template <class T>
Node<T>::~Node()
{
    info.~T();
    next = nullptr;
}

template <class T>
bool Node<T>::operator ==(Node<T> & other)
{
    return (info == other.info) && (next == other.next);
}

template <class T>
std::ostream & operator << (std::ostream & os, const Node<T> & node)
{
    os << node.info;
    
    return os;
}

#endif /* Node_hpp */
