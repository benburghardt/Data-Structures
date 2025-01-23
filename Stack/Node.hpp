/*
 * Author: Ben Burghardt
 * 
 * Simple doubly linked list node that stores a list of templated values
 *
 * Current implementaion only allows construction with a previous node
 * 
 */

#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>

template <typename T>
struct Node {   
    
    Node<T>* pPrev;
    Node<T>* pNext;
    T* value;
    size_t capacity;

    // Constructors
    Node();
    Node(Node<T>* prevLink, const size_t arrSize);
    Node(const size_t arrSize);
    Node(const Node<T> &other); 
    
    // Destructor
    ~Node();
};

template <typename T>
Node<T>::Node(){ 
    // Make empty Node
    pPrev = nullptr;
    pNext = nullptr;
    value = nullptr;
    capacity = 0;
}

template <typename T>
Node<T>::Node(Node<T>* prevLink, const size_t arrSize){
    // Link in new node with empty list 
    pPrev = prevLink;
    prevLink->pNext = this; 

    pNext = nullptr;

    value = new T[arrSize];
    capacity = arrSize;
}

template <typename T>
Node<T>::Node(const size_t arrSize){
    // Make empty Node with empty list
    pPrev = nullptr;
    pNext = nullptr;

    value = new T[arrSize];
    capacity = arrSize;
}

template <typename T>
Node<T>::Node(const Node<T> &other){
    // Deep copy values and copy next/prev pointers
    pPrev = other.pPrev;
    pNext = other.pNext;

    capacity = other.capacity;
    value = new T[capacity];
    for(int i = 0; i < capacity; i++){
        value[i] = other.value[i];
    }
}

template <typename T>
Node<T>::~Node(){
    delete value;
}

#endif