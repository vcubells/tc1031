//
//  Auto.cpp
//  actividad-1-2
//
//  Created by Vicente Cubells on 09/09/21.
//

#include "Auto.hpp"

std::ostream & Auto::print(std::ostream & os) const
{
    os << "Auto:" << tipo << std::endl;
    
    return os;
}

std::ostream & operator<<(std::ostream & os, const Auto & coche)
{
    return coche.print(os);
}
