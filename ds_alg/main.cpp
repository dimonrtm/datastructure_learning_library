#include <iostream>
#include "Stack.h"
#include <chrono>
#include <stack>

typedef std::chrono::high_resolution_clock Clock;

void testIntStack(){
   ds_alg::Stack<int> *stack = new ds_alg::LinkedStack<int>();
    try{
      stack->pop();
    }
    catch(const char *exc){
        std::cout << exc << std::endl;
    }

    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    stack->push(6);
    stack->push(7);
    stack->push(8);
    stack->push(9);
    stack->push(10);
    std::cout << stack->getSize() << std::endl;
    while(!stack->isEmpty()){
        int value = stack->peek();
        std::cout << value << " ";
        value = stack->pop();
        std::cout << value << " ";
    }
    std::cout << std::endl;
    delete stack;
}

void testDoubleStack(){
  ds_alg::Stack<double> *stack = new ds_alg::LinkedStack<double>();
    try{
      stack->pop();
    }
    catch(const char *exc){
        std::cout << exc << std::endl;
    }

    stack->push(1.1);
    stack->push(2.2);
    stack->push(3.3);
    stack->push(4.4);
    stack->push(5.5);
    stack->push(6.5);
    stack->push(7.5);
    stack->push(8.8);
    stack->push(9.9);
    stack->push(10.5);
    std::cout << stack->getSize() << std::endl;
    while(!stack->isEmpty()){
        double value = stack->peek();
        std::cout << value << " ";
        value = stack->pop();
        std::cout << value << " ";
    }
    std::cout << std::endl;
    delete stack;
}

void testStringStack(){
  ds_alg::Stack<std::string> *stack = new ds_alg::LinkedStack<std::string>();
    try{
      stack->pop();
    }
    catch(const char *exc){
        std::cout << exc << std::endl;
    }

    stack->push("one");
    stack->push("two");
    stack->push("three");
    stack->push("four");
    stack->push("five");
    stack->push("six");
    stack->push("seven");
    stack->push("eight");
    stack->push("nine");
    stack->push("ten");
    std::cout << stack->getSize() << std::endl;
    while(!stack->isEmpty()){
        std::string value = stack->peek();
        std::cout << value << " ";
        value = stack->pop();
        std::cout << value << " ";
    }
    std::cout << std::endl;
    delete stack;
}

class Node{
  private:
      int key;
      int value;
  public:
    Node(){
    this->key = 0;
    this->value = 0;
    }
    Node(int key, int value){
      this->key = key;
      this->value = value;
    }

    int getValue(){
    return this->value;
    }
};

void testClassInstanceStack(){
  ds_alg::Stack<Node> *stack = new ds_alg::LinkedStack<Node>();
    try{
      stack->pop();
    }
    catch(const char *exc){
        std::cout << exc << std::endl;
    }
    Node node = Node(1, 2);
    stack->push(node);
    node = Node(3, 4);
    stack->push(node);
    node = Node(5, 6);
    stack->push(node);
    node = Node(6, 7);
    stack->push(node);
    node = Node (8, 9);
    stack->push(node);
    node = Node(9, 10);
    stack->push(node);
    node = Node(11, 12);
    stack->push(node);
    node = Node(13, 14);
    stack->push(node);
    node = Node(15, 16);
    stack->push(node);
    node = Node(17, 18);
    stack->push(node);
    std::cout << stack->getSize() << std::endl;
    while(!stack->isEmpty()){
        Node value = stack->peek();
        std::cout << value.getValue() << " ";
        value = stack->pop();
        std::cout << value.getValue() << " ";
    }
    std::cout << std::endl;
    delete stack;
}

void testPointerStack(){
  ds_alg::Stack<Node*> *stack = new ds_alg::LinkedStack<Node*>();
    try{
      stack->pop();
    }
    catch(const char *exc){
        std::cout << exc << std::endl;
    }
    Node *node = new Node(1, 2);
    stack->push(node);
    node = new Node(3, 4);
    stack->push(node);
    node = new Node(5, 6);
    stack->push(node);
    node = new Node(6, 7);
    stack->push(node);
    node = new Node (8, 9);
    stack->push(node);
    node = new Node(9, 10);
    stack->push(node);
    node = new Node(11, 12);
    stack->push(node);
    node = new Node(13, 14);
    stack->push(node);
    node = new Node(15, 16);
    stack->push(node);
    node = new Node(17, 18);
    stack->push(node);
    std::cout << stack->getSize() << std::endl;
    while(!stack->isEmpty()){
        Node *value = stack->peek();
        std::cout << value->getValue() << " ";
        value = stack->pop();
        std::cout << value->getValue() << " ";
        delete value;
    }
    std::cout << std::endl;
    delete stack;
}

void test1000000Insertion(){
    ds_alg::Stack<int> *stack = new ds_alg::LinkedStack<int>();
    //std::stack<int> *stack = new std::stack<int>();
    auto t1 = Clock::now();
    for(int i = 1; i <= 1000000; i++){
      stack->push(i);
    }
    auto t2 = Clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() * 1e-6<< std::endl;
    while(!stack->isEmpty()){
     stack->pop();
    }
    delete stack;
    auto t3 = Clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t3 - t2).count() * 1e-6<< std::endl;
}

int main()
{
   testIntStack();
   testDoubleStack();
   testStringStack();
   testClassInstanceStack();
   testPointerStack();
   test1000000Insertion();
    return 0;
}
