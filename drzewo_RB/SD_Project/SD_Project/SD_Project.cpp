#include <iostream>
#include "Node.h"
#include "RB_Tree.h"
#include "Character.h"

using namespace std;

int main() {
    RB_Tree<Character> tree;
    //tree.insert(25);
    //tree.insert(11);
    //tree.insert(17);
    //tree.insert(4);
    //tree.insert(15);
    //tree.insert(19); 
    //tree.insert(52);
    //tree.insert(34);
    //tree.insert(39);
    //tree.insert(28);
    //tree.insert(31);
    //tree.insert(63);
    //tree.insert(69);

    tree.insert(Character('a', 15));
    tree.insert(Character('b', 12));
    tree.insert(Character('c', 17));


    tree.print(tree.getRoot());

    tree.insert(Character('d', 14));
    tree.insert(Character('e', 2));
    tree.insert(Character('f', 13));

    tree.print(tree.getRoot());

    return 0;
}
