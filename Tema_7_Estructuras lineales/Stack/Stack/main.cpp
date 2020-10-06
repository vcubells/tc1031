//
//  main.cpp
//  Stack
//
//  Created by Vicente Cubells on 06/10/20.
//

#include <iostream>
#include "Stack.hpp"

int main(int argc, const char * argv[]) {
    
    /* Crear una pila vacía */
    Stack<int> * stack = new Stack<int>();
    std::cout << "(C) Se crea una pila  vacía" << std::endl;
    
    /* Determinar si la pila está vacía */
    std::cout << (stack->empty() ? "(E) La pila está vacía" : "(E) La pila tiene elementos") << std::endl;
    
    /* Insertar elementos en la pila */
    for (int i = 1; i < 6; ++i) {
        stack->push(i);
    }
    
    /* Visualizar el contenido de la pila */
    std::cout << "(L) La pila tiene los siguientes elementos:" << std::endl;
    std::cout << *stack << std::endl;
    
    /* Obtener tamaño de la pila */
    std::cout << "(S) Tamaño de la pila: " << stack->size() << " elementos" << std::endl;
    
    /* Obtener el elemento superior de la pila */
    std::cout << "(T) El elemento superior de la pila es:" << *stack->top() << std::endl;
    
    /* Eliminar un elemento de la pila */
    Node<int> * node  = stack->pop();
    std::cout << "(R) El nodo eliminado de la pila es:" << *node << std::endl;
    
    std::cout << "(D) Liberando la memoria ocupada por el nodo eliminado" << std::endl;
    delete node;
    
    /* Visualizar el contenido de la pila */
    std::cout << "(L) La pila tiene los siguientes elementos:" << std::endl;
    std::cout << *stack << std::endl;
    
    /* Vaciar la pila */
    stack->clear();
    std::cout << "(V) Se vació la pila"<< std::endl;
    
    /* Determinar si la pila está vacía */
    std::cout << (stack->empty() ? "(E) La pila está vacía" : "(E) La pila tiene elementos") << std::endl;
    
    /* Liberando la memoria de la pila */
    delete stack;
    std::cout << "(D) Se liberó la memoria de la pila" << std::endl;
    
    return 0;
}
