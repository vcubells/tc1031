//
//  Persona.hpp
//  busqueda_secuencial
//
//  Created by Vicente Cubells on 29/02/24.
//  Copyright © 2024 Vicente Cubells Nonell. All rights reserved.
//

#ifndef Persona_hpp
#define Persona_hpp

#include <iostream>

class Persona {
private:
    std::string name = "Sin definir";
    std::string lastname = "Sin definir";
    int age = 0;
    
public:
    Persona() {}
    Persona(std::string _name, std::string _lastname, int _age) : name(_name), lastname(_lastname), age(_age)
    {}
    
    bool operator==(const Persona &);
    bool operator<(const Persona &);
    
    friend std::ostream & operator << (std::ostream & os, const Persona & );
    
    
    
};

#endif /* Persona_hpp */
