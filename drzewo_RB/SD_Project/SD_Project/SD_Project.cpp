#include <iostream>
#include "RB_Tree.h"
#include <string>
#include <vector>

using namespace std;

void read_text(RB_Tree<Character>& tree, char letters[], int counters[]) {
    for (int i = 0; i < 14; i++) {
        tree.insert(letters[i], counters[i]);
    }
}

int main() {
    RB_Tree<Character> tree;
    char letters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'w', 'z', 'v', 'm'};
    int counters[] = { 54, 23, 11, 24, 36, 49, 23, 41, 45, 22, 63, 31, 29, 12 };
    read_text(tree, letters, counters);
    tree.print(tree.getRoot());

    cout << tree.search('a')->getValue() << endl;

    cout << tree.search('d')->getValue() << endl;

    tree.remove(tree.search('w'));

    tree.print(tree.getRoot());

    return 0;
}
