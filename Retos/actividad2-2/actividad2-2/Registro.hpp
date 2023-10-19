//
//  Registro.hpp
//  actividad2-2
//
//  Created by Vicente Cubells on 02/10/23.
//

#ifndef Registro_hpp
#define Registro_hpp

#include <iostream>

class Registro {
private:
    std::string fecha = "";
    std::string hora = "";
    std::string ipOrigen = "";
    std::string nombreOrigen = "";
    std::string puertoOrigen = "";
    std::string ipDestino = "";
    std::string nombreDestino = "";
    std::string puertoDestino = "";
    
public:
    Registro() = default;
};

#endif /* Registro_hpp */
