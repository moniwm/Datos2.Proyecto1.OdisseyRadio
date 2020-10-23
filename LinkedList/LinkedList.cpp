/**
 * @brief This class contains the abstraction of a Linked List object type
 * @author Monica Waterhouse
 * @since 10/22/2020
 */

#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList(){
    this->head = nullptr;
    this->size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    delete this->head;
    delete this;
}

template <typename T>
int LinkedList<T>::getSize() {
    return this->size;
}

template <typename T>
T *LinkedList<T>::getElement(int position) {
    int current = 0;
    Node<T> *tempPtr = head;
    while(tempPtr != nullptr){
        if(current == position){
            return tempPtr->getData();
        }
        tempPtr = tempPtr->getNext();
        current++;
    }
    return;
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
            this->size--;
            return;
        }

        currentPtr = currentPtr->getNext();
        nextPtr = currentPtr->getNext();
    }
}

