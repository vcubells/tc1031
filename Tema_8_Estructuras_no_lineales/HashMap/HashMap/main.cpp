//
//  main.cpp
//  HashMap
//
//  Created by Vicente Cubells on 20/11/20.
//

#include <iostream>
#include "HashMap.cpp"
#include "HashMapList.cpp"

int main(int argc, const char * argv[]) {
    
    int capacity = 5;
    
    std::cout << " --- HashMap --- " << std::endl << std::endl;
    
    /* Crear un HashMap */
    HashMap<int, int> * tabla = new HashMap<int, int>(capacity);
    
    /* Insertar elementos */
    std::cout << tabla->put(1, 100) << std::endl;
    std::cout << tabla->put(5, 500) << std::endl;
    std::cout << tabla->put(11, 1100) << std::endl;
    std::cout << tabla->put(15, 15) << std::endl;
    std::cout << tabla->put(2, 2) << std::endl;
    std::cout << tabla->put(8, 8) << std::endl;

    std::cout << tabla->get(5) << std::endl;
    std::cout << tabla->get(15) << std::endl;
    std::cout << tabla->get(8) << std::endl;
    
    std::cout << *tabla << std::endl;
    
    /* Eliminar la tabla */
    delete tabla;
    
    std::cout << " --- HashMapList --- " << std::endl << std::endl;
    /* Crear un HashMapList */
    HashMapList<int, int> * hml = new HashMapList<int, int>(capacity);
    
    /* Insertar elementos */
    std::cout << hml->put(1, 1) << std::endl;
    std::cout << hml->put(5, 5) << std::endl;
    std::cout << hml->put(11, 11) << std::endl;
    std::cout << hml->put(15, 15) << std::endl;
    std::cout << hml->put(2, 2) << std::endl;
    std::cout << hml->put(8, 8) << std::endl;
    
    std::cout << hml->get(5) << std::endl;
    std::cout << hml->get(15) << std::endl;
    std::cout << hml->get(8) << std::endl;
    std::cout << hml->get(40) << std::endl;
    
    std::cout << *hml << std::endl;
    
    /* Eliminar la tabla */
    delete hml;
    
    return 0;
}
