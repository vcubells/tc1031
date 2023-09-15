//
//  Moto.hpp
//  actividad-1-2
//
//  Created by Vicente Cubells on 09/09/21.
//

#ifndef Moto_hpp
#define Moto_hpp

#include <iostream>
#include "Auto.hpp"

class Moto: public Auto {
private:
    int cilindraje {0};
public:
    Moto() {
        tipo = "Moto";
    };
    Moto(std::string _codigo, std::string _marca, int _modelo, int _kms, int _cilindraje):
    Auto(_codigo, _marca, _modelo, _kms), cilindraje(_cilindraje) {}
    
    virtual std::ostream & print(std::ostream &) const;
    
    friend std::ostream & operator<<(std::ostream & , const Moto & );
};

#endif /* Moto_hpp */
