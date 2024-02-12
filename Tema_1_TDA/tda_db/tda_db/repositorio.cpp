//
//  repositorio.cpp
//  tda_db
//
//  Created by Vicente Cubells on 12/02/24.
//

#include "repositorio.hpp"

template <class T>
class Repositorio {
    virtual int buscar(T value) = 0;
    virtual void insertar(T value) = 0;
    virtual int actualizar(T anterior, T nuevo) = 0;
    virtual void eliminar(T value) = 0;
};

