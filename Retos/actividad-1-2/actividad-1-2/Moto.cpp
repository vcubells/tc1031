//
//  Moto.cpp
//  actividad-1-2
//
//  Created by Vicente Cubells on 09/09/21.
//

#include "Moto.hpp"


std::ostream & Moto::print(std::ostream & os) const
{
    os << "Moto:" << tipo << std::endl;
    
    return os;
}

std::ostream & operator<<(std::ostream & os, const Moto & coche)
{
    return coche.print(os);
}
