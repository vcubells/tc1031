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
    int incidentes_entrada = 0;
    
public:
    Vertex() {}
    Vertex(V _info) : info(_info) {}
    ~Vertex();
    
    V getInfo() const;
    void setInfo(const V &);
    
    std::vector< Edge<V,E> * > * getEdges();
    
    int getIncidentesEntrada();
    void incIncidentesEntrada();
    void decIncidentesEntrada();
    
    void addEdge(Edge<V,E> *);
    void removeEdge(Edge<V,E> *);
    
    bool operator ==(const Vertex<V,E> &);
    
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
int Vertex<V,E>::getIncidentesEntrada()
{
    return incidentes_entrada;
}

template <class V, class E>
void Vertex<V,E>::incIncidentesEntrada()
{
    ++incidentes_entrada;
}

template <class V, class E>
void Vertex<V,E>::decIncidentesEntrada()
{
    --incidentes_entrada;
}

template <class V, class E>
void Vertex<V,E>::addEdge(Edge<V,E> * edge)
{
    edges.push_back(edge);
    edge->getTarget()->incIncidentesEntrada();
}

template <class V, class E>
void Vertex<V,E>::removeEdge(Edge<V,E> * edge)
{
    auto to_delete = find(edges.begin(), edges.end(), edge);
    edge->getTarget()->decIncidentesEntrada();
    edges.erase(to_delete);
    
}

template <class V, class E>
bool Vertex<V,E>::operator ==(const Vertex<V,E> & value)
{
    return info == value.getInfo();
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
