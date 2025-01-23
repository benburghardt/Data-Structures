/*
 * stack-stage3.h
 *
 * Implements a simple stack class using dynamic arrays.
 * This may be implemented in 3 stages:
 *   Stage 1: non-template stack class storing strings,
 *            unsafe copies/assignments
 *   Stage 2: template stack class, unsafe copies/assignments
 *   Stage 3: template stack class, safe copies/assignments
 *
 * Note: no underflow detection is performed.  Performing pop() or top()
 * on an empty stack results in undefined behavior (possibly crashing your
 * program)!
 *
 * Author: Your Name
 */

#ifndef NAIVE_STACK_HPP
#define NAIVE_STACK_HPP

#include <cstddef> // for size_t

// using namespace std;

template <typename t>
class NaiveStack {
  public:
    t top(){
        if(_size == 0) return NULL;

        return _data[_size - 1];
    }

    // inline definitions, doing nothing at the moment
    void push(const t &entry){
      

            t *temp = new t[_size + 1];

            for (size_t i = 0; i < _size; i++){
                temp[i] = _data[i];
            }
            delete[] _data;
            _data = temp;
            
            
            
    
        _data[_size] = entry;
        _size++;
    }
    void pop(){
        if(_size == 0) return;

        _size--;
    }
    size_t size() { return _size; }
    bool is_empty() { return (_size == 0) ? true : false; }

    NaiveStack() { _size = 0; _data = new t[1];}
    NaiveStack(const NaiveStack<t> &other){ deepCopy(this, other); }
    ~NaiveStack(){ delete[] _data; }

    NaiveStack<t> operator=(const NaiveStack<t> &other){
        if(&other == this) return *this;

        delete[] this->_data;

        deepCopy(this, other);

        return *this;
    }

  private:
    t *_data;
    size_t _size;
    void deepCopy(NaiveStack<t> *reciever, const NaiveStack<t> &giver){
        reciever->_size = giver._size;
        reciever->_data = new t[_size];

        for(size_t i = 0; i < _size; i++){
            reciever->_data[i] = giver._data[i];
        }
    }
};

#endif