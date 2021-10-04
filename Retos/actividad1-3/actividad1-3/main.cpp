//
//  main.cpp
//  actividad1-3
//
//  Created by Vicente Cubells on 27/09/21.
//

#include <iostream>
#include "Registro.hpp"
#include <vector>
#include <algorithm>
#include "/Users/vcubells/Developer/GitHub/tc1031/Tema_5_Ordenamiento/ordenamiento_generico/ordenamiento_generico/Ordenamiento.hpp"

int main(int argc, const char * argv[]) {
    
    std::vector<Registro> registros;
    
    registros.push_back(Registro("10-11-2021", "80"));
    registros.push_back(Registro("11-11-2021", "80"));
    registros.push_back(Registro("12-11-2021", "80"));
    registros.push_back(Registro("10-11-2021", "80"));
    registros.push_back(Registro("10-11-2021", "80"));
    registros.push_back(Registro("11-11-2021", "80"));
    registros.push_back(Registro("12-11-2021", "80"));
    registros.push_back(Registro("12-11-2021", "80"));
    registros.push_back(Registro("11-11-2021", "80"));
    
    std::copy(registros.begin(), registros.end(), std::ostream_iterator<Registro>(std::cout, " "));
    
    /* Registros del segundo día */
    
    std::vector<Registro> ordenado = Ordenamiento<Registro>::insercion(registros, Registro::compara_fecha_asc);
    
    std::cout << "Vector ordenado por fecha" << std::endl;
    
    std::copy(ordenado.begin(), ordenado.end(), std::ostream_iterator<Registro>(std::cout, " "));
    
    std::string fecha = ordenado[0].getFecha();
    
    int i = 1;
    for (; fecha == ordenado[i].getFecha(); ++i);
    
    fecha = ordenado[i].getFecha();
    
    std::cout << "Segundo día = " << fecha << std::endl;
    
    int cont = 0;
    for (; fecha == ordenado[i].getFecha(); ++i)
    {
        cont++;
    }
    
    std::cout << "Registro en Segundo día = " << cont << std::endl;
    
    return 0;
}
