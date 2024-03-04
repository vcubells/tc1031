//
//  Persona.cpp
//  busqueda_secuencial
//
//  Created by Vicente Cubells on 29/02/24.
//  Copyright © 2024 Vicente Cubells Nonell. All rights reserved.
//

#include "Persona.hpp"

bool Persona::operator==(const Persona & persona)
{
    return age == persona.age;
}

bool Persona::operator<(const Persona & persona)
{
    return age < persona.age;
}

std::ostream & operator << (std::ostream & os, const Persona & persona)
{
    os << persona.name << " " << persona.lastname << "(" << persona.age << ")" << std::endl;
    
    return os;
}
