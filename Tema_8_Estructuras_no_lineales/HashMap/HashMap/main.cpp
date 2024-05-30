//
//  main.cpp
//  HashMap
//
//  Created by Vicente Cubells on 20/11/20.
//

#include <iostream>
#include "HashMap.cpp"
#include "HashMapList.cpp"

int main(int argc, const char * argv[]) {
    
    int capacity = 5;
    
    std::cout << " --- HashMap --- " << std::endl << std::endl;
    
    /* Crear un HashMap */
    std::cout << "(C) Se crea el HashMap" << std::endl;
    HashMap<int, int> * tabla = new HashMap<int, int>(capacity);
    
    /* Insertar elementos */
    std::cout << "(I) Se inserta un elemento en el índice: " << tabla->put(1, 100) << std::endl;
    std::cout << "(I) Se inserta un elemento en el índice: " << tabla->put(5, 500) << std::endl;
    std::cout << "(I) Se inserta un elemento en el índice: " << tabla->put(11, 1100) << std::endl;
    std::cout << "(I) Se inserta un elemento en el índice: " << tabla->put(15, 15) << std::endl;
    std::cout << "(I) Se inserta un elemento en el índice: " << tabla->put(2, 2) << std::endl;
    
    /* Valores que no se pueden insertar porque la tabla está llena */
    std::cout << "(E) Valores que no se pueden insertar porque la tabla está llena" << std::endl;
    std::cout << "(I) Se inserta un elemento en el índice: " << tabla->put(8, 8) << std::endl;
    std::cout << "(I) Se inserta un elemento en el índice: " << tabla->put(20, 800) << std::endl;

    /* Obtener valores a partir de las claves */
    std::cout << "(G) Se recuperan valores a partir de sus llaves" << std::endl;
    std::cout << "(G) El valor de la llave 5 es: " << tabla->get(5) << std::endl;
    std::cout << "(G) El valor de la llave 15 es: "<< tabla->get(15) << std::endl;
    std::cout << "(G) El valor de la llave 8 es: "<< tabla->get(8) << std::endl;
    
    /* Mostrar contenido de la tabla */
    std::cout << "(L) Mostrar el  contenido de la tabla" << std::endl;
    std::cout << *tabla << std::endl;
    
    /* CASO DE PRUEBA ACTIVIDAD 5.1 */
    /* Eliminar elementos de la tabla */
    std::cout << "(R) Se eliminan valores a partir de sus llaves" << std::endl;
    std::cout << "(R) Se elimina el valor de la llave 5 es: " << tabla->remove(5) << std::endl;
    std::cout << "(R) Se elimina el valor de la llave 15 es: "<< tabla->remove(15) << std::endl;
    std::cout << "(R) Se elimina el  valor de la llave 8 es: "<< tabla->remove(8) << std::endl;
    
    /* Mostrar contenido de la tabla */
    std::cout << "(L) Mostrar el  contenido de la tabla después de eliminar elementos" << std::endl;
    std::cout << *tabla << std::endl;
    
    /* Eliminar la tabla */
    std::cout << "(D) Se elimina la tabla y se libera la memoria" << std::endl << std::endl;
    delete tabla;
    
    std::cout << " --- HashMapList --- " << std::endl << std::endl;
    /* Crear un HashMapList */
    std::cout << "(C) Se crea el HashMapList" << std::endl;
    HashMapList<int, int> * hml = new HashMapList<int, int>(capacity);
    
    /* Insertar elementos */
    std::cout << "(I) Se inserta un elemento en el índice: " << hml->put(1, 1) << std::endl;
    std::cout << "(I) Se inserta un elemento en el índice: " << hml->put(5, 5) << std::endl;
    std::cout << "(I) Se inserta un elemento en el índice: " << hml->put(11, 11) << std::endl;
    std::cout << "(I) Se inserta un elemento en el índice: " << hml->put(15, 15) << std::endl;
    std::cout << "(I) Se inserta un elemento en el índice: " << hml->put(2, 2) << std::endl;
    std::cout << "(I) Se inserta un elemento en el índice: " << hml->put(8, 8) << std::endl;
    std::cout << "(I) Se inserta un elemento en el índice: " << hml->put(20, 800) << std::endl;
    
    /* Obtener valores a partir de las claves */
    std::cout << "(G) Se recuperan valores a partir de sus llaves" << std::endl;
    std::cout << "(G) El valor de la llave 5 es: " << hml->get(5) << std::endl;
    std::cout << "(G) El valor de la llave 15 es: " << hml->get(15) << std::endl;
    std::cout << "(G) El valor de la llave 8 es: " << hml->get(8) << std::endl;
    std::cout << "(G) El valor de la llave 40 es: " << hml->get(40) << std::endl;
    
    /* Mostrar contenido de la tabla */
    std::cout << "(L) Mostrar el  contenido de la tabla" << std::endl;
    std::cout << *hml << std::endl;
    
    /* CASO DE PRUEBA ACTIVIDAD 5.1 */
    /* Eliminar elementos de la tabla */
    std::cout << "(R) Se eliminan valores a partir de sus llaves" << std::endl;
    std::cout << "(R) Se elimina el valor de la llave 5 es: " << hml->remove(5) << std::endl;
    std::cout << "(R) Se elimina el valor de la llave 15 es: "<< hml->remove(11) << std::endl;
    std::cout << "(R) Se elimina el  valor de la llave 8 es: "<< hml->remove(40) << std::endl;
    
    /* Mostrar contenido de la tabla */
    std::cout << "(L) Mostrar el  contenido de la tabla después de eliminar elementos" << std::endl;
    std::cout << *tabla << std::endl;
    
    /* Eliminar la tabla */
    std::cout << "(D) Se elimina la tabla y se libera la memoria" << std::endl << std::endl;
    delete hml;
    
    return 0;
}
