//
//  Libro.hpp
//  ejemplo_stl_map
//
//  Created by Vicente Cubells on 23/10/20.
//

#ifndef Libro_hpp
#define Libro_hpp

#include <iostream>

class Libro {
    std::string isbn;
    std::string titulo;
    int paginas;
    
public:
    Libro()
    {
        Libro("sin definir", "sin definir", 0);
    }
    
    Libro(std::string _isbn, std::string _titulo, int _pags) :
    titulo(_titulo), isbn(_isbn), paginas(_pags)
    {
        
    }
    
    ~Libro() {}
    
    friend std::ostream & operator<<(std::ostream &, Libro &);
};

#endif /* Libro_hpp */
