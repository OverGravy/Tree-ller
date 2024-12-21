// inluide standard libary
#include <iostream>
#include <vector>
#include "../lib/BinaryTree.h"
#include "../lib/GraphicsCore.h"
#include <math.h>

using namespace std;

int main()
{

    // set of key to insert in the binarytree
    vector<int> binary_tree = {40, 30, 50, 60, 90, 55, 87};

    // create a new binary tree
    BinaryTree btree;

    // create a graphics core object
    GraphicsCore graphics(&btree);

    // insert all the key in the binary tree                   // POTREI DARLO AL COSTRUTTORE DELLA CLASSE mettendo come opzione che se c'è allora lo carica
    for (const auto &key : binary_tree)
    {
        btree.insert(key);
    }
    cout << "Height: " << btree.get_height() << endl;

    // print the binary tree
    cout << "Level order traversal: ";
    vector<int> level_order = btree.level_order_traversal();
    for (const auto &key : level_order)
    {
        cout << key << " ";
    }

    // search a key in the binary tree
    cout << endl
         << "Searching 55: ";
    if (btree.search(55))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    // print the binary tree
    cout << "Level order traversal: ";
    vector<int> level_order2 = btree.level_order_traversal();
    for (const auto &key : level_order2)
    {
        cout << key << " ";
    }
    cout << endl;

    sf::Event event;

    // print in order traversal
    cout << "In order traversal: ";
    vector<int> in_order = btree.in_order_traversal();
    for (const auto &key : in_order)
    {
        cout << key << " ";
    }
    cout << endl;

    // print the binary tree with graphics core
    while (graphics.get_window()->isOpen())
    {

        while (graphics.get_window()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                graphics.get_window()->close();
            }
        }
        graphics.draw_binary_tree();
    }

    return 0;
}