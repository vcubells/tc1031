//
//  Persona.cpp
//  ordenamiento_generico
//
//  Created by Vicente Cubells Nonell on 04/09/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include "Persona.hpp"

bool Persona::edad_asc(Persona a, Persona b)
{
    return a.edad < b.edad;
}

bool Persona::edad_desc(Persona a, Persona b)
{
    return a.edad > b.edad;
}

bool Persona::operator<(Persona & persona)
{
    return nombre < persona.nombre;
}

bool Persona::operator>(Persona & persona)
{
    return nombre > persona.nombre;
}

std::ostream & operator<<(std::ostream & os, const Persona & persona)
{
    os << persona.nombre << " (" << persona.edad << ")" << std::endl;
    
    return os;
}
