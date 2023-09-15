//
//  Agencia.cpp
//  actividad-1-2
//
//  Created by Vicente Cubells on 14/09/23.
//

#include "Agencia.hpp"
#include "Moto.hpp"
#include "Camioneta.hpp"
#include <algorithm>


std::vector<Auto> Agencia::getAutos()
{
    return autos;
}

std::vector<Comprador> Agencia::getClientes()
{
    return clientes;
}

void Agencia::adicionarAuto(Auto coche)
{
    /* Adicionar un auto al vector de autos */
    autos.push_back(coche);
    
    std::cout << "INFO: El auto ha sido adicionado" << std::endl;
}

void Agencia::adicionarAuto()
{
    /* Seleccionar el tipo de auto */
    std::cout << "¿Qué tipo de vehículo desea adicionar? "<< std::endl;
    std::cout << "(A)uto" << std::endl;
    std::cout << "(M)oto" << std::endl;
    std::cout << "(C)amioneta" << std::endl;
    
    /* Leer el tipo de auto a adicionar */
    char tipo;
    std::cout << "Seleccione el tipo de auto: ";
    std::cin >> tipo;
    
    /* Validar que el tipo de auto seleccionado sea correcto */
    if (std::find(tipos.begin(), tipos.end(), tipo) == tipos.end()) {
        std::cout << "ERROR: El tipo de auto especificado es erróneo" << std::endl;
        return;
    }
    
    /* Leer el código */
    std::string codigo;
    std::cout << "Entre el código: ";
    std::cin >> codigo;
    
    /* Crear un auto dummy para hacer la comparación */
    Auto temp(codigo,"",0,0);
    
    /* Validar que el auto a adicionar no exista */
    if (std::find(autos.begin(), autos.end(), temp) != autos.end()) {
        std::cout << "ERROR: Un auto con ese código ya existe" << std::endl;
        return;
    }
    
    /* Leer la marca */
    std::string marca;
    std::cout << "Entre la marca: ";
    std::cin >> marca;
    
    /* Leer el modelo */
    int modelo;
    std::cout << "Entre el modelo: ";
    std::cin >> modelo;
    
    /* Leer el kilometraje */
    int kms;
    std::cout << "Entre el kilometraje: ";
    std::cin >> kms;
    
    switch (tipo) {
        /* Caso para un auto */
        case 'A':
        case 'a':
            /* Crear un auto nuevo */
            adicionarAuto(Auto(codigo, marca, modelo, kms));
            break;
        /* Caso para una moto */
        case 'M':
        case 'm':
            /* Leer el cilindraje */
            int cilindraje;
            std::cout << "Entre el cilindraje: ";
            std::cin >> cilindraje;
            
            /* Crear una moto nueva */
            adicionarAuto(Moto(codigo, marca, modelo, kms, cilindraje));
            break;
        /* Caso para una camioneta */
        case 'C':
        case 'c':
            /* Leer la tracción */
            std::string traccion;
            std::cout << "Entre la tracción (4x2, 4x4, AWD o 4WD): ";
            std::cin >> traccion;
            
            /* Crear una camioneta nueva */
            adicionarAuto(Camioneta(codigo, marca, modelo, kms, traccion));
            break;
    }
}

void Agencia::adicionarComprador(Comprador cliente)
{
    /* Adicionar un cliente al vector de clientes */
    clientes.push_back(cliente);
    
    std::cout << "INFO: El cliente ha sido adicionado" << std::endl;
}

void Agencia::adicionarComprador()
{
    std::cout << "Especifica los datos del cliente "<< std::endl;
    
    /* Leer el INE */
    std::string ine;
    std::cout << "Entre el INE: ";
    std::cin >> ine;
    
    /* Crear un objeto dummy para hacer la comparación */
    Comprador temp("","",ine);
    
    /* Validar que el cliente a adicionar no exista */
    if (std::find(clientes.begin(), clientes.end(), temp) != clientes.end()) {
        std::cout << "ERROR: Un cliente con ese INE ya existe" << std::endl;
        return;
    }
    
    /* Leer el nombre */
    std::string nombre;
    std::cout << "Entre el nombre: ";
    std::cin >> nombre;
    
    /* Leer los apellidos */
    std::string apellidos;
    std::cout << "Entre los apellidos: ";
    std::cin >> apellidos;
    
    /* Crear un nuevo cliente */
    adicionarComprador(Comprador(nombre, apellidos, ine));
}

void Agencia::adicionarVenta(Venta venta)
{
    ventas.push_back(venta);
    venta.getAuto().setComprado();
    
    std::cout << "INFO: La venta ha sido adicionada" << std::endl;
}

void Agencia::adicionarVenta()
{
    /* Validar que se tengan clientes */
    if (clientes.size() == 0) {
        std::cout << "ERROR: Aún no tiene clientes registrados" << std::endl;
        return;
    }
    
    /* Validar que se tengan autos */
    if (autos.size() == 0) {
        std::cout << "ERROR: Aún no tiene autos registrados" << std::endl;
        return;
    }
    
    /* Mostrar la lista de clientes */
    std::cout << " >>> Listado de clientes <<< " << std::endl;
    for (int i = 0; i < clientes.size(); ++i) {
        std::cout << i << "-" << clientes[i];
    }
    
    /* Leer el índide del cliente seleccionado */
    int index_cliente;
    std::cout << "Seleccione el número del cliente: " << std::endl;
    std::cin >> index_cliente;
    
    /* Validar que el cliente seleccionado sea válido */
    if (index_cliente < 0 || index_cliente >= clientes.size()) {
        std::cout << "ERROR: El comprador especificado no es válido" << std::endl;
        return;
    }
    
    /* Mostrar la lista de autos  */
    std::cout << " >>> Listado de autos <<< " << std::endl;
    for (int i = 0; i < autos.size(); ++i) {
        if (!autos[i].estaComprado()) {
            std::cout << i << "-" << autos[i];
        }
    }
    
    /* Leer el índice del auto seleccionado */
    int index_auto;
    std::cout << "Seleccione el número del auto: " << std::endl;
    std::cin >> index_auto;
    
    /* Validar que el auto seleccionado sea válido */
    if (index_auto < 0 || index_auto >= autos.size() || autos[index_auto].estaComprado()) {
        std::cout << "ERROR: El auto especificado no es válido" << std::endl;
        return;
    }
    
    /* Leer el monto de la venta */
    float monto;
    std::cout << "Entre el monto de la venta: ";
    std::cin >> monto;
    
    /* Adicionar la venta */
    adicionarVenta(Venta(monto, clientes[index_cliente], autos[index_auto]));
}

void Agencia::mostrarVentas()
{
    /* Validar que se hayan realizado ventas */
    if (ventas.size() == 0) {
        std::cout << "ERROR: Aún no se ha realizado ninguna venta" << std::endl;
    }
    else {
        /* Si existen ventas, se ordenan descendentemente por el monto */
        std::sort(ventas.begin(), ventas.end(), [](Venta a, Venta b) {return a.getMonto() > b.getMonto();});
        
        /* Se imprimen las ventas */
        std::cout << std::endl << " >>> Ventas ordenadas descendentemente por el monto " << std::endl;
        
        for (auto venta : ventas) {
            std::cout << venta;
        }
    }
}

void Agencia::autosPorComprador(Comprador cliente)
{
    std::cout << std::endl << " >>> Autos comprados por " << cliente;
    
    /* Mostrar los autos del cliente seleccionado */
    for (auto venta : ventas) {
        if (venta.getComprador().getINE() == cliente.getINE()) {
            std::cout << venta.getAuto();
        }
    }
}

void Agencia::autosPorComprador()
{
    /* Validar que existan clientes */
    if (clientes.size() == 0) {
        std::cout << "ERROR: Aún no tiene clientes registrados" << std::endl;
        return;
    }
    
    /* Mostrar la lista de clientes */
    std::cout << " >>> Listado de clientes <<< " << std::endl;
    for (int i = 0; i < clientes.size(); ++i) {
        std::cout << i << "-" << clientes[i];
    }
    
    /* Leer el número del cliente que va a comprar */
    int index;
    std::cout << "Seleccione el número del cliente a buscar: ";
    std::cin >> index;
    
    /* Validar que el cliente seleccionado sea válido */
    if (index < 0 || index >= clientes.size()) {
        std::cout << "ERROR: El cliente especificado no es válido" << std::endl;
    }
    else {
        /* Mostrar los autos del cliente seleccionado */
        autosPorComprador(clientes[index]);
    }
}

void Agencia::autosPorAñoYKms(int modelo, int kms)
{
    /* Buscar y mostrar los autos que cumplen con los criterios de búsqueda */
    std::cout << std::endl << " >>> Autos encontrados del año " << modelo << " y con kilometraje >= " << kms << std::endl;
    for (auto coche : autos) {
        if (coche.getModelo() == modelo && coche.getKms() >= kms) {
            std::cout << coche;
        }
    }
}

void Agencia::autosPorAñoYKms()
{
    /* Validar que se tengan autos */
    if (autos.size() == 0) {
        std::cout << "ERROR: Aún no tiene autos registrados" << std::endl;
        return;
    }
    
    /* Leer el año a buscar */
    int modelo;
    std::cout << "Entre el año a buscar: ";
    std::cin >> modelo;
    
    /* Leer el kilometraje mínimo */
    int kms;
    std::cout << "Entre el kilometraje a buscar: ";
    std::cin >> kms;
    
    /* Buscar y mostrar los autos que cumplen con los criterios de búsqueda */
    autosPorAñoYKms(modelo, kms);
}

Agencia::~Agencia()
{
    /* Eliminar las ventas realizadas */
    ventas.clear();
    
    /* Eliminar los autos registrados */
    autos.clear();
    
    /* Eliminar los clientes registrados */
    clientes.clear();
}
