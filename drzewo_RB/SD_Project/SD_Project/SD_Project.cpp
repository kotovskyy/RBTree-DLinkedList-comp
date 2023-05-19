#include <iostream>
#include "Node.h"
#include "RB_Tree.h"

using namespace std;

int main() {
    RB_Tree<int> tree;
    tree.insert(25);
    tree.insert(11);
    tree.insert(17);
    tree.insert(4);
    tree.insert(15);
    tree.insert(19); 
    tree.insert(52);
    tree.insert(34);
    tree.insert(39);
    tree.insert(28);
    tree.insert(31);
    tree.insert(63);
    tree.insert(69);
    ////TEST
    //RB_Tree<int> tree;
    //tree.insert(10);
    //tree.insert(6);
    //tree.insert(14);
    //tree.insert(9);
    //tree.insert(7);
    //tree.insert(17);
    //tree.insert(20);
    //tree.insert(13);
    //cout << "root :" << tree.getRoot()->getValue() << "," << tree.getRoot()->getColor();
    //cout << "\n left:" << tree.getRoot()->getLeft()->getValue() << "," << tree.getRoot()->getLeft()->getColor();
    //cout << ", right:" << tree.getRoot()->getRight()->getValue() << "," << tree.getRoot()->getRight()->getColor();
    //
    //cout << "\n, leftleft:" << tree.getRoot()->getLeft()->getLeft()->getValue() << "," << tree.getRoot()->getLeft()->getLeft()->getColor();
    //cout << ", leftright:" << tree.getRoot()->getLeft()->getRight()->getValue() << "," << tree.getRoot()->getLeft()->getRight()->getColor();
    //cout << ", rightleft:" << tree.getRoot()->getRight()->getLeft()->getValue() << "," << tree.getRoot()->getRight()->getLeft()->getColor();
    //cout << ", rightright:" << tree.getRoot()->getRight()->getRight()->getValue() << "," << tree.getRoot()->getRight()->getRight()->getColor();
    //cout << "\n, rightleftleft:" << tree.getRoot()->getRight()->getLeft()->getLeft()->getValue() << "," << tree.getRoot()->getRight()->getLeft()->getLeft()->getColor();
    //// insert dziala

    //cout << "=================================================\n\n";
    //cout << "MIN: " << tree.minimum(tree.getRoot())->getValue();
    //cout << "\nMAX: " << tree.maximum(tree.getRoot())->getValue() << endl;
    //// min i max dzila
    //cout << "=================================================\n\n";
    //cout << "kolor noda o wartosci 9: " << tree.search(9)->getColor() << endl;
    //// search działa

    //tree.print(tree.getRoot());
    //tree.remove(tree.search(14));
    //tree.print(tree.getRoot());
    
    
    tree.print(tree.getRoot());
    cout << endl;

    //insert dziala poprawnie
    tree.remove(tree.search(39));
    // remove działa poprawnie 
    tree.print(tree.getRoot());

    return 0;
}
