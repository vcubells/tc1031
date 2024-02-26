//
//  main.cpp
//  actividad1_1
//
//  Created by Vicente Cubells on 26/02/24.
//

#include <iostream>

/*
  T(n) =
  S(n) =
 */
int sumaInterativa(int n)
{
    int suma = 0;
    // TODO
    return suma;
}

/*
  T(n) =
  S(n) =
 */
int sumaRecursiva(int n)
{
    int suma = 0;
    // TODO
    return suma;
}

/*
  T(n) =
  S(n) =
 */
int sumaDirecta(int n)
{
    int suma = 0;
    // TODO
    return suma;
}

int main(int argc, const char * argv[]) {
    
    int casos[4] = {5, 100, 500, 1000};
    
    for (int i = 0; i < 4; ++i)
    {
        std::cout << " Caso " << i+1 << ", n = " << casos[i] << std::endl;
        
        std::cout << " sumaIterativa = " << sumaInterativa(casos[i]) << std::endl;
        std::cout << " sumaRecursiva = " << sumaRecursiva(casos[i]) << std::endl;
        std::cout << " sumaDirecta = " << sumaDirecta(casos[i]) << std::endl;
    }
    
    return 0;
}
