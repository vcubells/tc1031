//
//  Persona.hpp
//  ordenamiento_generico
//
//  Created by Vicente Cubells Nonell on 04/09/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#ifndef Persona_hpp
#define Persona_hpp

#include <iostream>

class Persona {
private:
    std::string nombre;
    int edad;
        
public:
    Persona():Persona("",0) {}
    Persona(std::string _nombre, int _edad) : nombre(_nombre), edad(_edad) {}
    
    static bool edad_asc(Persona, Persona);
    static bool edad_desc(Persona, Persona);
    
    bool operator<(Persona & persona);
    bool operator>(Persona & persona);
    
    friend std::ostream & operator<<(std::ostream & os, const Persona & persona);
};

#endif /* Persona_hpp */
