/**
 * @brief This file contains a node class and a linked list class in order to store different data types
 * @author Mónica Waterhouse Montoya
 * @since 10/22/2020
 */

#include "LinkedList.h"

template <typename T>
Node<T>::Node(T *data) {
    this->data = data;
    this->nextNode = nullptr;
}

template <typename T>
Node<T>::~Node<T>() {
    delete this->data;
    delete this->nextNode;
    delete this;
}

template <typename T>
T Node<T>::getData() {
    return this->data;
}

template <typename T>
Node<T> Node<T>::getNextNode() {
    return this->nextNode;
}

template <typename T>
void Node<T>::setNextNode(T *nextData) {
    this->nextNode = new Node<T>(*nextData);
}

template <typename T>
LinkedList<T>::LinkedList() {
    this->head = nullptr;
    this->size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    delete this->head;
    delete this;
}

template <typename T>
void LinkedList<T>::insertElement(T *data) {
    Node<T> *newNode = new Node<T>(data);
    Node<T> *tempPtr = this->head;

    newNode->setNext(nullptr);

    if(this->head == nullptr){
        this->head = newNode;
        this->size++;
        return;
    }

    while(tempPtr->getNext() != nullptr){
        tempPtr = tempPtr->getNext();
    }

    tempPtr->setNext(newNode);
    this->size++;
    return;
}

template <typename T>
void LinkedList<T>::removeElement(T *data) {
    Node<T> *currentPtr = this->head;
    Node<T> *nextPtr = currentPtr->getNext();

    if(head->getData()==data){
        this->head = head->getNext();
        this->size--;
        return;
    }

    while (nextPtr != nullptr){

        if(nextPtr->getData() == data) {
            currentPtr->setNext(nextPtr->getNext());
            delete nextPtr;
            this->size--;
            return;
        }

        currentPtr = currentPtr->getNext();
        nextPtr = currentPtr->getNext();
    }
}

template <typename T>
T *LinkedList<T>::getElement(int index) {
    Node<T> *tempPtr = head;
    int position = 0;
    while(tempPtr != nullptr){
        if( position == index){
            return tempPtr->getData();
        }
        tempPtr = tempPtr->getNext();
    }
    return nullptr;
}