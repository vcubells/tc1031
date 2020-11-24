//
//  Registro.hpp
//  actividad_5-2
//
//  Created by Vicente Cubells on 24/11/20.
//

#ifndef Registro_hpp
#define Registro_hpp

#include <iostream>

class Registro {
    std::string fecha;
    std::string hora;
    std::string origen;
    std::string ip_origen;
    int puerto_origen;
    
    std::string destino;
    std::string ip_destino;
    int puerto_destino;
    
public:
    Registro(std::string _fecha, std::string _hora,
             std::string _origen, std::string _ipo, int _pto,
             std::string _destino, std::string _ipd, int _ptod):
    fecha(_fecha), hora(_hora),
    origen(_origen), ip_origen(_ipo), puerto_origen(_pto),
    destino(_destino), ip_destino(_ipd), puerto_destino(_ptod)
    {}
    
    std::string getFecha() const;
    std::string getHora() const;
    std::string getOrigen() const;
    std::string getIPOrigen() const;
    int getPuertoOrigen() const;
    std::string getDestino() const;
    std::string getIPDestino() const;
    int getPuertoDestino() const;

    friend std::ostream & operator<<(std::ostream & , const Registro & );
    
};



#endif /* Registro_hpp */
