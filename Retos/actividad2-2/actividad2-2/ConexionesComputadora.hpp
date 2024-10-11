//
//  ConexionesComputadora.hpp
//  actividad2-2
//
//  Created by Vicente Cubells on 02/10/23.
//

#ifndef ConexionesComputadora_hpp
#define ConexionesComputadora_hpp

#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include "/Users/vcubells/Developer/GitHub/tc1031/Tema_7_Estructuras lineales/LinkedList/LinkedList/LinkedList.hpp"
#include "/Users/vcubells/Developer/GitHub/tc1031/Tema_7_Estructuras lineales/Stack/Stack/Stack.hpp"

template <class T>
class ConexionesComputadora {
private:
    std::string ip = "";
    std::string nombre = "";
    std::stack<T> conexionesEntrantes;
    std::list<T> conexionesSalientes;
    
    
public:
    ConexionesComputadora() = default;
    ConexionesComputadora(std::string _ip, std::string _name )
    :ip(_ip), nombre(_name) {};
    ~ConexionesComputadora();
    
    Stack<T> * getConexionesEntrantes();
    LinkedList<T> * getConexionesSalientes();
    
    void llenarConexiones(std::vector<T>);
    
    int totalConexionesEntrantes();
    int totalConexionesSalientes();
    T ultimaConexionEntrante();
    bool tresConexionesConsecutivas();
    
    /* Sobrecarga operador << */
    template <typename Tn>
    friend std::ostream & operator <<(std::ostream & os, const ConexionesComputadora<Tn> & cc);
};

template <class T>
ConexionesComputadora<T>::~ConexionesComputadora()
{
    /* Eliminar conexionesEntrantes */
    /* Eliminar conexionesSalientes */
}

template <class T>
void ConexionesComputadora<T>::llenarConexiones(std::vector<T> registros)
{
    for (auto registro : registros) {
        if (registro.getIpOrigen() == ip)
        {
            conexionesSalientes.push_back(registro);
        }
        else if (registro.getIpDestino() == ip )
        {
            conexionesEntrantes.push(registro);
        }
    }
}

template <class T>
int ConexionesComputadora<T>::totalConexionesEntrantes()
{
    return conexionesEntrantes.size();
}

template <class T>
int ConexionesComputadora<T>::totalConexionesSalientes()
{
    return conexionesSalientes.size();
}

template <class T>
T ConexionesComputadora<T>::ultimaConexionEntrante()
{
    return conexionesEntrantes.top();
}

template <class T>
bool ConexionesComputadora<T>::tresConexionesConsecutivas()
{
    if (conexionesSalientes.empty()) { return false; }
    
    int count = 1;
    T anterior = *(conexionesSalientes.begin());

    for (T temp : conexionesSalientes) {
        if (anterior == temp) {
            count++;
            if (count == 3) {
                break;
            }
        }
        else {
            anterior = temp;
            count = 1;
        }
    }
    
    if (count == 3) {
        return true;
    }
    
    return false;
}

template <class T>
std::ostream & operator <<(std::ostream & os, const ConexionesComputadora<T> & cc)
{
    os << "IP: " << cc.ip << std::endl;
    os << "Nombre: " << cc.nombre << std::endl;
    os << "--- Conexiones entrantes: ---" << std::endl;
    os << cc.conexionesEntrantes << std::endl;
    os << "--- Conexiones salientes: ---" << std::endl;
    os << cc.conexionesSalientes << std::endl;
    
    return os;
}

#endif /* ConexionesComputadora_hpp */
