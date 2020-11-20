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
    tabla->put(1, 1);
    tabla->put(5, 5);
    tabla->put(11, 11);
    tabla->put(15, 15);
    tabla->put(2, 2);
    tabla->put(8, 8);
    
    std::cout << tabla->get(5) << std::endl;
    std::cout << tabla->get(15) << std::endl;
    std::cout << tabla->get(8) << std::endl;
    
    /* Eliminar la tabla */
    delete tabla;
    
    return 0;
}
