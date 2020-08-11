//
//  Array.h
//  tc1031
//
//  Created by Vicente Cubells Nonell on 11/08/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#ifndef Array_h
#define Array_h

#define MAX 5

class Array
{
private:
    int datos[MAX];     // Espacio de almacenamiento
    int longitud = 0;   // Cantidad de elementos
    
public:
    int obtener(int index);
    int getLongitud();
    bool estaLleno();
    int eliminar();
    void insertar(int item);
    void imprimir();
};

#endif /* Array_h */
