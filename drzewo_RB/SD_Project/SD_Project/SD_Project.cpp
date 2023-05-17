#include <iostream>
#include "Node.h"
#include "RB_Tree.h"

using namespace std;

int main() {
    //TEST
    RB_Tree<int> tree;
    tree.insert(10);
    tree.insert(6);
    tree.insert(14);
    tree.insert(9);
    tree.insert(7);
    tree.insert(17);
    tree.insert(20);
    tree.insert(13);
    cout << "root :" << tree.getRoot()->getValue() << "," << tree.getRoot()->getColor();
    cout << "\n left:" << tree.getRoot()->getLeft()->getValue() << "," << tree.getRoot()->getLeft()->getColor();
    cout << ", right:" << tree.getRoot()->getRight()->getValue() << "," << tree.getRoot()->getRight()->getColor();
    
    cout << "\n, leftleft:" << tree.getRoot()->getLeft()->getLeft()->getValue() << "," << tree.getRoot()->getLeft()->getLeft()->getColor();
    cout << ", leftright:" << tree.getRoot()->getLeft()->getRight()->getValue() << "," << tree.getRoot()->getLeft()->getRight()->getColor();
    cout << ", rightleft:" << tree.getRoot()->getRight()->getLeft()->getValue() << "," << tree.getRoot()->getRight()->getLeft()->getColor();
    cout << ", rightright:" << tree.getRoot()->getRight()->getRight()->getValue() << "," << tree.getRoot()->getRight()->getRight()->getColor();
    cout << "\n, rightleftleft:" << tree.getRoot()->getRight()->getLeft()->getLeft()->getValue() << "," << tree.getRoot()->getRight()->getLeft()->getLeft()->getColor();
}// insert dziala

