//
//  Libro.cpp
//  ordenamiento_basico
//
//  Created by Vicente Cubells on 28/08/23.
//

#include "Libro.hpp"

bool Libro::operator<(Libro & libro)
{
    return ISBN < libro.ISBN;
}

bool Libro::operator>(Libro & libro)
{
    return ISBN > libro.ISBN;
}

bool Libro::operator<=(Libro & libro)
{
    return ISBN <= libro.ISBN;
}

/*
 std::copy(vector, vector+N, std::ostream_iterator<Libro>(std::cout, " "));
 
 std::ostream_iterator<Libro>(std::cout, " ") ->  operator<<(std::cout, iter)
 
 */

std::ostream & operator<<(std::ostream & os, const Libro & libro)
{
    os << "ISBN:  " << libro.ISBN << std::endl;
    
    return os;
}

