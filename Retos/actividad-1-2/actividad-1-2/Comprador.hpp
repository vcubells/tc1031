//
//  Comprador.hpp
//  actividad-1-2
//
//  Created by Vicente Cubells on 14/09/23.
//

#ifndef Comprador_hpp
#define Comprador_hpp

#include <iostream>

class Comprador {
private:
    std::string nombre {"Sin inicializar"};
    std::string apellidos {"Sin inicializar"};
    std::string ine {"Sin inicializar"};
    
public:
    Comprador() = default;
    Comprador(std::string _nombre, std::string _apellidos, std::string _ine):
    nombre(_nombre), apellidos(_apellidos), ine(_ine) {}
    
    std::string getINE();
    
    bool operator==(const Comprador &);
    
    friend std::ostream & operator<<(std::ostream &, const Comprador &);
};

#endif /* Comprador_hpp */
