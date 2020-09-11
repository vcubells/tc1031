//
//  main.cpp
//  biblioteca
//
//  Created by Vicente Cubells Nonell on 09/09/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include <vector>
#include "../../ordenamiento_generico/ordenamiento_generico/Ordenamiento.hpp"
#include "Biblioteca.hpp"

void menu(Biblioteca &);

int main(int argc, const char * argv[]) {
    
    /* Crear la biblioteca */
    Biblioteca biblioteca;
    
    /* Invocar la menú de opciones */
    menu(biblioteca);
    
    return 0;
}

Libro crearLibro()
{
    std::cout << "Introduzca los datos del libro: " << std::endl;
    std::cin.get();
    
    std::string titulo;
    std::cout << "Título: ";
    getline(std::cin, titulo);
    
    std::string autor;
    std::cout << "Autor: ";
    getline(std::cin, autor);
    
    std::string editorial;
    std::cout << "Editorial: ";
    getline(std::cin, editorial);
    
    std::string edicion;
    std::cout << "Edición: ";
    getline(std::cin, edicion);
    
    int paginas;
    std::cout << "Páginas: ";
    std::cin >> paginas;
    
    int año;
    std::cout << "Año de publicación: ";
    std::cin >> año;
    
    return Libro(titulo, autor, editorial, edicion, paginas, año);
}

void mostrarResultados(std::vector<Libro> & libros, std::string msg)
{
    if (libros.size() == 0) {
        std::cout << "No se encontraron libros con el criterio especificado";
    }
    else {
        /* Imprimir los libros encontrados */
        std::cout << msg << std::endl;
        std::copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout));
        libros.clear();
    }
}

auto seleccionarAlgoritmo()
{
    int opcion = 1;
    auto algoritmo = Ordenamiento<Libro>::burbuja;
    
    do {
        std::cout << "Selecciona el algoritmo de ordenamiento: " << std::endl;
        std::cout << "1 - Burbuja" << std::endl;
        std::cout << "2 - Selección" << std::endl;
        std::cout << "3 - Inserción" << std::endl;
        std::cout << "4 - QuickSort" << std::endl;
        std::cout << "5 - MergeSort" << std::endl;
        std::cin >> opcion;
    }
    while (opcion < 1 || opcion > 5);
    
    switch (opcion) {
        case 1:
            algoritmo = Ordenamiento<Libro>::burbuja;
            break;
        case 2:
            algoritmo = Ordenamiento<Libro>::seleccion;
            break;
        case 3:
            algoritmo = Ordenamiento<Libro>::insercion;
            break;
        case 4:
            algoritmo = Ordenamiento<Libro>::quicksort;
            break;
        case 5:
            algoritmo = Ordenamiento<Libro>::mergesort;
            break;
    }
    
    return algoritmo;
}

auto seleccionarAtributoOrden(int atributo, int orden)
{
    auto ordena = Libro::compara_titulo_asc;
    
    switch (atributo) {
        case 1: /* Título */
            if (orden == 1) {
                ordena = Libro::compara_titulo_asc;
            }
            else {
                ordena = Libro::compara_titulo_desc;
            }
            break;
        case 2: /* Autor */
            if (orden == 1) {
                ordena = Libro::compara_autor_asc;
            }
            else {
                ordena = Libro::compara_autor_desc;
            }
            break;
        case 3: /* Año */
            if (orden == 1) {
                ordena = Libro::compara_año_asc;
            }
            else {
                ordena = Libro::compara_año_desc;
            }
            break;
    }
    
    return ordena;
}

auto seleccionarComparacion()
{
    int atributo = 1;
    
    do {
        std::cout << "Selecciona el atributo de ordenamiento: " << std::endl;
        std::cout << "1 - Título" << std::endl;
        std::cout << "2 - Autor" << std::endl;
        std::cout << "3 - Año" << std::endl;
        std::cin >> atributo;
    }
    while (atributo < 1 || atributo > 3);
        
    int orden = 1;
    
    do {
        std::cout << "Selecciona el orden: " << std::endl;
        std::cout << "1 - Ascendente" << std::endl;
        std::cout << "2 - Descendente" << std::endl;
        std::cin >> orden;
    }
    while (orden < 1 || orden > 2);
    
    return seleccionarAtributoOrden(atributo, orden);
}

void menu(Biblioteca & biblioteca)
{
    int opcion;
    int año;
    std::string titulo;
    std::vector<Libro> encontrados;
    
    
    do {
        std::cout << "--- Menú de opciones ---" << std::endl;
        std::cout << "1 - Adicionar libro" << std::endl;
        std::cout << "2 - Eliminar libro" << std::endl;
        std::cout << "3 - Buscar menores que un año" << std::endl;
        std::cout << "4 - Buscar mayores a un año" << std::endl;
        std::cout << "5 - Buscar en un rango de años" << std::endl;
        std::cout << "6 - Buscar por autor" << std::endl;
        std::cout << "7 - Buscar por editorial" << std::endl;
        std::cout << "8 - Ordenar" << std::endl;
        std::cout << "9 - Mostrar libros en la biblioteca" << std::endl;
        std::cout << "10 - Salir" << std::endl;
        
        std::cout << "Ingresa la opción deseada: ";
        std::cin >> opcion;
        
        switch (opcion) {
            case 1:
            {
                /* Adicionar libros */
                Libro libro = crearLibro();
                biblioteca.adicionarLibro(libro);
                
                break;
            }
            case 2:
            {
                /* Eliminar libros*/
                std::cout << "Entre el título del libro a eliminar: ";
                std::cin.get();
                getline(std::cin, titulo);
                
                encontrados = biblioteca.eliminarLibro(titulo);
                
                mostrarResultados(encontrados, "Libros eliminados:");
                
                break;
            }
            case 3:
            {
                /* Buscar libros menores a un año */
                std::cout << "Entre el año: ";
                std::cin >> año;
                
                encontrados = biblioteca.buscarAntesDeAño(año);
                
                mostrarResultados(encontrados, "Libros encontrados:");
                
                break;
            }
            case 4:
            {
                /* Buscar mayores a un año */
                std::cout << "Entre el año: ";
                std::cin >> año;
                
                encontrados = biblioteca.buscarDespuesDeAño(año);
                
                mostrarResultados(encontrados, "Libros encontrados:");
                
                break;
            }
            case 5:
            {
                /* Buscar por rango de años */
                std::cout << "Entre el año inicial: ";
                std::cin >> año;
                
                int año_final;
                std::cout << "Entre el año final: ";
                std::cin >> año_final;
                
                encontrados = biblioteca.buscarEntreAños(año, año_final);
                
                mostrarResultados(encontrados, "Libros encontrados:");
                
                break;
            }
            case 6:
            {
                /* Buscar por autor */
                std::cout << "Entre el autor: ";
                std::cin.get();
                std::string autor;
                getline(std::cin, autor);
                    
                encontrados = biblioteca.buscarPorAutor(autor);
                    
                mostrarResultados(encontrados, "Libros encontrados:");
                    
                break;
            }
            case 7:
            {
                /* Buscar por editorial */
                std::cout << "Entre la editorial: ";
                std::cin.get();
                std::string editorial;
                getline(std::cin, editorial);
                
                encontrados = biblioteca.buscarPorEditorial(editorial);
                
                mostrarResultados(encontrados, "Libros encontrados:");
                
                break;
            }
            case 8:
            {
                /* Invocar al método ordenar */
                
                auto algoritmo = seleccionarAlgoritmo();
                auto compara = seleccionarComparacion();
                
                biblioteca.ordenar(algoritmo, compara);
                
                break;
            }
            case 9:
            {
                /* Visualizar los libros en la biblioteca  */
                if (biblioteca.size() == 0) {
                    std::cout << "La biblioteca está vacía" << std::endl;
                }
                else {
                    std::cout << "Libros en la biblioteca:" << std::endl;
                    std::cout << biblioteca;
                }
                
                break;
            }
            case 10:
                /* Terminar */
                std::cout << "Gracias por utilizar la biblioteca. Te esperamos pronto." << std::endl;
                break;
            default:
                std::cout << "Opción inválida" << std::endl;
                break;
        }
        
        std::cout << std::endl;
        
    }
    while (opcion != 10);
}
