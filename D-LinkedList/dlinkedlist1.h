#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include "dlinkedlistnode.h"

template<typename T>
class DLinkedList {
    private:
        DListNode<T>* head;
        DListNode<T>* tail;
    public:
        DLinkedList() {
            head = new DListNode<T>;
            tail = new DListNode<T>;
            head->next = tail;
            tail->prev = head;
            head->prev = nullptr;
            tail->next = nullptr;
        }

        ~DLinkedList() {
            while (!isEmpty()) {
                removeFront();
            }
            delete head;
            delete tail;
        }

        bool isEmpty() const {
            return (head->next == tail);
        }

        const T& front() const {
            return head->next->value;
        }

        const T& back() const {
            return tail->prev->value;
        }

        void addFront(const T& value) {
            add(head->next, value);
        }

        void addBack(const T& value) {
            add(tail, value);
        }

        void removeFront() {
            remove(head->next);
        }

        void removeBack() {
            remove(tail->prev);
        }
    protected:
        void add(DListNode<T>* v, const T& value) {
            DListNode<T>* nnode = new DListNode<T>;
            nnode->value = value;
            nnode->next = v;
            nnode->prev = v->prev;
            v->prev->next =  nnode;
            v->prev = nnode;
        }

        void remove(DListNode<T>* v) {
            v->prev->next = v->next;
            v->next->prev = v->prev;
            delete v;
        }
};

#endif