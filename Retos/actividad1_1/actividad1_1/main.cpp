//
//  main.cpp
//  actividad1_1
//
//  Created by Vicente Cubells on 26/02/24.
//

#include <iostream>

/*
  T(n) = 1*1 + 1*1 + 1*(n+1) + 1*n + 2*n + 1*1
       = 1 + 1 + n + 1 + n + 2n + 1
       = 4n + 4
       = O(n)
  S(n) = 1 + 1 + 1
       = 3
       = O(1)
 */
int sumaInterativa(int n)
{                                           // OE           veces
    int suma = 0;                           // 1            1
    // TODO
    for (int i = 1; i <= n; ++i) {          // 1 + 1 + 1    1 + (n + 1) + n
        suma += i;                          // 2            n
    }
    return suma;                            // 1            1
}

/*
  T(n) = 1*n + 1 + 3*(n-1)
       = n + 1 + 3n - 3
       = 4n - 2
       = O(n)
  S(n) = 1 * n
        = O(n)
 */
int sumaRecursiva(int n)
{
    // Condición de parada                 // OE            veces
    if ( n == 1) {                         //  1                n
        return 1;                          //  1                1
    }
    // Paso recursivo
    else {
        return n + sumaRecursiva(n-1);     // 3                 n-1
    }
}

/*
  T(n) = 1*1 + 4*1 + 1*1
       = 1 + 4 + 1
       = 6
       = O(1)
  S(n) = 2
       = O(1)
 */
int sumaDirecta(int n)
{                                          // OE            veces
    int suma = 0;                          // 1                 1
    // TODO
    suma = n * (n + 1) / 2;                // 4                 1
    
    return suma;                           // 1                 1
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
