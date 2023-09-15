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
    std::string traccion{"Sin definir"};
public:
    Camioneta() {
        tipo = "Camioneta";
    };
    Camioneta(std::string _codigo, std::string _marca, int _modelo, int _kms, std::string _traccion):
    Auto(_codigo, _marca, _modelo, _kms), traccion(_traccion) {}
    
    virtual std::ostream & print(std::ostream &) const;
    
    friend std::ostream & operator<<(std::ostream & , const Camioneta & );
};

#endif /* Camioneta_hpp */
