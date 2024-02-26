//
//  main.cpp
//  palindromo
//
//  Created by Vicente Cubells on 19/08/21.
//

#include <iostream>
#include <string>
#include <regex>

bool palindromo(std::string, unsigned long, unsigned long);

int main(int argc, const char * argv[]) {
    
    /* ¿Qué es un palíndromo? : Es una cadena que se lee igual de izquierda -> derecha que de derecha -> izquierda
        Ejemplos:
                oso, ana, oxxo
                dabale arroz a la zorra el abad ->
                dabalearrozalazorraelabad -> dabale....
     
     */
    
    std::string cadena;
    
    /* Leer cadena de caracteres */
    std::cout << "Entra una cadena de caracteres: ";
    std::getline(std::cin, cadena);
    
    std::cout << "Cadena: " << cadena << std::endl;
    
    /* Eliminar los espacios en blanco */
    auto cadena_sin_espacios = std::regex_replace(cadena, std::regex("\\s+"), "");
    
    /* Invocar a la función recursiva */
    bool es_palindromo = palindromo(cadena_sin_espacios, 0, cadena_sin_espacios.length()-1);
    
    /* Mostrar el resultado */
    if (es_palindromo) {
        std::cout << "Es un palíndromo";
    }
    else {
        std::cout << "No es un palíndromo";
    }
    
    std::cout << std::endl;
    
    return 0;
}

bool palindromo(std::string cadena, unsigned long izquierda, unsigned long  derecha)
{
    if (izquierda >= derecha) {
        return true;
    }
    else if (cadena[izquierda] != cadena[derecha]) {
        return false;
    }
    else {
        return palindromo(cadena, izquierda+1, derecha-1);
    }
}
