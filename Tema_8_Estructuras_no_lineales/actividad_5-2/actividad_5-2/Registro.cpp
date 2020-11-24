//
//  Registro.cpp
//  actividad_5-2
//
//  Created by Vicente Cubells on 24/11/20.
//

#include "Registro.hpp"



std::string Registro::getFecha() const
{
    return this->fecha;
}

std::string Registro::getHora() const
{
    return this->hora;
}

std::string Registro::getOrigen() const
{
    return this->origen;
}

std::string Registro::getIPOrigen() const
{
    return this->ip_origen;
}

int Registro::getPuertoOrigen() const
{
    return this->puerto_origen;
}

std::string Registro::getDestino() const
{
    return this->destino;
}

std::string Registro::getIPDestino() const
{
    return this->ip_destino;
}

int Registro::getPuertoDestino() const
{
    return this->puerto_destino;
}
    
std::ostream & operator<<(std::ostream & os, const Registro & registro)
{
    os << registro.fecha << ", ";
    os << registro.hora << ", ";
    os << registro.ip_origen << ", ";
    os << registro.puerto_origen << ", ";
    os << registro.origen << ", ";
    
    os << registro.ip_destino << ", ";
    os << registro.puerto_destino << ", ";
    os << registro.destino;
    os << std::endl;
    
    return os;
}
