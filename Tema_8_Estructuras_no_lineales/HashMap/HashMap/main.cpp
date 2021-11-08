//
//  main.cpp
//  HashMap
//
//  Created by Vicente Cubells on 20/11/20.
//

#include <iostream>
#include "HashMap.cpp"

int main(int argc, const char * argv[]) {
    
    int capacity = 5;
    
    /* Crear un HashMap */
    HashMap<int, int> * tabla = new HashMap<int, int>(capacity);
    
    /* Insertar elementos */
    std::cout << tabla->put(1, 1) << std::endl;
    std::cout << tabla->put(5, 5) << std::endl;
    std::cout << tabla->put(11, 11) << std::endl;
    std::cout << tabla->put(15, 15) << std::endl;
    std::cout << tabla->put(2, 2) << std::endl;
    std::cout << tabla->put(8, 8) << std::endl;
    
    std::cout << tabla->get(5) << std::endl;
    std::cout << tabla->get(15) << std::endl;
    std::cout << tabla->get(8) << std::endl;
    
    std::cout << *tabla;
    
    /* Eliminar la tabla */
    delete tabla;
    
    return 0;
}
