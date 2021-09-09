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
    std::string tipo;
public:
    Auto() {
        tipo = "Auto";
    }
    
    virtual std::ostream & print(std::ostream & ) const;
    
    friend std::ostream & operator<<(std::ostream &, const Auto &);
};

#endif /* Auto_hpp */
