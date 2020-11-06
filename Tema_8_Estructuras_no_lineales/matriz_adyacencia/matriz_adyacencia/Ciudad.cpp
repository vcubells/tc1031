//
//  Ciudad.cpp
//  matriz_adyacencia
//
//  Created by Vicente Cubells on 06/11/20.
//

#include "Ciudad.hpp"


std::string Ciudad::nombre() const
{
    return _nombre;
}

int Ciudad::habitantes() const
{
    return _habitantes;
}

Ciudad & Ciudad::operator=(const Ciudad & c){
    _habitantes = c._habitantes;
    _nombre = c._nombre;
    
    return *this;
}

std::ostream & operator <<(std::ostream & os, const Ciudad & c)
{
    os << c._nombre << "(" << c._habitantes << " habs)" << std::endl;
    
    return os;
}

