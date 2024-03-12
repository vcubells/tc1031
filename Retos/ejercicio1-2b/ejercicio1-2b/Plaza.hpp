//
//  Plaza.hpp
//  ejercicio1-2b
//
//  Created by Vicente Cubells on 12/03/24.
//

#ifndef Plaza_hpp
#define Plaza_hpp

#include <iostream>

class Plaza {
private:
    bool ocupada = false;
public:
    Plaza () {};
    Plaza (bool _ocupada) : ocupada(_ocupada) {}
    
    void setOcupada(bool value);
    bool getOcupada();
    
    bool operator==(const Plaza &);
    
};

#endif /* Plaza_hpp */
