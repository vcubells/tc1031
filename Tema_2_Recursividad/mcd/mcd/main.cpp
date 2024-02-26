//
//  main.cpp
//  mcd
//
//  Created by Vicente Cubells on 16/08/21.
//


#include <iostream>

int mcd(int m, int n)
{
    /* Condición de parada */
    int r = m % n;
    if (r == 0) {
        return n;
    }
    /* Paso recursivo */
    else {
        return mcd(n,r);
    }
}

int main(int argc, const char * argv[]) {
    int n = -1;
    int m = -1;
    
    /* Entrar el número m */
    do {
        std::cout << "Entre el número m: ";
        std::cin >> m;
    }
    while (m <= 0);
    
    /* Entrar el número n */
    do {
        std::cout << "Entre el número n: ";
        std::cin >> n;
    }
    while (n < 0);
    
    /* Calcular el mcd(m,n) */
    int resultado = mcd(m, n);
    
    /* Mostrar el resultado */
    std::cout << "mcd(" << m << "," << n << ") = " << resultado << std::endl;
    
    return 0;
}
