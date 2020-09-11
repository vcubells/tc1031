//
//  Persona.cpp
//  procesar_csv
//
//  Created by Vicente Cubells Nonell on 11/09/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include "Persona.hpp"

std::ostream & operator<<(std::ostream & os, const Persona & persona)
{
    os << persona.nombre << " - ";
    os << persona.email << " - ";
    os << persona.fecha << " - ";
    os << persona.edad;
    os << std::endl;
    
    return os;
}
