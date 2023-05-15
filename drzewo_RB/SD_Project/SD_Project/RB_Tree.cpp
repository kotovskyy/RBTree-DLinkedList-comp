#include "RB_Tree.h"
#include "Node.h"

template<class T>
RB_Tree<T>::RB_Tree() {
	root = nullptr;
}

template<class T>
RB_Tree<T>::~RB_Tree() {}

template<class T>
void RB_Tree<T>::insert(Node<T>* node){
	
}

template<class T>
void RB_Tree<T>::remove(Node<T>* node) {

}

template<class T>
void RB_Tree<T>::search(T key) {


}

template<class T>
void RB_Tree<T>::leftRotation(Node<T>* x) {
	Node<T>* y = x->getRight();						// inicjuje nowy wezel
	x->setRight(y->getLeft());					// ustawia lewe poddrzewo y jako prawe poddrzewo x
	if (y->getLeft() != nullptr) {					// jesli istnieje lewe poddrzewo y to jego rodzicem staje sie x
		y->getLeft()->setParent(x);
	}
	y->setParent(x->getParent());					// ustawiamy rodzica x jako rodzica y
	if (x->getParent() == nullptr) {				// jesli x byl rootem to teraz y jest rootem
		root = y;
	}
	else if (x->getParent()->getLeft() == x) {		// jesli byl x lewym potomkiem to y jest lewym potomkiem
		x->getParent()->setLeft(y);
	}
	else{											// jesli byl x prawym potomkiem to y jest prawym potomnkiem
		x->getParent()->setRight(y);
	}
	y->setLeft(x);								// lewym potomkiem y staje sie x
	x->setParent(y);							// rodzicem x staje sie y
}

template<class T>
void RB_Tree<T>::rightRotation(Node<T>* x) {
	Node<T>* y = x->getLeft();						// inicjuje nowy wezel
	x->setLeft(y->getRight());					// ustawia prawe poddrzewo y jako lewe poddrzewo x
	if (y->getRight() != nullptr) {					// jesli istnieje prawe poddrzewo y to jego rodzicem staje sie x
		y->getRight()->setParent(x);
	}
	y->setParent(x->getParent());					// ustawiamy rodzica x jako rodzica y
	if (x->getParent() == nullptr) {				// jesli x byl rootem to teraz y jest rootem
		root = y;
	}
	else if (x->getParent()->getLeft() == x) {		// jesli byl x lewym potomkiem to y jest lewym potomkiem
		x->getParent()->setLeft(y);
	}
	else {											// jesli byl x prawym potomkiem to y jest prawym potomnkiem
		x->getParent()->setRight(y);
	}
	y->setRight(x);							// prawym potomkiem y staje sie x
	x->setParent(y);							// rodzicem x staje sie y

}

template<class T>
void RB_Tree<T>::fixAfterInsert(Node<T>* x) {

}

template<class T>
void RB_Tree<T>::fixAfterRemove(Node<T>* x) {

}

template class RB_Tree<int>;