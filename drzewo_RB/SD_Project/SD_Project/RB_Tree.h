#ifndef RB_TREE_H_
#define RB_TREE_H_
#include "Node.h"

template<class T>
class RB_Tree {
	Node<T>* root;								// korzen drzewa
	Node<T>* nil;								// lisc drzewa
public:
	RB_Tree();									// konstruktor
	~RB_Tree();									// dekonstruktor

	void insert(Node<T> * node);				// dodaje 
	void remove(Node<T>* node);					// usuwa
	void search(T key);							// szuka
	void leftRotation(Node<T>* x);				// rotuje w lewo
	void rightRotation(Node<T>* x);				// rotuje w prawo
	void fixAfterInsert(Node<T>* x);			// napiawia po dodaniu
	void fixAfterRemove(Node<T>* x);			// naprawia po usuwaniu

};

#endif // !RB_TREE_H_


