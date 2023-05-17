#include "RB_Tree.h"
#include "Node.h"

template<class T>
RB_Tree<T>::RB_Tree() {
	root = nullptr;
}

template<class T>
RB_Tree<T>::~RB_Tree() {}

template<class T>
Node<T>* RB_Tree<T>::getRoot() {
	return root;
}
template<class T>
void RB_Tree<T>::insert(T value){
	Node<T>* node = new Node<T>();			//tworzy nody node
	node->setValue(value);					// nadaje mu wartosc 
	Node<T>* y = nullptr;						// node pomocniczy
	Node<T>* x = root;						// wskaznik na root
	while (!(x == nullptr)) {						// dopuki x jest jest lisciem
		y = x;								
		if (node->getValue() < x->getValue()) {	// jesli wartoœc dodawanego noda jest mniejsza to ptrzesun w lewo
			x = x->getLeft();
		}
		else {									 // jesli wartoœc dodawanego noda jest wieksza to ptrzesun w prawo
			x = x->getRight();
		}
	}
	node->setParent(y);					// ustaw y jako rodzica
	if (y == nullptr) {								// jesli y == 0 to nowy node jest korzeniem
		root = node;
	}
	else if (node->getValue() < y->getValue()) {	// jesli wartoœc dodawanego noda jest mniejsza od rodzica to jest lewym synam	
		y->setLeft(node);
	}
	else {											// jesli wartoœc dodawanego noda jest wieksza od rodzica to jest prawym synam
		y->setRight(node);
	}
	node->setColor(1);				// ustaw kolor dodanego noda na czerwony
	node->setLeft(nullptr);
	node->setRight(nullptr);
	fixAfterInsert(node);				// napraw drzewo
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
void RB_Tree<T>::fixAfterInsert(Node<T>* node) {

	while ((root != node) && (node->getParent()->getColor() == 1)) {			//pêtla jesli rodzic jest czerwony to wykonaj
		Node<T>* y = nullptr;		//node pomoczniczy
//==============JESLI JEST LEWYM SYNEM=======================
		if (node->getParent() == node->getParent()->getParent()->getLeft()) {		// jesli node jest lewym synem 
			y = node->getParent()->getParent()->getRight();							// ustawiamy y jako stryja
			if (y != nullptr && y->getColor() == 1) {												// streyj jest czerwony
				node->getParent()->setColor(0);								// ustawia ojca na czarno
				y->setColor(0);												// ustawia stryja na czarano
				node->getParent()->getParent()->setColor(1);					// ustawia dzidka na czerwono
				node = node->getParent()->getParent();								// zmienia wskaznik aktualne wezla odniesienia na dziadka
			}
			else {
				if (node == node->getParent()->getRight()) {						// 
					node = node->getParent();
					leftRotation(node);
				}
				node->getParent()->setColor(0);
				node->getParent()->getParent()->setColor(1);
				rightRotation(node->getParent()->getParent());
			}
		}
//==============JESLI JEST PRAWYM SYNEM=======================
		else if (node->getParent() == node->getParent()->getParent()->getRight()) {	// jesli node jest prawym synem 
			y = node->getParent()->getParent()->getLeft();							// ustawiamy y jako stryja
			if (y != nullptr && y->getColor() == 1) {												// streyj jest czerwony
				node->getParent()->setColor(0);								// ustawia ojca na czarno
				y->setColor(0);												// ustawia stryja na czarano
				node->getParent()->getParent()->setColor(1);					// ustawia dzidka na czerwono
				node = node->getParent()->getParent();								// zmienia wskaznik aktualne wezla odniesienia na dziadka
			}
			else {
				if (node == node->getParent()->getLeft()) {
					node = node->getParent();
					rightRotation(node);
				}
				node->getParent()->setColor(0);
				node->getParent()->getParent()->setColor(1);
				leftRotation(node->getParent()->getParent());
			}
		}
	}                                                                                                                                                                                                      
	root->setColor(0);	//root musi byc czarny
}

template<class T>
void RB_Tree<T>::fixAfterRemove(Node<T>* node) {

}

template class RB_Tree<int>;