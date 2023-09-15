//
//  Camioneta.cpp
//  actividad-1-2
//
//  Created by Vicente Cubells on 09/09/21.
//

#include "Camioneta.hpp"

std::ostream & Camioneta::print(std::ostream & os) const
{
    Auto::print(os);
    
    os << ", " << traccion;
    
    return os;
}

std::ostream & operator<<(std::ostream & os, const Camioneta & coche)
{
    coche.print(os);
    os << std::endl;
    return os;
}
