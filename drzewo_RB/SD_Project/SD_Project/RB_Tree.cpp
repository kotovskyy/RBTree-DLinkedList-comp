#include "RB_Tree.h"
#include "Node.h"
#include <iostream>

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
void RB_Tree<T>::print(Node<T>* node) {
	// prosta wersja algorytmu inorder tree traversal
	if (node != nullptr) {						// jesli node nie jest nullptr
		print(node->getLeft());					// wywolaj print() dla jego lewego poddrzewa
		std::cout << node->getValue() << " ";   // po tym, jak wypisze lewe poddrzewo wypisz node
		print(node->getRight());				// wywolaw print() dla prawego poddrzewa
	}
}

template<class T>
void RB_Tree<T>::insert(T value){
	Node<T>* node = new Node<T>();			//tworzy nowy node
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
	fixAfterInsert(node);				// napraw drzewo
}

template<class T>
void RB_Tree<T>::transplant(Node<T>* first, Node<T>* second) {
	// Funkcja wstawia node second zamiast noda first
	if (first->getParent() == nullptr) {                 // jesli zamieniany node jest rootem
		this->root = second;							 // ustaw second jako nowy root
	}		
	else if (first = first->getParent()->getLeft()) {
		first->getParent()->setLeft(second);             // 
	}
	else {
		first->getParent()->setRight(second);
	}
	if (second != nullptr) {
		second->setParent(first->getParent());
	}
}

template<class T>
void RB_Tree<T>::remove(Node<T>* node) {
	Node<T>* y = node;
	Node<T>* x = nullptr;                      // node that contains child of y
	bool y_orig_color = y->getColor();
	if (node->getLeft() == nullptr) {
		x = node->getRight();
		//
		x->setParent(node);
		//
		transplant(node, node->getRight());		//x - y's child; takes y's place in the tree
	}
	else if (node->getRight() == nullptr) {
		x = node->getLeft();
		//
		x->setParent(node);
		//
		transplant(node, node->getLeft());
	}
	else {
		y = minimum(node->getRight());
		y_orig_color = y->getColor();
		x = y->getRight();
		//
		x->setParent(y);
		//
		if (y != node->getRight()) {
			transplant(y, y->getRight());
			y->setRight(node->getRight());
			y->getRight()->setParent(y);
		}
		else {
			x->setParent(y);
		}
		transplant(node, y);
		y->setLeft(node->getLeft());
		y->getLeft()->setParent(y);
		y->setColor(node->getColor());
	}
	if (y_orig_color == 0) {
		fixAfterRemove(x);
	}
}

template<class T>
void RB_Tree<T>::fixAfterRemove(Node<T>* node) {
	Node<T>* sibling = nullptr;
	while ( (node != this->root) && (node->getColor() == 0)) {
		if (node == node->getParent()->getLeft()) {
			sibling = node->getParent()->getRight();
			if (sibling->getColor() == 1) {
				sibling->setColor(0);
				node->getParent()->setColor(1);
				leftRotation(node->getParent());
				sibling = node->getParent()->getRight();
			}
			if ((sibling->getLeft()->getColor() == 0) && (sibling->getRight()->getColor() == 0)){
				sibling->setColor(1);
				node = node->getParent();
			}
			else {
				if (sibling->getRight()->getColor() == 0) {
					sibling->getLeft()->setColor(0);
					sibling->setColor(1);
					rightRotation(sibling);
					sibling = node->getParent()->getRight();
				}
				sibling->setColor(node->getParent()->getColor());
				node->getParent()->setColor(0);
				sibling->getRight()->setColor(0);
				leftRotation(node->getParent());
				node = this->root;
			}
		}
		else {
			sibling = node->getParent()->getLeft();
			if (sibling->getColor() == 1) {
				sibling->setColor(0);
				node->getParent()->setColor(1);
				rightRotation(node->getParent());
				sibling = node->getParent()->getLeft();
			}
			if ((sibling->getRight()->getColor() == 0) && (sibling->getLeft()->getColor() == 0)) {
				sibling->setColor(1);
				node = node->getParent();
			}
			else {
				if (sibling->getLeft()->getColor() == 0) {
					sibling->getRight()->setColor(0);
					sibling->setColor(1);
					leftRotation(sibling);
					sibling = node->getParent()->getLeft();
				}
				sibling->setColor(node->getParent()->getColor());
				node->getParent()->setColor(0);
				sibling->getLeft()->setColor(0);
				rightRotation(node->getParent());
				node = this->root;
			}
		}
	}
	node->setColor(0);
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
			if (y != nullptr && y->getColor() == 1) {												// stryj jest czerwony
				node->getParent()->setColor(0);								// ustawia ojca na czarno
				y->setColor(0);												// ustawia stryja na czarano
				node->getParent()->getParent()->setColor(1);					// ustawia dziadka na czerwono
				node = node->getParent()->getParent();								// zmienia wskaznik aktualne wezla odniesienia na dziadka
			}
			else {
				if (node == node->getParent()->getRight()) {						// jesli node jest prawym synem  
					node = node->getParent();							// przypisz aktualny node rodzicowi
					leftRotation(node);								// wykonaj lewa rotacje
				}
				node->getParent()->setColor(0);								// rodzic ma kolor czarny
				node->getParent()->getParent()->setColor(1);						// dziadek ma czerwony
				rightRotation(node->getParent()->getParent());						// rotuje w prawo
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
				if (node == node->getParent()->getLeft()) {					// jesli node jest lewym synem  
					node = node->getParent();						// przypisz aktualny node rodzicowi
					rightRotation(node);							// wykonaj prawa rotacje
				}
				node->getParent()->setColor(0);							// rodzic ma kolor czarny
				node->getParent()->getParent()->setColor(1);					// dziadek ma czerwony
				leftRotation(node->getParent()->getParent());					// rotuje w lewo
			}
		}
	}                                                                                                                                                                                                      
	root->setColor(0);	//root musi byc czarny
}


template<class T>
Node<T>* RB_Tree<T>::search(T key) {
	Node<T>* y = root;
	while (y != nullptr) {
		if (y->getValue() == key) {
			return y;
		}
		else if (key < y->getValue()) {
			y = y->getLeft();
		}
		else {
			y = y->getRight();
		}
	}
	return nullptr;
}

template<class T>
Node<T>* RB_Tree<T>::minimum(Node<T>* node) {
	Node<T>* y = node;
	while (y->getLeft() != nullptr) {
		y = y->getLeft();
	}
	return y;
}

template<class T>
Node<T>* RB_Tree<T>::maximum(Node<T>* node) {
	Node<T>* y = node;
	while (y->getRight() != nullptr) {
		y = y->getRight();
	}
	return y;
}


template class RB_Tree<int>;
