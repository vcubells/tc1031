//
//  main.cpp
//  aritmética_apuntadores
//
//  Created by Vicente Cubells on 22/09/20.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    /* Definir un arreglo de enteros */
    int vector[5];
    
    /* Asignar valor al vector */
    for (int i = 0; i < 5; ++i) {
        vector[i] = i;
    }
    
    /* Imprimir el vector */
    for (int i = 0; i < 5; ++i) {
        std::cout << i << " = " << vector[i] << std::endl;
    }
    
    /* Imprimir vector con aritmética de apuntadores */
    int * fin = vector + 5;
    for (int * p = vector; p < fin; ++p) {
        std::cout << p << " <- " << *p << std::endl;
    }
    
    /* Imprimir utilizando un iterador */
    for (auto valor : vector) {
        std::cout << &valor << " <- " << valor << std::endl;
    }

    
    return 0;
}
