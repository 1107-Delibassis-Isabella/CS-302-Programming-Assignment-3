#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "stdio.h"
#include "Token.h"
#include "Node.h"

template <typename T>
class LinkedQueue {
    private:
    //template <typename T>
/*struct Node {
    T data;
    Node <T>* next;
    Node(const T& val, Node<T>* n = nullptr) : data(val), next(n) {}
};*/
        Node<T>* frontPtr;
        Node<T>* backPtr;
        int count;
    public:
        LinkedQueue();
        LinkedQueue(const LinkedQueue<T>& other);
        LinkedQueue<T>& operator= (const LinkedQueue<T>& other);
        ~LinkedQueue();
        T findFront();
        void enqueue(const T& value);
        void dequeue();
        bool isEmpty() const;
        int size() const;
        void clear();
};
#endif