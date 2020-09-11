//
//  main.cpp
//  procesar_csv
//
//  Created by Vicente Cubells Nonell on 10/09/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//
//
// Parte de este código fue obtenido de https://stackoverflow.com/questions/34218040/how-to-read-a-csv-file-data-into-an-array

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Persona.hpp"

auto read_csv_strings(std::string filename)
{
    /* Crear un vector de vector de strings */
    std::vector< std::vector<std::string> > lineas;

    /* Crear un input filestream para leer el archivo CSV */
    std::ifstream file(filename);

    /* Verificar si no hubo error al abrir el archivo */
    if(!file.is_open()) throw std::runtime_error("No se puede abrir el archivo");

    /* Definir variable que almacena cada línea */
    std::string linea;
    
    /* Leer datos línea a línea */
    while(std::getline(file, linea))
    {
        /* Crear un steam de la línea */
        std::stringstream ss(linea);
    
        /* Variable que almacena cada campo leído */
        std::string campo;
        
        /* Definir un vector para almacenar cada campo */
        std::vector<std::string> fila;
        
        /* Iterar sobre la línea para extraer cada campo */
        while(std::getline(ss, campo, ','))
        {
            fila.push_back(campo);
        }
        
        /* Insertar la fila con los campos separados en un vector */
        lineas.push_back(fila);
    }

    /* Cerrar el archivo */
    file.close();

    /* Regresar el vector de líneas leídas */
    return lineas;
}
                
auto read_csv_persona(std::string filename)
{
    /* Crear un vector de vector de strings */
    std::vector< Persona > lineas;

    /* Crear un input filestream para leer el archivo CSV */
    std::ifstream file(filename);

    /* Verificar si no hubo error al abrir el archivo */
    if(!file.is_open()) throw std::runtime_error("No se puede abrir el archivo");

    /* Definir variable que almacena cada línea */
    std::string linea;
    
    /* Leer datos línea a línea */
    while(std::getline(file, linea))
    {
        /* Crear un steam de la línea */
        std::stringstream ss(linea);
    
        /* Variables que almacenan cada campo leído */
        std::string nombre;
        std::string email;
        std::string fecha;
        int edad;
        
        /* Iterar sobre la línea para extraer cada campo */
        getline(ss, nombre, ',');
        getline(ss, email, ',');
        getline(ss, fecha, ',');
        ss >> edad;
        
        /* Insertar la fila con los campos separados en un vector */
        lineas.push_back(Persona(nombre,email,fecha,edad));
    }

    /* Cerrar el archivo */
    file.close();

    /* Regresar el vector de líneas leídas */
    return lineas;
}

int main(int argc, const char * argv[])
{
    /* Lectura de los datos como strings */
    std::vector< std::vector<std::string> > cadenas = read_csv_strings("/Users/vcubells/Downloads/datos.csv");
    
    /* Imprimir el vector */
    for (auto line : cadenas) {
        std::copy(line.begin(), line.end(), std::ostream_iterator<std::string>(std::cout, " | "));
    }
    
    std::cout << std::endl << std::endl;
    
    /* Lectura de los datos como un objeto Persona */
    std::vector< Persona > personas = read_csv_persona("/Users/vcubells/Downloads/datos.csv");
    
    /* Imprimir el vector */
    std::copy(personas.begin(), personas.end(), std::ostream_iterator<Persona>(std::cout));

    return 0;
}
    
