//
//  Registro.cpp
//  actividad1-3
//
//  Created by Vicente Cubells on 27/09/21.
//

#include "Registro.hpp"

std::string Registro::getFecha() const
{
    return fecha;
}

bool Registro::compara_fecha_asc(Registro a, Registro b)
{
    return a.fecha < b.fecha;
}

bool Registro::compara_fecha_eq(Registro a, Registro b)
{
   return a.fecha == b.fecha;
}

std::ostream & operator<<(std::ostream & os, const Registro & registro)
{
    os << registro.fecha;
    os << std::endl;
    
    return os;
}
