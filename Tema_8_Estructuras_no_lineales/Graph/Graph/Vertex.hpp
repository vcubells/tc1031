//
//  Vertex.hpp
//  Graph
//
//  Created by Vicente Cubells on 10/11/20.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <iostream>
#include <vector>
#include "Edge.hpp"

template <class V, class E>
class Vertex {
    V info;
    std::vector< Edge<V, E> * > edges;
    
public:
    Vertex() {}
    Vertex(V _info) : info(_info) {}
    ~Vertex();
    
    V getInfo() const;
    void setInfo(const V &);
    
    std::vector< Edge<V,E> * > * getEdges();
    
    void addEdge(Edge<V,E> *);
    void removeEdge(Edge<V,E> *);
    
    template <class Vn, class En>
    friend std::ostream & operator <<(std::ostream &, const Vertex<Vn, En> &);
    
};

template <class V, class E>
Vertex<V,E>::~Vertex()
{
    for (auto e : edges) {
        delete e;
    }
    
    edges.clear();
}

template <class V, class E>
V Vertex<V,E>::getInfo() const
{
    return info;
}

template <class V, class E>
void Vertex<V,E>::setInfo(const V & value)
{
    info = value;
}

template <class V, class E>
std::vector< Edge<V,E> * > * Vertex<V, E>::getEdges()
{
    return &edges;
}

template <class V, class E>
void Vertex<V,E>::addEdge(Edge<V,E> * edge)
{
    edges.push_back(edge);
}

template <class V, class E>
void Vertex<V,E>::removeEdge(Edge<V,E> * edge)
{
    auto to_delete = find(edges.begin(), edges.end(), edge);
    edges.erase(to_delete);
}

template <class V, class E>
std::ostream & operator <<(std::ostream & os, const Vertex<V,E> & vertex)
{
    os << "Vertex: " << vertex.info << std::endl;
    
    for (auto  e : vertex.edges) {
        os << *e << std::endl;
    }
    
    return os;
}

#endif /* Vertex_hpp */
