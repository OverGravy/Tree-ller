//GraphicsCore.h
#pragma once

#include "BinaryTree.h"
#include <SFML/Graphics.hpp>
#include <vector>

// this class will define the methods to draw the tree using sfml library


// list of define to draw things
#define BT_NODE_RADIUS 20
#define BT_NODE_DISTANCE BT_NODE_RADIUS *2


using namespace std;


class GraphicsCore
{
private:
    // screen dimension set by default to 800x600
    int width = 1920;
    int height = 1080;

    // trees object needed to draw the tree
    BinaryTree* Bt;

    // sfml objects
    sf::RenderWindow window;
    sf::Font font;

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


