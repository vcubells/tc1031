//
//  main.cpp
//  ejemplo_stl_map
//
//  Created by Vicente Cubells on 23/10/20.
//

#include <iostream>
#include <map>
#include "Libro.hpp"

int main(int argc, const char * argv[]) {
    
    std::map<int, std::string> personas;
    
    std::pair<int,std::string> p1(1,"Maria");
    personas.insert(p1);
    
    std::pair<int,std::string> p2(10,"Juana");
    personas.insert(p2);
    
    personas[3] = "Pepe";
    
    for (auto elem : personas) {
        std::cout << "Key: " << elem.first << ", Value: " << elem.second << std::endl;
    }
    
    std::cout << "--- Buscar un valor ---" << std::endl;
    
    std::map<int,std::string>::iterator it;
    
    it = personas.find(20);
    
    if (it ==  personas.end()) {
        std::cout << "La persona buscada no se encontró" << std::endl;
    }
    else {
        std::cout << "La persona buscada es:  " << it->second << std::endl;
    }
    
    
    std::cout << "--- Mapa de Libros ---" << std::endl << std::endl;
    
    std::map<std::string, Libro> libros;
    
    libros["1"] = Libro("1", "El señor de los anillos", 700);
    libros["2"] = Libro("2", "El capital", 550);
    libros["3"] = Libro("3", "El arte de la guerra", 345);
    
    for (auto elem : libros) {
        std::cout << "ISBN: " << elem.first << ", Libro: " << elem.second << std::endl;
    }
    
    std::cout << "--- Buscar un valor ---" << std::endl;
    
    std::map<std::string, Libro>::iterator it2;
    
    it2 = libros.find("3");
    
    if (it2 ==  libros.end()) {
        std::cout << "El libro no se encontró" << std::endl;
    }
    else {
        std::cout << "El libro es:  " << it2->second << std::endl;
    }
    
    /* Mapa con una estructura lineal */
    std::map<std::string, std::vector<Libro> > combinado;
    
    return 0;
}
