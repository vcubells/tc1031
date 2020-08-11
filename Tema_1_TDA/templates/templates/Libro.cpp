//
//  Libro.cpp
//  tc1031
//
//  Created by Vicente Cubells Nonell on 11/08/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "Libro.hpp"

Libro::Libro(int _id)
{
    id = _id;
}

int Libro::getId()
{
    return id;
}

bool Libro::operator <(Libro & libro)
{
    return id < libro.id;
}

std::ostream & operator << (std::ostream & os, const Libro & libro)
{
    os << "Libro ID: " << libro.id << std::endl;
    
    return os;
}
