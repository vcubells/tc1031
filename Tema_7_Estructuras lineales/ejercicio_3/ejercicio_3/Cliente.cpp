//
//  Cliente.cpp
//  ejercicio_3
//
//  Created by Vicente Cubells on 15/04/24.
//

#include "Cliente.hpp"

float Cliente::getDuracion() const
{
    return duracion;
}

void Cliente::addOperacion(Operacion op)
{
    operaciones.push_back(op);
    duracion += op.getTiempo();
}

bool Cliente::operator==(Cliente c) const
{
    return nombre == c.nombre;
}

std::ostream & operator <<(std::ostream & os, const Cliente & cliente)
{
    os << cliente.nombre << std::endl;
    os << "Tiempo total: " << cliente.duracion << std::endl;
    os << "Operaciones: " << std::endl;
    for (auto op : cliente.operaciones) {
        os << op;
    }
    
    return os;
}
