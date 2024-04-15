//
//  Cliente.hpp
//  ejercicio_3
//
//  Created by Vicente Cubells on 15/04/24.
//

#ifndef Cliente_hpp
#define Cliente_hpp

#include <iostream>
#include "Operacion.hpp"
#include <list>

class Cliente {
    std::string nombre = "undefined";
    std::list<Operacion> operaciones;
    float duracion = 0.0;
    
public:
    Cliente() {}
    Cliente(std::string _nombre) : nombre(_nombre) {}
    
    float getDuracion() const;
    void addOperacion(Operacion);
    
    bool operator==(Cliente) const;
    
    friend std::ostream & operator <<(std::ostream &, const Cliente &);
    
};

#endif /* Cliente_hpp */
