//
//  Persona.hpp
//  procesar_csv
//
//  Created by Vicente Cubells Nonell on 11/09/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#ifndef Persona_hpp
#define Persona_hpp

#include <iostream>

class Persona {
private:
    std::string nombre;
    std::string email;
    std::string fecha;
    int edad;
    
public:
    Persona(std::string n, std::string e, std::string f, int ed):
    nombre(n), email(e), fecha(f), edad(ed) {}
    
    friend std::ostream & operator<<(std::ostream & os, const Persona & persona);
};

#endif /* Persona_hpp */
