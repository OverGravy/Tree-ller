// inluide standard libary 
#include <iostream>
#include <vector>
#include "../lib/BinaryTree.h"
#include <math.h>


using namespace std;

int main() {


    // set of key to insert in the binarytree
    vector<int> binary_tree = {40,30,50,60,90,55,87};
    
    // create a new binary tree
    BinaryTree btree;

    // insert all the key in the binary tree                   // POTREI DARLO AL COSTRUTTORE DELLA CLASSE mettendo come opzione che se c'è allora lo carica
    for (int i = 0; i < binary_tree.size(); i++){
        btree.insert(binary_tree[i]);
    }
    cout << "Height: " << btree.get_height() << endl;

    // print the binary tree
    cout << "Level order traversal: ";
    vector<int> level_order = btree.level_order_traversal();
    for (int j = 0; j < level_order.size(); j++){
        cout << level_order[j] << " ";
    }

    // print the binary tree in a more readable way
    vector<int> level_order_print = btree.level_order_traversal_print();
    cout << endl << "Print the tree: "<< endl;


    int space = ((pow(2,btree.get_height())-1)/2)*4;   //((number of node in the last level )/ 2)*(number of digits in the biggest key) 

    // find a way to print the tree in a more readable way as a test              

    for (int k = 0; k < btree.get_height(); k++){

       for (int w = 0; w<pow(2,k); w++){
           cout << level_order_print[pow(2,k)-1+w] << "     ";
       }
         cout << endl;
    }

    // search a key in the binary tree
    cout << endl << "Searching 55: ";
    if (btree.search(55))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl; 

    btree.cancel(55);

    // print the binary tree
    cout << "Level order traversal: " << endl;
    vector<int> level_order2 = btree.level_order_traversal();
    for (int j = 0; j < level_order2.size(); j++){
        cout << level_order2[j] << " ";

    }
    cout << endl;

   
    return 0;
}