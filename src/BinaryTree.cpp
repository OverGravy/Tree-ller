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
        cout << "Insert: " << value << endl;
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






// BASIC OPERATION

// rifarla senza ricorsione ma con un while e usando la root interna
void BinaryTree::destroy_tree(const BinaryNode* node) {
    if (node) {
        destroy_tree(node->left);      // Elimina il sottoalbero sinistro
        destroy_tree(node->right);     // Elimina il sottoalbero destro
        delete node;                  // Elimina il nodo corrente
    }
}

// Constructor
BinaryTree::BinaryTree() : root(nullptr), height(0) {}

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
        BinaryNode *child = node->left ? node->left : node->right; // if the left child is not null, the child is the left child, otherwise the right child
        delete node;
        node = child;
    }
    // update the height of the tree after every cancel
  //  height = calculate_height_recursive(root);

    return true; // successfully deleted the node
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
        cout << "Node: " << node->key << endl;
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



// GETTER

// get the root pointer
BinaryNode* BinaryTree::get_root() const {
    return root;
}

// the high of the tree
int BinaryTree::get_height() const {
    return height;
}

//Function top get a level order traversal of the tree but modified to print the tree in a more readable way
vector<int> BinaryTree::level_order_traversal_print(){

    // using a queue cause it's a FIFO data structure
    vector<int> result;
    queue<BinaryNode *> q;
    q.push(root);               // push the root as the first node to visit 


    // i have to stop in 2 condition, if the queue is empty or if the result vector is full
    // cause if its full i have visited all the node in the tree even the null one and i have to stop 

    while (!q.empty() && result.size() < pow(2,height)-1)    
    {
        BinaryNode *node = q.front();       // get the first node in the queue without removing it
        q.pop();                            // remove the node from the queue
        if (node!= nullptr)
        {
            result.push_back(node->key);     // add the key to the result
 
            // if theres no chil i then push nuollptr in the queue to keep the structure of the tree
            if(node->left != nullptr)
                q.push(node->left);          // push the left child
            else
                q.push(nullptr);

            if(node->right != nullptr)
                q.push(node->right);         // push the right child
            else
                q.push(nullptr);

        }else if(node == nullptr){           // if the node is null push 2 null pointer in the queue to keep the structure of the tree
            result.push_back(-1);
            q.push(nullptr);
            q.push(nullptr);
        }
       
    }
    return result;

}