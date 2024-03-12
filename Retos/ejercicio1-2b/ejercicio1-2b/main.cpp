//
//  main.cpp
//  ejercicio1-2b
//
//  Created by Vicente Cubells on 12/03/24.
//

#include <iostream>
#include "Nivel.hpp"

int main(int argc, const char * argv[]) {
    
    Nivel nivel1;
    
    nivel1.cambiarEstado(0, true);
    nivel1.cambiarEstado(1, true);
    nivel1.cambiarEstado(2, false);
    
    int result = nivel1.buscarDisponible();
    if (result == -1 )
    {
        std::cout << "No hay lugares disponibles" << std::endl;
    }
    else {
        std::cout << "El lugar asignado es la plaza " << result << std::endl;
    }
    
    
    return 0;
}
