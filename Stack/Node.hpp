#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
struct Node {   
    Node<T>* pPrev;
    T* value;
    Node<T>* pNext; 

    Node(){
        pPrev = nullptr;
        value = nullptr;
        pNext = nullptr;
    }
    Node(Node<T>* prevLink, int arrSize){
        pPrev = prevLink;
        prevLink->pNext = this;
        value = new T[arrSize];
        pNext = nullptr;
    }
    Node(nullptr_t, int arrSize){
        pPrev = nullptr;
        value = new T[arrSize];
        pNext = nullptr;
    }
    ~Node(){
        delete value;
    }
    };
    
#endif