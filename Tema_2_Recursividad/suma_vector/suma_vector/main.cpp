//
//  main.cpp
//  suma_vector
//
//  Created by Vicente Cubells on 16/08/21.
//


#include <iostream>
#include <vector>

int suma(std::vector<int> v, int pos, int n)
{
    /* Condición de parada */
    if (pos == n-1) {
        return v[pos];
    }
    /* Paso recursivo */
    else {
        return v[pos] + suma(v, pos+1, n);
    }
}

int main(int argc, const char * argv[]) {
    
    int n = 0;
    
    /* Entrar el número de elementos */
    do {
        std::cout << "Entre el número de elementos: ";
        std::cin >> n;
    }
    while (n < 1);
    
    /* Inicializar el vector */
    std::vector<int> v(n,1);
    
    /* Imprimir el vector */
    for (int x : v)
            std::cout << x << " ";
    
    std::cout << std::endl;
    
    /* Calcular la suma */
    int resultado = suma(v,0,n);
    
    /* Mostrar el resultado */
    std::cout << "La suma de " << n << " elementos = " << resultado << std::endl;
    
    return 0;
}

