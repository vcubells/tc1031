//
//  Libro.hpp
//  biblioteca
//
//  Created by Vicente Cubells Nonell on 09/09/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#ifndef Libro_hpp
#define Libro_hpp

#include <iostream>

class Libro {
private:
    std::string titulo;
    std::string autor;
    std::string editorial;
    std::string edicion;
    int paginas;
    int año;
    
    
public:
    
    Libro():Libro("indefinido","indefinido","indefinido","indefinido",0,0)
    {
        
    }
    
    Libro(std::string _titulo, std::string _autor, std::string _editorial, std::string _edicion, int _paginas, int _año)
    : titulo(_titulo), autor(_autor), editorial(_editorial), edicion(_edicion), paginas(_paginas), año(_año)
    {
        
    }
    
    ~Libro()
    {
        
    }
    
    auto Titulo()       -> std::string &       { return titulo; }
    auto Titulo() const -> const std::string & { return titulo; }
    
    auto Autor()       -> std::string &       { return autor; }
    auto Autor() const -> const std::string & { return autor; }
    
    auto Editorial()       -> std::string &       { return editorial; }
    auto Editorial() const -> const std::string & { return editorial; }
    
    auto Edicion()       -> std::string &       { return edicion; }
    auto Edicion() const -> const std::string & { return edicion; }
    
    auto Paginas()       -> int &       { return paginas; }
    auto Paginas() const -> const int & { return paginas; }
    
    auto Año()       -> int &       { return año; }
    auto Año() const -> const int & { return año; }
    
    static bool compara_titulo_asc(Libro, Libro);
    static bool compara_titulo_desc(Libro, Libro);
    static bool compara_titulo_eq(Libro, Libro);
    
    static bool compara_autor_asc(Libro, Libro);
    static bool compara_autor_desc(Libro, Libro);
    static bool compara_autor_eq(Libro, Libro);
    
    static bool compara_editorial_asc(Libro, Libro);
    static bool compara_editorial_desc(Libro, Libro);
    static bool compara_editorial_eq(Libro, Libro);
    
    static bool compara_edicion_asc(Libro, Libro);
    static bool compara_edicion_desc(Libro, Libro);
    static bool compara_edicion_eq(Libro, Libro);
    
    static bool compara_paginas_asc(Libro, Libro);
    static bool compara_paginas_desc(Libro, Libro);
    static bool compara_paginas_eq(Libro, Libro);
    
    static bool compara_año_asc(Libro, Libro);
    static bool compara_año_desc(Libro, Libro);
    static bool compara_año_eq(Libro, Libro);
    
    friend std::ostream & operator<<(std::ostream & os, const Libro & libro);
};

#endif /* Libro_hpp */
