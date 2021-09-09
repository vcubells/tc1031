//
//  main.cpp
//  actividad-1-2
//
//  Created by Vicente Cubells on 09/09/21.
//

#include <iostream>
#include <vector>
#include "Moto.hpp"
#include "Camioneta.hpp"

int main(int argc, const char * argv[]) {
    
    std::vector<Auto *> autos;
    
    auto a1 = new Auto(); // Auto * a1 = new Auto;
    auto m1 = new Moto();
    auto c1 = new Camioneta();
    auto a2 = new Auto();
    
    autos.push_back(a1);
    autos.push_back(m1);
    autos.push_back(c1);
    autos.push_back(a2);
    
    for (auto a : autos) {
        //a->print();
        std::cout << *a << std::endl;
        delete a;
    }
    
    
    
    return 0;
}
