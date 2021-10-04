//
//  Registro.hpp
//  actividad1-3
//
//  Created by Vicente Cubells on 27/09/21.
//

#ifndef Registro_hpp
#define Registro_hpp

#include <iostream>

class Registro {
    std::string fecha;
    std::string puerto_destino;
    
public:
    Registro() {}
    Registro(std::string _fecha, std::string _pd ) : fecha(_fecha), puerto_destino(_pd) {}
    
    std::string getFecha() const;
    
    static bool compara_fecha_asc(Registro, Registro);
    static bool compara_fecha_eq(Registro, Registro);
    
    friend std::ostream & operator<<(std::ostream & os, const Registro & registo);
    
    
};


#endif /* Registro_hpp */
