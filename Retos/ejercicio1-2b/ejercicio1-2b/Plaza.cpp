//
//  Plaza.cpp
//  ejercicio1-2b
//
//  Created by Vicente Cubells on 12/03/24.
//

#include "Plaza.hpp"

void Plaza::setOcupada(bool value)
{
    ocupada = value;
}

bool Plaza::getOcupada()
{
    return ocupada;
}

bool Plaza::operator==(const Plaza & otra)
{
    return ocupada == otra.ocupada;
}
