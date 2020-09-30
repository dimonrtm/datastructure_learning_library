#ifndef INCLUDE_STACK_HPP
#define INCLUDE_STACK_HPP

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
    virtual int size() = 0;
    virtual ~Stack() = default;

};

template <typename T>
class ArrayStack :public Stack{
private:
    static const int DEFAULT_INITIAL_CAPACITY = 16;
    private size;
    private capacity;
    private T *array;
    private int top;
    void resize();
public:
    ArrayStack();
    explicit ArrayStack(int capacity);
    void push(T value) override;
    T pop() override;
    T peek() override;
    bool isEmpty() override;
    int size() override;
    ~ArrayStack();
    };

}

#endif // INCLUDE_STACK_HPP
