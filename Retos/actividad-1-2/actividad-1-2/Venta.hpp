//
//  Venta.hpp
//  actividad-1-2
//
//  Created by Vicente Cubells on 14/09/23.
//

#ifndef Venta_hpp
#define Venta_hpp

#include <iostream>
#include "Comprador.hpp"
#include "Auto.hpp"

class Venta {
private:
    float monto {0.0};
    Comprador comprador {};
    Auto coche {};
    
public:
    Venta() = default;
    Venta(float _monto, Comprador  _comprador, Auto  _auto):
    monto(_monto), comprador(_comprador), coche(_auto) {}
    
    float getMonto();
    Comprador getComprador();
    Auto getAuto();
    
    friend std::ostream & operator<<(std::ostream &, const Venta &);
};

#endif /* Venta_hpp */
