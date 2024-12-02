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
    int max_height = (BT_NODE_RADIUS *2  * h) + (BT_NODE_RADIUS * h);
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

    // height of the tree
    int h = Bt->get_height();

    // clear the window
    window.clear(sf::Color::Black);


    // first position of the lefter node on the last level
    float x = 270;
    cout << x << endl;
    float y = h* BT_NODE_RADIUS * 4;

    int level = 0;

    for (int i=h; i>0; i--){
        for (int j=0; j<pow(2,i-1); j++){
            sf::CircleShape node(BT_NODE_RADIUS);
            node.setPosition(x + j*BT_NODE_DISTANCE*2*BT_NODE_RADIUS, y);
            node.setFillColor(sf::Color::White);
            window.draw(node);
        }
        level++;
        y -= BT_NODE_RADIUS * 4;
        x += (BT_NODE_RADIUS * 2)*level;
    }

    window.display();
}

// get the window
sf::RenderWindow *GraphicsCore::get_window()
{
    return &window;
}
