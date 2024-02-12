//
//  SQLReporitorio.cpp
//  tda_db
//
//  Created by Vicente Cubells on 12/02/24.
//

#include "SQLReporitorio.hpp"
#include "repositorio.cpp"

class SQLRepositorio : public Repositorio<int>
{
    virtual int buscar(int value)
    {
        //TODO
        // SELECT id, nombre FROM tabla WHERE id = value;
        
        return 0;
    }
    
    virtual void insertar(int value)
    {
        //TODO
        // INSERT INTO tabla()
    }
    
    virtual int actualizar(int anterior, int nuevo)
    {
        //TODO
        // UPDATE ... WHERE
        return 0;
    }
    
    virtual void eliminar(int value)
    {
        //TODO
        // DELETE FROM table WHERE id = value
    }
};
