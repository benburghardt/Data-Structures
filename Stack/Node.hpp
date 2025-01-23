/*
 * Simple doubly linked list node that stores a list of templated values
 *
 * Current implementaion only allows construction with a previous node
 * 
 */

#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
struct Node {   
    
    Node<T>* pPrev;
    Node<T>* pNext;
    T* value;
    size_t capacity;

    // Constructors
    Node();
    Node(Node<T>* prevLink, size_t arrSize);
    Node(size_t arrSize);
    
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
Node<T>::Node(Node<T>* prevLink, size_t arrSize){
    // Link in new node with empty list 
    pPrev = prevLink;
    prevLink->pNext = this; 

    pNext = nullptr;

    value = new T[arrSize];
    capacity = arrSize;
}

template <typename T>
Node<T>::Node(size_t arrSize){
    // Make empty Node with empty list
    pPrev = nullptr;
    pNext = nullptr;

    value = new T[arrSize];
    capacity = arrSize;
}

template <typename T>
Node<T>::~Node(){
    delete value;
}

#endif