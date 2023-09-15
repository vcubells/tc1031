//
//  Comprador.cpp
//  actividad-1-2
//
//  Created by Vicente Cubells on 14/09/23.
//

#include "Comprador.hpp"

std::string Comprador::getINE()
{
    return ine;
}

bool Comprador::operator==(const Comprador & _comprador)
{
    return ine == _comprador.ine;
}

 std::ostream & operator<<(std::ostream & os, const Comprador & _comprador)
{
     os << _comprador.nombre << " " << _comprador.apellidos << " (" << _comprador.ine << ")" << std::endl;
     
     return os;
}
