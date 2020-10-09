//
//  main.cpp
//  ejercicio_1
//
//  Created by Vicente Cubells on 09/10/20.
//

#include <iostream>
#include "../../Queue/Queue/Queue.cpp"
#include "../../Stack/Stack/Stack.cpp"

int main(int argc, const char * argv[]) {
    
    /* Crear una cola vacía */
    Queue<int> * queue = new Queue<int>();
    std::cout << "(C) Se crea una cola  vacía" << std::endl;
    
    /* Insertar elementos en la cola */
    for (int i = 1; i < 11; ++i) {
        queue->enqueue(i);
    }
    
    /* Visualizar el contenido de la cola */
    std::cout << "(L) La cola tiene los siguientes elementos:" << std::endl;
    std::cout << *queue << std::endl;
    
    /*
     * Invertir el contenido de la cola utilizando
     * una estructura auxilia pila
     */
    
    /* Crear una estructura auxiliar pila */
    Stack<int> * stack = new Stack<int>();
    
    /* Pasar los elementos de la cola a la pila */
    while ( !queue->empty() )
    {
        stack->push( queue->dequeue() );
    }
    
    /* Pasar los elementos de la pila a la cola */
    while ( !stack->empty() )
    {
        queue->enqueue( stack->pop() );
    }
    
    /* Liberar la memoria de la pila */
    delete stack;
    
    /* Visualizar el contenido de la cola invertida */
    std::cout << "(L) La cola invertida tiene los siguientes elementos:" << std::endl;
    std::cout << *queue << std::endl;
    
    /*
     * Invertir el contenido de la cola utilizando
     * el método reverse()
     */
    
    queue->reverse();
    
    /* Visualizar el contenido de la cola invertida */
    std::cout << "(L) La cola invertida tiene los siguientes elementos:" << std::endl;
    std::cout << *queue << std::endl;
    
    /* Liberar la memoria ocupada */
    delete queue;
    std::cout << "(D) Se liberó la memoria de la cola" << std::endl;
    
    return 0;
}
