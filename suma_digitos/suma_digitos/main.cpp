//
//  main.cpp
//  suma_digitos
//
//  Created by Vicente Cubells on 19/08/21.
//

#include <iostream>

int suma_digitos(int);

int main(int argc, const char * argv[]) {
    
    int numero;
    
    /* Pedir al usurio que entre un número entero */
    std::cout << "Entre el número entero: ";
    std::cin >> numero;
    
    /* Sumar los dígitos del número e imprimir el resultado */
    std::cout << "La suma de los dígitos es =  " << suma_digitos(numero) << std::endl;
    
    return 0;
}

/*
                                                                suma_digitos(123) -> 6
 Paso 1.  n = 123  resto = 123 % 10 = 3   n = 123 / 10 = 12     3 + suma_digitos(12)=3 -> 6
 Paso 2.  n = 12   resto = 12 % 10 = 2    n = 12 / 10 = 1       2 + suma_digitos(1)=1 -> 3
 Paso 3.  n = 1    resto = 1 % 10 = 1     n = 1 / 10 = 0        1
                                                                2 + 1 = 3
                                                                3 + 3 = 6
 
 suma_digitos(123)  = resto (3) + suma_digitos(12)
                    = resto (3) + ( resto (2) + suma_digitos(1) )
                    = resto (3) + ( resto (2) + 1 )
 ------------------------------------------------------------------
                    = resto (3) + ( 3 )
                    = 6
 
 */

int suma_digitos(int n)
{
    int resto = n % 10;
    n = n / 10;
    
    /* Condición base o de parada */
    if (n == 0) {
        return resto;
    }
    /* Invocación recursiva */
    else {
        return resto + suma_digitos(n);
    }
}
