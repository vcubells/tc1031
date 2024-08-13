//
//  main.cpp
//  suma_vector
//
//  Created by Vicente Cubells on 16/08/21.
//


#include <iostream>
#include <vector>

int suma_iterativa(std::vector<int> v)
{
    int total = 0;
    for (int i = 0; i < v.size(); ++i) {
    // for (int i = N-1; i >=0 N; —i) {
        total += v[i];
    }
    return total;
}

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

