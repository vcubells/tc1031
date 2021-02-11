//
//  ConexionesComputadoras.hpp
//  actividad_5-2
//
//  Created by Vicente Cubells on 24/11/20.
//

#ifndef ConexionesComputadoras_hpp
#define ConexionesComputadoras_hpp

#include <iostream>
#include <vector>

class ConexionesComputadoras {
    std::string _ip;
    std::string _nombre;
    std::vector<std::string> _entrantes;
    std::vector<std::string> _salientes;
    
public:
    
    ConexionesComputadoras(std::string ip, std::string nombre) {
        this->_ip = ip;
        this->_nombre = nombre;
    }
    
    std::string getIP() const
    {
        return this->_ip;
    }
    
};

#endif /* ConexionesComputadoras_hpp */
