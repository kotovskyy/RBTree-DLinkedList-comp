#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include "dlinkedlistnode.h"

template<typename T>
class DLinkedList {
    private:
        DListNode<T>* head;
        DListNode<T>* tail;
    public:
        DLinkedList();
        ~DLinkedList();
        bool isEmpty() const;
        const T& front() const;
        const T& back() const;
        void addFront(const T& value);
        void addBack(const T& value);
        void removeFront();
        void removeBack();
    protected:
        void add(DListNode<T>* v, const T& value);
        void remove(DListNode<T>* v);
};

#endif