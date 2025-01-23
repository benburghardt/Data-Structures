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

#ifndef IMPROVED_STACK_HPP
#define IMPROVED_STACK_HPP

#include "Node.hpp"

using namespace std;



template <typename t>
class ImprovedStack {
  public:
    t top(){
        if(_size == 0) return NULL;

        return _data->value[_size - 1];
    }

    // inline definitions, doing nothing at the moment
    void push(const t &entry){
        if(_size == _capacity){
            Node<t>* temp = new Node<t>(_data,_capacity*2);
            _data = _data->pNext;
            _size = 0;
            _capacity *= 2;
            
        }
        _data->value[_size] = entry;
        _size++;
    }
    void pop(){
        if(_size == 0) return;

        _size--;

        if(_size == 0 && _data->pPrev != nullptr) {
            _data = _data->pPrev;
            delete _data->pNext;
            _capacity /= 2;
            _size = _capacity; 
        }
    }
    size_t size() { return _size; }
    bool is_empty() { return (_size == 0) ? true : false; }

    ImprovedStack() { _size = 0; _capacity = 1; _data = new Node<t>(nullptr,1);}
    //stack(const stack<t> &other){ deepCopy(this, other); }
    ~ImprovedStack(){ 
        while(_data->pPrev != nullptr){
            _data = _data->pPrev;
            delete _data->pNext;
        } 
        delete _data;
    }

    ImprovedStack<t> operator=(const ImprovedStack<t> &other){
        if(&other == this) return *this;

        delete[] this->_data;

        //deepCopy(this, other);

        return *this;
    }

  private:
    Node<t> *_data;
    size_t _size;
    size_t _capacity;
    /*void deepCopy(stack<t> *reciever, const stack<t> &giver){
        reciever->_size = giver._size;
        reciever->_capacity = giver._capacity;

        while(giver._data->pPrev != nullptr){
            giver._capacity /= 2;
            giver._data = giver._data->pPrev;
        }

        reciever->_data = new Node<t>(nullptr,1);
        reciever->_data->value[0] = giver._data->value[0];
        giver._capacity *= 2;
        giver._data = giver._data->pNext;

        while(giver._data->pNext != nullptr){
            
            giver._capacity *= 2;
            giver._data = giver._data->pNext;
        }

        reciever->_capacity = giver._capacity;
        reciever->_size = giver._size;
        for (int i = 0; i < giver._size){

        }
    }*/
};

#endif