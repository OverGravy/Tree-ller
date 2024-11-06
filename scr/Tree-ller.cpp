// inluide standard libary 
#include <iostream>
#include <vector>
#include "../lib/BinaryTree.h"


using namespace std;

int main() {


    // set of key to insert in the binarytree
    vector<int> binary_tree = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // create a new binary tree
    BinaryTree btree;

    // TEST THE FUNCTION

    // insert all the key in the binary tree
    for (int key : binary_tree)
        btree.insert(key);
    
    // print all the key in the binary tree in order
    btree.print_in_order();

    // search a key in the binary tree
    cout << endl << "Search 5: " << btree.search(5) << endl;

    // cancel a key in the binary tree
    cout << "Cancel 5: " << btree.cancel(5) << endl;

   
    return 0;
}