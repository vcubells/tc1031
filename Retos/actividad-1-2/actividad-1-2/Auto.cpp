//
//  Auto.cpp
//  actividad-1-2
//
//  Created by Vicente Cubells on 09/09/21.
//

#include "Auto.hpp"

int Auto::getModelo()
{
    return modelo;
}

int Auto::getKms()
{
    return kms;
}

bool Auto::estaComprado()
{
    return comprado;
}

void Auto::setComprado()
{
    comprado = true;
}

bool Auto::operator==(const Auto & _auto)
{
    return codigo == _auto.codigo;
}

std::ostream & Auto::print(std::ostream & os) const
{
    os << tipo << ": " << marca << ", " << modelo << ", " << kms << " kms";
    
    return os;
}

std::ostream & operator<<(std::ostream & os, const Auto & coche)
{
    
    coche.print(os);
    os << std::endl;
    return os;
}
