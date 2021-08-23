//
//  main.cpp
//  invierte_cadena
//
//  Created by Vicente Cubells on 23/08/21.
//

#include <iostream>

std::string invierte(std::string, unsigned long, unsigned long);


int main(int argc, const char * argv[]) {
    std::string cadena;
    
    /* Leer cadena de caracteres */
    std::cout << "Entra una cadena de caracteres: ";
    std::getline(std::cin, cadena);
    
    std::cout << "Cadena: " << cadena << std::endl;
    
    /* Invocar a la función recursiva */
    std::string invertida = invierte(cadena, 0, cadena.length()-1);
    
    std::cout << "Invertida: " << invertida << std::endl;
    
    return 0;
}

std::string invierte(std::string cadena, unsigned long izquierda, unsigned long  derecha)
{
    if (izquierda >= derecha) {
        return cadena;
    }
    else {
        std::swap(cadena[izquierda], cadena[derecha]);
        return invierte(cadena, izquierda+1, derecha-1);
    }
}
