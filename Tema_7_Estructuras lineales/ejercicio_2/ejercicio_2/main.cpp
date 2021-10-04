//
//  main.cpp
//  ejercicio_2
//
//  Created by Vicente Cubells on 04/10/21.
//

#include <iostream>
#include "../../Queue/Queue/Queue.cpp"

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
    
    /* Obtener el elemento a eliminar de la cola */
    std::cout << "¿Qué elemento quieres eliminar?: ";
    int elemento = 0;
    std::cin >> elemento;
    
    /* Declarar una cola auxiliar */
    Queue<int> * queue_aux = new Queue<int>();
    std::cout << "(C) Se crea una cola auxiliar vacía" << std::endl;
    
    /* Buscar y eliminar el elemento */
    Node<int> * temp;
    while ( !queue->empty() )
    {
        temp = queue->dequeue();
        if (temp->getInfo() != elemento) {
            queue_aux->enqueue(temp);
        }
        else {
            delete temp;
        }
    }
    
    /* Eliminar la memoria ocupada */
    delete queue;
    
    /* Visualizar el contenido de la cola */
    std::cout << "(L) La cola auxiliar tiene los siguientes elementos:" << std::endl;
    std::cout << *queue_aux << std::endl;
    
    /* Otras funcionalidades */
    /*
     ....
     */
    
    /* Eliminar la memoria ocupada */
    delete queue_aux;
    
    return 0;
}
