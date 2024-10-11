//
//  Registro.cpp
//  actividad2-2
//
//  Created by Vicente Cubells on 02/10/23.
//

#include "Registro.hpp"
#

bool Registro::operator==(const Registro & other)
{
    return (
            fecha == other.fecha &&
            hora == other.hora &&
            ipOrigen == other.ipOrigen &&
            puertoOrigen == other.puertoOrigen &&
            nombreOrigen == other.nombreOrigen &&
            ipDestino == other.ipDestino &&
            puertoDestino == other.puertoDestino &&
            nombreDestino == other.nombreDestino
            );
}

bool Registro::operator!=(const Registro & other)
{
    return !(*this==other);
}

std::ostream & operator << (std::ostream & os, const Registro & _value)
{
    os << "Fecha: " << _value.fecha << std::endl;
    os << "Hora: " << _value.hora << std::endl;
    os << "IP Origen: " << _value.ipOrigen << std::endl;
    os << "Puerto Origen: " << _value.puertoOrigen << std::endl;
    os << "Nombre Origen: " << _value.nombreOrigen << std::endl;
    os << "IP Destino: " << _value.ipDestino << std::endl;
    os << "Puerto Destino: " << _value.puertoDestino << std::endl;
    os << "Nombre Destino: " << _value.nombreDestino << std::endl;
    
    return os;
}

