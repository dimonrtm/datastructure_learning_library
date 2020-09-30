#include "include/Stack.hpp"
#include <cstring>

ds_alg::ArrayStack::ArrayStack(){
    this->array = new T[this->DEFAULT_INITIAL_CAPACITY];
    this->capacity = this->DEFAULT_INITIAL_CAPACITY;
    this->size = 0;
    this->top = -1;
    }
    
ds_alg::ArrayStack::ArrayStack(int capacity){
    this->array = new T[capacity];
    this->capacity = capacity;
    this->size = 0;
    this->top = -1;
    }
    
void ds_alg::push(T value){
    this->top++;
    if(this->top == this->capacity){
        this->resize();
        this->array[this->top] = value;
        }
    else{
        this->array[this->top] = value;
        }
    }
    
void ds_alg::resize(){
    int newCapacity = this->capacity * 2;
    T *temp = new T[newCapacity];
    for(int i = 0; i < this->capacity; i++){
        temp[i] = this->array[i];
        }
    delete [] this->array;
    this->array = temp;
    this->capacity = newCapacity;
    }