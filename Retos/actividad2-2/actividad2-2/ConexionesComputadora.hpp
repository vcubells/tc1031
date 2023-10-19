//
//  ConexionesComputadora.hpp
//  actividad2-2
//
//  Created by Vicente Cubells on 02/10/23.
//

#ifndef ConexionesComputadora_hpp
#define ConexionesComputadora_hpp

#include <iostream>
#include "/Users/vcubells/Developer/GitHub/tc1031/Tema_7_Estructuras lineales/LinkedList/LinkedList/LinkedList.hpp"
#include "/Users/vcubells/Developer/GitHub/tc1031/Tema_7_Estructuras lineales/Stack/Stack/Stack.hpp"

template <class T>
class ConexionesComputadora {
private:
    std::string ip = "";
    std::string nombre = "";
    Stack<T> * conexionesEntrantes = new Stack<T>();
    LinkedList<T> * conexionesSalientes = new LinkedList<T>();
    
public:
    ConexionesComputadora() = default;
    ConexionesComputadora(std::string _ip, std::string _name )
    :ip(_ip), nombre(_name) {};
    
    Stack<T> * getConexionesEntrantes();
    LinkedList<T> * getConexionesSalientes();
    
    void llenarConexiones(std::vector<T>);
    
    int totalConexionesEntrantes();
    int totalConexionesSalientes();
    T ultimaConexionEntrante();
    void tresConexionesConsecutivas();
};

template <class T>
void ConexionesComputadora<T>::llenarConexiones(std::vector<T> registros)
{
    for (auto registro : registros) {
        if (registro.getIPOrigen() == ip)
        {
            conexionesSalientes->insert_back(registro);
        }
        else if (registro.getIPDestino() == ip )
        {
            conexionesEntrantes->push(registro);
        }
    }
}

template <class T>
int ConexionesComputadora<T>::totalConexionesEntrantes()
{
    return conexionesEntrantes->size();
}

template <class T>
int ConexionesComputadora<T>::totalConexionesSalientes()
{
    return conexionesSalientes->size();
}

template <class T>
T ConexionesComputadora<T>::ultimaConexionEntrante()
{
    return conexionesEntrantes->top();
}

template <class T>
void ConexionesComputadora<T>::tresConexionesConsecutivas()
{
    
}


#endif /* ConexionesComputadora_hpp */
