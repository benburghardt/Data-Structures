/*
 * Author: Ben Burghardt
 * 
 * Improved implementation of stack that uses a linked list of growing containers.
 * 
 * Allows user to access to the next element, add a new element, or remove the next element of the stack.
 * 
 * This improved implementation of a stack stores pointer to a linked list node that contains a dynamic 
 * array. Each node will be initialized with a specific size and when its capacity is reached the stack
 * will append a new node to the linked list with dobuble the capacity of the last node.
 * 
 * Using a linked list allows the stack to never reallocate memory and copy its elements to the new list.
 * This makes both the memory complexity and time complexity operate in constant time.
 * 
 * By doubling the capacity of each consecutive node, new memory does not need to be allocated or deallocated
 * each time push and pop are called. This optimization reduces the average number of operations performed 
 * per push and pop. However if a large enough stack size is reached there may not be large enough memory 
 * sectors to create the next node. Additionally, if relatively few items are allocated in the last node then
 * up to 50% of the memory allocated to the stack would be unused.
 * 
 * The size of the allocated memory in the nodes can be altered to avoid the aforementioned drawbacks.
 * 
 * 
 *     |  Time Complexity   |  Memory Complexity
 * ----+--------------------+---------------------
 * Push|       O(1)         |        O(1)            
 * ----+--------------------+---------------------
 * Pop |       O(1)         |        O(1)
 * ----+--------------------+---------------------
 * Top |       O(1)         |        O(1)          
 * 
 */

#ifndef IMPROVED_STACK_HPP
#define IMPROVED_STACK_HPP

#include "Node.hpp"

template <typename T>
class ImprovedStack {
  public:
    // Simple operations
    /**
     * @brief Returns the next element in the stack
     */
    T top();

    /**
     * @brief Add one element to the top of the stack
     * 
     * @param element 
     */
    void push(const T &element);

    /**
     * @brief Remove the next element in the stack
     */
    void pop();

    // Stack information
    size_t size();
    bool is_empty();

    // Constructors/Destructor
    ImprovedStack();
    ImprovedStack(const ImprovedStack<T> &other);
    ~ImprovedStack();

    // Assignment operator
    ImprovedStack<T> operator=(const ImprovedStack<T> &other);

  private:
    Node<T> *_data;
    size_t _size;

    void _deepCopy(ImprovedStack<T> *reciever, const ImprovedStack<T> &giver);
};

template <typename T>
T ImprovedStack<T>::top(){
    if(_size == 0) return NULL;
    return _data->value[_size - 1];
}

template <typename T>
void ImprovedStack<T>::push(const T &element){
    // If current container maxes out create a new container with double the capacity
    if(_size == _data->capacity){
        Node<T>* temp = new Node<T>(_data,_data->capacity*2);
        _data = _data->pNext;
        _size = 0;
    }

    // Insert value
    _data->value[_size] = element;
    _size++;
}

template <typename T>
void ImprovedStack<T>::pop(){
    // No elements in stack
    if(_size == 0) return;

    _size--;
    
    // If last element in container is popped try to go to the previous container
    if(_size == 0 && _data->pPrev != nullptr) {
        _data = _data->pPrev;
        delete _data->pNext;
        _size = _data->capacity; 
    }
}

template <typename T>
size_t ImprovedStack<T>::size()  // current container size + filled containers
{ return _size + _data->capacity - 1; }

template <typename T>
bool ImprovedStack<T>::is_empty() 
{ return (_size == 0) ? true : false; }

template <typename T>
ImprovedStack<T>::ImprovedStack() 
{ _size = 0; _data = new Node<T>(1);}

template <typename T>
ImprovedStack<T>::ImprovedStack(const ImprovedStack<T> &other)
{ _deepCopy(this, other); }

template <typename T>
ImprovedStack<T>::~ImprovedStack(){ 
    // Delete each container
    while(_data->pPrev != nullptr){
        _data = _data->pPrev;
        delete _data->pNext;
    } 
    delete _data;
}

template <typename T>
ImprovedStack<T> ImprovedStack<T>::operator=(const ImprovedStack<T> &other){
    // Self assignment protection
    if(&other == this) return *this;

    // Delete each container
    while(_data->pPrev != nullptr){
        _data = _data->pPrev;
        delete _data->pNext;
    } 
    delete _data;

    _deepCopy(this, other);

    return *this;
}

template <typename T>
void ImprovedStack<T>::_deepCopy(ImprovedStack<T> *reciever, const ImprovedStack<T> &giver){
    reciever->_data = new Node<T>(1);

    // Get pointer to the bottom of the giver stack
    Node<T>* tempGiverData = giver->_data;
    while(tempGiverData->pPrev != nullptr){
        tempGiverData = tempGiverData->pPrev;
    }

    // Push all elements of giver stack into reciever stack
    // Start with all filled containers
    while(tempGiverData->pNext != nullptr){
        for(int i = 0; i < tempGiverData->capacity; i++){
            reciever->push(tempGiverData->value[i]);
        }
        tempGiverData = tempGiverData->pNext;
    }

    // Copy elements from top container
    for(int i = 0; i < giver._size; i++){
        reciever->push(tempGiverData->value[i]);
    }
}

#endif