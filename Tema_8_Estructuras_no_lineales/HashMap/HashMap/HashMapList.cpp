//
//  HashMapList.cpp
//  HashMapList
//
//  Created by Vicente Cubells on 22/11/21.
//

#include "HashMapList.hpp"

#include <vector>
#include <set>
#include <iostream>

template <class K, class V>
class HashMapList {
    int _capacity = 0;
    
    std::vector<K> _keys;
    std::vector<V>  _values;
    std::vector<bool> _status;
    std::vector<std::set<std::pair<K,V> > > _others;
    
    int _size = 0;
    
    int hash_function(K) const;
    
public:
    HashMapList(int);
    ~HashMapList();
    
    bool empty() const;
    int size() const;
    int capacity() const;
    
    int put(K,V);
    V get(K);
    
    // TODO Actividad 5.1 Implementar la función remove
    bool remove (K);
    
    template <typename Kn, typename Vn>
    friend std::ostream & operator <<(std::ostream & os, const HashMapList<Kn,Vn> & hm);
};

template <class K, class V>
HashMapList<K,V>::HashMapList(int capacity)
{
    this->_capacity = capacity;
    this->_status = std::vector<bool>(capacity);
    this->_keys = std::vector<K>(capacity);
    this->_values = std::vector<V>(capacity);
    this->_others = std::vector<std::set<std::pair<K,V> > >(capacity);
    
    fill(_status.begin(), _status.end(), false);
}

template <class K, class V>
HashMapList<K,V>::~HashMapList()
{
    /*
    delete this->_status;
    delete this->_values;
    delete this->_keys;
     */
}

template <class K, class V>
bool HashMapList<K,V>::empty() const
{
    return this->_size == 0;
}

template <class K, class V>
int HashMapList<K,V>::size() const
{
    return this->_size;
}

template <class K, class V>
int HashMapList<K,V>::capacity() const
{
    return this->_capacity;
}

template <class K, class V>
int HashMapList<K,V>::hash_function(K key) const
{
    // TODO Actividad 5.1 Cambiar la función hash
    return key % this->_capacity;
}

template <class K, class V>
int HashMapList<K,V>::put(K key,V value)
{
    int indice = hash_function(key);

    if (this->_status[indice] && this->_keys[indice] != key ) {
        this->_others[indice].insert(std::make_pair(key, value));
    }
    else {
        this->_keys[indice] = key;
        this->_values[indice] = value;
        this->_status[indice] = true;
    }
    
    this->_size++;
        
    return indice;
}

template <class K, class V>
V HashMapList<K,V>::get(K key)
{
    int indice = hash_function(key);
    
    if (this->_status[indice]) {
        if (this->_keys[indice] == key) {
            return this->_values[indice];
        }
        else {
            for (auto p : this->_others[indice])
            {
                if (p.first == key) {
                    return p.second;
                }
            }
        }
    }
    
    return -1;
}

template <class K, class V>
bool HashMapList<K,V>::remove(K key)
{
    // TODO Actividad 5.1 Implementar la función remove
    return false;
}

template <class K, class V>
std::ostream & operator <<(std::ostream & os, const HashMapList<K,V> & hm)
{
    for (int i = 0; i < hm._capacity; ++i) {
        os << "--- Indice "<< i << " ---" << std::endl;
        if (hm._status[i]) {
            os << hm._keys[i] << " : " << hm._values[i] << std::endl;
            for (auto p : hm._others[i]) {
                os << p.first << " : " << p.second << std::endl;
            }
            
        }
    }
    
    return os;
}

