#include "dlinkedlist.h"

template<typename T>
DLinkedList<T>::DLinkedList() {
    head = new DListNode<T>;
    tail = new DListNode<T>;
    head->next = tail;
    tail->prev = head;
    head->prev = nullptr;
    tail->next = nullptr;
}

template<typename T>
DLinkedList<T>::~DLinkedList() {
    while (!isEmpty()) {
        removeFront();
    }
    delete head;
    delete tail;
}

template<typename T>
bool DLinkedList<T>::isEmpty() const {
    return (head->next == tail);
}

template<typename T>
const T& DLinkedList<T>::front() const {
    return head->next->value;
}

template<typename T>
const T& DLinkedList<T>::back() const {
    return tail->prev->value;
}

template<typename T>
void DLinkedList<T>::add(DListNode<T>* v, const T& value) {
    DListNode<T>* nnode = new DListNode<T>;
    nnode->value = value;
    nnode->next = v;
    nnode->prev = v->prev;
    v->prev->next =  nnode;
    v->prev = nnode;
}

template<typename T>
void DLinkedList<T>::remove(DListNode<T>* v) {
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v;
}

template<typename T>
void DLinkedList<T>::addFront(const T& value) {
    add(head->next, value);
}

template<typename T>
void DLinkedList<T>::addBack(const T& value) {
    add(tail, value);
}

template<typename T>
void DLinkedList<T>::removeFront() {
    remove(head->next);
}

template<typename T>
void DLinkedList<T>::removeBack() {
    remove(tail->prev);
}
