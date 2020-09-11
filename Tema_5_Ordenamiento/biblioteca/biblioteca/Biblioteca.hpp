//
//  Biblioteca.hpp
//  biblioteca
//
//  Created by Vicente Cubells Nonell on 09/09/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#ifndef Biblioteca_hpp
#define Biblioteca_hpp

#include <iostream>
#include <vector>
#include "Libro.hpp"

class Biblioteca {
private:
    std::vector<Libro> libros;
    
    std::vector<Libro> compara(Libro, bool(*)(Libro, Libro));
    
public:
    Biblioteca(){}
    
    ~Biblioteca();
    
    void adicionarLibro(Libro);
    std::vector<Libro> eliminarLibro(std::string);
    std::vector<Libro> buscarAntesDeAño(int);
    std::vector<Libro> buscarDespuesDeAño(int);
    std::vector<Libro> buscarEntreAños(int, int);
    std::vector<Libro> buscarPorAutor(std::string);
    std::vector<Libro> buscarPorEditorial(std::string);
    void ordenar(
                 std::vector<Libro>(*)(std::vector<Libro>, bool(*)(Libro,Libro)),
                 bool(*)(Libro,Libro)
                );
    unsigned long size();
    
    friend std::ostream & operator<<(std::ostream & os, const Biblioteca & biblioteca);
};

#endif /* Biblioteca_hpp */
