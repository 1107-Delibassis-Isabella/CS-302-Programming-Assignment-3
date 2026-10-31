#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node <T>* next;
    Node(const T& val, Node<T>* n = nullptr) : data(val), next(n) {}
};
#endif