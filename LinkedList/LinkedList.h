/**
 * @brief This file contains a node class and a linked list class in order to store different data types
 * @author Mónica Waterhouse Montoya
 * @since 10/22/2020
 */

#ifndef ODISSEYRADIO_LINKEDLIST_H
#define ODISSEYRADIO_LINKEDLIST_H

template <typename T>
class Node{

private:
    T *data;
    Node<T> *nextNode;

public:
    Node(T *data);
    ~Node();

    T getData();
    Node<T> getNextNode();
    void setNextNode(T *nextData);
};

template <typename T>

class LinkedList {

private:
    Node<T> *head;
    int size;

public:
    LinkedList();
    ~LinkedList();

    void insertElement(T *data);
    void removeElement(T *data);
    T *getElement(int index);
};



#endif //ODISSEYRADIO_LINKEDLIST_H
