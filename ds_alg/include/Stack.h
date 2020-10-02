#ifndef STACK_H
#define STACK_H
namespace ds_alg
{
template <typename T>
class Stack
{
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T peek() = 0;
    virtual bool isEmpty() = 0;
    virtual int getSize() = 0;
    virtual ~Stack() = default;

};


template <typename T>
class ArrayStack :public Stack<T>{
private:
    static const int DEFAULT_INITIAL_CAPACITY = 16;
    int size;
    int capacity;
    T *array;
    int top;

    void resize(){
      int newCapacity = this->capacity * 2;
      T *temp = new T[newCapacity];
      for(int i = 0; i < this->capacity; i++){
          temp[i] = this->array[i];
         }
      delete [] this->array;
      this->array = temp;
      this->capacity = newCapacity;
    }

public:
    ArrayStack(){
      this->array = new T[this->DEFAULT_INITIAL_CAPACITY];
      this->capacity = this->DEFAULT_INITIAL_CAPACITY;
      this->size = 0;
      this->top = -1;
    }

    ArrayStack(int capacity){
      this->array = new T[capacity];
      this->capacity = capacity;
      this->size = 0;
      this->top = -1;
    }

    void push(T value) override{
    this->top++;
    if(this->top == this->capacity){
        this->resize();
        this->array[this->top] = value;
        }
    else{
        this->array[this->top] = value;
        }
    this->size++;
    }

    T pop() override {
    if(this->top == -1){
        throw "stack is empty";
        }
    T value = this->array[this->top];
    this->top--;
    this->size--;
    return value;
    }

    T peek() override{
    if(this->top == -1){
        throw "stack is empty";
        }
    T value = this->array[this->top];
    return value;
    }

    bool isEmpty() override{
    return this->top == -1;
    }

    int getSize() override{
     return this->size;
    }

    ~ArrayStack(){
    delete [] this->array;
    }
    };

template<typename T>
class LinkedStack;

template<typename T>
class StackNode{
friend class LinkedStack<T>;
private:
    T value;
    StackNode *next;
protected:
    StackNode(T value){
      this->value = value;
      this->next = nullptr;
    }

    ~StackNode(){

    }
};

template<typename T>
class LinkedStack: public Stack<T>{
private:
    StackNode<T> *top;
    int size;
public:
    LinkedStack(){
      this->top = nullptr;
      this->size = 0;
    }

    void push(T value) override{
      StackNode<T> *newNode = new StackNode<T>(value);
      //newNode->setNext(this->top);
      newNode->next = top;
      this->top = newNode;
      this->size++;
    }

    T pop() override{
      if(this->top == nullptr){
        throw "stack is empty";
      }
      StackNode<T> *deletedNode = this->top;
      //this->top = deletedNode->getNext();
      this->top = deletedNode->next;
      //T value = deletedNode->getValue();
      T value = deletedNode->value;
      delete deletedNode;
      this->size--;
      return value;
    }

    T peek() override{
      //T value = this->top->getValue();
      T value = this->top->value;
      return value;
    }

    bool isEmpty() override{
      return this->top == nullptr;
    }

    int getSize() override{
      return this->size;
    }

    ~LinkedStack(){
      while(!isEmpty()){
        this->pop();
      }
    }
};
}

#endif // STACK_H
