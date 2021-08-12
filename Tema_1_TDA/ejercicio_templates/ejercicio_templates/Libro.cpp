//
//  Libro.cpp
//  ejercicio_templates
//
//  Created by Vicente Cubells on 12/08/21.
//

#include "Libro.hpp"

std::ostream & operator<<(std::ostream & os, const Libro & libro)
{
    os << libro.titulo;
    os << std::endl;
    
    return os;
}
