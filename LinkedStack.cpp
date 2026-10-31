#include "LinkedStack.h"

template <typename T>
LinkedStack<T>::LinkedStack() {
    topPtr = NULL;
    count = 0;
}

template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& other) {
    if (other.topPtr != NULL) {
        Node<T>* otherCurr = other.topPtr;
        Node<T>* newHead = new Node<T>(otherCurr->data);
        Node<T>* newCurr = newHead;
        otherCurr = otherCurr->next;

        while (otherCurr != NULL) {
            newCurr->next = new Node<T>(otherCurr->data);
            newCurr = newCurr->next;
            otherCurr = otherCurr->next;
        }
        topPtr = newHead;
        count = other.count;
    }
}
template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& other) {
    if (this != &other) {
        Node<T>* otherCurr = other.topPtr;
        Node<T>* newHead = new Node<T>(otherCurr->data);
        Node<T>* newCurr = newHead;
        otherCurr = otherCurr->next;

        while (otherCurr != NULL) {
            newCurr->next = new Node<T>(otherCurr->data);
            newCurr = newCurr->next;
            otherCurr = otherCurr->next;
        }
        topPtr = newHead;
        count = other.count;
    }

    return *this;
}
template <typename T>
LinkedStack<T>::~LinkedStack() {
    clear();
}
template <typename T>
void LinkedStack<T>::push(const T& value) {
    /*if (topPtr == NULL) {
        cout << "Stack Underflow" << endl;
        return;
    }*/
    topPtr = new Node<T>(value, topPtr);
    //temp->next = topPtr; //idk if this is correct
    //topPtr = temp;
    count++;
}

template <typename T>
void LinkedStack<T>::pop() {
    if (topPtr == NULL) {
        //std::cout << "Stack Underflow" << std::endl;
        return;
    }
    Node<T>* temp = topPtr;
    topPtr = topPtr->next;
    //int val = temp->count; //idk if this is correct
    count--;
    delete temp;
}

template <typename T>
bool LinkedStack<T>::isEmpty() const {
    return topPtr == NULL;
}

template <typename T>
int LinkedStack<T>::size() const {
    return count;
}

template <typename T>
void LinkedStack<T>::clear() { //idk if this is correct
    if (topPtr == NULL) {
        return;
    }
    while (!isEmpty()) {
        pop();
    }
    count = 0;
}

template <typename T>
T LinkedStack<T>::findTop() {
    if (isEmpty() == true) {
        return T{};
    }
    return topPtr->data;
}

template class LinkedStack<Token>;
template class LinkedStack<int>;