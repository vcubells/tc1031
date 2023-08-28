//
//  main.cpp
//  busqueda_basica
//
//  Created by Vicente Cubells on 24/08/23.
//

#include <iostream>

int busquedaSecuencial(int vector[], int N, int valor)
{
    int i = 0;
    int encontrado = -1;
    while (encontrado == -1 && i < N)
    {
    if ( valor == vector[i] ) {
        encontrado = i;
    }
        i++;
    }
    return encontrado;
}

int busquedaBinaria(int vector[], int N, int valor)
{
    if (N == 0) { return 0; }
    int mitad, inf = 0, sup = N - 1;
    do {
        mitad = (inf + sup) / 2;
        if (valor > vector[mitad]) {
            inf = mitad + 1;
        }
        else {
            sup = mitad - 1;
        }
    }
    while (vector[mitad] != valor && inf <= sup);

    if (vector[mitad] == valor) { return mitad; }
    else { return -1; }
}

int main(int argc, const char * argv[]) {
    
    if (argc < 3) {
        std::cout << "Use: a.out número_buscar algoritmo" << std::endl;
        exit(0);
    }
    
    int numero = atoi(argv[1]);
    char algoritmo = *(argv[2]);
    int encontrado = 0;
    
    srand((unsigned int) time(NULL));
    
    const int N = 1000000;
    
    int vector[N];
    
    /* Inicializar el vector con números aleatorios */
    for (int i = 0; i < N; ++i) {
        vector[i] = i; // rand() % 10000;
    }
    
    switch (algoritmo) {
        case 'S':
            encontrado = busquedaSecuencial(vector, N, numero);
            break;
        case 'B':
            encontrado = busquedaBinaria(vector, N, numero);
            break;
        default:
            std::cout << "Use: a.out número_buscar algoritmo" << std::endl;
            break;
    }
    
    if (encontrado > 0)
    {
        std::cout << "El número " << numero << " se  encuentra en la posición " << encontrado << std::endl;
    }
    else {
        std::cout << "El número " << numero << " no se  encuentra" << std::endl;
    }
    
    return 0;
}
