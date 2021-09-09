//
//  Camioneta.hpp
//  actividad-1-2
//
//  Created by Vicente Cubells on 09/09/21.
//

#ifndef Camioneta_hpp
#define Camioneta_hpp

#include <iostream>
#include "Auto.hpp"

class Camioneta: public Auto {
private:
    std::string traccion;
public:
    Camioneta() {
        tipo = "Camioneta";
        traccion = "4WD";
    }
    
    virtual std::ostream & print(std::ostream &) const;
    
    friend std::ostream & operator<<(std::ostream & , const Camioneta & );
};

#endif /* Camioneta_hpp */
