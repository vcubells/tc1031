//
//  Camioneta.cpp
//  actividad-1-2
//
//  Created by Vicente Cubells on 09/09/21.
//

#include "Camioneta.hpp"

std::ostream & Camioneta::print(std::ostream & os) const
{
    os << "Camioneta: " << tipo << " - Tracción: " << traccion << std::endl;
    
    return os;
}

std::ostream & operator<<(std::ostream & os, const Camioneta & coche)
{
    return coche.print(os);
}
