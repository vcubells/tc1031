//
//  Ciudad.hpp
//  matriz_adyacencia
//
//  Created by Vicente Cubells on 06/11/20.
//

#ifndef Ciudad_hpp
#define Ciudad_hpp

#include <iostream>

class Ciudad {
    std::string _nombre = "Fantasma";
    int _habitantes = 0;
    
public:
    Ciudad() {}
    Ciudad(std::string _nombre, int _hab) : _nombre(_nombre), _habitantes(_hab) {}

    ~Ciudad() {}
    
    std::string nombre() const;
    int habitantes() const;
    
    Ciudad & operator=(const Ciudad &);
    
    friend std::ostream & operator <<(std::ostream &, const Ciudad &);
};

#endif /* Ciudad_hpp */
