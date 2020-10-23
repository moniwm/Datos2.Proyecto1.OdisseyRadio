/**
 * @brief Object that represents the node of a generic linked list
 * @author Monica Waterhouse
 * @since 10/22/2020
 */

#include "Node.h"

template <typename T>
Node<T>::Node(T data) {
    this->data = data;
}

template <typename T>
Node<T>::~Node(){
    delete this->data;
    delete this->nextNode;
    delete this;
}

/**
 * Gets the value of the data assigned to this node
 * @tparam T this template allows to give different types of data
 * @return the data value
 */
template <typename T>
T *Node<T>::getData() {
    return this->data;
}

/**
  * Sets the value of the next node
  * @param next is the value that will be set to the next node
  */

template <typename T>
void Node<T>::setNext(T next) {
    this->nextNode = new Node(nextData);
}

/**
 * @tparam T this template allows to give different types of data
 * @return the next node
 */
template <typename T>
Node<T> *Node<T>::getNext() {
    return this->nextNode;
}

