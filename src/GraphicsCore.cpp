// implementaton of the GraphicsCore class

#include "../lib/GraphicsCore.h"
#include <math.h>

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

// Private function that update Keys_Bt and adjust some parameters
void GraphicsCore::update_Bt()
{
    // update bt keys vector
    keys_Bt = Bt->level_order_traversal_print();

    // adjust the circle vector
    circles.resize(keys_Bt.size());

    // get the hight of the tree to understand if it will fit in the window
    int h = Bt->get_height();

    // calculate max possible height and width defined parameters
    int max_height = (BT_HIGHT_DISTANCE_BTWEEN_NODES * h) + (BT_NODE_RADIUS * h);
    int max_width = (BT_NODE_DISTANCE * pow(2, h - 1)) + (BT_NODE_RADIUS * pow(2, h - 1));

    // if the tree is too big for the window resize the window
    if (max_height > height || max_width > width)
    {
        // resize the window
        height = max_height + 50;
        width = max_width + 50;
        window.setSize(sf::Vector2u(width, height));
    }
}

// function to draw the binary tree
void GraphicsCore::draw_binary_tree()
{
    // check if the vector changed
    if (Bt_redraw)
    {
        update_Bt();
        Bt_redraw = false;
    }

     keys_Bt = Bt->level_order_traversal_print();

    // clear the window
    window.clear(sf::Color::Black);

    int level = 0;                     // current level of the tree
    int nodes_in_level = 1;            // numbero of nodes in the current level
    int index_in_level = 0;            // index of the current node in the current level
    int x_offset = width / 2; // offset to center the tree    
    int y_offset = BT_NODE_RADIUS * 2; 
    float x = 0;
    float y = 10;

        for (int i = 0; i < keys_Bt.size(); i++)
        {
            // if the nodes dosen't exist skip
            if (keys_Bt[i] == -1)
            {
                index_in_level++;
                if (index_in_level == nodes_in_level)
                {
                    // skip to the next level
                    level++;
                    nodes_in_level *= 2;
                    index_in_level = 0;
                }
                continue;
            }

            // calculate the position of the node
            x = x_offset + (index_in_level - (nodes_in_level / 2.0)) * BT_NODE_DISTANCE;
            y = level * y_offset;

            // draw the node
            sf::CircleShape node(BT_NODE_RADIUS);
            node.setPosition(x - BT_NODE_RADIUS, y - BT_NODE_RADIUS); // center the node
            node.setFillColor(sf::Color::White);
            window.draw(node);

            // draw the key of the node in the center of the node
            sf::Text text;
            text.setFont(font);
            text.setString(std::to_string(keys_Bt[i]));
            text.setCharacterSize(15);
            text.setFillColor(sf::Color::Black);
            text.setPosition(x - 5, y - 10); // off to the center
            window.draw(text);

            // next node
            index_in_level++;
            if (index_in_level == nodes_in_level)
            {
                // next level
                level++;
                nodes_in_level *= 2;
                index_in_level = 0;
            }
        }


    window.display();
}

// get the window
sf::RenderWindow *GraphicsCore::get_window()
{
    return &window;
}