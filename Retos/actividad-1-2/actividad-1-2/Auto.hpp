//
//  Auto.hpp
//  actividad-1-2
//
//  Created by Vicente Cubells on 09/09/21.
//

#ifndef Auto_hpp
#define Auto_hpp

#include <iostream>

class Auto {
protected:
    std::string tipo{"Auto"};
    std::string codigo{"Sin definir"};
    std::string marca{"Sin definir"};
    int modelo{0};
    int kms{0};
    bool comprado { false };
    
public:
    Auto() = default;
    Auto(std::string _codigo, std::string _marca, int _modelo, int _kms):
    codigo(_codigo), marca(_marca), modelo(_modelo), kms(_kms) {}
    
    int getModelo();
    int getKms();
    
    bool estaComprado();
    void setComprado();
    
    bool operator==(const Auto &);
    
    virtual std::ostream & print(std::ostream & ) const;
    
    friend std::ostream & operator<<(std::ostream &, const Auto &);
};

#endif /* Auto_hpp */
