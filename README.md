# Tree-ller
Small univeristy project: tree implementation as structure and relative operation on them using c++ and Sflm for graphics part.

## Type of tree implemented so far:

- Research binary tree (BT)

## Operation implemented in BT so far:

- Insertion
- Cancel     (need to be fixed)
- Search

# Binary Tree data structure

The binary tree is realized as a structure composed by a root node and a pointer to the left and right child. The key value will be a positive int number for an easy comparasion. This type of trre implement different type of operation privaliging the recursive approach. Traveling the tree is done in three different way: pre-order (implemented with stack), in-order (implemented with stack) and post-order (implemented with stack) por-level(implement with queue) The tree will be printed in a graphical way using the SFML library.

# How to run the project

1. Install sfml library
```sh
    sudo apt-get install libsfml-dev
```
2. Build the project
```sh
    make -B all
```

