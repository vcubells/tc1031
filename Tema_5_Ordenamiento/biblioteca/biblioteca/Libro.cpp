//
//  Libro.cpp
//  biblioteca
//
//  Created by Vicente Cubells Nonell on 09/09/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include "Libro.hpp"

bool Libro::compara_titulo_asc(Libro a, Libro b)
{
    return a.Titulo() < b.Titulo();
}

bool Libro::compara_titulo_desc(Libro a, Libro b)
{
   return a.Titulo() > b.Titulo();
}

bool Libro::compara_titulo_eq(Libro a, Libro b)
{
   return a.Titulo() == b.Titulo();
}

bool Libro::compara_autor_asc(Libro a, Libro b)
{
    return a.Autor() < b.Autor();
}

bool Libro::compara_autor_desc(Libro a, Libro b)
{
    return a.Autor() > b.Autor();
}

bool Libro::compara_autor_eq(Libro a, Libro b)
{
    return a.Autor() == b.Autor();
}

bool Libro::compara_editorial_asc(Libro a, Libro b)
{
    return a.Editorial() < b.Editorial();
}

bool Libro::compara_editorial_desc(Libro a, Libro b)
{
    return a.Editorial() > b.Editorial();
}

bool Libro::compara_editorial_eq(Libro a, Libro b)
{
    return a.Editorial() == b.Editorial();
}

bool Libro::compara_paginas_asc(Libro a, Libro b)
{
    return a.Paginas() < b.Paginas();
}

bool Libro::compara_paginas_desc(Libro a, Libro b)
{
    return a.Paginas() > b.Paginas();
}

bool Libro::compara_paginas_eq(Libro a, Libro b)
{
    return a.Paginas() == b.Paginas();
}

bool Libro::compara_año_asc(Libro a, Libro b)
{
    return a.Año() < b.Año();
}

bool Libro::compara_año_desc(Libro a, Libro b)
{
    return a.Año() > b.Año();
}

bool Libro::compara_año_eq(Libro a, Libro b)
{
    return a.Año() == b.Año();
}


std::ostream & operator<<(std::ostream & os, const Libro & libro)
{
    os << libro.autor << " (";
    os << libro.año << "). ";
    os << libro.titulo << ", ";
    os << libro.edicion << " edición, ";
    os << libro.editorial << ", ";
    os << "Págs. " << libro.paginas << ".";
    os << std::endl;
    
    return os;
}


