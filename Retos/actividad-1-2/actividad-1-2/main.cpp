//
//  main.cpp
//  actividad-1-2
//
//  Created by Vicente Cubells on 09/09/21.
//

#include <iostream>
#include "Agencia.hpp"
#include "Moto.hpp"
#include "Camioneta.hpp"



int main(int argc, const char * argv[]) {
    
    
    /* Crear la agencia */
    Agencia agencia;
    
    /* ----------------------- */
    /* --- Casos de prueba --- */
    /* ----------------------- */
    
    /* Crear autos */
    agencia.adicionarAuto(Auto("a1", "Honda", 2020, 35000));
    agencia.adicionarAuto(Moto("m1", "Ducati", 2020, 80000, 600 ));
    agencia.adicionarAuto(Camioneta("c1", "Toyota", 2019, 67000, "4x2"));
    agencia.adicionarAuto(Auto("a2", "BMW", 2022, 5000));
    
    /* Crear clientes */
    agencia.adicionarComprador(Comprador("Juana", "Bacallao", "1"));
    agencia.adicionarComprador(Comprador("Vicente", "Merario", "2"));
    agencia.adicionarComprador(Comprador("Valentin", "Siempre", "3"));
    
    /* Adicionar ventas */
    agencia.adicionarVenta(Venta(600000, agencia.getClientes()[0], agencia.getAutos()[0]));
    agencia.adicionarVenta(Venta(100000, agencia.getClientes()[1], agencia.getAutos()[1]));
    agencia.adicionarVenta(Venta(350000, agencia.getClientes()[2], agencia.getAutos()[2]));
    agencia.adicionarVenta(Venta(800000, agencia.getClientes()[0], agencia.getAutos()[3]));
    
    /* Mostrar ventas ordenadas por monto */
    agencia.mostrarVentas();
    
    /* Mostrar autos de un cliente */
    agencia.autosPorComprador(agencia.getClientes()[0]);
    
    /* Mostrar autos por año y kiloometraje */
    agencia.autosPorAñoYKms(2020, 40000);
    
    /* ----------------------- */
    /* --- Fin de los Casos -- */
    /* ----------------------- */
    
    /* Definir la variable para leer la opción seleccionada */
    int opcion = 0;
    
    /* Repetir el menú de opciones hasta que el usuario decida salir */
    do {
        /* Mostrar el menú de opciones */
        std::cout << "*******************************" << std::endl;
        std::cout << "*** Servicios de la agencia ***" << std::endl;
        std::cout << "*******************************" << std::endl;
        
        std::cout << "1-Adicionar un cliente" << std::endl;
        std::cout << "2-Adicionar un auto" << std::endl;
        std::cout << "3-Adicionar una venta" << std::endl;
        std::cout << "4-Mostrar las ventas ordenadas" << std::endl;
        std::cout << "5-Buscar los autos de un cliente" << std::endl;
        std::cout << "6-Buscar los autos por año y por kilometraje " << std::endl;
        std::cout << "0-Salir" << std::endl;
        
        /* Leer la opción seleccionada */
        std::cout << "Selecciona la opción deseada: ";
        std::cin >> opcion;
        
        /* Ejecutar la acción según la opción seleccionada */
        switch (opcion) {
            case 1:
                agencia.adicionarComprador();
                break;
            case 2:
                agencia.adicionarAuto();
                break;
            case 3:
                agencia.adicionarVenta();
                break;
            case 4:
                agencia.mostrarVentas();
                break;
            case 5:
                agencia.autosPorComprador();
                break;
            case 6:
                agencia.autosPorAñoYKms();
                break;
            case 0:
                std::cout << "Gracias por utilizar la agencia, lo esperamos pronto!!!" << std::endl;
                break;
            default:
                std::cout << "ERROR: La opción especificada no existe" << std::endl;
                break;
        }
        
    }
    while (opcion != 0);

    
    return 0;
}
