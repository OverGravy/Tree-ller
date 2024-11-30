//GraphicsCore.h
#pragma once

#include "BinaryTree.h"
#include <SFML/Graphics.hpp>
#include <vector>

// this class will define the methods to draw the tree using sfml library


// list of define to draw things
#define BT_NODE_RADIUS 30
#define BT_NODE_DISTANCE 100
#define BT_HIGHT_DISTANCE_BTWEEN_NODES BT_NODE_RADIUS/2


using namespace std;


class GraphicsCore
{
private:
    // screen dimension set by default to 800x600
    int width = 800;
    int height = 600;

    // trees object needed to draw the tree
    BinaryTree* Bt;

    // sfml objects
    sf::RenderWindow window;
    sf::Font font;

    // vector of circles too draw bt nodes
    vector<sf::CircleShape> circles;

    //Btree local variable and function to update them
    vector<int> keys_Bt;
    bool Bt_redraw = false;

    // function that update Keys_Bt and adjust some parameters
    void update_Bt();


public:
    // constructor
    GraphicsCore(BinaryTree* Bt);

    // destructor
    ~GraphicsCore();

    // function to draw the tree
    void draw_binary_tree();

    // GETTER

    // get the window
    sf::RenderWindow* get_window();

};


