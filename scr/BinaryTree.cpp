// function implemnattion of BinaryTree class

#include "../lib/BinaryTree.h"

// Insert a new node recursively, node is the ptr to the root of the subtree, it will chose where to put the new node depending on the value
BinaryNode *BinaryTree::insert_recursive(BinaryNode *&node, const int value)
{

    if (!node)
        return new BinaryNode(value); // if the node is null, create a new node with the value, this is the base case
    if (value < node->key)
        node->left = insert_recursive(node->left, value); // go left if the value is less than the key, right otherwise
    else
        node->right = insert_recursive(node->right, value); // go right
    return node;                                            // return the node pointer
}

// Search a node recursively, node is the ptr to the root of the subtree, it will chose where to go depending on the value return the address of the node if found, nullptr otherwise
BinaryNode *BinaryTree::search_recursive(BinaryNode *node, const int value)
{

    if (!node)
        return nullptr; // if the node is null, return false
    if (node->key == value)
        return node; // if the value is the same as the key, return the node
    if (value < node->key)
        return search_recursive(node->left, value); // go left if the value is less than the key, right otherwise
    return search_recursive(node->right, value);    // else go right
}

void BinaryTree::destroy_tree(BinaryNode* node) {
    if (node) {
        destroy_tree(node->left);      // Elimina il sottoalbero sinistro
        destroy_tree(node->right);     // Elimina il sottoalbero destro
        delete node;                  // Elimina il nodo corrente
    }
}

// Constructor
BinaryTree::BinaryTree() : root(nullptr) {}

// Destructor
BinaryTree::~BinaryTree()
{
    // delete roots pointer

}

// Insert a new node in the tree recursively
void BinaryTree::insert(const int value)
{
    root = insert_recursive(root, value);
}

// Search a node in the tree recursively and return the address of the node if found, nullptr otherwise
bool BinaryTree::search(const int value)
{
    return search_recursive(root, value) != nullptr;
}

// Cancel a node in the tree recursively finding the succesor if needed to replace the node
bool BinaryTree::cancel(const int value)
{
    // find the node to cancel
    BinaryNode *node = search_recursive(root, value);
    if (!node)
        return false; // if the node is not found, return

    // if the node has two children
    if (node->left && node->right)
    {
        // find the succesor
        BinaryNode *succesor = node->right;                            // the succesor is the leftmost node in the right subtree
        while (succesor->left)
            succesor = succesor->left;
        // replace the node with the succesor
        node->key = succesor->key;
        // delete the succesor
        cancel(succesor->key);
    }
    // case with just one children or no children
    else
    {
        // if the node has one child, replace the node with the child
        BinaryNode *child = node->left ? node->left : node->right;
        delete node;
        node = child;
    }
    return true; // successfully deleted the node
}

// print in console all the nodes in order ( !!! JUST A TEST FUNCTION !!!) i will decide if i will keep it or not
void print_in_order_recursive(BinaryNode *node)
{
    if (!node)                             // if the node is null,
        return;           
    print_in_order_recursive(node->left);   // go left
    std::cout << node->key << " ";          // print the key
    print_in_order_recursive(node->right);  // go right
}

void BinaryTree::print_in_order()
{
    print_in_order_recursive(root);
    std::cout << std::endl;
}
