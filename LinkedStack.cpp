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
            newCurr->next = new Node<T>(other->data);
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
            newCurr->next = new Node<T>(other->data);
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
    Node* temp = new Node(value);
    temp->next = topPtr; //idk if this is correct
    topPtr = temp;
    count++;
}

template <typename T>
void LinkedStack<T>::pop() {
    if (topPtr == NULL) {
        cout << "Stack Underflow" << endl;
        return;
    }
    Node* temp = topPtr;
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
    while (topPtr != NULL) {
        Node<T>* temp = topPtr;
        topPtr = topPtr.next->;
        delete temp;
    }
    count = 0;
}

template <typename T>
T LinkedStack<T>::findTop() {
    if (isEmpty() == true) {
        return nullptr;
    }
    return topPtr->data;
}