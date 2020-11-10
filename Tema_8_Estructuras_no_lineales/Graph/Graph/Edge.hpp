//
//  Edge.hpp
//  Graph
//
//  Created by Vicente Cubells on 10/11/20.
//

#ifndef Edge_hpp
#define Edge_hpp

#include <iostream>

template <class V, class E>
class Vertex;

template <class V, class E>
class Edge {
    E info;
    Vertex<V,E> * target = nullptr;
    
public:
    Edge() {}
    Edge(E _info, Vertex<V,E> * _target) :
    info(_info), target(_target) {}
    
    ~Edge();
    
    E getInfo() const;
    void setInfo(const E &);
    
    Vertex<V,E> * getTarget() const;
    void setTarget(const Vertex<V,E> *);
    
    template <class Vn,class En>
    friend std::ostream & operator <<(std::ostream &, const Edge<Vn, En>  &);
    
};

template <class V, class E>
Edge<V,E>::~Edge()
{
    target = nullptr;
}

template <class V, class E>
E Edge<V,E>::getInfo() const
{
    return info;
}

template <class V, class E>
void Edge<V,E>::setInfo(const E & value)
{
    info = value;
}

template <class V, class E>
Vertex<V,E> * Edge<V,E>::getTarget() const
{
    return target;
}

template <class V, class E>
void Edge<V,E>::setTarget(const Vertex<V,E> * vertex)
{
    target = vertex;
}

template <class V, class E>
std::ostream & operator <<(std::ostream & os, const Edge<V, E> & edge)
{
    os << edge.info << " ---> " << edge.target->getInfo() << std::endl;
    
    return os;
}

#endif /* Edge_hpp */
