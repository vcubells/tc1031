//
//  NoSQLRepositorio.cpp
//  tda_db
//
//  Created by Vicente Cubells on 12/02/24.
//

#include "NoSQLRepositorio.hpp"
#include "repositorio.cpp"

class NoSQLRepositorio : public Repositorio<float>
{
    virtual int buscar(float value)
    {
        //TODO
        // find {id, nombre} .... ;
        
        return 0;
    }
    
    virtual void insertar(float value)
    {
        //TODO
        // add {id: 3, nombre : "Juan"} ...
    }
    
    virtual int actualizar(float anterior, float nuevo)
    {
        //TODO
        // match {} ...
        return 0;
    }
    
    virtual void eliminar(float value)
    {
        //TODO
        // match {id : value} ....
    }
};
