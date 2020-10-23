/**
 * @brief This class contains the abstraction of a Linked List object type
 * @author Monica Waterhouse
 * @since 10/22/2020
 */

#ifndef ODISSEYRADIO_LINKEDLIST_H
#define ODISSEYRADIO_LINKEDLIST_H

#include "Node.h"

template <typename T>

class LinkedList {

private:
    Node<T> *head;
    int size;

public:
    LinkedList();
    ~LinkedList();

    int getSize();
    Node<T> getFirst();

    void insertElement(T *data);
    void removeElement(T *data);
    T *getElement(int position);


};


#endif //ODISSEYRADIO_LINKEDLIST_H
