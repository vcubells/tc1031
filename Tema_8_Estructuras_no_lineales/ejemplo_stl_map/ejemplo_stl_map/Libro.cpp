//
//  Libro.cpp
//  ejemplo_stl_map
//
//  Created by Vicente Cubells on 23/10/20.
//

#include "Libro.hpp"

std::ostream & operator<<(std::ostream & os, Libro & libro)
{
    os << libro.isbn << " - " << libro.titulo << "( " << libro.paginas << ")" << std::endl;
    
    return os;
}

