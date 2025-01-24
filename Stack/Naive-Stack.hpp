/*
 * Author: Ben Burghardt 
 *
 * Simple templated Stack implementation that uses a dynamic array to store elements.
 * 
 * Allows user to access to the next element, add a new element, or remove the next element of the stack.
 * 
 * Naive implementation will reallocate memory each time push is called, adding space for 1 more element.
 * This implementation makes the cost of pushing elements to the stack O(N) as the entire stack is copied
 * to the new memory each push.
 * 
 * This implementation has a smarter pop method. Instead of reallocating memory to match the new stack
 * the size counter is decremented by 1. This implementation allows the top method to return the correct
 * value after popping without reallocating memory.
 * 
 *     |  Time Complexity   |  Memory Complexity
 * ----+--------------------+---------------------
 * Push|       O(N)         |        O(N)            
 * ----+--------------------+---------------------
 * Pop |       O(1)         |        O(1)
 * ----+--------------------+---------------------
 * Top |       O(1)         |        O(1)            
 * 
 */

#ifndef NAIVE_STACK_HPP
#define NAIVE_STACK_HPP

#include <cstddef> // for size_t

template <typename T>
class NaiveStack {
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
    NaiveStack();
    NaiveStack(const NaiveStack<T> &other);
    ~NaiveStack();

    // Assignment operator
    NaiveStack<T> operator=(const NaiveStack<T> &other);

  private:
    T *_data;
    size_t _size;

    void _deepCopy(NaiveStack<T> *reciever, const NaiveStack<T> &giver);
};


template <typename T>
T NaiveStack<T>::top(){
    if(_size == 0) return NULL;
    return _data[_size - 1];
}

template <typename T>
void NaiveStack<T>::push(const T &element){
    // Add enough memory for 1 element
    T *temp = new T[_size + 1];

    // Deep copy elements
    for (size_t i = 0; i < _size; i++){
        temp[i] = _data[i];
    }
    delete[] _data;
    _data = temp;

    // Insert new element
    _data[_size] = element;
    _size++;
}

template <typename T>
void NaiveStack<T>::pop(){
    if(_size == 0) return;
    _size--;
}

template <typename T>
size_t NaiveStack<T>::size() 
{ return _size; }

template <typename T>
bool NaiveStack<T>::is_empty() 
{ return (_size == 0) ? true : false; }

 
template <typename T>
NaiveStack<T>::NaiveStack() 
{ _size = 0; _data = nullptr;}

template <typename T>
NaiveStack<T>::NaiveStack(const NaiveStack<T> &other) 
{ deepCopy(this, other); }

template <typename T>
NaiveStack<T>::~NaiveStack()
{ delete[] _data; }

template <typename T>
NaiveStack<T> NaiveStack<T>::operator=(const NaiveStack<T> &other){
    // Self assignment protection
    if(&other == this) return *this;

    // Clear old data
    delete[] this->_data;

    _deepCopy(this, other);

    return *this;
}

template <typename T>
void NaiveStack<T>::_deepCopy(NaiveStack<T> *reciever, const NaiveStack<T> &giver){
    // Allocate memory
    reciever->_size = giver._size;
    reciever->_data = new T[_size];

    // Copy all elements
    for(size_t i = 0; i < _size; i++){
        reciever->_data[i] = giver._data[i];
    }
}

#endif