//
//  main.cpp
//  apuntadores
//
//  Created by Vicente Cubells on 22/09/20.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    /* Declarar variables enteras y un apuntador */
    int i, j, *p;
    
    /* Obtener la dirección de memoria de i */
    p =  &i;
    
    std::cout << "Dirección de i = " << p << std::endl;
    std::cout << "Dirección de p = " << &p << std::endl;
    
    /* Almacenar un valor en i = 10 */
    *p = 10; // i=10
    
    std::cout << "Valor de i = " << i << std::endl;
    std::cout << "Valor de *p = " << *p << std::endl;
    
    /* Obtener la dirección de j */
    p = &j;
    
    std::cout << "Dirección de j = " << p << std::endl;
    
    /* Almacenar un valor en j = -2 */
    *p = -2;
    
    std::cout << "Valor de j = " << j << std::endl;
    
    return 0;
}
