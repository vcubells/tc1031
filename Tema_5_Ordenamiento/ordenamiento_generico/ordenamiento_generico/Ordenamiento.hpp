//
//  Ordenamiento.hpp
//  ordenamiento_generico
//
//  Created by Vicente Cubells Nonell on 01/09/20.
//  Copyright © 2020 Vicente Cubells Nonell. All rights reserved.
//

#ifndef Ordenamiento_hpp
#define Ordenamiento_hpp

#include <iostream>
#include <vector>

template <class T>
class Ordenamiento {
public:
    static std::vector<T> burbuja(std::vector<T>, bool(*)(T,T));
    static std::vector<T> insercion(std::vector<T>, bool(*)(T,T));
    
    static bool asc(T,T);
    static bool desc(T,T);
    
};

template <class T>
bool Ordenamiento<T>::asc(T a, T b)
{
    return a < b;
}

template <class T>
bool Ordenamiento<T>::desc(T a, T b)
{
    return a > b;
}

template <class T>
std::vector<T> Ordenamiento<T>::burbuja(std::vector<T> e, bool compara (T,T))
{
    int n = (int) e.size();
    
    for (int i = 0; i < n; ++i) {
        for (int j = n-1; j > i; --j) {
            if ( compara(e[j], e[j-1]) ) {
                std::swap(e[j], e[j-1]);
            }
        }
    }
    
    return e;
}


template <class T>
std::vector<T> Ordenamiento<T>::insercion(std::vector<T> e, bool compara (T,T))
{
    /* Por hacer */
    
    return e;
}
#endif /* Ordenamiento_hpp */
