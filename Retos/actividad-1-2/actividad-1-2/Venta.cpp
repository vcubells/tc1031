//
//  Venta.cpp
//  actividad-1-2
//
//  Created by Vicente Cubells on 14/09/23.
//

#include "Venta.hpp"

float Venta::getMonto()
{
    return monto;
}

Comprador Venta::getComprador()
{
    return comprador;
}

Auto Venta::getAuto()
{
    return coche;
}

 std::ostream & operator<<(std::ostream & os, const Venta & _venta)
{
     os << " --- " << std::endl;
     os << "Monto: " << _venta.monto << std::endl;
     os << _venta.coche;
     os << "Cliente: " << _venta.comprador;
    
     return os;
}
