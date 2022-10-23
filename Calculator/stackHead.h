#ifndef STACK_H
#define STACK_H
#include <iostream>
struct MemoryException : public std::exception {
    const char* what() {
        return "Unable to allocate memory for a stack node!";
    }
};
struct EmptyStackException : public std::exception {
    const char* what() {
        return "";
    }
};
template <class T>
struct nodeStack {
    T data;
    nodeStack<T>* next;
};
template <class T>
class Stack
{
public:
    Stack();
    virtual ~Stack();
    void push(T data);
    T pop();
    T peep();
    bool isEmpty();
    int getCount();
    void empty();
protected:
private:
    nodeStack<T>* top;
    int count;
};
#endif // STACK_H


