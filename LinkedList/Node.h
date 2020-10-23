/**
 * @brief Object that represents the node of a generic linked list
 * @author Monica Waterhouse
 * @since 10/22/2020
 */

#ifndef ODISSEYRADIO_NODE_H
#define ODISSEYRADIO_NODE_H

template <typename T>

class Node {

private:
    T *data;
    Node<T> *nextNode;

public:
    Node(T data);
    ~Node();

    T *getData();
    Node<T> *getNext();
    void setNext(T nextData);

};


#endif //ODISSEYRADIO_NODE_H
