#include <iostream>
#include <chrono>
#include <stack>
#include <random>
#include <ctime>
#include "Stack.h"
#include "Sort.h"
#include "Search.h"

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

void testInsertionSort(){
     std::mt19937 gen(time(nullptr));
   std::uniform_int_distribution<> uid_int(0, 1000);
   int array[5] = {5, 4, 3, 2, 1};
   ds_alg::insertionSort(array, 5);
   for(int i = 0; i < 5; i++){
       std::cout << array[i] << " ";
   }
   std::cout << std::endl;
   std::cout << "gen" << std::endl;
   int *bigArray = new int[100000];
   for(int i = 0; i < 100000; i++){
       bigArray[i] = uid_int(gen);
   }
   std::cout << "sort" << std::endl;
   auto t1 = Clock::now();
   ds_alg::insertionSort(bigArray, 100000);
   auto t2 = Clock::now();
   std::cout << "end" << std::endl;
   std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << std::endl;
   delete [] bigArray;
}

void testLinearSearch(){
   int array[5] ={5, 4, 3, 2, 1};
   int index = ds_alg::linearSearch(array, 5, 1);
   std::cout << index << std::endl;
   index = ds_alg::linearSearch(array, 5, 10);
   std::cout << index << std::endl;
}

void testSelectionSort(){
    std::mt19937 gen(time(nullptr));
   std::uniform_int_distribution<> uid_int(0, 1000);
   int array[5] = {5, 4, 3, 2, 1};
   ds_alg::selectionSort(array, 5);
   for(int i = 0; i < 5; i++){
       std::cout << array[i] << " ";
   }
   std::cout << std::endl;
   std::cout << "gen" << std::endl;
   int *bigArray = new int[100000];
   for(int i = 0; i < 100000; i++){
       bigArray[i] = uid_int(gen);
   }
   std::cout << "sort" << std::endl;
   auto t1 = Clock::now();
   ds_alg::selectionSort(bigArray, 100000);
   auto t2 = Clock::now();
   std::cout << "end" << std::endl;
   std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()<< std::endl;
   delete [] bigArray;
}

void testMergeSort(){
    std::mt19937 gen(time(nullptr));
   std::uniform_int_distribution<> uid_int(0, 1000);
   int array[5] = {5, 4, 3, 2, 1};
   ds_alg::mergeSort(array, 0, 4);
   for(int i = 0; i < 5; i++){
       std::cout << array[i] << " ";
   }
   std::cout << std::endl;
   std::cout << "gen" << std::endl;
   int *bigArray = new int[100000];
   for(int i = 0; i < 100000; i++){
       bigArray[i] = uid_int(gen);
   }
   std::cout << "sort" << std::endl;
   auto t1 = Clock::now();
   ds_alg::mergeSort(bigArray, 0, 99999);
   auto t2 = Clock::now();
   std::cout << "end" << std::endl;
   std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()<< std::endl;
   delete [] bigArray;
}

void testMergeSortWithoutSignals(){
    std::mt19937 gen(time(nullptr));
   std::uniform_int_distribution<> uid_int(0, 1000);
   int array[5] = {5, 4, 3, 2, 1};
   ds_alg::mergeSortWithoutSignals(array, 0, 4);
   for(int i = 0; i < 5; i++){
       std::cout << array[i] << " ";
   }
   std::cout << std::endl;
   std::cout << "gen" << std::endl;
   int *bigArray = new int[100000];
   for(int i = 0; i < 100000; i++){
       bigArray[i] = uid_int(gen);
   }
   std::cout << "sort" << std::endl;
   auto t1 = Clock::now();
   ds_alg::mergeSortWithoutSignals(bigArray, 0, 99999);
   auto t2 = Clock::now();
   std::cout << "end" << std::endl;
   std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()<< std::endl;
   delete [] bigArray;
}

void testBinarySearch(){
   int array[5] ={1, 2, 3, 4, 5};
   int index = ds_alg::binarySearch(array, 5, 5);
   std::cout << index << std::endl;
   index = ds_alg::binarySearch(array, 5, 10);
   std::cout << index << std::endl;
}

void testBinarySearchVsLinearSearch(){
   std::mt19937 gen(time(nullptr));
   std::uniform_int_distribution<> uid_int(0, 1000);
   std::cout << "gen" << std::endl;
   int *bigArray = new int[100000];
   for(int i = 0; i < 100000; i++){
       bigArray[i] = uid_int(gen);
   }
   std::cout << "sort" << std::endl;
   ds_alg::mergeSortWithoutSignals(bigArray, 0, 99999);
   std::cout << "linearSearch" << std::endl;
   auto t1 = Clock::now();
   int key = ds_alg::linearSearch(bigArray, 100000, 1000);
   auto t2 = Clock::now();
   std:: cout << key << std::endl;
   std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()<< std::endl;
   std::cout << "binarySearch" << std::endl;
   t1 = Clock::now();
   key = ds_alg::binarySearch(bigArray, 100000, 1000);
   t2 = Clock::now();
   std:: cout << key << std::endl;
   std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()<< std::endl;
}

void testBubbleSort(){
   std::mt19937 gen(time(nullptr));
   std::uniform_int_distribution<> uid_int(0, 1000);
   int array[5] = {5, 4, 3, 2, 1};
   ds_alg::bubbleSort(array, 5);
   for(int i = 0; i < 5; i++){
       std::cout << array[i] << " ";
   }
   std::cout << std::endl;
   std::cout << "gen" << std::endl;
   int *bigArray = new int[100000];
   for(int i = 0; i < 100000; i++){
       bigArray[i] = uid_int(gen);
   }
   std::cout << "sort" << std::endl;
   auto t1 = Clock::now();
   ds_alg::bubbleSort(bigArray,100000);
   auto t2 = Clock::now();
   std::cout << "end" << std::endl;
   std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()<< std::endl;
   delete [] bigArray;
}

void testInversionsCount(){
    std::mt19937 gen(time(nullptr));
   std::uniform_int_distribution<> uid_int(0, 1000);
   int array[5] = {5, 4, 3, 2, 1};
   long long inversions = ds_alg::inversionCount(array, 0, 4);
   std::cout << inversions << std::endl;
   for(int i = 0; i < 5; i++){
       std::cout << array[i] << " ";
   }
   std::cout << std::endl;
   std::cout << "gen" << std::endl;
   int *bigArray = new int[100000];
   for(int i = 0; i < 100000; i++){
       bigArray[i] = uid_int(gen);
   }
   std::cout << "sort" << std::endl;
   auto t1 = Clock::now();
   inversions = ds_alg::inversionCount(bigArray, 0, 99999);
   auto t2 = Clock::now();
   std::cout << "end" << std::endl;
   std::cout << inversions << std::endl;
   std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()<< std::endl;
   delete [] bigArray;
}

int main()
{
  testInversionsCount();
   return 0;
}
