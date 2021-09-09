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
public:
    Moto() {
        tipo = "Moto";
    }
    
    virtual std::ostream & print(std::ostream &) const;
    
    friend std::ostream & operator<<(std::ostream & , const Moto & );
};

#endif /* Moto_hpp */
