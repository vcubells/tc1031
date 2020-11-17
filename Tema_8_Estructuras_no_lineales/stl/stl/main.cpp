//
//  main.cpp
//  stl
//
//  Created by Vicente Cubells on 17/11/20.
//

#include <iostream>
#include <utility>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>

int main(int argc, const char * argv[]) {
    
    /* Par */
    std::pair<int, std::string> par = std::make_pair(1, "Pepe");
    
    std::cout << "--- Par <int, string> ----" << std::endl;
    std::cout << par.first << " : " << par.second << std::endl;
    
    /* List */
    std::list<int> lista;
    lista.push_back(4);
    lista.push_back(5);
    lista.push_back(4);
    lista.push_back(1);
    
    std::cout << "--- List <int> ----" << std::endl;
    std::list<int>::const_iterator
        lit (lista.begin()),
        lend(lista.end());
    
    for(;lit!=lend;++lit) {
        std::cout << *lit << " ";
    }
    
    std::cout << std::endl;

    /* Par de lista */
    std::pair<int, std::list<int> > par_lista = std::make_pair(1, lista);
    
    std::cout << "--- Par <int, list<int> > ----" << std::endl;

    std::cout << par_lista.first << " : ";
    
    std::list<int> second_list = par_lista.second;
    lit = second_list.begin();
    lend = second_list.end();
    
    for(;lit!=lend;++lit) {
        std::cout << *lit << " ";
    }
    
    std::cout << std::endl;
    
    /* Lista de pares */
    std::list< std::pair<int, std::string> > lista_par;
    lista_par.push_back(par);
    
    std::cout << "--- List < Par <int, string > ----" << std::endl;
    std::list<std::pair<int, std::string> > ::const_iterator
        lpit (lista_par.begin()),
        lpend(lista_par.end());
    
    for(;lpit!=lpend;++lpit) {
        std::cout << lpit->first << " : " << lpit->second << " ";
    }
    
    std::cout << std::endl;
    
    
    /* Stack de pares de lista */
    std::stack< std::pair<int, std::list<int> > > pila;
    pila.push(par_lista);
    
    /* Queue de pares */
    std::queue< std::pair<int, std::string> > cola;
    cola.push(par);
    
    /* Queue de listas de int */
    std::queue< std::list<int> > cola_listas;
    cola_listas.push(lista);
    
    /* Map de pares */
    std::map<int, std::string, std::greater<int>> mapa;
    mapa.insert(std::make_pair(1, "1"));
    mapa.insert(std::make_pair(6, "6"));
    mapa.insert(std::make_pair(8, "8"));
    mapa.insert(std::make_pair(2, "2"));
    
    std::cout << "--- Map < int, string > ----" << std::endl;
    std::map<int, std::string> ::const_iterator
        mit (mapa.begin()),
        mend(mapa.end());
    
    for(;mit!=mend;++mit) {
        std::cout << mit->first << ":" << mit->second << " ";
    }
    
    std::cout << std::endl;
    
    std::cout << "--- Set <int> ----" << std::endl;
    
    std::set<int> s;          // equivale a set<int, less<int> >
    s.insert(2);
    s.insert(5);
    s.insert(2);     // el repetido no es insertado
    s.insert(1);
    std::set<int>::const_iterator
        sit (s.begin()),
        send(s.end());
    
    for(;sit!=send; ++sit)
        std::cout << *sit << " ";

    std::cout << std::endl;
    
    return 0;
}
