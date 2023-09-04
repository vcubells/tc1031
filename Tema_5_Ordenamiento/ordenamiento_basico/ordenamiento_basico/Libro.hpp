//
//  Libro.hpp
//  ordenamiento_basico
//
//  Created by Vicente Cubells on 28/08/23.
//

#ifndef Libro_hpp
#define Libro_hpp

#include <iostream>

class Libro {
    int ISBN;
public:
    Libro() {};
    Libro(int _isbn) : ISBN(_isbn) {};
    bool operator<(Libro &);
    bool operator>(Libro &);
    bool operator<=(Libro &);
    
    friend std::ostream & operator<<(std::ostream & os, const Libro & libro);
};

#endif /* Libro_hpp */
