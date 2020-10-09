//
//  main.cpp
//  ejercicio_1_stl
//
//  Created by Vicente Cubells on 09/10/20.
//

#include <iostream>
#include <queue>
#include <stack>

int main(int argc, const char * argv[]) {
    
    /* Crear una cola vacía */
    std::queue<int> queue;
    std::cout << "(C) Se crea una cola  vacía" << std::endl;
    
    /* Insertar elementos en la cola */
    for (int i = 1; i < 11; ++i) {
        queue.push(i);
    }
    
    /* Visualizar el contenido de la cola */
    std::cout << "(L) La cola tiene los siguientes elementos:" << std::endl;
    std::copy(&queue.front(), &queue.back()+1, std::ostream_iterator<int>(std::cout));
    std::cout << std::endl;
    
    /*
     * Invertir el contenido de la cola
     */
    
    /* Crear una estructura auxiliar pila */
    std::stack<int> stack;
    
    /* Pasar los elementos de la cola a la pila */
    while ( !queue.empty() )
    {
        stack.push( queue.front() );
        queue.pop();
    }
    
    /* Pasar los elementos de la pila a la cola */
    while ( !stack.empty() )
    {
        queue.push( stack.top() );
        stack.pop();
    }
    
    
    /* Visualizar el contenido de la cola invertida */
    std::cout << "(L) La cola invertida tiene los siguientes elementos:" << std::endl;
    std::copy(&queue.front(), &queue.back()+1, std::ostream_iterator<int>(std::cout));
    std::cout << std::endl;
    
    return 0;
}

