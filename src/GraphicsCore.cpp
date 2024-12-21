// implementaton of the GraphicsCore class

#include "../lib/GraphicsCore.h"
#include <math.h>
#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h> 

// constructor
GraphicsCore::GraphicsCore(BinaryTree *Bt) : window(sf::VideoMode(width, height), "Tree-ller")
{
    // set the binary tree
    this->Bt = Bt;

    // set the window position
    window.setPosition(sf::Vector2i(100, 100));

    // set the window framerate
    window.setFramerateLimit(60);

    // set the window background color
    window.clear(sf::Color::Black);

    // load the font
    if(!font.loadFromFile("../assets/fonts/arial.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
    }
}

// destructor
GraphicsCore::~GraphicsCore()
{
    // close the window
    window.close();
}



void GraphicsCore::draw_binary_tree()
{
    int h = Bt->get_height();

    if (h == 0) return; // Handle empty tree

    // Clear the window
    window.clear(sf::Color::Black);

    // Calculate dynamic spacing
    float level_spacing = static_cast<float>(height) / (h + 1); // Vertical spacing
    float initial_spacing = static_cast<float>(width) / (pow(2, h - 1) + 1); // Initial horizontal spacing

    // Recursive lambda to draw nodes and edges using BT nodes list
    std::function<void(BinaryNode*, int, float, float, float)> draw_node = [&](BinaryNode* node, int level, float x, float y, float spacing) {
        if (!node) return;

        // Draw current node
        sf::CircleShape circle(BT_NODE_RADIUS);
        circle.setFillColor(sf::Color::White);
        circle.setPosition(x - BT_NODE_RADIUS, y - BT_NODE_RADIUS);
        window.draw(circle);

        // Draw the node's key
        sf::Text text;
        text.setFont(font); // Assuming font is loaded
        text.setString(std::to_string(node->key));
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x - 10, y - 15); // Center text
        window.draw(text);

        // Calculate child positions
        float child_y = y + level_spacing;

        // Draw left child and edge
        if (node->left)
        {
            float child_x = x - spacing / 2.0f;
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y + BT_NODE_RADIUS)),
                sf::Vertex(sf::Vector2f(child_x, child_y - BT_NODE_RADIUS))
            };
            window.draw(line, 2, sf::Lines);
            draw_node(node->left, level + 1, child_x, child_y, spacing / 2.0f);
        }

        // Draw right child and edge
        if (node->right)
        {
            float child_x = x + spacing / 2.0f;
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y + BT_NODE_RADIUS)),
                sf::Vertex(sf::Vector2f(child_x, child_y - BT_NODE_RADIUS))
            };
            window.draw(line, 2, sf::Lines);
            draw_node(node->right, level + 1, child_x, child_y, spacing / 2.0f);
        }
    };

    // Start drawing from the root node
    if (Bt->get_root())
    {
        float root_x = static_cast<float>(width) / 2.0f; // Center the root horizontally
        float root_y = level_spacing / 2.0f; // Start at the top with some margin
        draw_node(Bt->get_root(), 0, root_x, root_y, initial_spacing);
    }

    // Display the rendered tree
    window.display();
}



// get the window
sf::RenderWindow *GraphicsCore::get_window()
{
    return &window;
}
