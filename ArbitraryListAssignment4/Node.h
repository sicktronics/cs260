#pragma once
/*
* NOTE: I originally used this file for Assignment 3, and am
* using a slightly modified version here.
*
* This templated struct (public by default) stores information
* on a single "node" that will live in our linked list.
*
* The template allows the linked list to manage different
* data types.
*/ 

struct Node{

    // A node has three attributes:
    int value;          // (1) The value it holds,
    Node *prevNode;     // (2) A pointer to the address of the previous node,
    Node *nextNode;     // (3) A pointer to the address of the next node.

    Node() {}    // Default constructor
    
    // Our constructor that takes the two attributes.
    Node(int val, Node *prev, Node *next) {
        this->value = val;
        this->prevNode = prev;
        this->nextNode = next;
    }
};  // End of Node struct.