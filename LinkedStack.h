#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include "stdio.h"
#include "Token.h"
#include "Node.h"
using namespace std;

template <typename T>
class LinkedStack {
    private: 
       //template <typename T>
/*struct Node {
    T data;
    Node <T>* next;
    Node(const T& val, Node<T>* n = nullptr) : data(val), next(n) {}
};*/
        Node<T>* topPtr;
        int count;
    public: 
        LinkedStack();
        LinkedStack(const LinkedStack<T>& other);
        LinkedStack<T>& operator=(const LinkedStack<T>& other);
        ~LinkedStack();
        void push(const T& value);
        void pop();
        bool isEmpty() const;
        int size() const;
        void clear();

        T findTop();
};
#endif