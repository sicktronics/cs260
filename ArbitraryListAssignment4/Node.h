#pragma once
/*
* NOTE: I originally used this file for Assignment 3, and am
* re-using it here (just changing the struct name from 'Element'
* to 'Node').
*
* This templated struct (public by default) stores information
* on a single "node" that will live in our linked list.
*
* The template allows the linked list to manage different
* data types.
*/ 

struct Node{

    // A node has two attributes:
    int value;          // (1) The value it holds,
    Node *nextNode;  // (2) A pointer to the address of the next node.

    Node() {}    // Default constructor
    
    // Our constructor that takes the two attributes.
    Node(int val, Node *nxt) {
        this->value = val;
        this->nextNode = nxt;
    }
};  // End of Node struct.