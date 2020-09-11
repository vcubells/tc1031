//
//  Biblioteca.cpp
//  biblioteca
//
//  Created by Vicente Cubells Nonell on 09/09/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include "Biblioteca.hpp"

Biblioteca::~Biblioteca()
{
    libros.clear();
}

void Biblioteca::adicionarLibro(Libro libro)
{
    libros.push_back(libro);
}

std::vector<Libro> Biblioteca::eliminarLibro(std::string titulo)
{
    int i = 0;
    
    std::vector<Libro> eliminados;
    
    long int size = libros.size();
    
    while (i < size) {
        if ( libros[i].Titulo() == titulo) {
            eliminados.push_back(libros[i]);
            libros.erase(libros.begin()+i);
        }
        ++i;
    }
    
    return eliminados;
}

std::vector<Libro> Biblioteca::compara(Libro buscar, bool(comparador)(Libro, Libro))
{
    int i = 0;
    
    std::vector<Libro> encontrados;
    
    long int size = libros.size();
    
    while (i < size) {
        if ( comparador(libros[i], buscar) ) {
            encontrados.push_back(libros[i]);
        }
        ++i;
    }
    
    return encontrados;
}

std::vector<Libro> Biblioteca::buscarAntesDeAño(int año)
{
    Libro buscar;
    buscar.Año() = año;
    
    return compara(buscar, Libro::compara_año_asc);
}

std::vector<Libro> Biblioteca::buscarDespuesDeAño(int año)
{
    Libro buscar;
    buscar.Año() = año;
    
    return compara(buscar, Libro::compara_año_desc);
}

std::vector<Libro> Biblioteca::buscarEntreAños(int despues, int antes)
{
    int i = 0;
    
    std::vector<Libro> encontrados;
    
    long int size = libros.size();
    
    while (i < size) {
        if (libros[i].Año() >= despues && libros[i].Año() <= antes) {
            encontrados.push_back(libros[i]);
        }
        ++i;
    }
    
    return encontrados;
}

std::vector<Libro> Biblioteca::buscarPorAutor(std::string autor)
{
    Libro buscar;
    buscar.Autor() = autor;
    
    return compara(buscar, Libro::compara_autor_eq);
}

std::vector<Libro> Biblioteca::buscarPorEditorial(std::string editorial)
{
    Libro buscar;
    buscar.Editorial() = editorial;
    
    return compara(buscar, Libro::compara_editorial_eq);
}

void Biblioteca::ordenar(
                         std::vector<Libro>(* algoritmo)(std::vector<Libro>, bool(*)(Libro,Libro)),
                         bool(* compara)(Libro,Libro)
)
{
    libros = algoritmo(libros, compara);
}

unsigned long Biblioteca::size()
{
    return libros.size();
}

std::ostream & operator<<(std::ostream & os, const Biblioteca & biblioteca)
{
    for (auto libro : biblioteca.libros) {
        os << libro;
    }
    
    return os;
}
