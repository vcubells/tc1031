//
//  Libro.cpp
//  tc1031
//
//  Created by Vicente Cubells Nonell on 11/08/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "Libro.hpp"

Libro::Libro(int _id)
{
    id = _id;
}

int Libro::getId()
{
    return id;
}

/*
 int a=1;
 int b=4;
  a < b es lo mismo que a.operator<(b)
 */
bool Libro::operator <(Libro & libro)
{
    return id < libro.id;
    // return autor < libro.autor
    // return titulo < libro.titulo
}

bool Libro::operator >(Libro & libro)
{
    return id > libro.id;
}

bool Libro::operator ==(Libro & libro)
{
    return id == libro.id;
}


void Libro::print()
{
    std::cout << "Id:" << id << std::endl;
}

std::ostream & operator << (std::ostream & os, const Libro & libro)
{
    os << "Libro ID: " << libro.id << std::endl;
    
    return os;
}


/*
 Sobrecarga
 
 1- Sobrecarga de métodos
    
    bool Insert(int item);              // Método 1
    bool Insert(int item, int index);   // Método 2
 
    objeto.Insert(5);   // Llama al método 1
    objeto.Insert(3,1); // Llama al método 2
 
 2- Sobrecarga de operadores
 
    bool Clase::operator <(Clase & otra)
    bool Clase::operator >(Clase & otra)
 
    objeto.operator <(otra)
    
 */
