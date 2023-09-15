//
//  Agencia.hpp
//  actividad-1-2
//
//  Created by Vicente Cubells on 14/09/23.
//

#ifndef Agencia_hpp
#define Agencia_hpp

#include <iostream>
#include <vector>
#include "Venta.hpp"

class Agencia {
private:
    std::vector<Auto> autos;
    std::vector<Comprador> clientes;
    std::vector<Venta> ventas;
    
    std::vector<char> tipos = {'A','a','C','c','M','m'};
    
public:
    Agencia() = default;
    
    std::vector<Auto> getAutos();
    std::vector<Comprador> getClientes();
    
    void adicionarAuto(Auto);
    void adicionarAuto();
    
    void adicionarComprador(Comprador);
    void adicionarComprador();
    
    void adicionarVenta(Venta);
    void adicionarVenta();
    
    void mostrarVentas();
    
    void autosPorComprador(Comprador);
    void autosPorComprador();
    
    void autosPorAñoYKms(int, int);
    void autosPorAñoYKms();
    
    virtual ~Agencia();
};


#endif /* Agencia_hpp */
