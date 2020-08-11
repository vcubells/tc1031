//
//  Libro.hpp
//  tc1031
//
//  Created by Vicente Cubells Nonell on 11/08/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#ifndef Libro_hpp
#define Libro_hpp

class Libro
{
private:
    int id;
public:
    Libro(int _id);
    
    int getId();
    
    bool operator <(Libro & libro);
    
    friend std::ostream & operator << (std::ostream & os, const Libro & libro);
};

#endif /* Libro_hpp */
