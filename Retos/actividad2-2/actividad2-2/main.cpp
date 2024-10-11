//
//  main.cpp
//  actividad2-2
//
//  Created by Vicente Cubells on 02/10/23.
//

#include <iostream>
#include "Registro.hpp"
#include "ConexionesComputadora.hpp"

int main(int argc, const char * argv[]) {
    /* Actividad 1.3 */
    std::vector<Registro> registros;
    
    registros.push_back(Registro());
    registros.push_back(Registro());
    registros.push_back(Registro());
    
    /* Suponiendo que mi dirección de red sea la siguiente */
    std::string red = "172.16.1";
    
    /* Actividad 2.2 */
    
    /* Definir la IP */
    std::string ip = "";
    std::cout << "Entra un número entre 1 y 150: ";
    std::cin >> ip;
    ip = red + "." + ip;
    
    /* Crear objeto ConexionesComputadoras */
    ConexionesComputadora<Registro> mipc(ip, "prueba");
    
    /* Llenar las estructuras */
    mipc.llenarConexiones(registros);
    
    /* Imprimir la última conexión */
    std::cout << "La última conexión entrante es "  << mipc.ultimaConexionEntrante() << std::endl;
    
    /* Imprimir el número de conexiones entrantes */
    std::cout << "El total de conexiones entrantes es:  "  << mipc.totalConexionesEntrantes() << std::endl;
    
    /* Imprimir el número de conexiones salientes */
    std::cout << "El total de conexiones salientes es: "  << mipc.totalConexionesSalientes() << std::endl;
    
    /* Imprimir si hay 3 conexiones consecutivas */
    bool existe = mipc.tresConexionesConsecutivas();
    
    if (existe) {
        std::cout << "Si existen tres conexiones consecutivas a un mismo sitio web" << std::endl;
    }
    else {
        std::cout << "Noexisten tres conexiones consecutivas a un mismo sitio web" << std::endl;
    }
    
    return 0;
}
