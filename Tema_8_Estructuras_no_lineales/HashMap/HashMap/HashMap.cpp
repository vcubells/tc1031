//
//  HashMap.cpp
//  HashMap
//
//  Created by Vicente Cubells on 20/11/20.
//

#include "HashMap.hpp"
#include <vector>

template <class K, class V>
class HashMap {
    int _capacity = 0;
    
    std::vector<K> _keys;
    std::vector<V>  _values;
    std::vector<std::string> _status;
    
    int _size = 0;
    
    int hash_function(K) const;
    
public:
    HashMap(int);
    ~HashMap();
    
    bool empty() const;
    int size() const;
    
    bool put(K,V);
    int rehash(int, int);
    V get(K);
};

template <class K, class V>
HashMap<K,V>::HashMap(int capacity)
{
    this->_capacity = capacity;
    this->_status = std::vector<std::string>(capacity);
    this->_keys = std::vector<K>(capacity);
    this->_values = std::vector<V>(capacity);
    
    fill(_status.begin(), _status.end(), "vacio");
}

template <class K, class V>
HashMap<K,V>::~HashMap()
{
    /*
    delete this->_status;
    delete this->_values;
    delete this->_keys;
     */
}

template <class K, class V>
bool HashMap<K,V>::empty() const
{
    return this->_size == 0;
}

template <class K, class V>
int HashMap<K,V>::size() const
{
    return this->_size;
}

template <class K, class V>
int HashMap<K,V>::hash_function(K key) const
{
    return key % this->_capacity;
}

template <class K, class V>
bool HashMap<K,V>::put(K key,V value)
{
    int indice = hash_function(key);

    if (this->_status[indice] == "ocupado") {
        indice = rehash(indice, 0); //Recalcular
    }
    
    if (indice > -1) {
        this->_keys[indice] = key;
        this->_values[indice] = value;
        this->_status[indice] = "ocupado";
        
        return true;
    }
    
    return false;
}

template <class K, class V>
int HashMap<K,V>::rehash(int indice, int steps)
{
    if (indice < this->_capacity && steps < this->_capacity) {
        
        ++indice;
        
        if (indice == this->_capacity) indice = 0;
        
        if (this->_status[indice] == "ocupado")
        {
            indice = rehash(indice, ++steps);
        }
        
        return indice;
    }
    else {
        return -1;
    }
}

template <class K, class V>
V HashMap<K,V>::get(K key)
{
    bool found = false;
    int steps = 0;
    
    int indice = hash_function(key);
    
    while (!found && steps < this->_capacity) {
        if (this->_status[indice] == "ocupado") {
            if (this->_keys[indice] == key) {
                found = true;
            }
            else {
                found = false;
                ++indice;
                if (indice == this->_capacity) indice = 0;
            }
        }
        else {
            ++indice;
            if (indice == this->_capacity) indice = 0;
        }
        
        ++steps;
    }
   
    if (found) return this->_values[indice];
    else
        return -1;
}


