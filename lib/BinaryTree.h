// BinaryTree.h
#pragma once

#include "AbstractTree.h"
#include <iostream>
#include <vector>

//  Node rapresentation:

//  | ptr sx subtree | Key | ptr dx subtree |

// Basic opertaion implemented:

// Insert: insert a new node in the tree recursively
// Search: search a node in the tree recursively and return the address of the node if found, nullptr otherwise
// Cancel: NEED TO BE FIXED
// Calculate Hight: calculate the height of the tree recursively

// Traveling implemented:

// Level order traversal: return a vector of the key in the tree

using namespace std;

// Structure describing the Node
struct BinaryNode
{
    int key; // actual data stored in the node
    BinaryNode *left;
    BinaryNode *right;

    // structure custructur
    BinaryNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

// This class implemnets evry methode needed
class BinaryTree : public AbstractTree
{
private:
    BinaryNode *root; 
    int height;

    // PRIVATE FUNCTIONS

    // private function that Insert a new node recursively, node is the ptr to the root of the subtree, it will chose where to put the new node depending on the value
    BinaryNode *insert_recursive(BinaryNode *&node, const int value);

    // private function that Search a node recursively, node is the ptr to the root of the subtree, it will chose where to go depending on the value return the address of the node if found, nullptr otherwise
    BinaryNode *search_recursive(BinaryNode *node, const int value);

    // private function that calculate the height of the tree recursevly
    int calculate_height_recursive(BinaryNode* node);

    // Destroy the tree recursively
    void destroy_tree(const BinaryNode* node);

public:
    BinaryTree();
    ~BinaryTree();                    

    // BASIC OPERATION

    // Insert a new node
    void insert(const int value) override;

    // Cancel an existing node and return 1 if it finds it or 0 if it fails ( the node is not in the tree )
    bool cancel(const int value) override;

    // Search a node and return 1 if it finds it or 0 if it fails
    bool search(const int value) override;

    // TRAVELING

    // level-order traversal returning a vector of the key in the tree
    vector<int> level_order_traversal();

    //GETTER

    // funtction to get root pointer
    BinaryNode* get_root() const;

    // get the height of the tree
    int get_height() const;
     
    //Function top get a level order traversal of the tree but modified to print the tree in a more readable way
    vector<int> level_order_traversal_print();

};