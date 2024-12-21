// function implemnattion of BinaryTree class

#include "../lib/BinaryTree.h"
#include <queue>
#include <math.h>

using namespace std;




// PRIVATE FUNCTIONS

// Insert a new node recursively, node is the ptr to the root of the subtree, it will chose where to put the new node depending on the value
BinaryNode *BinaryTree::insert_recursive(BinaryNode *&node, const int value)
{



    if (!node){
        
         // if the node is null create a new node, and change node with the new node
        node = new BinaryNode(value);

        std::cout << name << " > " << "Inserting a new node:" << value << endl;

        return node; // return the node pointer for the insert function
       
    }
    if (value < node->key)
        node->left = insert_recursive(node->left, value);    // go left if the value is less than the key, right otherwise
    else
        node->right = insert_recursive(node->right, value);  // go right

    return node;                                             // return the node pointer
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


int BinaryTree::calculate_height_recursive(BinaryNode* node) {
    // Caso base: se il nodo è nullo, l'altezza è 0
    if (node == nullptr) {
        return 0;
    }

    // Altezza del sottoalbero sinistro
    int leftHeight = calculate_height_recursive(node->left);
    
    // Altezza del sottoalbero destro
    int rightHeight = calculate_height_recursive(node->right);
    
    // L'altezza dell'albero è il massimo tra l'altezza sinistra e destra, più 1 (il nodo corrente)
    return 1 + std::max(leftHeight, rightHeight);
}


// private function that travels in-order recursively
void BinaryTree::in_order_traversal_recursive(BinaryNode *node, vector<int> &result)
{
    if (node != nullptr)
    {
        in_order_traversal_recursive(node->left, result);  // go left
        result.push_back(node->key);                       // add the key to the result
        in_order_traversal_recursive(node->right, result); // go right
    }
}

// private function that travels pre-order recursively
void BinaryTree::pre_order_traversal_recursive(BinaryNode *node, vector<int> &result)
{
    if (node != nullptr)
    {
        result.push_back(node->key);                       // add the key to the result
        pre_order_traversal_recursive(node->left, result);  // go left
        pre_order_traversal_recursive(node->right, result); // go right
    }
}

// private function that travels post-order recursively
void BinaryTree::post_order_traversal_recursive(BinaryNode *node, vector<int> &result)
{
    if (node != nullptr)
    {
        post_order_traversal_recursive(node->left, result);  // go left
        post_order_traversal_recursive(node->right, result); // go right
        result.push_back(node->key);                        // add the key to the result
    }
}




// BASIC OPERATION

// rifarla senza ricorsione ma con un while e usando la root interna
void BinaryTree::destroy_tree(const BinaryNode* node) {
    if (node) {
        destroy_tree(node->left);      // Elimina il sottoalbero sinistro
        destroy_tree(node->right);     // Elimina il sottoalbero destro
        delete node;                  // Elimina il nodo corrente
    }
}

// COSTRUCTORS
BinaryTree::BinaryTree() : root(nullptr), height(0) {}

// Copy constructor
BinaryTree::BinaryTree(const BinaryTree& other) {
    // Copy the root of the other tree
    root = other.root;
    // Copy the height of the other tree
    height = other.height;
}

// Constructor that recive the vector of keys of positive integer and insert them in the tree
BinaryTree::BinaryTree(const vector<int>& keys) : root(nullptr), height(0) {
    // Insert all the keys in the tree
    for (const auto &key : keys) {
        insert(key);
    }
}

// Constructor that recive the name of the tree
BinaryTree::BinaryTree(const string name) : root(nullptr), height(0) {
    this->name = name;
}

// Constructor that recive the vector of keys of positive integer and insert them in the tree and the name of the tree
BinaryTree::BinaryTree(const vector<int>& keys, const string name) : root(nullptr), height(0) {
    this->name = name;
    // Insert all the keys in the tree
    for (const auto &key : keys) {
        insert(key);
    }
}


// Destructor
BinaryTree::~BinaryTree()
{
    // delete roots pointer

}

// Insert a new node in the tree recursively
void BinaryTree::insert(const int value)
{
    insert_recursive(root, value);

    // update the height of the tree after every insert
 height = calculate_height_recursive(root);
}

// Search a node in the tree recursively and return the address of the node if found, nullptr otherwise
bool BinaryTree::search(const int value)
{
    return search_recursive(root, value) != nullptr;
}

// Search a node in the tree recursively and return the address of the node if found, nullptr otherwise
BinaryNode* BinaryTree::find(const int value)
{
    return search_recursive(root, value);
}

// Cancel a node in the tree recursively finding the succesor if needed to replace the node
bool BinaryTree::cancel(const int value)
{
    BinaryNode *node = root;
    BinaryNode *father = nullptr;

    // if the value is the root i need to find the node pointer and the father pointer
    if(node->key != value){

        while(node != nullptr) {   // find the node to cancel and the father 
           
            father = node;
            if(node->left!= nullptr){           // check if the value is the left or right child of the father if they exist
                if(value == node->left->key){
                   node = node->left;
                   break;
                }
            }
            else if(node->right!= nullptr){
                if (value == node->right->key)
                {
                    node = node->right;
                    break;
                }
            }
           if(value < node->key){                // go left if the value is less than the key, right otherwise
                node = node->left;
            }
            else{
                node = node->right;
            }   
        }
    }

    // if the value is not in the tree
    if (!node)
        return false;


    // if the node has two children
    if (node->left!=nullptr && node->right!=nullptr)
    {
        // find the succesor
        
        BinaryNode *succesor = node->right;                            // the succesor is the leftmost node in the right subtree

       
        // Find the father of the succesor
        BinaryNode *father_succesor = succesor;
        while (succesor->left != nullptr)
        {
            father_succesor = succesor;
            succesor = succesor->left;
        }
        
        if (father_succesor == succesor) // if the succesor is the right child of the node
        {
           
            node->key = succesor->key;               // replace the node with the succesor
            node->right = nullptr;                   // update the right pointer of the node to null
            delete succesor;                         // delete the succesor that will alwayse be a leaf

        }else{
          
            node->key = succesor->key;              // replace the node with the succesor
            father_succesor->left = nullptr;        // update the father pointer to null
            std::cout << name << " > " << "Cancelling a node with 2 children: " << node->key << " " << "Replaced with: " << succesor->key << endl;
            delete succesor;                        // delete the succesor that will alwayse be a leaf
        }

        
    
    }
    else if(node->left!=nullptr || node->right!= nullptr)        // case with just one children or no children
    {
        BinaryNode *child;         

        // find where is the child
        if(node->left){
            child = node->left;
            node->left = nullptr;    // update the father taht is going to lose the child
        }
        else{
            child = node->right;
            node->right = nullptr;   // update the father taht is going to lose the child
        }
        
        node->key = child->key;      // update the key of the father with the key of the child

        std::cout << name << " > " << "Cancelling a node with 1 child: " << node->key << " " << "Replasing it withe the child: " << child->key << endl;

        delete child;

    }else{       // case the node is a leaf
        
        if(node == root){                  // if the node is the root
            root = nullptr;
            std::cout << name << " > " << "Cancelling the root with no children: " << node->key << " " << "The tree is empty" << endl;
            delete node;
        }else{                             // if the node is not the root
            if(father->left == node){      // update the father pointer to null
                father->left = nullptr;
            }
            else{
                father->right = nullptr;
            }
            std::cout << name << " > " << "Cancelling a leaf: " << node->key << endl;
        delete node;
        
        }
    }

    // update the height of the tree after every cancel
    height = calculate_height_recursive(root);
    return true;


}




// TRAVELING

// level-order traversal returning a vector of the key in the tree
vector<int> BinaryTree::level_order_traversal()
{
    // using a queue cause it's a FIFO data structure
    vector<int> result;
    queue<BinaryNode *> q;
    q.push(root);               // push the root as the first node to visit 
    while (!q.empty())      
    {
        BinaryNode *node = q.front();   // get the first node in the queue without removing it
        q.pop();                        // remove the node from the queue
        if (node != nullptr)
        {
            result.push_back(node->key); // add the key to the result

            // if the node has a left child, push it in the queue
            if(node->left != nullptr)
                q.push(node->left);          // push the left child
            
            // if the node has a right child, push it in the queue
            if(node->right != nullptr)
                q.push(node->right);         // push the right child
        }
    }
    return result;
}

// in-order traversal returning a vector of the key in the tree
vector<int> BinaryTree::in_order_traversal()
{
    vector<int> result;
    in_order_traversal_recursive(root, result);
    return result;
}


// pre-order traversal returning a vector of the key in the tree
vector<int> BinaryTree::pre_order_traversal()
{
    vector<int> result;
    pre_order_traversal_recursive(root, result);
    return result;
}

// post-order traversal returning a vector of the key in the tree
vector<int> BinaryTree::post_order_traversal()
{
    vector<int> result;
    post_order_traversal_recursive(root, result);
    return result;
}





// GETTER

// get the root pointer
BinaryNode* BinaryTree::get_root() const {
    return root;
}

// the high of the tree
int BinaryTree::get_height() const {
    return height;
}
















