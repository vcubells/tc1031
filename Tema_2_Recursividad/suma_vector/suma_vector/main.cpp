//
//  main.cpp
//  suma_vector
//
//  Created by Vicente Cubells on 16/08/21.
//


#include <iostream>
#include <vector>

int suma_iterativa(std::vector<int> v)
{                                           //  OE          |  p
    int total = 0;                          //   1          |  1(1)
    for (int i = 0; i < v.size(); ++i) {    //  1 + 1+ 1    |  1(1) + 1(n+1) + 1(n)
        total += v[i];                      //  3           |  3(n)
    }
    return total;                           //  1           |   1(1)
}                                           //          T(n) = 1(1) + 1(1) + 1(n+1) + 1(n) + 3(n) + 1(1)
                                            //          T(n) = 1 + 1 + n + 1 + n + 3n + 1
                                            //          T(n) = 5n + 4
                                            //          O(n) = n

int suma(std::vector<int> v, int pos)
{
    /* Condición de parada */
    if (pos == v.size() - 1) {
        return v[pos];
    }
    /* Paso recursivo */
    else {
        return v[pos] + suma(v, pos+1);
    }
}

int suma_inversa(std::vector<int> v, int pos)
{
    /* Condición de parada */
    if (pos == 0) {
        return v[pos];
    }
    /* Paso recursivo */
    else {
        return v[pos] + suma_inversa(v, pos-1);
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
    std::vector<int> v(n,5);
    
    /* Imprimir el vector */
    for (int x : v) {
        std::cout << x << " ";
    }
        
    std::cout << std::endl;
    
    /* Calcular la suma */
    int resultado = suma(v,0);
    
    /* Mostrar el resultado */
    std::cout << "La suma recursiva de " << n << " elementos = " << resultado << std::endl;
    
    /* Calcular la suma recursiva a la inversa */
    resultado = suma_inversa(v,v.size()-1);
    
    /* Mostrar el resultado */
    std::cout << "La suma recursiva inversa de " << n << " elementos = " << resultado << std::endl;
    
    /* Calcular la suma iterativa */
    resultado = suma_iterativa(v);
    
    /* Mostrar el resultado */
    std::cout << "La suma iterativa de " << n << " elementos = " << resultado << std::endl;
    
    
    return 0;
}

