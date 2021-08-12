//
//  Libro.hpp
//  ejercicio_templates
//
//  Created by Vicente Cubells on 12/08/21.
//

#ifndef Libro_hpp
#define Libro_hpp

#include <iostream>

class Libro
{
    std::string titulo;
public:
    Libro() : Libro("Sin definir") {}
    Libro(std::string t) : titulo(t) {}
    
    friend std::ostream & operator<<(std::ostream & os, const Libro & libro);
    
    };

#endif /* Libro_hpp */
