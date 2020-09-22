//
//  main.cpp
//  memoria_dinámica
//
//  Created by Vicente Cubells on 22/09/20.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    /* Reservar memoria para un int sin inicializar */
    int * i = new int;
    
    std::cout << i << " <- " << *i << std::endl;
    
    /* Asignar un valor */
    *i = 5;
    
    std::cout << i << " <- " << *i << std::endl;
    
    /* Reservar memoria para un int e inicializar */
    int * p = new int(10);
    
    std::cout << p << " <- " << *p << std::endl;
    
    /* Reservar mucha memoria */
    double * grande = new (std::nothrow) double[1000];
    
    if (grande == nullptr) {
        std::cout << "No se puedo reservar la memoria" << std::endl;
    }
    else {
        std::cout << "Si se puedo reservar la memoria: " << grande << std::endl;
        delete[] grande;
    }
    
    /* Asignar null a un apuntador */
    char * str;
    
    //std::cout << " Antes inicializar = " << str << std::endl;
    
    str = nullptr;
    //std::cout << " Después de inicializar = " << str << std::endl;
    
    
    /* Liberar la memoria */
    delete i;
    delete p;

    
    return 0;
}
