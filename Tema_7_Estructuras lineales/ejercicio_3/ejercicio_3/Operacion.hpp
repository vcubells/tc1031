//
//  Operacion.hpp
//  ejercicio_3
//
//  Created by Vicente Cubells on 15/04/24.
//

#ifndef Operacion_hpp
#define Operacion_hpp

#include <iostream>

class Operacion {
    std::string nombre = "undefined";
    float tiempo = 0.0;
    
public:
    Operacion() {}
    Operacion(std::string _nombre, float _tiempo) :
    nombre(_nombre), tiempo(_tiempo) {}
    
    float getTiempo() const;
    std::string getNombre() const;
    
    friend std::ostream & operator <<(std::ostream &, const Operacion &);
};

#endif /* Operacion_hpp */
