//
//  Operacion.cpp
//  ejercicio_3
//
//  Created by Vicente Cubells on 15/04/24.
//

#include "Operacion.hpp"


float Operacion::getTiempo() const
{
    return tiempo;
}

std::string Operacion::getNombre() const
{
    return nombre;
}

std::ostream & operator <<(std::ostream & os, const Operacion & op)
{
    os << op.nombre << "(" << op.tiempo << ")" << std::endl;
    
    return os;
}
