//
//  main.cpp
//  actividad_5-2
//
//  Created by Vicente Cubells on 24/11/20.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "Registro.hpp"
#include "ConexionesComputadoras.hpp"
#include "/Users/vcubells/Developer/GitHub/tc1031/Tema_8_Estructuras_no_lineales/BinaryTree/BinaryTree/BST.hpp"

auto read_csv(std::string filename)
{
    /* Crear un vector de Registros */
    std::vector< Registro > lineas;

    /* Crear un input filestream para leer el archivo CSV */
    std::ifstream file(filename);

    /* Verificar si no hubo error al abrir el archivo */
    if(!file.is_open()) {
        std::cout << "ERROR: No se puede abrir el archivo" << std::endl;
        return lineas;
    }

    /* Definir variable que almacena cada línea */
    std::string linea;
    
    /* Leer datos línea a línea */
    while(std::getline(file, linea))
    {
        /* Crear un steam de la línea */
        std::stringstream ss(linea);
    
        /* Variables que almacenan cada campo leído */
        std::string fecha;
        std::string hora;
        std::string origen;
        std::string ip_origen;
        std::string pto;
        std::string destino;
        std::string ip_destino;
        std::string ptod;
        
        /* Iterar sobre la línea para extraer cada campo */
        getline(ss, fecha, ',');
        getline(ss, hora, ',');
        getline(ss, ip_origen, ',');
        getline(ss, pto, ',');
        getline(ss, origen, ',');
        getline(ss, ip_destino, ',');
        getline(ss, ptod, ',');
        getline(ss, destino);
        
        if (pto == "-") { pto = "0"; }
        if (ptod == "-") { ptod = "0"; }
        
        /* Insertar la fila con los campos separados en un vector */
        lineas.push_back(Registro(fecha,hora,origen,ip_origen,stoi(pto),destino,ip_destino,stoi(ptod)));
    }

    /* Cerrar el archivo */
    file.close();

    /* Regresar el vector de líneas leídas */
    return lineas;
}

std::map<std::string, int> conexionesPorDia(std::string fecha, std::vector<Registro> registros)
{
    std::map<std::string, int> frecuencias;
    
    for (auto r : registros) {
        
        if (r.getFecha() == fecha) {
            
            std::string destino = r.getDestino();
            
            std::size_t found_reto_com = destino.find("reto.com");
            
            std::size_t found_ = destino.find("-");
            
            if (found_reto_com == std::string::npos && found_ == std::string::npos) {
                frecuencias[destino]++;
            }
        }
    }
    
    return frecuencias;
}


 class Info
 {
    private:
        std::string dominio = "";
        int frecuencia = 0;
 public:
     Info() {}
     Info(std::string _dominio, int _frecuencia) : dominio(_dominio), frecuencia(_frecuencia) {}
     
     bool operator <(Info & otro)
     {
         return this->frecuencia < otro.frecuencia;
     }
     
     bool operator >(Info & otro)
     {
         return this->frecuencia > otro.frecuencia;
     }
     
     bool operator ==(Info & otro)
     {
         return this->dominio == otro.dominio;
     }
 }

void top(int n, std::string fecha)
{
    std::map<std::string, int> frecuencias = conexionesPorDia(fecha, registros);
    
    BST<Info> * bst = new BST<Info>();
    
    for (auto entry : frecuencias) {
        bst->insert(Info(entry.first, entry.second));
    }
    
    bst->topN(bst->getRoot(), n, 0);
    
    delete bst;
}

int main(int argc, const char * argv[]) {
    
    std::string filename;
    
    if (argc == 2) {
        filename = argv[1];
    }
    else {
        filename = "/Users/vcubells/Documents/Work Files/Clases/ITESM/Santa Fe/2020/Otoño Ago-Dic 2020/TC1031/reto/equipo0.csv";
    }
    
    /* Leer archivo CSV */
    std::vector<Registro> registros = read_csv(filename);
    
    if (registros.empty()) {
        return 0;
    }
    
    /* Mostrar los primeros 10 registros */
    //std::copy(registros.begin(), registros.begin() + 10, std::ostream_iterator<Registro>(std::cout));
    
    /* Crear el conjunto y el diccionario */
    
//    std::cout << "--- 1. Set de dominios ----" << std::endl;
//
//    std::set<std::string> dominios;
    
    //std::map<std::string, std::string> mapa;
    
    
//    for (auto r : registros) {
//        std::string origen = r.getOrigen();
//
//        std::size_t found_reto_com = origen.find("reto.com");
//
//        std::size_t found_ = origen.find("-");
//
//        if (found_reto_com == std::string::npos && found_ == std::string::npos) {
//            dominios.insert(origen);
//
//            /* Insertar en el Hash */
//            //ConexionesComputadoras conexiones(r.getIPOrigen(), origen);
//            mapa.insert(std::make_pair(origen, r.getIPOrigen()));
//        }
        
//        std::string destino = r.getDestino();
//
//        std::size_t found_reto_com = destino.find("reto.com");
//
//        std::size_t found_ = destino.find("-");
//
//        if (found_reto_com == std::string::npos && found_ == std::string::npos) {
//            //dominios.insert(destino);
//
//            /* Insertar en el Hash */
//            //ConexionesComputadoras conexiones(r.getIPDestino(), destino);
//            //mapa.insert(std::make_pair(destino, r.getIPDestino() ));
//
//        }
//    }
    
//    for (auto d : dominios) {
//        std::cout << d << std::endl;
//    }
    
    std::map<std::string, int> frecuencias = conexionesPorDia("10-8-2020", registros);
    
    for (auto p : frecuencias) {
        std::cout << p.first << " : " << p.second << std::endl;
    }
        
    std::cout << std::endl;
    
//    std::cout << "--- 2. IPs de dominios raros ----" << std::endl;
//
//    std::cout << mapa["1cvh4vcwcer9x7me4lr1.net"] << std::endl;
//    std::cout << mapa["gzk5twsf423mak2wmldj.ru"] << std::endl;
    
    
    /* Eliminar todos los registros */
    registros.clear();
    //dominios.clear();
    frecuencias.clear();
    
    return 0;
}
