// AbstractTree.h
#pragma once

// Abstract class to describe the operation that every tree will implement.

class AbstractTree
{
public:
    virtual ~AbstractTree() = default;

    // Insert a new node
    virtual void insert(const int value) = 0;

    // Cancel an existing node
    virtual bool cancel(const int value) = 0;

    // Search a node and return 1 if it finds it or 0 if it fails
    virtual bool search(const int value) = 0;

    // Other common methode among tress could be added
};