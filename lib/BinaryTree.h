// BinaryTree.h
#pragma once

#include "AbstractTree.h"
#include <iostream>

//  Node rapresentation:

//  | ptr sx subtree | Key | ptr dx subtree |

// Opertaion implemented:

// Insert: insert a new node in the tree recursively
// Search: search a node in the tree recursively and return the address of the node if found, nullptr otherwise
// Cancel: cancel a node in the tree recursively finding the succesor if needed to replace the node

// NEED TO IMPLENET THE 3 TYPE OF VISIT (IN ORDER, PRE ORDER, POST ORDER)

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

    // Insert a new node recursively, node is the ptr to the root of the subtree, it will chose where to put the new node depending on the value
    BinaryNode *insert_recursive(BinaryNode *&node, const int value);

    // Search a node recursively, node is the ptr to the root of the subtree, it will chose where to go depending on the value return the address of the node if found, nullptr otherwise
    BinaryNode *search_recursive(BinaryNode *node, const int value);

    // Destroy the tree recursively
    void BinaryTree::destroy_tree(BinaryNode* node);

public:
    BinaryTree();
    ~BinaryTree();                    

    // Insert a new node
    void insert(const int value) override;

    // Cancel an existing node and return 1 if it finds it or 0 if it fails ( the node is not in the tree )
    bool cancel(const int value) override;

    // Search a node and return 1 if it finds it or 0 if it fails
    bool search(const int value) override;

    // print in console all the nodes in order ( !!! JUST A TEST FUNCTION !!!)
    void print_in_order();
};
