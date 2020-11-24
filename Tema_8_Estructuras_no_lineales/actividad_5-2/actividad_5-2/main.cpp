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
    
    std::cout << "--- Set de dominios ----" << std::endl;
    
    std::set<std::string> dominios;
    
    for (auto r : registros) {
        std::string origen = r.getOrigen();
        
        std::size_t found = origen.find("reto.com");
        
        if (found == std::string::npos) {
            dominios.insert(origen);
        }
        
        std::string destino = r.getDestino();
        
        found = destino.find("reto.com");
        
        if (found == std::string::npos) {
            dominios.insert(destino);
        }
    }
    
    for (auto d : dominios) {
        std::cout << d << std::endl;
    }
        
    std::cout << std::endl;
    
    /* Eliminar todos los registros */
    registros.clear();
    dominios.clear();
    
    return 0;
}
