//
//  Moto.cpp
//  actividad-1-2
//
//  Created by Vicente Cubells on 09/09/21.
//

#include "Moto.hpp"


std::ostream & Moto::print(std::ostream & os) const
{
    Auto::print(os);
    
    os << ", " << cilindraje;
    
    return os;
}

std::ostream & operator<<(std::ostream & os, const Moto & coche)
{
    coche.print(os);
    os << std::endl;
    return os;
}
