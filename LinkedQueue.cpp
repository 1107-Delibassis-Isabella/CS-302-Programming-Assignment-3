#include "LinkedQueue.h"

template <typename T>
LinkedQueue<T>::LinkedQueue() {
    frontPtr = NULL;
    backPtr = NULL; 
    count = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& other) {
    Node<T>* curr = other.frontPtr;
    while (curr!= NULL) {
        enqueue(curr->data);
        curr = curr->next; 
    }
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator= (const LinkedQueue<T>& other) {
    if (this != &other) {
        clear();
        Node<T>* curr = other.frontPtr;
        while(curr!= NULL) {
            enqueue(curr->data);
            curr = curr->next;
        }
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& value) {
    Node<T> newNode = new Node<T>(value);
    if (backPtr == NULL) {
        frontPtr = newNode;
    } else {
        backPtr->next = newNode;
    }
    backPtr = newNode;
    count++;
}

template<typename T>
void LinkedQueue<T>::dequeue() {
    if (backPtr == NULL) {
        return;
    } else {
        Node<T>* temp = frontPtr;
        frontPtr = frontPtr->next;
        if (frontPtr == NULL) {
            backPtr = NULL;
        }
        delete temp;
        count--;
    }
}

template<typename T>
bool LinkedQueue<T>::isEmpty() const {
    if (count == 0) {
        return true;
    }
    return false; 
}

template <typename T>
int LinkedQueue<T>::size() const {
    return count;
}

template<typename T>
void LinkedQueue<T>::clear() {
    while(frontPtr != NULL) {
        Node<T>* temp = frontPtr;
        frontPtr = frontPtr->next;
        delete temp;
    }
    backPtr = NULL;
    count = 0;
}

template <typename T>
T LinkedQueue<T>::findFront() {
    if (isEmpty() == true) {
        return nullptr;
    }
    return frontPtr->data;
}