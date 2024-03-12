//
//  Nivel.hpp
//  ejercicio1-2b
//
//  Created by Vicente Cubells on 12/03/24.
//

#ifndef Nivel_hpp
#define Nivel_hpp
#include "/Users/vcubells/Developer/GitHub/tc1031/Tema_4_Búsqueda/busqueda_secuencial/busqueda_secuencial/Busqueda.hpp"
#include <iostream>
#include <vector>
#include "Plaza.hpp"

class Nivel {
private:
    std::vector<Plaza> plazas = std::vector<Plaza>(3);
    
public:
    Nivel() {}
    int buscarDisponible();
    void cambiarEstado(int pos, bool estado);
};

#endif /* Nivel_hpp */
