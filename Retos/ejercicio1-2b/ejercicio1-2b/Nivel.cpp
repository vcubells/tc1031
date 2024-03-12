//
//  Nivel.cpp
//  ejercicio1-2b
//
//  Created by Vicente Cubells on 12/03/24.
//

#include "Nivel.hpp"

int Nivel::buscarDisponible()
{
    Plaza dummy;
    
    int valor = Busqueda<Plaza>::busquedaSecuencial(plazas, dummy);
    
    return valor;
}

void Nivel::cambiarEstado(int pos, bool estado)
{
    plazas[pos].setOcupada(estado);
}
