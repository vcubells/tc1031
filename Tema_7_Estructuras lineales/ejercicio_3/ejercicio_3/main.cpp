//
//  main.cpp
//  ejercicio_3
//
//  Created by Vicente Cubells on 15/04/24.
//

#include <iostream>
#include "Cliente.hpp"

int main(int argc, const char * argv[]) {
   
    /* Definir la lista de clientes */
    std::list<Cliente> clientes;
    
    /* Adicionar clientes a la lista */
    
    Cliente c1("José");
    c1.addOperacion(Operacion("Retiro", 4));
    c1.addOperacion(Operacion("Depósito", 2));
    
    clientes.push_back(c1);
    
    Cliente c2("Maria");
    c2.addOperacion(Operacion("Consulta", 3.5));
    c2.addOperacion(Operacion("Pago", 2));
    
    clientes.push_back(c2);
    
    /* Mostrar los clientes actuales */
    for (auto c : clientes) {
        std::cout << c;
    }
    
    /* Obtener tiempo de espera de un cliente */
    float tiempo_atencion = 0.0;
    Cliente buscar("José");
    
    for (auto c : clientes) {
        tiempo_atencion += c.getDuracion();
        
        if (c == buscar) {
            break;
        }
    }
    
    std::cout << "El tiempo de atención para el cliente es: " << tiempo_atencion << std::endl;
    
    return 0;
}
