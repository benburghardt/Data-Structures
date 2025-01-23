/*
 * Author: Ben Burghardt 
 *
 * Simple templated Stack implementation that uses a dynamic array to store elements
 * 
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
     * @brief Get next element in the stack
     */
    T top();

    /**
     * @brief Add one element to the top of the stack
     * 
     * @param element 
     */
    void push(const T &element);

    /**
     * @brief 
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
    _data[_size] = entry;
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
NaiveStack<T>::~NaiveStack(){ delete[] _data; }

template <typename T>
NaiveStack<T> NaiveStack<T>::operator=(const NaiveStack<T> &other){
    if(&other == this) return *this;

    delete[] this->_data;

    deepCopy(this, other);

    return *this;
}

template <typename T>
void NaiveStack<T>::_deepCopy(NaiveStack<T> *reciever, const NaiveStack<T> &giver){
    reciever->_size = giver._size;
    reciever->_data = new T[_size];

    for(size_t i = 0; i < _size; i++){
        reciever->_data[i] = giver._data[i];
    }
}

#endif